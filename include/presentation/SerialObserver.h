#ifndef SERIAL_OBSERVER_H
    #define SERIAL_OBSERVER_H

    #include <Arduino.h>
    #include "Observer.h"
    #include "EventType.h"

    class SerialObserver : public Observer {
        public:
            void update(EventType eventType) override;
    };

#endif // SERIAL_OBSERVER_H
