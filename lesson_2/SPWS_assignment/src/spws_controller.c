#include "../include/spws_controller.h"
#include "../include/hal_sensors.h"
#include "../include/hal_actuators.h"

extern SystemState_t systemState;
extern SystemSettings_t systemSetting;
extern SensorData_t sensorData;

void SPWS_runAutoMode(void)
{
    readSensorValues();
    if(sensorData.soilMoisturePercent < systemSetting.minMoistureThreshold)
    {
        turnPumpOn();   
        while(systemState.pumpState == PUMP_ON)
        {
            readSensorValues();
            if(sensorData.soilMoisturePercent > systemSetting.maxMoistureThreshold)
            {
                turnPumpOff();
            }
            else if(systemState.wateringTimeCounter == systemSetting.maxWateringDuration_s)
            {
                turnPumpOff();
            }
        }
    }
};

void SPWS_runManualMode(void)
{
    if(systemState.pumpState = PUMP_ON)
    {
        turnPumpOff();
    }

};

void updateLEDState(SystemState_t systemState)
{
    if(systemState.ledState == LED_NORMAL) 
    {
        if(systemState.pumpState == PUMP_ON)
        {
            systemState.currentMode = LED_WATERING;
        }
        else if((systemState.pumpState == PUMP_OFF) && (sensorData.soilMoisturePercent < systemSetting.minMoistureThreshold))
        {
            systemState.currentMode = LED_LOW_MOISTURE_ALERT;
        }
    } else if(systemState.currentMode == LED_LOW_MOISTURE_ALERT)
    {
        if(systemState.pumpState == PUMP_ON)
        {
            systemState.currentMode = LED_WATERING;
        }
    } else if(systemState.currentMode == LED_WATERING)
    {
        if((systemState.pumpState == PUMP_OFF) && (sensorData.soilMoisturePercent < systemSetting.minMoistureThreshold))
        {
            systemState.currentMode == LED_LOW_MOISTURE_ALERT;
        } else if((systemState.pumpState == PUMP_OFF) && (sensorData.soilMoisturePercent > systemSetting.minMoistureThreshold))
        {
            systemState.currentMode == LED_NORMAL;
        }
    }
    displayLED(systemState.ledState);
}