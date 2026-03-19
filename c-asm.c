#include <stddef.h>

void function_1() {
    int a = 3 + 2;
}

void function_2() {
    int b = 4 + 2;
}

int piyush() {
  
     //void (*func_ptr)() = function_1; // same: void (*func_ptr)() = &function_1;
    void (*func_ptr)() = NULL;

    func_ptr = function_1;
    func_ptr();
    
    func_ptr = function_2;
    func_ptr();

    int c = 8 + 1;

    return 0;

}