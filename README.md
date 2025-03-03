# RGB_YCbCr-Converter

**RGB_YCbCr-Converter** is a Python and C-based tool for converting RGB images to the YCbCr color space. It compares the performance of a Python implementation with a highly optimized C kernel and generates grayscale images from the luminance (Y) component.

## Features
- **RGB to YCbCr Conversion**: Implements the ITU-R BT.601 standard for converting RGB images to YCbCr.
- **Performance Comparison**: Compares the execution time of a Python implementation with a C kernel.
- **Grayscale Image Generation**: Extracts the Y component (luminance) to create grayscale images.
- **Error Checking**: Ensures the Python and C implementations produce nearly identical results, with a configurable error threshold.

## Requirements
- **Python 3.x**
- **GCC** (for compiling the C kernel)
- Python libraries:
  ```bash
  pip install numpy opencv-python Pillow

## Sample Input
  ```bash
  python3 convertRGB.py -i test2input.jpg -o test2outputbw.jpg
