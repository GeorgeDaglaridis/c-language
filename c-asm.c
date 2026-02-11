//#include <stdio.h>

int piyush(){

    struct pixel_t {
        unsigned int l;
        unsigned char r;
        unsigned char g;
        unsigned char b;
    
    };

    struct pixel_t pixel;
    pixel.l = 4;
    pixel.r = 255;
    pixel.g = 253;
    pixel.b = 252;
    
    //printf("%ld\n", sizeof(pixel));

    return 0;
}