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
    int mappedLevel = this->mapLevel(this->frontRegulator.getNeedleLevel());

    return mappedLevel;
}

int WsDataTransformer::getMiddleLedMatrixLevel()
{
    int mappedLevel = this->mapLevel(this->middleRegulator.getNeedleLevel());

    return mappedLevel;
}

int WsDataTransformer::getBackLedMatrixLevel()
{
    int mappedLevel = this->mapLevel( this->backRegulator.getNeedleLevel());

    return mappedLevel;
}

int WsDataTransformer::getAllLedMatrixLevel()
{
    if (this->frontRegulator.getNeedleLevel() == this->middleRegulator.getNeedleLevel() && this->middleRegulator.getNeedleLevel() == this->backRegulator.getNeedleLevel()) {
        int mappedLevel = this->mapLevel(this->frontRegulator.getNeedleLevel());

        return mappedLevel;
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

    return JSON.stringify(sliderValues);
}

int WsDataTransformer::mapLevel(int level) {
    return map(level, Regulator::MIN_LEVEL, Regulator::MAX_LEVEL, 0, 100);
}
