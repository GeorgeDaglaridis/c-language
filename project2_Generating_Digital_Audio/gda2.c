#include <stdio.h>
#include <math.h>

#define PI                 (3.14)
#define SAMPLE_RATE_Hz     (44100)
#define BIT_DEPTH          (16)
#define MAX_VALUE_ENCODING ((int)(pow(2, (BIT_DEPTH-1)) - 1))

// Function declarations/prototypes
void generate_sine(int frequency_Hz, int duration_sec, short int *samples);
int write_to_file(char *file_name, short int *samples, int nof_samples);

int main() {

    int frequency_Hz = 0;
    int duration_sec = 0;

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
    printf("\n");

    int total_samples = duration_sec*SAMPLE_RATE_Hz;
    short int audio_samples[total_samples];

    generate_sine(frequency_Hz, duration_sec, audio_samples);

    char output_str[30];
    sprintf(output_str, "output_%dHz_%dsec.raw", frequency_Hz, duration_sec);

    write_to_file(output_str, audio_samples, total_samples);

    return 0;
}

// Function definition
void generate_sine(int frequency_Hz, int duration_sec, short int *samples) {

    float time = 0;
    float angle = 0;
    short int sample = 0;

    int total_samples = duration_sec*SAMPLE_RATE_Hz;
    
    // Mathematically speaking the formula is sin(2 * PI * frequency_Hz * (sample/SAMPLE_RATE_Hz))
    for(int i = 0; i < total_samples; i = i+1) {
        // Be carefull: in principal / refers to integer division and the result throws away the decimal part
        time = i * ((float)1 / SAMPLE_RATE_Hz); 
        angle = 2 * PI * frequency_Hz * time;
        sample = MAX_VALUE_ENCODING * sin(angle);
        samples[i] = sample;
    }
}

// Function definition
int write_to_file(char *file_name, short int *samples, int nof_samples) {

    FILE *fp;
    fp = fopen(file_name, "wb");
    if(fp == NULL) {
        printf("Error in opening file!\n");
        return 1;
    }

    int j = 0;
    while(j < nof_samples) {
        // flag should have the num of object written, once per iteration
        int flag = fwrite(&samples[j], sizeof(short int), 1, fp);
        if(!flag) {
            printf("Write operation failed in the %dth object\n", j);
            return 1;
        }
        j++;
    }
    fclose(fp);

    return 0;
}