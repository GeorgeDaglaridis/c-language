#include <stdio.h>

union xyz {
    int a;
    unsigned int b;
    char c;
    float d;
};

int main() {

    union xyz u;
    printf("sizeof(u): %d\n", sizeof(u)); // 4, union has the size of its biggest member
    printf("address of u.a: %p\n", &(u.a));
    printf("address of u.b: %p\n", &(u.b));
    printf("address of u.c: %p\n", &(u.c));
    printf("address of u.d: %p\n", &(u.d));

    u.a = -1;
    printf("A. %d\n", u.a);

    /**
     * member a of union u has value -1 assigned to it but
     * since all members of the union occupy the same memory space,
     * the one of its largest member, when member/element b is printed
     * it prints the representation of -1 as an unsinged number.

     * 0xffffffff as a signed 32-bit (4-byte) number represents -1 ( -2^(32-1) + ((2^(32-1)) - 1) ), whereas
     * 0xffffffff as a unsigned 32-bit (4-byte) number represents ((2^32) - 1)e = 4294967295

     * here both members a and b have the same size
     */
    printf("B. %u\n", u.b);

    u.b = 101;
    printf("C. %d\n", u.a);
    
    u.a = 0xa;
    /** 
     * Although element a is a 4 byte integer the value 10 (0xa) assigned to it 
     * could also be represented by a 1 byte number. Thus when element c, which 
     * is of type char (1 byte), is printed we see the same number that was assigned 
     * to a before.
     */ 
    printf("D. %d\n", u.c);

    u.a = 0xFF0000AA;
    /** 
     * We know that the way data are stored into memory follow little endian, which means
     * that the LSbyte is stored at the lowest place in memory.
     * Given that, when 1-byte signed element c is about to be printed it will print the 
     * first byte it finds at the lowest memory location which is 0xAA. Since element c is 
     * a singed value number -86 is printed.   
    */
    printf("E. %d\n", u.c); // 0xAA represented as
    printf("F. %d\n", (unsigned char)u.c); // 0xAA represents 170 when 1-byte singed c is casted as 1-byte unsinged
    
    // u.a now holds value 0xFF000041 but u.c holds only the 1st byte which corresponds
    // to the LSbyte of elemetn u.a which is 0x41
    u.a = 0xFF000041;
    printf("G. %c\n", u.c); // 0x41 is printed as a 1-byte char represented by letter A

    // u.a now holds value 0xFF000042 whereas u.c holds only the 1st byte which corresponds
    // to the LSbyte of elemetn u.a which is 0x42
    u.a = u.a + 1;
    printf("H. %c\n", u.c); // 0x42 is printed as a 1-byte char represented by letter B

    // u.c = 0x00000042 + 0x00ff0001 = 0x00ff0043, but u.c only holds the LS byte which is 0x43
    u.c = u.c + 0x00ff0001; 
    printf("I. 0x%x\n", u.a);
    printf("J. 0x%x\n", u.c); // 0x43 is only printed since we have a 1-byte signed char
    printf("K. %c\n", u.c);   // 0x43 is printed as a 1-byte char represented by letter C

    u.a = 0xFF000041;
    printf("L. 0x%x\n", u.a); // 0xFF000041
    u.b = u.b + 0x00ff0000;
    printf("M. 0x%x\n", u.a); // 0xFFFF0041
    printf("N. 0x%x\n", u.b); // 0xFFFF0041
    printf("O. %c\n", u.c);   // 0x41 is printed as a 1-byte char represented by letter A

    return 0;
}