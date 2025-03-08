#ifndef REGULATOR_H
    #define REGULATOR_H

    #include "domain/Device.h"
    #include <Arduino.h>

    class Regulator : public Device {
        protected:
            uint16_t currentLevel = 0;
            uint16_t needleLevel = 0;
            uint16_t updatePeriod = 1;
            unsigned long lastUpdateTime = 0;
            int pin;

        public:
            const int DELAY_SET_LEVEL = 2000;
            static const int MAX_LEVEL = 255;
            static const int MIN_LEVEL = 0;
            Regulator(int pin);
            void setLevel(uint16_t level);
            void update() override;
            int getNeedleLevel();
    };

#endif // REGULATOR_H
