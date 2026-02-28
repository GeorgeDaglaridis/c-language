#include <stdio.h>

typedef enum {
    TEMPERATURE,
    HUMIDITY,
    PRESSURE
} SensorType;

typedef enum {
    ACTIVE,
    INACTIVE,
    ERROR
} SensorStatus;

typedef union SensorData {
    struct 
    {
        short int min_range;
        short int max_range;
        float reading;        
    } temperature;

    struct 
    {
        float calibration;
        float reading;
    } humidity;

    struct 
    {
        short int altitude;
        float reading;        
    } pressure;
    
} SensorData;

typedef struct sensor {
    unsigned char id;
    unsigned char name[20];
    SensorType sensorType;
    SensorData sensorData;
    SensorStatus sensorStatus;  
} Sensor;

void main() {
    SensorData sensorData = { .temperature.min_range = -5, .temperature.max_range = 10, .temperature.reading = 6,
                              .humidity.calibration = 12, .humidity.reading  = 8, 
                              .pressure.altitude = 100, .pressure.reading = 50
                            };

    printf("&sensorData = %p\n", &sensorData);
    printf("&sensorData.temperature.min_range = %p\n", &sensorData.temperature.min_range);
    printf("&sensorData.temperature.max_range = %p\n", &sensorData.temperature.max_range);
    printf("&sensorData.temperature.reading = %p\n", &sensorData.temperature.reading);
    printf("&sensorData.humidity.calibration = %p\n", &sensorData.humidity.calibration);
    printf("&sensorData.humidity.reading = %p\n", &sensorData.humidity.reading);
    printf("&sensorData.pressure.altitude = %p\n", &sensorData.pressure.altitude);
    printf("&sensorData.pressure.reading = %p\n\n", &sensorData.pressure.reading);

    printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    printf("sensorData.temperature.reading = %d\n", sensorData.temperature.reading);
    printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);

    /*
    sensorData.temperature.min_range = -10;
    sensorData.temperature.max_range = 10;
    sensorData.humidity.calibration = 20;
    printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    printf("sensorData.temperature.reading = %d\n", sensorData.temperature.reading);
    printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);
    //sensorData.humidity.calibration = 20;
    printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    X
    
    /*
    sensorData.humidity.calibration = 20;
    printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);
    printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    sensorData.humidity.calibration = 10;
    printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
*/
    printf("sizeof(sensorData) = %d\n", sizeof(sensorData));
    printf("sizeof(sensorData.temperature) = %d\n", sizeof(sensorData.temperature));
    printf("sizeof(sensorData.humidity) = %d\n", sizeof(sensorData.humidity));
    printf("sizeof(sensorData.pressure) = %d\n", sizeof(sensorData.pressure));
}