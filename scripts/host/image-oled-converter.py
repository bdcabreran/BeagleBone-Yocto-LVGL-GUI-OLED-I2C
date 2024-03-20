from PIL import Image

def prepare_image_for_oled(image_path, output_path, display_width=128, display_height=64):
    # Load the image
    img = Image.open(image_path)

    # Calculate the new size to keep the aspect ratio
    img_ratio = img.width / img.height
    display_ratio = display_width / display_height

    if img_ratio >= display_ratio:
        new_width = display_width
        new_height = int(display_width / img_ratio)
    else:
        new_width = int(display_height * img_ratio)
        new_height = display_height

    # Resize the image
    img_resized = img.resize((new_width, new_height), Image.ANTIALIAS)

    # Convert to monochrome
    img_monochrome = img_resized.convert('1')

    # Save the processed image
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

def display_image_in_terminal(image_data, width, height):
    print("Displaying image in terminal...")
    bytes_per_row = (width + 7) // 8

    for y in range(height):
        row = ''
        for x in range(width):
            byte_index = y * bytes_per_row + x // 8
            bit_index = x % 8
            if byte_index < len(image_data):
                pixel_on = image_data[byte_index] & (1 << (7 - bit_index))
                row += '.' if pixel_on else ' '
            else:
                row += ' '
        print(row)

def print_c_array(image_data, width, height):
    """
    Print the image data as a C array.
    """
    print(f"static const uint8_t image_width = {width};")
    print(f"static const uint8_t image_height = {height};")
    print("static const uint8_t image_data[] = {")
    
    # Print the image data in rows of 8 bytes for readability
    for i, byte in enumerate(image_data):
        if i % 8 == 0:
            print("\n    ", end="")  # Newline and indent for every 8 bytes
        print(f"0x{byte:02X}, ", end="")
    
    print("\n};")

# Example usage with the previous steps
image_path = 'img/linux-logo.png'  # Update this path
output_path = 'img/linux-logo.bmp'
output_path, image_width, image_height = prepare_image_for_oled(image_path, output_path)

# Convert BMP to binary data and get dimensions
image_data, width, height = convert_bmp_to_c_array(output_path)

# Display the image in the terminal
display_image_in_terminal(image_data, width, height)

# Print the C array
print_c_array(image_data, width, height)

