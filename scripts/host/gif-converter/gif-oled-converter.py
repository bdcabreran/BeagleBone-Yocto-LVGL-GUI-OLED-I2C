from PIL import Image, ImageSequence
import os

def ensure_directory(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)

def prepare_frame_for_oled(frame, display_width=128, display_height=64):
    img_ratio = frame.width / frame.height
    display_ratio = display_width / display_height

    if img_ratio >= display_ratio:
        new_width = display_width
        new_height = int(display_width / img_ratio)
    else:
        new_width = int(display_height * img_ratio)
        new_height = display_height

    frame_resized = frame.resize((new_width, new_height), Image.ANTIALIAS)
    frame_monochrome = frame_resized.convert('1')

    return frame_monochrome, new_width, new_height

def frame_to_c_array(gif_name, frame, frame_number, frame_width, frame_height, c_file):
    data = []
    for y in range(frame_height):
        for x in range(0, frame_width, 8):
            byte = 0
            for bit in range(8):
                if x + bit < frame_width:
                    pixel = frame.getpixel((x + bit, y))
                    byte |= (0 if pixel == 0 else 1) << (7 - bit)
            data.append(byte)

    # Write individual frame C array to .c file with unique names
    frame_identifier = f"{gif_name}_f{frame_number}"
    c_file.write(f"const uint8_t {frame_identifier}_width = {frame_width};\n")
    c_file.write(f"const uint8_t {frame_identifier}_height = {frame_height};\n")
    c_file.write(f"const uint8_t {frame_identifier}_data[] = {{\n")
    for i, byte in enumerate(data):
        if i % 8 == 0 and i > 0:
            c_file.write("\n")
        c_file.write(f"0x{byte:02X}, ")
    c_file.write("\n};\n\n")
    
    return f"{frame_identifier}_data"

def process_gif_and_generate_code(gif_path, display_width=128, display_height=64):
    gif = Image.open(gif_path)
    gif_name = os.path.splitext(os.path.basename(gif_path))[0]
    frames_directory = f"frames/{gif_name}_frames"
    code_directory = f"generated_code/{gif_name}"
    ensure_directory(frames_directory)
    ensure_directory(code_directory)
    
    c_file_path = f"{code_directory}/{gif_name}.c"
    h_file_path = f"{code_directory}/{gif_name}.h"

    with open(c_file_path, 'w') as c_file, open(h_file_path, 'w') as h_file:
        # Write includes and guards
        c_file.write(f"#include <stdint.h>\n#include \"{gif_name}.h\"\n\n")
        h_file.write(f"#ifndef {gif_name.upper()}_H\n#define {gif_name.upper()}_H\n\n#include <stdint.h>\n")
        h_file.write(f"extern const uint16_t {gif_name}_frame_size;\n")
        h_file.write(f"extern const uint8_t {gif_name}_frame_width;\n")
        h_file.write(f"extern const uint8_t {gif_name}_frame_height;\n")
        h_file.write(f"extern const uint8_t {gif_name}_frame_count;\n")

        frames_data = []

        for frame_number, frame in enumerate(ImageSequence.Iterator(gif)):
            prepared_frame, frame_width, frame_height = prepare_frame_for_oled(frame, display_width, display_height)
            frame_path = os.path.join(frames_directory, f"{gif_name}_frame{frame_number}.bmp")
            prepared_frame.save(frame_path)
            frame_data_name = frame_to_c_array(gif_name, prepared_frame, frame_number, frame_width, frame_height, c_file)
            frames_data.append(frame_data_name)

        # Write metadata and parent array with unique names
        c_file.write(f"const uint8_t {gif_name}_frame_count = {len(frames_data)};\n")
        c_file.write(f"const uint16_t {gif_name}_frame_size = sizeof({frames_data[0]});\n")
        c_file.write(f"const uint8_t {gif_name}_frame_width = {gif_name}_f0_width;\n")
        c_file.write(f"const uint8_t {gif_name}_frame_height = {gif_name}_f0_height;\n")

        c_file.write(f"const uint8_t* {gif_name}_frames_data[] = {{\n")
        for frame_data_name in frames_data:
            c_file.write(f"    {frame_data_name},\n")
        c_file.write("};\n")


        # Write external references to .h file
        for frame_data_name in frames_data:
            h_file.write(f"extern const uint8_t {frame_data_name}[];\n")
        h_file.write(f"extern const uint8_t* {gif_name}_frames_data[{len(frames_data)}];\n\n#endif // {gif_name}_H\n")

# Example usage
gif_path = "gifs/penguin.gif"
process_gif_and_generate_code(gif_path)
