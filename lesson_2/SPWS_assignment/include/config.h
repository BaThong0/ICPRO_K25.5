#ifndef CONFIG_H
#define CONFIG_H_
#include<stdio.h>

// Operation mode of the system
typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} SystemMode_t;

// Status of the water pump
typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_t;

// Status of the LED
typedef enum {
    LED_NORMAL,             // Green: Normal, waiting
    LED_WATERING,           // Yellow: Planting
    LED_LOW_MOISTURE_ALERT, // Red blink: Low moisture, warning
    LED_ERROR               // Red continuously: Error
} LedState_t;

// Main storing data structure read from sensors
typedef struct {
    float soilMoisturePercent;
    float airTemperatureCelcius;
} SensorData_t;

// Main storing system's parameters
typedef struct {
    float minMoistureThreshold;             //minimal moisture threashold to start plant 
    float maxMoistureThreshold;             //maximal moisture to stop plant
    unsigned int maxWateringDuration_s;     //maximum planting time (s)
    unsigned int sensorReadInterval_s;      //frequency of reading sensor value (s)
    unsigned int manualWateringDuration_s;  //duration to manual plant (s)
} SystemSettings_t;

// Struct to control state of system
typedef struct {
    SystemMode_t currentMode;
    PumpState_t pumpState;
    LedState_t ledState;
    unsigned int wateringTimeCounter;       //count planting time
    unsigned int sensorCheckCounter;        //count frequency of planting
} SystemState_t;

SystemState_t systemState;
SystemSettings_t systemSetting;
SensorData_t sensorData;
#endif

