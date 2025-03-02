#ifndef REGULATOR_H
    #define REGULATOR_H

    #include "domain/Device.h"

    class Regulator : public Device {
        public:
            virtual void setLevel(uint8_t level) = 0;
    };

#endif // REGULATOR_H
