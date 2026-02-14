#include <stdio.h>

/*
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
*/

void main(){

    /*
    struct pixel_t pixel;
    union pixelu_t pixelu;
    
    //printf("%ld\n", sizeof(struct pixel_t));
    printf("%ld\n", sizeof(union pixelu_t));
    */

    //int i = 10;
    int j = 2;
    // while ( i > 0 ){
    //     if (i == 5){
    //         i = i-1;
    //         continue;
    //     }
    //     printf("When continue is used, i = %d\n", i);
    //     i = i-1;  
    // }
    
    /*
    while ( i > 0 ){
        if (i == 5){
            i = i-1;
            break;
        }
        printf("When break is used, i = %d\n", i);
        i = i-1;  
    }
    */

    // I thought it should have been different but in both cases, i-- or --i,
    // i gets decremented after the body of the loop is executed
    for (int i = 10; i > 0; --i){
        printf("i gets decremented before the body of the loop is executed, i = %d\n", i);
        j = j + 200;
    }

    return;
}