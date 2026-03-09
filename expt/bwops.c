#include <stdio.h>

void main() {

    int a = 0xA1;
    int b = 0x52;
    printf("& : 0x%x\n", a & b);
    printf("| : 0x%x\n", a | b);
    printf("^ : 0x%x\n", a ^ b);
    printf("~a : 0x%x\n", ~a);
    printf("~b : 0x%x\n\n", ~b);

    long int c = 0xA1;
    long int d = 0x52;
    printf("& : 0x%lx\n", c & d);
    printf("| : 0x%lx\n", c | d);
    printf("^ : 0x%lx\n", c ^ d);
    printf("~c : 0x%lx\n", ~c);
    printf("~d : 0x%lx\n\n", ~d);


    char e = 0xff;
    printf("e = %d\n", e);
    char f = 0xff >> 2;
    printf("f = %d\n", f);
}