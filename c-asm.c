int piyush(){

    //const int xyz = 10;
    //xyz = 20;

    volatile int i = 10;
    i = i + 1;
    i = i + 10;

    return i;
}