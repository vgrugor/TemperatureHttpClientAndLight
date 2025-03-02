#ifndef BACK_REGULATOR_H
    #define BACK_REGULATOR_H

    #include "domain/Regulator.h"
    #include <Arduino.h>

    class BackRegulator : public Regulator {
        private:
            int pin;

        public:
            BackRegulator(int pin);
            void setLevel(uint16_t level) override;
            void update() override;
    };

#endif // BACK_REGULATOR_H
