#include <math.h>
#include <string.h>

// In-lin macros from lectures
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char *ycc_pixels, int width, int height) {
    if (width <= 0 || height <= 0) {
        // Handle zero or negative dimensions by returning an array of zeros
        memset(ycc_pixels, 0, width * height * 3);
        return;
    }

    // There are (width * height) pixels and each pixel has 3 bytes (R,G,B)
    // Stored row-major order
    // Pixel 0: R0, G0, B0
    // Pixel 1: R1, G1, B1
    for (int i = 0; i < width * height; i++) {
        int r = rgb_pixels[3 * i];
        int g = rgb_pixels[3 * i + 1];
        int b = rgb_pixels[3 * i + 2];

        // Apply the BT.601 conversion formula
        int y  = (int)round(0.299 * r + 0.587 * g + 0.114 * b);
        int cb = (int)round(128 - 0.168736 * r - 0.331264 * g + 0.5 * b);
        int cr = (int)round(128 + 0.5 * r - 0.418688 * g - 0.081312 * b);

        // Luma (Y) ranges from 16 to 235
        ycc_pixels[3 * i] = min(max(y, 16), 235);
        // Cb (Blue minus luma) ranges from 16 to 240
        ycc_pixels[3 * i + 1] = min(max(cb, 16), 240);
        // Cr (Red minus luma) ranges from 16 to 240
        ycc_pixels[3 * i + 2] = min(max(cr, 16), 240);

    }
}