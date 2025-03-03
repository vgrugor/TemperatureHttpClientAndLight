#ifndef MIDDLE_REGULATOR_H
    #define MIDDLE_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class MiddleRegulator : public Regulator {
        public:
           MiddleRegulator(int pin);
    };

#endif // MIDDLE_REGULATOR_H
