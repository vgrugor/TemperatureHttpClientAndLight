// DS18B20Sensor.cpp
#include "infrastructure/DS18B20Sensor.h"
#include <Arduino.h>

DS18B20Sensor::DS18B20Sensor(int pin, unsigned long updateInterval) : Sensor(updateInterval), oneWire(pin), sensors(&oneWire) {
    sensors.begin();

    if (sensors.getDeviceCount() > 0) {
        sensors.getAddress(deviceAddress, 0);
    }
}

float DS18B20Sensor::readValue() {
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempC(deviceAddress);

    delay(DS18B20Sensor::DELAY_GETTING_VALUE);

    Serial.println("Temperature: " + String(temperatureC));

    return temperatureC;
}
