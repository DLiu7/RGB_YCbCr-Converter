#include <math.h>
#include <string.h>

// In-line macros from lectures
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char *ycc_pixels, int width, int height) {

    if(width <= 0){
        width = 0;
    }

    if(height <= 0){
        height = 0;
    }

    int totalPixels = width * height;

    if (totalPixels <= 0) {
        memset(ycc_pixels, 0, totalPixels * 3); 
        return;
    }

    // There are (width * height) pixels and each pixel has 3 bytes (R,G,B)
    // Stored row-major order
    // Pixel 0: R0, G0, B0
    // Pixel 1: R1, G1, B1
    for (int i = 0; i < totalPixels; i++) {
        int r = rgb_pixels[3*i];
        int g = rgb_pixels[3*i + 1];
        int b = rgb_pixels[3*i + 2];

        // Apply the BT.601 conversion formula
        int y  = (int)round(0.299 * r + 0.587 * g + 0.114 * b);
        int cr = (int)round(128 + 0.5 * r - 0.418688 * g - 0.081312 * b);
        int cb = (int)round(128 - 0.168736 * r - 0.331264 * g + 0.5 * b);

        // Clamping ranges for YCrCb
        y = max(0, min(y, 255));    
        cr = max(0, min(cr, 255));
        cb = max(0, min(cb, 255));

        //Force cast to char (8-bits)
        ycc_pixels[3*i]     = (unsigned char)y;
        ycc_pixels[3*i + 1] = (unsigned char)cr;
        ycc_pixels[3*i + 2] = (unsigned char)cb;

    }
}