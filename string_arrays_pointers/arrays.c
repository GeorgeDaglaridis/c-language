#include <stdio.h>

/*
int main() {
    int x[2] = {1, 2};
    int int_array[2] = {11, 21};
    int y[2] = {8, 9};

    int_array[2] = 101;

    printf("x[0] = %d\n", x[0]);
    printf("y[0] = %d\n", y[0]);
    printf("exit\n");
    return 0;
}
*/

int main() {
    int x[2] = {1, 2};
    long int int_array[2] = {11, 21};
    int y[2] = {8, 9};

    y[2] = 101;

    printf("x[0] = %d\n", x[0]);
    printf("y[0] = %d\n", y[0]);
    printf("int_array[0 ] = %ld\n", int_array[0]);
    printf("int_array[1] = %ld\n", int_array[1]);
    printf("exit\n");
    return 0;
}