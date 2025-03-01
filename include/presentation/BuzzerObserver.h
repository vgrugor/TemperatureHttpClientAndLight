#ifndef BUZZER_OBSERVER_H
    #define BUZZER_OBSERVER_H

    #include <Arduino.h>
    #include "Observer.h"
    #include "EventType.h"
    #include "infrastructure/BuzzerActuator.h"

    class BuzzerObserver : public Observer {
        private:
            BuzzerActuator buzzerActuator;

        public:
            BuzzerObserver(BuzzerActuator buzzerActuator);
            void update(EventType eventType) override;
    };

#endif // BUZZER_OBSERVER_H
