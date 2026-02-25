#include <stdio.h>
#include <math.h>

#define PI                 (3.14)
#define SAMPLE_RATE_Hz     (44100)
#define BIT_DEPTH          (16)
#define MAX_VALUE_ENCODING ((int)(pow(2, (BIT_DEPTH-1)) - 1))

int main() {

    int frequency_Hz = 0;
    int duration_sec = 0;
    //int amplitude    = 0;

    printf("Enter frequency in Hz: ");
    if ( (scanf("%d", &frequency_Hz) != 1) || (frequency_Hz < 0) ) {
        fprintf(stderr, "Invalid input!\n");
        return 1;
    }
    
    printf("Enter time duration in sec: ");
    if ( (scanf("%d", &duration_sec) != 1) || (duration_sec < 0) ) {
        fprintf(stderr, "Invalid input!\n");
        return 1;
    }

    /*
    printf("Enter amplitude: ");
    if( scanf("%d", &amplitude) != 1 ) {
        fprintf(stderr, "Invalid input!\n");
        return 1;
    }
    */
    printf("\n");

    int total_samples = duration_sec*SAMPLE_RATE_Hz;
    short int samples[total_samples];

    float time = 0;
    float angle = 0;
    short int sample = 0;

    // Mathematically speaking the formula is sin(2 * PI * frequency_Hz * (sample/SAMPLE_RATE_Hz))
    for(int i = 0; i < total_samples; i = i+1) {
        // Be carefull: in principal / refers to integer division and the result throws away the decimal part
        time = i * ((float)1 / SAMPLE_RATE_Hz); 
        //printf("time = %.10lf ", time);
        angle = 2 * PI * frequency_Hz * time;
        //printf("i = %d, angle = %.10lf ", i, angle);
        sample = MAX_VALUE_ENCODING * sin(angle);
        //printf("%d ", sample);
        samples[i] = sample;
        //printf("%d ", samples[i]);
    }

    char output_str[30];
    sprintf(output_str, "output_%dHz_%dsec.raw", frequency_Hz, duration_sec);
    //printf("%s\n", output_str);

    FILE *fp;
    fp = fopen(output_str, "wb");
    if(fp == NULL) {
        printf("Error in opening file!\n");
        return 1;
    }

    int j = 0;
    while(j < total_samples) {
        // flag should have the num of object written, once per iteration
        int flag = fwrite(&samples[j], sizeof(short int), 1, fp);
        if(!flag) {
            printf("Write operation failed in the %dth object\n", j);
        }
        j++;
    }
    fclose(fp);
    printf("\n");

    printf("frequency_Hz = %d\n", frequency_Hz);
    printf("duration_sec = %d\n", duration_sec);
    printf("MAX_VALUE_ENCODING = %d\n", MAX_VALUE_ENCODING);
    printf("SAMPLE_RATE_Hz = %d\n", SAMPLE_RATE_Hz);

    printf("sizeof(short int) = %d\n", sizeof(short int));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));

    return 0;
}