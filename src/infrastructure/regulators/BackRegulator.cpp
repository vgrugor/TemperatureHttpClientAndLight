#include "infrastructure/regulators/BackRegulator.h"

BackRegulator::BackRegulator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void BackRegulator::setLevel(uint16_t level) {
    if (level > 1023) {
        level = 1023;
    }

    analogWrite(pin, level);
}

void BackRegulator::update() {
    // Обновление состояния актуатора (если требуется)
}
