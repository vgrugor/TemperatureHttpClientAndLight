#ifndef FRONT_REGULATOR_H
    #define FRONT_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class FrontRegulator : public Regulator {
        private:
            int pin;

        public:
            FrontRegulator(int pin);
            void setLevel(uint16_t level) override;
            void update() override;
    };

#endif // FRONT_REGULATOR_H
