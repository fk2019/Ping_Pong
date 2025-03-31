#!/usr/bin/python
from PIL import Image

# Load the image
image_path = 'images/ball.png'
img = Image.open(image_path)

# Get the bounding box of the non-transparent area
bbox = img.getbbox()

# Crop the image to the bounding box
cropped_img = img.crop(bbox)

# Save the cropped image
cropped_img.save('images/new.png')
