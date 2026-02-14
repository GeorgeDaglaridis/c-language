#include <stdio.h>

extern int a;

extern void foo();

void main() {
    a = a + 1;
    printf("main: %d\n", a);
  
    foo();
    return;
}