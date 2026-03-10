#include <stdio.h>

void main() {

    long int a = 0x1;

    printf("a = 0x%lx\n", a);
    printf("a << 1:  0x%lx\n", a << 1);
    printf("a << 2:  0x%lx\n", a << 2);
    printf("a << 63: 0x%lx\n", a << 63);

    // since we are out of the boundaries a register can hold it 
    // seems to be executing a rotation
    printf("a << 64: 0x%lx\n", a << 64);
    printf("a << 65: 0x%lx\n\n", a << 65);

    a = 0x8;
    printf("a = 0x%lx\n", a);
    printf("a >> 1:  0x%lx\n", a >> 1);
    printf("a >> 2:  0x%lx\n", a >> 2);
    printf("a >> 3:  0x%lx\n", a >> 3);
    printf("a >> 4:  0x%lx\n", a >> 4);   // seems that no rotation is happening
    printf("a >> 5:  0x%lx\n", a >> 5);   // seems that no rotation is happening
    printf("a >> 6:  0x%lx\n\n", a >> 6); // seems that no rotation is happening

    /* 
     * When we perform a right shift in a signed value an arithmetic
     * rigth sift operation is executed where the sign bit is copied
     * to the rigth to all the bit positions that become vacant due
     * to the rigth shift.
     */
    a = 0x8000000000000000;
    printf("Arithmetic rigth shift operation\n");
    printf("signed a = 0x%lx\n", a);
    printf("a >> 63: 0x%lx\n",   a >> 63);
    printf("a >> 64: 0x%lx\n",   a >> 64);
    printf("a >> 65: 0x%lx\n",   a >> 65);
    printf("a >> 66: 0x%lx\n\n", a >> 66);

    a = 0x4000000000000000;
    printf("signed a = 0x%lx\n", a);
    printf("a >> 62: 0x%lx\n", a >> 62);
    printf("a >> 61: 0x%lx\n", a >> 61);
    printf("a >> 60: 0x%lx\n", a >> 60);

    printf("a >> 63: 0x%lx\n", a >> 63);
    printf("a >> 64: 0x%lx\n", a >> 64);
    printf("a >> 65: 0x%lx\n\n", a >> 65);

    unsigned long int b = 0x8000000000000000;
    printf("Logical rigth shift operation\n");
    printf("unsigned b = 0x%lx\n", b);
    printf("b >> 63: 0x%lx\n",   b >> 63);
    printf("b >> 64: 0x%lx\n",   b >> 64);
    printf("b >> 65: 0x%lx\n",   b >> 65);
    printf("b >> 66: 0x%lx\n\n", b >> 66);

    b = 0x4000000000000000;
    printf("unsigned b = 0x%lx\n", b);
    printf("b >> 62: 0x%lx\n", b >> 62);
    printf("b >> 61: 0x%lx\n", b >> 61);
    printf("b >> 60: 0x%lx\n", b >> 60);

    printf("b >> 63: 0x%lx\n", b >> 63);
    printf("b >> 64: 0x%lx\n", b >> 64);
    printf("b >> 65: 0x%lx\n\n\n", b >> 65);

    /* 
     * How to perform multiplication for instance if your system 
     * does not have multipliers as hardware.
     * i.e.: (3 x 5) = 3 x (4 + 1) = (3 x 4) + 3 = (3 << 2) + 3 
     */
    printf("3 x 5 = %d\n", 3 * 5);
    printf("(3 << 2) + 3 = %d\n", (3 << 2) + 3);


}