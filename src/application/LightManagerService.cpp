#include "application/LightManagerService.h"

LightManagerService::LightManagerService(Regulator& frontRegulator, Regulator& middleRegulator, Regulator& backRegulator) 
    : frontRegulator(frontRegulator), 
    middleRegulator(middleRegulator),
    backRegulator(backRegulator)
{}

void LightManagerService::changeAllLedMatrixLevel(int level) {
    this->frontRegulator.setLevel(level);
    this->middleRegulator.setLevel(level);
    this->backRegulator.setLevel(level);
}

void LightManagerService::changeTimerMinute(int level) {
    //String timerMinute = message.substring(2);
    //wsData.setTimerMinute(timerMinute.toInt());
    //this->taskScheduler.addTaskInMinutes(wsData.getTimerMinute(), DisableAllLedMatrixTask::run);
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
