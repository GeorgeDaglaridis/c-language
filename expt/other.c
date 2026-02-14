#include <stdio.h>

static int a = 10;

static void foo() {
    a = a + 1;
    printf("foo: %d\n", a);

    return;
}

void bar() {
    static char b = 3;
    b = b + 1;

    foo();

    printf("bar: %d\n", b);
    return;
    
}