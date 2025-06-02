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

void max_pixel(char *source_path){
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

}

void min_component(char *source_path, char component) {
    int width, height, nbChannels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        int min_component_value = 765;
        int min_x = 0;
        int min_y = 0;

        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int pixel_index = (y * width + x) * nbChannels;
                int R = data[pixel_index];
                int G = data[pixel_index + 1];
                int B = data[pixel_index + 2];
                int component_value;

                if (component == 'R' || component == 'r') {
                    component_value = R;
                } else if (component == 'G' || component == 'g') {
                    component_value = G;
                } else if (component == 'B' || component == 'b') {
                    component_value = B;
                } else {
                    printf("Option de composante invalide.\n");
                    return;
                }
                if (component_value < min_component_value) {
                    min_component_value = component_value;
                    min_x = x;
                    min_y = y;
                }
            }
        }
        printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_component_value);
    }

}

void max_component(char *source_path, char component) {
    int width;
    int height;
    int nbChannels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        int max_component_value = -1;
        int max_x = 0;
        int max_y = 0;

        int y;
        int x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int pixel_index = (y * width + x) * nbChannels;
                int R = data[pixel_index];
                int G = data[pixel_index + 1];
                int B = data[pixel_index + 2];
                int component_value;

                if (component == 'R' || component == 'r') {
                    component_value = R;
                } else if (component == 'G' || component == 'g') {
                    component_value = G;
                } else if (component == 'B' || component == 'b') {
                    component_value = B;
                } else {
                    printf("Option de composante invalide.\n");
                    return;
                }
                if (component_value > max_component_value) {
                    max_component_value = component_value;
                    max_x = x;
                    max_y = y;
                }
            }
        }

        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_component_value);
    }

}

void min_pixel(char *source_path){
    int width;
    int height;
    int nbChannels;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int min_sum = INT_MAX;
    int min_x = 0;
    int min_y = 0;

    int y, x;
    for (y = 0 ; y < height; y++) {
        for (x = 0; x<width; x++){
            int pixel_index = (y * width + x) * nbChannels;
            int R = data[pixel_index];
            int G = data[pixel_index + 1];
            int B = data[pixel_index +2];
            int SUM = R + G + B;

            if (SUM < min_sum){
                min_sum = SUM;
                min_x = x;
                min_y = y;
            }
        }
    }

    int min_pixel_index = (min_y*width + min_x)* nbChannels;
    int min_R = data[min_pixel_index];
    int min_G = data[min_pixel_index+1];
    int min_B = data[min_pixel_index+2];

    printf("min_pixel (%d, %d): %d, %d, %d", min_x, min_y, min_R, min_G, min_B);

}  

void color_red (char* source_path){
    int width , height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int x;
    int y;
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){
            data[y*width*3 + x*3+1] = 0;
            data[y*width*3 + x*3+2] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_blue (char* source_path){
    int width , height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int x;
    int y;
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){
            data[y*width*3 + x*3] = 0;
            data[y*width*3 + x*3+1] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_green(char* source_path){
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int y;
    int x;
    for (y = 0; y < height; y++){
        for (x=0; x < width; x++){
        data[y*width*3 + x*3] = 0;
        data[y*width*3 + x*3+2] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
} 

void color_gray (char* source_path) {
    int width;
    int height;
    int nbChannels;
    unsigned char*source_data;
    unsigned char*target_data;
    if(read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char *)malloc(width * height *nbChannels *sizeof(unsigned char));
        int y, x;
        for (y = 0; y < height; y++){
            for (x = 0; x< width; x++){

            int pixel_index = (y*width +x) * nbChannels;

            unsigned char red = source_data [pixel_index];
            unsigned char green = source_data [pixel_index + 1];
            unsigned char blue = source_data [ pixel_index+ 2];

            unsigned char gray = (red + green + blue) / 3;

            source_data[pixel_index] = gray;
            source_data[pixel_index + 1] = gray;
            source_data[pixel_index + 2] = gray;
            
            }
        }

        write_image_data("image_out.bmp", target_data, width, height);
        free(source_data);
    }
}

void rotate_cw(char* source_path) {
    int width, height, nbChannels;
    unsigned char *source_data;
    unsigned char *target_data;

    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char *)malloc(width * height * nbChannels * sizeof(unsigned char));

        int target_width = height;
        int target_height = width;

        int y, x;
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((x * target_width) + (target_width - 1 - y)) * nbChannels;

                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];

                if (nbChannels == 4){
                    target_data[target_pixel_index +3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bpm", target_data, target_width, target_height);

        free(source_data);
        free(target_data);
    }
}

void mirror_horizontal(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int y, x, c;
    unsigned char temp;
    for (y = 0; y < height; y++){
        for (x = 0; x < width/2; x++){
            for (c = 0; c < nbChannels; c++){
                temp = data[y*width*nbChannels + x * nbChannels + c];
                data[y * width * nbChannels + x * nbChannels + c] = data[y * width * nbChannels + (width - x - 1)*nbChannels + c];
                data[y * width * nbChannels + (width - x- 1) * nbChannels + c] = temp;
            }
        }
    }
    write_image_data("image_out.bpm", data, width, height);
    free(data);
}

void mirror_vertical(char *source_path){
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);

    int y, x, c;
    unsigned char temp;
    for(y = 0; y < height/2; y++){
        for (x = 0; x < width; x++){
            for (c = 0; c < nbChannels; c++){
                temp = data[y * width * nbChannels + x * nbChannels + c];
                data[y * width * nbChannels + x * nbChannels + c] = data[(height - y - 1) * width * nbChannels + x *nbChannels + c];
                data [(height - y - 1) * width * nbChannels + x * nbChannels + c] = temp;
            }
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free(data);
}

void rotate_acw(char* source_path) {
    int width, height, nbChannels;
    unsigned char* source_data;
    unsigned char* target_data;
 
    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char*)malloc(width * height * nbChannels * sizeof(unsigned char));
        int target_width = height;
        int target_height = width;
 
        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((target_height - 1 - x) * target_width + y) * nbChannels;
 
                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];
 
                if (nbChannels == 4) {
                    target_data[target_pixel_index + 3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bmp", target_data, target_width, target_height);
 
        free(source_data);
        free(target_data);
    }
}

void mirror_total(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);

    int y, x, c;
    unsigned char temp;

    for (y = 0; y < height; y++){
        for (x = 0; x < width/2; x++){
            for (c = 0; c < nbChannels; c++){
                temp = data[y*width*nbChannels + x*nbChannels + c];
                data[y*width*nbChannels + x*nbChannels + c] = data[y*width*nbChannels + (width -x - 1)*nbChannels + c];
                data[y*width*nbChannels + (width - x - 1)*nbChannels + c] = temp;
            }
        }
    }

    for (y = 0; y < height/2; y++){
        for (x = 0; x < width; x++){
            for (c = 0; c < nbChannels; c++){
                temp = data[y * width * nbChannels + x * nbChannels + c];
                data[y * width * nbChannels + x * nbChannels + c] = data[(height - y - 1) * width * nbChannels + x * nbChannels + c];
                data[(height - y - 1) * width * nbChannels + x * nbChannels + c] = temp;
            }
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free(data);
}

void color_gray_luminance(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            unsigned char red = data[y * width * 3 + x * 3];
            unsigned char green = data[y * width * 3 + x * 3 + 1];
            unsigned char blue = data[y * width * 3 + x * 3 + 2];
            unsigned char gray = (unsigned char)(0.21 * red + 0.72 * green + 0.07 * blue);
            
            data[y * width * 3 + x * 3] = gray;
            data[y * width * 3 + x * 3 + 1] = gray;
            data[y * width * 3 + x * 3 + 2] = gray;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_desaturate(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));
    if (new_data == NULL) {
        printf("pas de sortie.\n");
        return;
    }
    int i = 0;
    while (i < width * height) {
        pixelRGB *pixel = (pixelRGB *)(data + i * channel_count);
        unsigned char min_value = pixel->R;
        if (pixel->G < min_value) {
            min_value = pixel->G;
        }
        if (pixel->B < min_value) {
            min_value = pixel->B;
        }
        unsigned char max_value = pixel->R;
        if (pixel->G > max_value) {
            max_value = pixel->G;
        }
        if (pixel->B > max_value) {
            max_value = pixel->B;
        }
        unsigned char new_value = (min_value + max_value) / 2;
        new_data[i * channel_count] = new_value;
        new_data[i * channel_count + 1] = new_value;
        new_data[i * channel_count + 2] = new_value;
        i++;
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_invert(char* source_path) {
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            unsigned char red = data[y * width * 3 + x * 3];
            unsigned char green = data[y * width * 3 + x * 3 + 1];
            unsigned char blue = data[y * width * 3 + x * 3 + 2];
            data[y * width * 3 + x * 3] = 255 - red;    // Invert red component
            data[y * width * 3 + x * 3 + 1] = 255 - green;  // Invert green component
            data[y * width * 3 + x * 3 + 2] = 255 - blue;   // Invert blue component
    }
}
 
    write_image_data("image_out.bmp", data, width, height);
    free(data);
}

void scale_crop(char*source_path, int center_x, int center_y, int crop_width, int crop_height){
    int width, height, nbChannels;
    unsigned char*source_data;
    unsigned char*target_data;
    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)){
        target_data = (unsigned char*)malloc(crop_width * crop_height * nbChannels * sizeof(unsigned char));
        int target_width = crop_width;
        int target_height = crop_height;
        int start_x = center_x - crop_width / 2;
        int start_y = center_y - crop_height /2;
        int y, x;
        for (y = 0, y < crop_height; y++){
            
        }
    }
}