#include <stdio.h>

int main() {

    // charptr is a pointer pointing to the address of the first element 
    // of the 3-element array of chars
    char *charptr = "Hi";

    printf("charptr points to the address %p of the first element of the array\n", charptr);
    printf("another way of exressing the pointer which points to the address %p of the first element of the array\n", charptr+0);
    printf("&charptr[0] is the address %p of the first element of the array\n", &charptr[0]);
    printf("charptr[0] points to the first element of the array of chars which is %c\n", charptr[0]);
    printf("(charptr+0)[0]: another way of showing the first element of the array of chars which is %c\n\n", (charptr+0)[0]);

    /************************************************************************************************************************************************/
    printf("charptr+1 points to the next address %p which basically holds one byte, essentially the second element of the array\n", charptr+1);
    printf("&charptr[1] is the address %p of the second element of the array\n", &charptr[1]);
    printf("charptr[1] points to the second element of the array of chars which is %c\n", charptr[1]);
    // charptr+0 holds the address of the first element of the 3-element array("Hi"), basically holds the array itself,
    // and by indexing it [1] you ask for the second element
    printf("(charptr+0)[1]: another way of showing the second element of the array of chars which is %c\n", (charptr+0)[1]);
    // charptr+1 holds the address of the second element of the 3-element array("Hi"), basically holds a "new" array("i") 
    // created by the initial one and by indexing it [0] you ask for the first element of that new array which is 'i'
    printf("(charptr+1)[0]: another way of showing the second element of the array of chars which is %c\n\n", (charptr+1)[0]);
    
    /*************************************************************************************************************************************************/
    printf("charptr+2 points to the next address %p which basically holds one byte, essentially the third element of the array\n", charptr+2);
    printf("&charptr[2] is the address %p of the third element of the array\n", &charptr[2]);
    printf("charptr[2] points to the third element of the array of chars which is %c\n", charptr[2]);
    // charptr+0 holds the address of the first element of the 3-element array("Hi"), basically holds the array itself,
    // and by indexing it [2] you ask for the third and last element, null character cannot be actually printed
    printf("(charptr+0)[2]: another way of showing the third element of the array of chars which is %c\n", (charptr+0)[2]);
    // charptr+2 holds the address of the third element of the 3-element array("Hi"), basically holds a "new" array("\0") 
    // created by the initial one and by indexing it [0] you ask for the first element of that new array which is '\0', null character cannot be actually printed
    printf("(charptr+2)[0]: another way of showing the third element of the array of chars which is %c\n\n", (charptr+2)[0]);
    printf("/*************************************************************************************************************************************************/\n\n");


    char greetings[3] = "Hi";
    // charptr2 points to the address of the first element of the array of chars named greetings
    char *charptr2 = greetings;
    
    printf("charptr2 points to the address %p of the first element of the array\n", charptr2);
    printf("another way of exressing the pointer which points to the address %p of the first element of the array\n", charptr2+0);
    printf("&charptr2[0] is the address %p of the first element of the array\n", &charptr2[0]);
    printf("charptr2[0] points to the first element of the array of chars which is %c\n", charptr2[0]);
    printf("(charptr2+0)[0]: another way of showing the first element of the array of chars which is %c\n\n", (charptr2+0)[0]);

    /************************************************************************************************************************************************/
    printf("charptr2+1 points to the next address %p which basically holds one byte, essentially the second element of the array\n", charptr2+1);
    printf("&charptr2[1] is the address %p of the second element of the array\n", &charptr2[1]);
    printf("charptr2[1] points to the second element of the array of chars which is %c\n", charptr2[1]);
    // charptr2+0 holds the address of the first element of the 3-element array greetings ("Hi"), basically holds the array itself,
    // and by indexing it [1] you ask for the second element
    printf("(charptr2+0)[1]: another way of showing the second element of the array of chars which is %c\n", (charptr2+0)[1]);
    // charptr2+1 holds the address of the second element of the 3-element array greetigs ("Hi"), basically holds a "new" array("i") 
    // created by the initial one and by indexing it [0] you ask for the first element of that new array which is 'i'
    printf("(charptr2+1)[0]: another way of showing the second element of the array of chars which is %c\n\n", (charptr2+1)[0]);

    /*************************************************************************************************************************************************/
    printf("charptr2+2 points to the next address %p which basically holds one byte, essentially the third element of the array\n", charptr2+2);
    printf("&charptr2[2] is the address %p of the third element of the array\n", &charptr2[2]);
    printf("charptr2[2] points to the third element of the array of chars which is %c\n", charptr2[2]);
    // charptr2+0 holds the address of the first element of the 3-element array("Hi"), basically holds the array itself,
    // and by indexing it [2] you ask for the third and last element, null character cannot be actually printed
    printf("(charptr2+0)[2]: another way of showing the third element of the array of chars which is %c\n", (charptr2+0)[2]);
    // charptr2+2 holds the address of the third element of the 3-element array("Hi"), basically holds a "new" array("\0") 
    // created by the initial one and by indexing it [0] you ask for the first element of that new array which is '\0', null character cannot be actually printed
    printf("(charptr2+2)[0]: another way of showing the third element of the array of chars which is %c\n\n", (charptr2+2)[0]);
    printf("/*************************************************************************************************************************************************/\n");
    printf("/*************************************************************************************************************************************************/\n\n");

    char *str = "Piyush";

    // str is a pointer to a char. Once defined and initialized, *str refers to the content 
    // of the pointer which is an address to a char, basically an address to a byte.
    // This is why sizeof(*str) -> 1 byte 
    printf("size of the address char pointer 'str' points to: %ld byte\n", sizeof(*str));
    printf("address where char pointer 'str' points to: %p\n", str);
    printf("address of the first element of char array: %p\n", &str[0]);
    printf("address of the first element of the array of chars named ''Piyush'': %p\n", &("Piyush"[0]));
    printf("alternative: address of the first element of the array of chars named ''Piyush'': %p\n", &("Piyush"));
    //  warning: format ‘%c’ expects argument of type ‘int’, but argument 2 has type ‘char *’
    printf("pointers points to an address which holds string: %s\n", str);
    printf("pointers points to an address which holds char: %c\n", *str);
    printf("/*************************************************************************************************************************************************/\n\n");

    // the size allocated for the pointer itself has to do with the architecture of the 
    // machine linux is running to. Here we have a x64 machine so sizeof(str) -> 8 bytes 
    printf("size of char pointer 'str' itself: %ld bytes\n", sizeof(str));
    printf("address allocated of the pointer 'str' itself: %p\n\n", &str);

    printf("alternative: pointers points to an address which holds char: %c\n", *(&str)[0]);



    


    return 0;
}