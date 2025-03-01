#include "presentation/BuzzerObserver.h"

BuzzerObserver::BuzzerObserver(BuzzerActuator buzzerActuator) : buzzerActuator(buzzerActuator) {}

void BuzzerObserver::update(EventType eventType) {
    if (eventType == EventType::WIFI_TRY_CONNECT) {
        this->buzzerActuator.setState(HIGH);
        delay(200);
        this->buzzerActuator.setState(LOW);
    } else if (eventType == EventType::WIFI_CONNECTED) {
        this->buzzerActuator.setState(HIGH);
        delay(500);
        this->buzzerActuator.setState(LOW);
    }
}
