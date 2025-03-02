#ifndef REGULATOR_H
    #define REGULATOR_H

    #include "domain/Device.h"
    #include <Arduino.h>

    class Regulator : public Device {
        public:
            virtual void setLevel(uint16_t level) = 0;
    };

#endif // REGULATOR_H
