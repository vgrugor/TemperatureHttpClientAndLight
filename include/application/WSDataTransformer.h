#ifndef WS_DATA_TRANSFORMER_H
    #define WS_DATA_TRANSFORMER_H

    #include <Arduino.h>
    #include <map>
    #include <Arduino_JSON.h>
    #include "infrastructure/regulators/FrontRegulator.h"
    #include "infrastructure/regulators/MiddleRegulator.h"
    #include "infrastructure/regulators/BackRegulator.h"
    #include "infrastructure/sensors/DS18B20Sensor.h"
    #include "application/SettingsStorage.h"

    class WsDataTransformer {
        public:
            WsDataTransformer(
                FrontRegulator& frontRegulator, 
                MiddleRegulator& middleRegulator, 
                BackRegulator& backRegulator,
                DS18B20Sensor& temperatureSensor
            );
            int getFrontLedMatrixLevel();
            int getMiddleLedMatrixLevel();
            int getBackLedMatrixLevel();
            int getAllLedMatrixLevel();
            int getTimerMinute();
            float getTemperature();
            String toJSON();

        private:
            FrontRegulator& frontRegulator;
            MiddleRegulator& middleRegulator;
            BackRegulator& backRegulator;
            DS18B20Sensor& temperatureSensor;
            SettingsStorage& settingsStorage;
    };

#endif //WS_DATA_TRANSFORMER_H
