#include <estia-image.h>
#include <stddef.h>
#include "utils.h"
 
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 *
 */

pixelRGB* get_pixel(unsigned char *data, const unsigned int *width, const unsigned int *height, const unsigned int n, const unsigned int x, const unsigned int y) {
  if (data == NULL || x >= *width || y >= *height) {
    return NULL; 
  }

  unsigned int pixel_index = (y * (*width) + x) * n;

  return (pixelRGB*) &data[pixel_index];
}

void set_pixel(unsigned char* data, unsigned int width, unsigned int channels, unsigned int x, unsigned int y, pixelRGB pixel) {
    if (data == NULL || channels < 3) return;
    unsigned int i = (y * width + x) * channels;
    data[i]     = pixel.R;
    data[i + 1] = pixel.G;
    data[i + 2] = pixel.B;
}