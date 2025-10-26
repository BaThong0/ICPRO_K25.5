#include "../include/hal_actuators.h"
#include "../include/hal_buttons.h"
#include "../include/hal_sensors.h"
#include "../include/spws_controller.h"

extern SystemState_t systemState;
extern SystemSettings_t systemSetting;

void System_Init()
{
    systemState = {
        .currentMode = MODE_AUTO,
        .pumpState = PUMP_OFF,
        .ledState = LED_NORMAL,
        .wateringTimeCounter = 0,
        .sensorCheckCounter = 0
    };

    systemSetting = {
        .minMoistureThreshold = 20,
        .maxMoistureThreshold = 100,
        .maxWateringDuration_s = 300,
        .sensorReadInteval_s = 10,
        .manualWateringDuration_s = 60,
    };
    updateLEDState(systemState);

}

int main(void)
{
    /* Initialize the system */
    System_Init();

    while(1)
    {
        /* Update LED for each loop */
        updateLEDState(systemState);

        /* Check if the button1 is pressed, toggle mode between AUTO and MANUAL */
        if(pressButton1) 
        {
            if(systemState.currentMode == MODE_AUTO)
            {
                systemState.currentMode = MODE_MANUAL;
                SPWS_runManualMode();

            } else if(systemState.currentMode == MODE_MANUAL)
            {
                systemState.currentMode = MODE_AUTO;
                SPWS_runAutoMode();
            }

        } else if(pressButton2) /* Check if the button2 is pressed */
        {
            if(systemState.currentMode == MODE_MANUAL) /* If current mode is manual, turn on pumps for manual watering duration */
            {
                systemState.pumpState = PUMP_ON;
                processTime(systemSetting.manualWateringDuration_s);
                systemState.pumpState = PUMP_OFF;
            } else 
            {
                /* Do nothing */
            }
        }

        if(systemState.currentMode == MODE_AUTO)
        {
            SPWS_runAutoMode();
        } else if(systemState.currentMode == MODE_MANUAL)
        {
            SPWS_runManualMode();
        }
    }

    return 0;
}

/*
- thread 1: user interaction, button press
- thread 2: environment parameters changes
- thread 3: main system 
*/