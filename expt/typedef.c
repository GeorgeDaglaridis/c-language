#include <stdio.h>

struct pixel_t {
    unsigned int l;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    
};

union pixelu_t {
    unsigned char r;
    unsigned short g;    
};

void main(){

    struct pixel_t pixel;
    union pixelu_t pixelu;
    
    //printf("%ld\n", sizeof(struct pixel_t));
    printf("%ld\n", sizeof(union pixelu_t));

}