#include "domain/Device.h"

#ifndef SENSOR_H
    #define SENSOR_H

class Sensor : public Device {
    protected:
       unsigned long lastUpdateTime = 0;
       unsigned long updateInterval = 5000;
       float value = __FLT_MIN__;

    public:
        Sensor(unsigned long updateInterval);
        virtual float readValue() = 0;
        float getLastValue() const;
        void update() override;
};

#endif // SENSOR_H
