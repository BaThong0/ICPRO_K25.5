#include "../include/hal_actuators.h"

extern SystemState_t systemState;

void turnPumpOn(void) {
    systemState.pumpState = PUMP_ON;
};
void turnPumpOff(void) {
    systemState.pumpState = PUMP_OFF;
};
void displayLED(LedState_t ledState) {
    switch(ledState)
    {
        case LED_NORMAL:
            printf("GREEN LED!!!\n");
            break;
        case LED_WATERING:
            printf("YELLOW LED!!!\n");
            break;
        case LED_LOW_MOISTURE_ALERT:
            printf("RED BLINK!!!\n");
            break;
        case LED_ERROR:
            printf("RED LED!!!\n");
            break;
        default:
            break;
    }
};