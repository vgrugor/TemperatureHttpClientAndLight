#include "domain/Actuator.h"

class RelayActuator : public Actuator {
    private:
        int pin;
    public:
        RelayActuator(int pin) : pin(pin) {
            pinMode(pin, OUTPUT);
        }

        void setState(bool state) override {
            digitalWrite(pin, state ? HIGH : LOW);
        }

        void update() override {
            // Обновление состояния актуатора
        }
};
