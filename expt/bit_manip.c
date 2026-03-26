#include <stdio.h>

int main() {

    int victim = 0xabcdef23;
    int mask = 0xff << 8; // 0x0000ff00

    printf("victim: 0x%x\n", victim);
    printf("mask: 0x%x\n", mask);
    printf("victim & mask: 0x%x\n", victim & mask); // 0xef00
    printf("victim | mask: 0x%x\n", victim | mask); // 0xabcdff23

    mask = ~mask; // 0xffff00ff
    printf("reverted mask: 0x%x\n", mask);
    printf("victim & mask: 0x%x\n", victim & mask); // 0xabcd0023
    printf("victim | mask: 0x%x\n", victim | mask); // 0xffffefff

    mask = ~mask; // revert again, reset to initial value so I can continue with my examples
    mask = mask | (mask << 16); 
    printf("new mask: 0x%x\n", mask); // 0xff00ff00
    printf("victim & mask: 0x%x\n", victim & mask); // 0xab00ef00
    printf("victim | mask: 0x%x\n", victim | mask); // 0xffcdff23

    return 0;
}