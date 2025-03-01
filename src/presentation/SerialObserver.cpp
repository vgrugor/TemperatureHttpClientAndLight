#include "presentation/SerialObserver.h"

void SerialObserver::update(EventType eventType) {
    String message;

    switch (eventType) {
        case EventType::WIFI_TRY_CONNECT: message = "SUCCESS"; break;
        case EventType::WIFI_CONNECTED: message = "SUCCESS"; break;
    }

    Serial.println(message);
}
