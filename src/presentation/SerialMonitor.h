#include "domain/Sensor.h"

class SerialMonitor {
    private:
        Sensor& sensor;
    public:
        SerialMonitor(Sensor& sensor) : sensor(sensor) {}

        void displayData() {
            float value = sensor.readValue();
            Serial.print("Temperature: ");
            Serial.println(value);
        }
};
