#ifndef FRONT_REGULATOR_H
    #define FRONT_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class FrontRegulator : public Regulator {
        public:
            FrontRegulator(int pin);
    };

#endif // FRONT_REGULATOR_H
