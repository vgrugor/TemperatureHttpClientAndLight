#include "application/SettingsStorage.h"

SettingsStorage::SettingsStorage() {
    this->initializeData();
}

SettingsStorage& SettingsStorage::getInstance() {
    static SettingsStorage instance;
    return instance;
}

void SettingsStorage::initializeData() {
    this->timerMinute = 0;
}

int SettingsStorage::getTimerMinute() {
    return this->timerMinute;
}

void SettingsStorage::setTimerMinute(int minute) {
    this->timerMinute = minute;
}
