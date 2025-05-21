#include <estia-image.h>
#include <stddef.h>
#include "utils.h"
 
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 *
 */
pixelRGB* get_pixel(unsigned char *data, const unsigned int *width, const unsigned int *height, const unsigned int n, const unsigned int x, const unsigned int y) {
  if (data == NULL || x >= *width || y >= *height) {
    return NULL; // VÃ©rification des prÃ©conditions
  }

  unsigned int pixel_index = (y * (*width) + x) * n;

  return (pixelRGB*) &data[pixel_index];
}
