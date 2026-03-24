#include <stdio.h>

int main() {
    unsigned int a = 0x1;
    printf("a = 0x%x, a << 31: 0x%x\n", a, a << 31); // Logical shift to the left

    a = 0x80000000;
    printf("a = 0x%x, a >> 31: 0x%x\n", a, a >> 31); // Logical shift to the right

    int b = 0x1; // signed
    printf("b = 0x%x, b << 31: 0x%x\n", b, b << 31); // Logical shift to the left

    b = 0x80000000;
    printf("b = 0x%x, b >> 31: 0x%x\n", b, b >> 31); // Arithmetic shift to the right, signed bit is preserved

    printf("b = 0x%x, b >> 4: 0x%x\n", b, b >> 4);   // Arithmetic shift to the right, signed bit is preserved

    b = 0x40000000;
    printf("b = 0x%x, b >> 30: 0x%x\n", b, b >> 30); // Arithmetic shift to the right

    printf("b = 0x%x, b >> 4: 0x%x\n", b, b >> 4);   // Arithmetic shift to the right

    

    return 0;
}