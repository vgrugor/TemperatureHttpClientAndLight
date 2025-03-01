#include "domain/Device.h"

class Actuator : public Device {
public:
    virtual void setState(bool state) = 0;
};
