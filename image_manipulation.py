import numpy as np
from PIL import Image


# take path to an image file ('.png' file) as input and return
# a list representation of the image
def image_to_list(filename):
    img = Image.open(filename)
    img.load()
    data = np.asarray(img, dtype="int32")
    return data.tolist()


# take list representation of an image and save it as a '.png' file named filename
def write_image(image_list, filename):
    if '.png' not in filename:
        print("ERROR: Image should be saved in .png format")
        return -1
    image = np.array(image_list, dtype=np.uint8)
    im = Image.fromarray(image)
    im.save(filename)


def rotate_90_degrees(image_array, direction):
    """
    (nested_list, integer) --> nested_list

    The function rotates the inputted image array based on the specified direction. A direction of -1 rotates the image
    90 degrees counter-clockwise. A direction of 1 rotates the image 90 degrees clockwise. The image dimensions must be
    square

    >> rotate_90_degrees([[01, 02, 03], [11, 12, 13], [21, 22, 23]], -1)
    [[03, 02, 01], [13, 12, 11], [23, 22, 21]]
    """
    counter = []
    clock = []
    for i in range(max(len(image_array[0]), len(image_array))):
        counter.append([])
        clock.append([])
    for i, j in enumerate(image_array):
        for a, b in enumerate(j):
            counter[a].append(b)
    if direction == -1:
        return counter[::-1]
    elif direction == 1:
        image_array2 = image_array[::-1]
        for i, j in enumerate(image_array2):
            for a, b in enumerate(j):
                clock[a].append(b)
        return clock


def flip_image(image_array, axis):
    """
    (nested_list, integer) --> nested_list

    The function takes in an array of an image and flips it around a specified axis. The output is the rotated image
    array. axis = 1 specifies the x-axis, axis = -1 specifies the y-axis, and axis = -1 specifies the y = x axis.

    >> flip_image([[01, 02, 03], [11, 12, 13], [21, 22, 23]], 1)
    [[23, 22, 21], [13, 12, 11], [01, 02, 03]]
    """
    y_axis = []
    if axis == 0:
        for i in range(max(len(image_array[0]), len(image_array))):
            temp_list = image_array[i]
            temp_list.reverse()
            y_axis.append(temp_list)
        return y_axis
    elif axis == 1:
        image_array.reverse()
        return image_array
    elif axis == -1:
        temp_image = rotate_90_degrees(image_array, 1)
        temp_image.reverse()
        return temp_image


def invert_grayscale(image_array):
    """
    (nested_list) --> nested_list

    The function takes in an rgb image array and outputs an inverted grayscale image array. It calls the function
    rgb_to_grayscale in order to convert it to grayscale and then subtracts the individual pixels from 255 to invert the
    array.

    >> invert_grayscale([[23, 148, 201]])
    [[232, 107, 54]]
    """
    image_array = rgb_to_grayscale(image_array)
    for i in range(len(image_array)):
        for j in range(max(len(image_array), len(image_array[0]))):
            image_array[i][j] = 255 - image_array[i][j]
    return image_array


def crop(image_array, direction, n_pixels):
    """
    (nested_list, string, integer) --> nested_list

    The function takes in an image array and outputs a cropped version of the image array. direction specifies the
    direction of crop and n_pixels specifies the amount of pixels the image is cropped by.

    >> crop([[01, 02, 03], [11, 12, 13]], 'left', 1)
    [[02, 03], [12, 13]]
    """
    new_image = []
    for i in range(len(image_array)):
        new_image.append([])
    if direction == 'right':
        for i in range(len(image_array)):
            for j in range(len(image_array)):
                new_image[i] = image_array[i][0:-n_pixels]
        return new_image
    if direction == 'left':
        for i in range(len(image_array)):
            for j in range(len(image_array)):
                new_image[i] = image_array[i][n_pixels:]
        return new_image
    if direction == 'up':
        new_image = image_array[n_pixels:]
        return new_image
    if direction == 'down':
        new_image = image_array[0:-n_pixels]
        return new_image


def rgb_to_grayscale(rgb_image_array):
    """
    (nested_list) --> nested_list

    The function converts an rgb image array to a grayscale image array by multiplying and adding the rgb channels into
    1 grayscale pixel.

    >> rgb_to_grayscale([[[1, 1, 1]]])
    [[1]]
    """
    row = []
    for i in range(len(rgb_image_array)):
        row.append([])
    for i in range(len(rgb_image_array)):
        for j in range(len(rgb_image_array[0])):
            pixel_i = rgb_image_array[i][j][0] * 0.2989 + rgb_image_array[i][j][1] * 0.587 + rgb_image_array[i][j][2] * \
                      0.114
            row[i].append(pixel_i)
    return row


def invert_rgb(image_array):
    """
    (nested_list) --> nested_list

    The function takes in an rgb image array and inverts it. It does so by subtracting the red, green, and blue pixels
    from 255.

    >> invert_rgb([[[234, 21, 0]]])
    [[[21, 234, 255]]]
    """
    for i in range(len(image_array)):
        for j in range(len(image_array[0])):
            image_array[i][j][0] = 255 - image_array[i][j][0]
            image_array[i][j][1] = 255 - image_array[i][j][1]
            image_array[i][j][2] = 255 - image_array[i][j][2]
    return image_array
