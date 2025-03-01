#include "infrastructure/LedActuator.h"

LedActuator::LedActuator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void LedActuator::setState(bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
}

void LedActuator::update() {
    // Обновление состояния актуатора (если требуется)
}
