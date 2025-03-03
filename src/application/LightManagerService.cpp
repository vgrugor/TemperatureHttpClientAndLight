#include "application/LightManagerService.h"

LightManagerService::LightManagerService(
    Regulator& frontRegulator, 
    Regulator& middleRegulator, 
    Regulator& backRegulator,
    Scheduler& scheduler
) : frontRegulator(frontRegulator), 
    middleRegulator(middleRegulator),
    backRegulator(backRegulator),
    scheduler(scheduler)
{}

void LightManagerService::changeAllLedMatrixLevel(int level) {
    this->frontRegulator.setLevel(level);
    this->middleRegulator.setLevel(level);
    this->backRegulator.setLevel(level);
}

void LightManagerService::changeTimerMinute(int timerMinute) {
    SettingsStorage::getInstance().setTimerMinute(timerMinute);

    this->scheduler.addTask(timerMinute * 60 * 1000, [this]() {
        this->changeAllLedMatrixLevel(0);
        SettingsStorage::getInstance().setTimerMinute(0);
    }, false);
    // TODO: notify client
}

void LightManagerService::changeFrontLedMatrixLevel(int level) {
    this->frontRegulator.setLevel(level);
}

void LightManagerService::changeMiddleLedMatrixLevel(int level) {
    this->middleRegulator.setLevel(level);
}

void LightManagerService::changeBackLedMatrixLevel(int level) {
    this->backRegulator.setLevel(level);
}
