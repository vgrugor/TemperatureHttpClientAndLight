#include "infrastructure/regulators/FrontRegulator.h"

FrontRegulator::FrontRegulator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void FrontRegulator::setLevel(uint16_t level) {
    if (level > 1023) {
        level = 1023;
    }

    analogWrite(pin, level);
}

void FrontRegulator::update() {
    // Обновление состояния актуатора (если требуется)
}
