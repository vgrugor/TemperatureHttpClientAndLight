#include "domain/Regulator.h"
#include <Arduino.h>

Regulator::Regulator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void Regulator::update() {
    if (this->currentLevel == this->needleLevel) {
        return;
    }

    unsigned long currentTime = millis();

    if ((unsigned long)(currentTime - this->lastUpdateTime) >= this->updatePeriod) {
        if (this->currentLevel > this->needleLevel) {
            this->currentLevel--;
        }

        if (this->currentLevel < this->needleLevel) {
            this->currentLevel++;
        }

        this->lastUpdateTime = currentTime;

        analogWrite(pin, this->currentLevel);
    }
}

int Regulator::getNeedleLevel() {
    return this->needleLevel;
}

void Regulator::setLevel(uint16_t level) {
    if (level > Regulator::MAX_LEVEL) {
        level = Regulator::MAX_LEVEL;
    }

    uint16_t diff = abs((uint16_t)level - (uint16_t)this->currentLevel);

    if (diff == 0) {
        this->updatePeriod = 0;
    } else {
        this->updatePeriod = max(1, Regulator::DELAY_SET_LEVEL / diff);
    }

    this->needleLevel = level;
}
