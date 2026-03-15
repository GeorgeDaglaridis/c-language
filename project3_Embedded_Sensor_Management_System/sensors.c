#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    struct {
        short int min_range;
        short int max_range;
        float reading;        
    } __attribute__((packed)) temperature; // Not sure __attribute__((packed)) is needed in this project
                                           // It was added for educationla puproses

    struct {
        float calibration;
        float reading;
    } __attribute__((packed)) humidity;

    struct {
        short int altitude;
        float reading;        
    } __attribute__((packed)) pressure;
    
} SensorData;

typedef struct sensor {
    uint8_t id;
    unsigned char name[20];
    SensorType sensorType;
    SensorData sensorData;
    SensorStatus sensorStatus;  
} __attribute__((packed)) Sensor;

// Function prototypes - Function declarations used only in this .c file (static)
// If used by othe .c files as well remove static keyword and put them in a .h file
static void init_sensors(Sensor *sensors, int *cnt_sensors);
static void display_sensors(const Sensor *sensors, const int cnt, const SensorStatus status, const uint8_t detail_list);
static void deactivate_all_sensors(Sensor *sensors, const int cnt);
static void activate_all_sensors(Sensor *sensors, const int cnt);
static void deactivate_sensors_by_type(Sensor *sensors, const int cnt, const SensorType sensor_type);
static void activate_sensors_by_type(Sensor *sensors, const int cnt, const SensorType sensor_type);
static void deactivate_sensor_by_ID(Sensor *sensors, const int id);
static void activate_sensor_by_ID(Sensor *sensors, const int id);

// Global arrays
static const char sensor_status_str[SENSOR_STATUS_CNT][9] = {"Inactive", "Active", "Error"}; // lives in FLASH/ROM
// or
// static const char *sensor_status_str[SENSOR_STATUS_CNT] = {"Inactive", "Active", "Error"}; // The string literals live in FLASH/ROM, but the 3 pointers live in RAM
// or
// static const char const *sensor_status_str[SENSOR_STATUS_CNT] = {"Inactive", "Active", "Error"}; // The string literals and the 3 pointers all live in FLASH/ROM

static const char sensor_type_str[ALL_SENSOR_TYPES][12] = {"Temperature", "Humidity", "Pressure"}; // lives in FLASH/ROM
// or
// static const char *sensor_type_str[ALL_SENSOR_TYPES] = {"Temperature", "Humidity", "Pressure"}; // The string literals live in FLASH/ROM, but the 3 pointers live in RAM
// or
// static const char const *sensor_type_str[ALL_SENSOR_TYPES] = {"Temperature", "Humidity", "Pressure"}; // The string literals and the 3 pointers all live in FLASH/ROM


int main() {

    /*
    SensorData sensorData;

    printf("sizeof(SensorType): %d\n", sizeof(SensorType));
    printf("sizeof(SensorStatus): %d\n", sizeof(SensorStatus));
    printf("sizeof(sensorData.temperature): %d\n", sizeof(sensorData.temperature));
    printf("sizeof(sensorData.humidity): %d\n", sizeof(sensorData.humidity));
    printf("sizeof(sensorData.pressure): %d\n", sizeof(sensorData.pressure));
    printf("sizeof(sensorData.temperature): %d\n", sizeof(sensorData.temperature));
    printf("sizeof(SensorData): %d\n", sizeof(SensorData));
    printf("sizeof(Sensor): %d\n", sizeof(Sensor));
    */
   
    Sensor sensors[SENSORS_MAX_CAPACITY] = {0};
    int cnt_sensors = 0;
    
    init_sensors(sensors, &cnt_sensors);

    display_sensors(sensors, cnt_sensors, ACTIVE, 0); // 0: display all infos, 1: display short infos
    //display_sensors(sensors, cnt_sensors, INACTIVE, 0);
    //deactivate_sensor_by_ID(sensors, 2);       // deactivates sensor ID 2 (index: ID # -1)
    //display_sensors(sensors, &cnt_sensors, ACTIVE, 0);
    //activate_sensor_by_ID(sensors, 2);
    //display_sensors(sensors, &cnt_sensors, ACTIVE, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, TEMPERATURE);
    display_sensors(sensors, cnt_sensors, ACTIVE, 0);
    //display_sensors(sensors, cnt_sensors, INACTIVE, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, HUMIDITY);
    display_sensors(sensors, cnt_sensors, ACTIVE, 0);
    //display_sensors(sensors, cnt_sensors, INACTIVE, 0);
    deactivate_sensors_by_type(sensors, cnt_sensors, PRESSURE);
    display_sensors(sensors, cnt_sensors, ACTIVE, 0);
    //display_sensors(sensors, cnt_sensors, INACTIVE, 0);
    activate_sensors_by_type(sensors, cnt_sensors, ALL_SENSOR_TYPES);
    display_sensors(sensors, cnt_sensors, ACTIVE, 0);
    //display_sensors(sensors, cnt_sensors, INACTIVE, 0);

    //deactivate_sensors(sensors, cnt_sensors);
    //activate_sensors(sensors, cnt_sensors);

    return 0;
}

void init_sensors(Sensor *sensors, int *cnt_sensors) {

    printf("How many sensors you want to initialize (max 10)? : ");
    if( (scanf("%d", cnt_sensors) != 1) || (*cnt_sensors < 1) ) {
        printf("ERROR: Invalid input\n");
        exit(1);
    }

    // Check the number of sensors provided is within the limit (SENSORS_MAX_CAPACITY).
    if(*cnt_sensors > SENSORS_MAX_CAPACITY) {
        printf("ERROR: more sensors provided than the available\n");
        exit(1);
    }

    int i = 0;
    while(i < *cnt_sensors) {
        printf("\nProvide the type of sensor, (TEMPERATURE:0, HUMIDITY:1, PRESSURE:2): ");
        if(scanf("%d", &sensors[i].sensorType) != 1) {
            printf("ERROR: Invalid negative input\n");
            exit(1);
        }
        printf("\n");

        sensors[i].sensorStatus = INACTIVE; // Make sure sensor is inactive before you start initializing it!

        switch (sensors[i].sensorType) {
            case TEMPERATURE:
                printf("Provide ID, name, min and max values, of Temperature sensor: ");
                if(scanf("%hhu %s %hd %hd", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.temperature.min_range, &sensors[i].sensorData.temperature.max_range) == 0) {
                    printf("ERROR: Invalid input\n");
                    exit(1);
                }
                printf("Initialize a Temperature sensor: ID %hhu, \"%s\", range %hd to %hd celsius.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.temperature.min_range, sensors[i].sensorData.temperature.max_range);
                sensors[i].sensorStatus = ACTIVE;
                break;

            case HUMIDITY:
                printf("Provide ID, name, and calibration factor of Humidity sensor: ");
                if(scanf("%hhu %s %f", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.humidity.calibration) == 0) {
                    printf("ERROR: Invalid input\n");
                    exit(1);
                }
                printf("Initialize a Humidity sensor: ID %hhu, \"%s\", callibration factor %.2f.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.humidity.calibration);
                sensors[i].sensorStatus = ACTIVE;
                break;

            case PRESSURE:
                printf("Provide ID, name, and altitude compensation of Pressure sensor: ");
                if(scanf("%hhu %s %hd", &sensors[i].id, &sensors[i].name, &sensors[i].sensorData.pressure.altitude) == 0) {
                    printf("ERROR: Invalid input\n");
                    exit(1);
                }
                printf("Initialize a Pressure sensor: ID %hhu, \"%s\", altitude compensation %hd m.\n", sensors[i].id, sensors[i].name, sensors[i].sensorData.pressure.altitude);
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
void display_sensors(const Sensor *sensors, int cnt, const SensorStatus status, const uint8_t detail_list) {

    printf("\n----------- Display %s sensors -----------\n\n", sensor_status_str[status]);

    for(int i= 0; i < cnt; i++) {
        if(sensors[i].sensorStatus == status) {

            printf("\n%s sensor ID %hhu.\n", sensor_type_str[sensors[i].sensorType], sensors[i].id);
            printf("Name: %s.\n", sensors[i].name);
            printf("Current status: %s\n", sensor_status_str[sensors[i].sensorStatus]);

            switch (sensors[i].sensorType) {
                case TEMPERATURE:
                    if(detail_list != 1) {
                        printf("Range %hd to %hd celsious.\n", sensors[i].sensorData.temperature.min_range, sensors[i].sensorData.temperature.max_range);
                        printf("Current reading %.2f celsious.\n", sensors[i].sensorData.temperature.reading);
                    }
                    break;

                case HUMIDITY:
                    if(detail_list != 1) {
                        printf("Callibration factor %.2f.\n", sensors[i].sensorData.humidity.calibration);
                        printf("Current reading %.2f.\n", sensors[i].sensorData.humidity.reading);
                    }
                    break;

                case PRESSURE:
                    if(detail_list != 1) {
                        printf("Altitude compensation %hd.\n", sensors[i].sensorData.pressure.altitude);
                        printf("Current reading %.2f.\n", sensors[i].sensorData.pressure.reading);
                    }
                    break;                
                default:
                    break;
            }
        }
    }
}

void deactivate_all_sensors(Sensor *sensors, const int cnt) {
    for(int i= 0; i < cnt; i++) {
        if(sensors[i].sensorStatus == ACTIVE) {
            sensors[i].sensorStatus = INACTIVE;
        }
    }
    printf("\nAll sensors are deactivated!\n");
}
void activate_all_sensors(Sensor *sensors, const int cnt) {
    for(int i= 0; i < cnt; i++) {
        if(sensors[i].sensorStatus == INACTIVE) {
            sensors[i].sensorStatus = ACTIVE;
        }
    }
    printf("\nAll sensors are activated!\n");
}

// sensor_type: TEMPERATURE:0, HUMIDITY:1, PRESSURE:2, ALL:3
void deactivate_sensors_by_type(Sensor *sensors, const int cnt, const SensorType sensor_type) {

    // Pointer to a const char. string literal "ALL_SENSOR_TYPES" does not change
    // but pointer type_str can change
    const char *type_str = "ALL_SENSOR_TYPES";

    for(int i= 0; i < cnt; i++) {
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
void activate_sensors_by_type(Sensor *sensors, const int cnt, const SensorType sensor_type) {

    // Pointer to a const char. string literal "ALL_SENSOR_TYPES" does not change
    // but pointer type_str can change
    const char *type_str = "ALL_SENSOR_TYPES";

    for(int i= 0; i < cnt; i++) {
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
void deactivate_sensor_by_ID(Sensor *sensors, const int id) {
    int index = id - 1;
    sensors[index].sensorStatus = INACTIVE;
}
void activate_sensor_by_ID(Sensor *sensors, const int id) {
    int index = id - 1;
    sensors[index].sensorStatus = ACTIVE;
}

