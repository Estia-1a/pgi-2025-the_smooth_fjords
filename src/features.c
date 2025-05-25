#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "features.h"
#include "utils.h"
 
/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */
 
void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path) {
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("dimension: %d, %d", width,height);
    }
    else {
        printf("ERROR");
    }
}

void first_pixel(char *source_path){
    unsigned char *data;
    int width;
    int height;
    int nbChannels;
    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
    }
    else {
        printf("ERROR");
    }
}

void tenth_pixel(char *source_path){
    unsigned char *data;
    int width;
    int height;
    int nbChannels;
    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        printf("tenth_pixel: %d, %d, %d", data[27], data[28], data[29]);
    }
    else {
        printf("ERROR");
    }
}

void second_line(char *source_path){
    unsigned char *data;
    int width;
    int height;
    int nbChannels;
    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        int pixelIndex = (width * nbChannels);

        if (pixelIndex < width * height * nbChannels) {
            printf("second_line: %d, %d, %d\n", data[pixelIndex], data[pixelIndex + 1], data[pixelIndex + 2]);
        } else {
            printf("The image does not have a second line with at least one pixel.\n");
        }
    }
    else {
        printf("ERROR");
    }
}

void print_pixel(char *source_path, int x, int y){
    int width;
    int height;
    int nbChannels;
    unsigned char* data;
    int R,G,B;
    if (read_image_data(source_path, &data, &width, &height, &nbChannels) !=0){
        unsigned int position = 3*(y*width+x);
        R = data[position];
        G = data[position+1];
        B = data[position+2];
        printf("print_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
    }
    else {
        printf("ERROR");
    }
}

void max_pixel(char *source_path) {
    int width;
    int height;
    int nbChannels;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int max_sum = 0;
    int max_x = 0;
    int max_y = 0;

    int y, x;
    for (y=0 ; y < height; y++) {
        for (x=0; x<width; x++){
            int pixel_index = (y*width + x) * nbChannels;
            int R = data[pixel_index];
            int G = data[pixel_index + 1];
            int B = data[pixel_index +2];
            int SUM = R+G+B;
            if (SUM > max_sum){
                max_sum = SUM;
                max_x = x;
                max_y = y;
            }
        }
    }

    int max_pixel_index = (max_y*width + max_x)* nbChannels;
    int max_R = data[max_pixel_index];
    int max_G = data[max_pixel_index+1];
    int max_B = data[max_pixel_index+2];

    printf("max_pixel (%d, %d): %d, %d, %d", max_x, max_y, max_R, max_G, max_B);

    free(data);
}
