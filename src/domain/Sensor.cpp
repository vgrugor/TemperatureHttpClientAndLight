#include "domain/Sensor.h"
#include <Arduino.h>

Sensor::Sensor(unsigned long updateInterval) : updateInterval(updateInterval) {
    this->lastUpdateTime = millis();
}

void Sensor::update() {
    if (this->value == __FLT_MIN__) {
        this->value = this->readValue();
    }

    unsigned long currentTime = millis();

    if ((unsigned long)(currentTime - this->lastUpdateTime) >= this->updateInterval) {
        this->value = this->readValue();
        this->lastUpdateTime = currentTime;
    }
}

float Sensor::getLastValue() const {
    return this->value;
}
