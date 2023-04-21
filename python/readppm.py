from PIL import Image
import sys

if len(sys.argv) >= 2:
    file = sys.argv[1]
    with open(file, "r") as f:
        lines = f.readlines()
        dimensions = tuple([int(x) for x in lines[1].split(" ")])
        img = Image.new("RGB", dimensions)
        pixels = []
        for i in range(3, len(lines)):
            line = lines[i]
            pixel = tuple([int(x) for x in line.split(" ")])
            pixels.append(pixel)
        for y in range(dimensions[1]):
            for x in range(dimensions[0]):
                pixel = pixels.pop(0)
                img.putpixel((x, y), pixel)
        img.show()
