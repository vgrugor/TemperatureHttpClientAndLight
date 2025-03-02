#include "presentation/observers/LedObserver.h"

LedObserver::LedObserver(LedActuator ledActuator) : ledActuator(ledActuator) {}

void LedObserver::update(EventType eventType, const String& message) {
    switch (eventType) {
        //WIFI events
        case EventType::WIFI_START_CONNECT: 
            this->ledActuator.setState(HIGH);
            
            break;
        case EventType::WIFI_TRY_CONNECT: 
            break;
        case EventType::WIFI_CONNECTED: 
            this->ledActuator.setState(LOW);

            break;
        case EventType::WIFI_RECONNECT: 
            break;
        
        //temperature events
        case EventType::READ_TEMPERATURE: 
            this->ledActuator.setState(HIGH);
            delay(100);
            break;this->ledActuator.setState(LOW);
            delay(100);
            
            break;
        case EventType::SEND_TEMPERATURE:
            this->ledActuator.setState(HIGH);
            delay(1000);
            break;this->ledActuator.setState(LOW);
            delay(1000);
            this->ledActuator.setState(HIGH);
            delay(1000);
            break;this->ledActuator.setState(LOW);
            delay(1000);

            break;
    }
}
