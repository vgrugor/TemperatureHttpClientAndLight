#include "application/WSDataTransformer.h"

WsDataTransformer::WsDataTransformer(
    FrontRegulator& frontRegulator, 
    MiddleRegulator& middleRegulator, 
    BackRegulator& backRegulator,
    DS18B20Sensor& temperatureSensor
) : frontRegulator(frontRegulator), 
    middleRegulator(middleRegulator), 
    backRegulator(backRegulator),
    temperatureSensor(temperatureSensor),
    settingsStorage(SettingsStorage::getInstance())
{}

int WsDataTransformer::getFrontLedMatrixLevel()
{
    return this->frontRegulator.getNeedleLevel();
}

int WsDataTransformer::getMiddleLedMatrixLevel()
{
    return this->middleRegulator.getNeedleLevel();
}

int WsDataTransformer::getBackLedMatrixLevel()
{
    return this->backRegulator.getNeedleLevel();
}

int WsDataTransformer::getAllLedMatrixLevel()
{
    if (this->frontRegulator.getNeedleLevel() == this->middleRegulator.getNeedleLevel() && this->middleRegulator.getNeedleLevel() == this->backRegulator.getNeedleLevel()) {
        return this->frontRegulator.getNeedleLevel();
    } else {
        return 0;
    }
}

int WsDataTransformer::getTimerMinute()
{
    return this->settingsStorage.getTimerMinute();
}

float WsDataTransformer::getTemperature()
{
    return this->temperatureSensor.getLastValue();
}

String WsDataTransformer::toJSON()
{
    JSONVar sliderValues;

    sliderValues["sliderValue1"] = String(this->getAllLedMatrixLevel());
    sliderValues["sliderValue2"] = String(this->getTimerMinute());
    sliderValues["sliderValue3"] = String(this->getFrontLedMatrixLevel());
    sliderValues["sliderValue4"] = String(this->getMiddleLedMatrixLevel());
    sliderValues["sliderValue5"] = String(this->getBackLedMatrixLevel());
    sliderValues["sliderValue6"] = String(this->getTemperature());
    sliderValues["sliderValue7"] = 0; //TODO: Delete this

    return JSON.stringify(sliderValues);
}
