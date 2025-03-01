#include "presentation/LedObserver.h"

LedObserver::LedObserver(LedActuator ledActuator) : ledActuator(ledActuator) {}

void LedObserver::update(EventType eventType) {
    if (eventType == EventType::WIFI_TRY_CONNECT) {
        this->ledActuator.setState(HIGH);
        delay(200);
        this->ledActuator.setState(LOW);
    } else if (eventType == EventType::WIFI_CONNECTED) {
        this->ledActuator.setState(HIGH);
        delay(500);
        this->ledActuator.setState(LOW);
    }
}
