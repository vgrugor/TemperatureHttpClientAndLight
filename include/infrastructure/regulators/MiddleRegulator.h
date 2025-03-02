#ifndef MIDDLE_REGULATOR_H
    #define MIDDLE_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class MiddleRegulator : public Regulator {
        private:
            int pin;

        public:
            MiddleRegulator(int pin);
            void setLevel(uint8_t level) override;
            void update() override;
    };

#endif // MIDDLE_REGULATOR_H
