from PIL import Image
import os

def ensure_directory(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)

def prepare_image_for_oled(image_path, output_path, display_width=128, display_height=64):
    img = Image.open(image_path)
    img_ratio = img.width / img.height
    display_ratio = display_width / display_height

    if img_ratio >= display_ratio:
        new_width = display_width
        new_height = int(display_width / img_ratio)
    else:
        new_width = int(display_height * img_ratio)
        new_height = display_height

    img_resized = img.resize((new_width, new_height), Image.ANTIALIAS)
    img_monochrome = img_resized.convert('1')
    img_monochrome.save(output_path)

    return output_path, new_width, new_height

def convert_bmp_to_c_array(bmp_path):
    with Image.open(bmp_path) as img:
        img_monochrome = img.convert('1')
        data = []
        for y in range(img.height):
            for x in range(0, img.width, 8):
                byte = 0
                for bit in range(8):
                    if x + bit < img.width:
                        pixel = img_monochrome.getpixel((x + bit, y))
                        byte |= (0 if pixel == 0 else 1) << (7 - bit)
                data.append(byte)
        return data, img.width, img.height

def write_c_and_h_files(image_data, image_name, width, height):
    directory_path = "generated_code"
    ensure_directory(directory_path)

    c_file_path = os.path.join(directory_path, f"{image_name}.c")
    h_file_path = os.path.join(directory_path, f"{image_name}.h")

    with open(h_file_path, 'w') as h_file:
        h_file.write(f"#ifndef {image_name.upper()}_H\n")
        h_file.write(f"#define {image_name.upper()}_H\n\n")
        h_file.write("#include <stdint.h>\n\n")
        h_file.write(f"extern const uint8_t {image_name}_width;\n")
        h_file.write(f"extern const uint8_t {image_name}_height;\n")
        h_file.write(f"extern const uint8_t {image_name}_data[];\n")
        h_file.write(f"extern const uint16_t {image_name}_size;\n\n")
        h_file.write("#endif // " + image_name.upper() + "_H\n")

    with open(c_file_path, 'w') as c_file:
        c_file.write('#include <stdint.h>\n')
        c_file.write(f'#include "{image_name}.h"\n\n')
        c_file.write(f"const uint8_t {image_name}_width = {width};\n")
        c_file.write(f"const uint8_t {image_name}_height = {height};\n")
        c_file.write(f"const uint8_t {image_name}_data[] = {{\n")
        for i, byte in enumerate(image_data):
            if i % 8 == 0:
                c_file.write("\n    ")
            c_file.write(f"0x{byte:02X}, ")
        c_file.write("\n};\n")

        c_file.write(f"const uint16_t {image_name}_size = sizeof({image_name}_data);\n")

# Example usage
image_name = "linux_img2"
image_path = f"img/{image_name}.png"
output_path = f"generated_bmp/{image_name}.bmp"
output_path, image_width, image_height = prepare_image_for_oled(image_path, output_path)
image_data, width, height = convert_bmp_to_c_array(output_path)
write_c_and_h_files(image_data, image_name, width, height)
