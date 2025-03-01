#ifndef OBSERVER_H
    #define OBSERVER_H

    #include "EventType.h"
    #include <Arduino.h>

    class Observer {
        public:
            virtual void update(EventType eventType) = 0;
    };

#endif
