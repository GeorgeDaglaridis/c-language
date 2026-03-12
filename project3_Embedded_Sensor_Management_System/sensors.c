#include <stdio.h>
#include <stdlib.h>

#define SENSORS_MAX_CAPACITY 10

typedef enum {
    TEMPERATURE,
    HUMIDITY,
    PRESSURE,
    ALL_SENSOR_TYPES
} SensorType;

typedef enum {
    INACTIVE,
    ACTIVE,
    ERROR,
    SENSOR_STATUS_CNT
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

// Function prototypes - Function declarations used only in this .c file (static)
// If used by othe .c files as well remove static keyword and put them in a .h file
static void init_sensors(Sensor *sensors, int *cnt_sensors);
static void display_sensors(const Sensor *sensors, int cnt, unsigned char short_list);
static void deactivate_all_sensors(Sensor *sensors, int cnt);
static void activate_all_sensors(Sensor *sensors, int cnt);
static void deactivate_sensors_by_type(Sensor *sensors, int cnt, SensorType sensor_type);
static void activate_sensors_by_type(Sensor *sensors, int cnt, SensorType sensor_type);
static void deactivate_sensor_by_ID(Sensor *sensors, int id);
static void activate_sensor_by_ID(Sensor *sensors, int id);

// Global arrays
static const char sensor_status_str[SENSOR_STATUS_CNT][9] = {"INACTIVE", "ACTIVE", "ERROR"}; // lives in FLASH/ROM
// or
// static const char *sensor_status_str[SENSOR_STATUS_CNT] = {"INACTIVE", "ACTIVE", "ERROR"}; // The string literals live in FLASH/ROM, but the 3 pointers live in RAM
// or
// static const char const *sensor_status_str[SENSOR_STATUS_CNT] = {"INACTIVE", "ACTIVE", "ERROR"}; // The string literals and the 3 pointers all live in FLASH/ROM

static const char sensor_type_str[ALL_SENSOR_TYPES][12] = {"TEMPERATURE", "HUMIDITY", "PRESSURE"}; // lives in FLASH/ROM
// or
// static const char *sensor_type_str[ALL_SENSOR_TYPES] = {"TEMPERATURE", "HUMIDITY", "PRESSURE"}; // The string literals live in FLASH/ROM, but the 3 pointers live in RAM
// or
// static const char const *sensor_type_str[ALL_SENSOR_TYPES] = {"TEMPERATURE", "HUMIDITY", "PRESSURE"}; // The string literals and the 3 pointers all live in FLASH/ROM


void main() {

    Sensor sensors[SENSORS_MAX_CAPACITY] = {0};
    int cnt_sensors = 0;
    unsigned char short_list = 0;

    init_sensors(sensors, &cnt_sensors);

    //deactivate_sensors(sensors, cnt_sensors);
    //activate_sensors(sensors, cnt_sensors);

    display_sensors(sensors, cnt_sensors, 0); // 0: display all infos, 1: display short infos
    //deactivate_sensor_by_ID(sensors, 2);       // deactivates sensor ID 2 (index: ID # -1)
    //display_sensors(sensors, &cnt_sensors, 0);
    //activate_sensor_by_ID(sensors, 2);
    //display_sensors(sensors, &cnt_sensors, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, TEMPERATURE);
    display_sensors(sensors, cnt_sensors, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, HUMIDITY);
    display_sensors(sensors, cnt_sensors, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, PRESSURE);
    display_sensors(sensors, cnt_sensors, 0);
    activate_sensors_by_type(sensors, cnt_sensors, ALL_SENSOR_TYPES);
    display_sensors(sensors, cnt_sensors, 0);



    
    // SensorData sensorData = { .pressure.altitude = 100, .pressure.reading = 50

    // printf("&sensorData = %p\n", &sensorData);
    // printf("&sensorData.temperature.min_range = %p\n", &sensorData.temperature.min_range);
    // printf("&sensorData.temperature.max_range = %p\n", &sensorData.temperature.max_range);
    // printf("&sensorData.temperature.reading = %p\n", &sensorData.temperature.reading);
    // printf("&sensorData.humidity.calibration = %p\n", &sensorData.humidity.calibration);
    // printf("&sensorData.humidity.reading = %p\n", &sensorData.humidity.reading);
    // printf("&sensorData.pressure.altitude = %p\n", &sensorData.pressure.altitude);
    // printf("&sensorData.pressure.reading = %p\n\n", &sensorData.pressure.reading);

    // printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    // printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    // printf("sensorData.temperature.reading = %d\n", sensorData.temperature.reading);
    // printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    // printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);
    // printf("sensorData.pressure.altitude = %d\n", sensorData.pressure.altitude);
    // printf("sensorData.pressure.reading = %d\n", sensorData.pressure.reading);

    
    // sensorData.temperature.min_range = -10;
    // sensorData.temperature.max_range = 10;
    // sensorData.humidity.calibration = 20;
    // printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    // printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    // printf("sensorData.temperature.reading = %d\n", sensorData.temperature.reading);
    // printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    // printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);
    // //sensorData.humidity.calibration = 20;
    // printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    // printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    // printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    
    
    
    // sensorData.humidity.calibration = 20;
    // printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    // printf("sensorData.humidity.reading = %d\n", sensorData.humidity.reading);
    // printf("sensorData.temperature.max_range = %d\n", sensorData.temperature.max_range);
    // printf("sensorData.temperature.min_range = %d\n", sensorData.temperature.min_range);
    // sensorData.humidity.calibration = 10;
    // printf("sensorData.humidity.calibration = %d\n", sensorData.humidity.calibration);
    //

    
    // printf("sizeof(sensorData) = %d\n", sizeof(sensorData));
    // printf("sizeof(sensorData.temperature) = %d\n", sizeof(sensorData.temperature));
    // printf("sizeof(sensorData.humidity) = %d\n", sizeof(sensorData.humidity));
    // printf("sizeof(sensorData.pressure) = %d\n", sizeof(sensorData.pressure));

    
}

void init_sensors(Sensor *sensors, int *cnt_sensors) {

    printf("How many sensors you want to initialize (max 10)? : ");
    scanf("%d", cnt_sensors);

    // Check the number of sensors provided is within the limit (SENSORS_MAX_CAPACITY).
    if(*cnt_sensors > SENSORS_MAX_CAPACITY) {
        printf("Error: more sensors provided than the available\n");
        exit(1);
    }

    int i = 0;
    while(i < *cnt_sensors) {
        printf("\nProvide the type of sensor, (TEMPERATURE:0, HUMIDITY:1, PRESSURE:2): ");
        scanf("%d", &sensors[i].sensorType);
        printf("\n");

        switch (sensors[i].sensorType) {
            case TEMPERATURE:
                printf("Provide ID, name, min and max values, of Temperature sensor: ");
                scanf("%d %s %d %d", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.temperature.min_range, &sensors[i].sensorData.temperature.max_range);
                printf("Initialize a Temperature sensor: ID %d, \"%s\", range %d to %d celsius.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.temperature.min_range, sensors[i].sensorData.temperature.max_range);
                sensors[i].sensorStatus = ACTIVE;
                break;

            case HUMIDITY:
                printf("Provide ID, name, and calibration factor of Humidity sensor: ");
                scanf("%d %s %f", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.humidity.calibration);
                printf("Initialize a Humidity sensor: ID %d, \"%s\", callibration factor %.2f.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.humidity.calibration);
                sensors[i].sensorStatus = ACTIVE;
                break;

            case PRESSURE:
                printf("Provide ID, name, and altitude compensation of Pressure sensor: ");
                scanf("%d %s %d", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.pressure.altitude);
                printf("Initialize a Pressure sensor: ID %d, \"%s\", altitude compensation %d m.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.pressure.altitude);
                sensors[i].sensorStatus = ACTIVE;
                break;
            default:
                printf("No sensor exists for the provided type: %d. Type again!\n", sensors[i].sensorType);
                i--;
                break;
        }
        i++;

        printf("\n");
    }
    printf("Sensors initialized: %d.\n", *cnt_sensors);
}

// 0: display all infos, 1: display short infos
void display_sensors(const Sensor *sensors, int cnt, unsigned char short_list) {
    int i = 0;
    for(int i=0; i<cnt; i++) {
        if(sensors[i].sensorStatus == ACTIVE) {

            switch (sensors[i].sensorType) {
                case TEMPERATURE:
                    printf("\nTemperature sensor ID %d.\n", sensors[i].id);
                    printf("Name: %s.\n", sensors[i].name);
                    if(short_list != 1) {
                        printf("Current status: %s\n", sensor_status_str[sensors[i].sensorStatus]);
                        printf("Range %d to %d celsious.\n", sensors[i].sensorData.temperature.min_range, sensors[i].sensorData.temperature.max_range);
                        printf("Current reading %d celsious.\n", sensors[i].sensorData.temperature.reading);
                    }
                    break;

                case HUMIDITY:
                    printf("\nHumidity sensor ID %d.\n", sensors[i].id);
                    printf("Name: %s.\n", sensors[i].name);
                    if(short_list != 1) {
                        printf("Current status: %s\n", sensor_status_str[sensors[i].sensorStatus]);
                        printf("Callibration factor %.2f.\n", sensors[i].sensorData.humidity.calibration);
                        printf("Current reading %d.\n", sensors[i].sensorData.humidity.reading);
                    }
                    break;

                case PRESSURE:
                    printf("\nPressure sensor ID %d.\n", sensors[i].id);
                    printf("Name: %s\n", sensors[i].name);
                    if(short_list != 1) {
                        printf("Current status: %s\n", sensor_status_str[sensors[i].sensorStatus]);
                        printf("Altitude compensation %d.\n", sensors[i].sensorData.pressure.altitude);
                        printf("Current reading %d.\n", sensors[i].sensorData.pressure.altitude);
                    }
                    break;                
                default:
                    break;
            }
        }
    }
}

void deactivate_all_sensors(Sensor *sensors, int cnt) {
    for(int i=0; i<cnt; i++) {
        if(sensors[i].sensorStatus == ACTIVE) {
            sensors[i].sensorStatus = INACTIVE;
        }
    }
    printf("\nAll sensors are deactivated!\n");
}
void activate_all_sensors(Sensor *sensors, int cnt) {
    for(int i=0; i<cnt; i++) {
        if(sensors[i].sensorStatus == INACTIVE) {
            sensors[i].sensorStatus = ACTIVE;
        }
    }
    printf("\nAll sensors are activated!\n");
}

// sensor_type: TEMPERATURE:0, HUMIDITY:1, PRESSURE:2, ALL:3
void deactivate_sensors_by_type(Sensor *sensors, int cnt, SensorType sensor_type) {

    // Pointer to a const char. string literal "ALL_SENSOR_TYPES" does not change
    // but pointer type_str can change
    const char *type_str = "ALL_SENSOR_TYPES";

    for(int i=0; i<cnt; i++) {
        // Deactivate all sensors
        if(sensor_type == ALL_SENSOR_TYPES) {
            if(sensors[i].sensorStatus == ACTIVE) {
                sensors[i].sensorStatus = INACTIVE;
            }
        }
        // Deactivate sensors by Type
        else if(sensors[i].sensorType == sensor_type) {
            if(sensors[i].sensorStatus == ACTIVE) {
                sensors[i].sensorStatus = INACTIVE;
                type_str = sensor_type_str[sensor_type];
            }
        }
    }
    printf("\n%s sensors are deactivated!\n", type_str);
}

// sensor_type: TEMPERATURE:0, HUMIDITY:1, PRESSURE:2, ALL:3
void activate_sensors_by_type(Sensor *sensors, int cnt, SensorType sensor_type) {

    // Pointer to a const char. string literal "ALL_SENSOR_TYPES" does not change
    // but pointer type_str can change
    const char *type_str = "ALL_SENSOR_TYPES";

    for(int i=0; i<cnt; i++) {
        // Deactivate all sensors
        if(sensor_type == ALL_SENSOR_TYPES) {
            if(sensors[i].sensorStatus == INACTIVE) {
                sensors[i].sensorStatus = ACTIVE;
            }
        }
        // Deactivate sensors by Type
        else if(sensors[i].sensorType == sensor_type) {
            if(sensors[i].sensorStatus == INACTIVE) {
                sensors[i].sensorStatus = ACTIVE;
                type_str = sensor_type_str[sensor_type];
            }
        }
    }
    printf("\n%s sensors are activated!\n", type_str);
}

/*
 * Sensor sensors[SENSORS_MAX_CAPACITY]
 * sensors is an array of structs where each struct
 * holds the infos for one type of sensors without
 * knowing in advance which type is initialized first.
 * We know though that we provide IDs to each sensor in an
 * order (1 - 10), following the way they are stored in the
 * array.
 * i.e.:
 * [0] -> ID 1  Temp1
 * [1] -> ID 2  Hum1
 * [2] -> ID 3  Pres1
 * [3] -> ID 4  Hum2
 * [4] -> ID 5  Hum3
 * [5] -> ID 6  Pres2
 * [6] -> ID 7  Temp2
 * [7] -> ID 8  Temp3
 * [8] -> ID 9  Pres3
 * [9] -> ID 10 Pres4
*/
void deactivate_sensor_by_ID(Sensor *sensors, int id) {
    int index = id - 1;
    sensors[index].sensorStatus = INACTIVE;
}
void activate_sensor_by_ID(Sensor *sensors, int id) {
    int index = id - 1;
    sensors[index].sensorStatus = ACTIVE;
}

