// DS18B20Sensor.h
#ifndef DS18B20SENSOR_H
    #define DS18B20SENSOR_H

    #include <OneWire.h>
    #include <DallasTemperature.h>
    #include "domain/Sensor.h"
    #include "presentation/EventNotifier.h"
    #include "presentation/EventType.h"

    class DS18B20Sensor : public Sensor {
        private:
            const int DELAY_GETTING_VALUE = 2000;
            OneWire oneWire;
            DallasTemperature sensors;
            DeviceAddress deviceAddress;

        public:
            DS18B20Sensor(int pin, unsigned long interval);
            float readValue() override;
    };

#endif // DS18B20SENSOR_H
