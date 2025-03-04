#ifndef BACK_REGULATOR_H
    #define BACK_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class BackRegulator : public Regulator {
        public:
            BackRegulator(int pin);
    };

#endif // BACK_REGULATOR_H
