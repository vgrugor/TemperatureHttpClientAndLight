#include "infrastructure/regulators/MiddleRegulator.h"

MiddleRegulator::MiddleRegulator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void MiddleRegulator::setLevel(uint16_t level) {
    if (level > 1023) {
        level = 1023;
    }

    analogWrite(pin, level);
}

void MiddleRegulator::update() {
    // Обновление состояния актуатора (если требуется)
}
