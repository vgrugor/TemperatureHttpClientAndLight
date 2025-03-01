#include <Arduino.h>
#include "presentation/EventNotifier.h"

void EventNotifier::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void EventNotifier::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void EventNotifier::notifyObservers(EventType eventType) {
    for (auto observer : observers) {
        observer->update(eventType);
    }
}
