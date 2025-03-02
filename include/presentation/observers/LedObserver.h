#ifndef LED_OBSERVER_H
    #define LED_OBSERVER_H

    #include <Arduino.h>
    #include "Observer.h"
    #include "presentation/EventType.h"
    #include "infrastructure/LedActuator.h"

    class LedObserver : public Observer {
        private:
            LedActuator ledActuator;

        public:
            LedObserver(LedActuator ledActuator);
            void update(EventType eventType, const String& message = "") override;
    };

#endif // LED_OBSERVER_H
