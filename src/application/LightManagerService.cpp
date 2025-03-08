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
    int mappedLevel = this->mapLevel(level);

    this->frontRegulator.setLevel(mappedLevel);
    this->middleRegulator.setLevel(mappedLevel);
    this->backRegulator.setLevel(mappedLevel);
}

void LightManagerService::changeTimerMinute(int timerMinute) {
    SettingsStorage::getInstance().setTimerMinute(timerMinute);

    EventNotifier& eventNotifier = EventNotifier::getInstance();
    eventNotifier.notifyObservers(EventType::TIMER_SET);

    this->scheduler.addTask(
        TaskIds::LIGHT_DISABLE_TASK,
        timerMinute * 60 * 1000, 
        [this, &eventNotifier]() {
            this->changeAllLedMatrixLevel(0);

            SettingsStorage::getInstance().setTimerMinute(0);

            eventNotifier.notifyObservers(EventType::WEB_SOCKET_NOTIFY_CLIENT);
            eventNotifier.notifyObservers(EventType::TIMER_APPLIED);
        }, 
        false
    );
}

void LightManagerService::changeFrontLedMatrixLevel(int level) {
    int mappedLevel = this->mapLevel(level);

    this->frontRegulator.setLevel(mappedLevel);
}

void LightManagerService::changeMiddleLedMatrixLevel(int level) {
    int mappedLevel = this->mapLevel(level);

    this->middleRegulator.setLevel(mappedLevel);
}

void LightManagerService::changeBackLedMatrixLevel(int level) {
    int mappedLevel = this->mapLevel(level);

    this->backRegulator.setLevel(mappedLevel);
}

int LightManagerService::mapLevel(int level) {
    if (level > 100) {
        level = 100;
    } else if (level < 0) {
        level = 0;
    }

    return map(level, 0, 100, Regulator::MIN_LEVEL, Regulator::MAX_LEVEL);
}
