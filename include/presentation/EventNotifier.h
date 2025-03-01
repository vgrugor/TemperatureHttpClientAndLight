#ifndef EVENTNOTIFIER_H
    #define EVENTNOTIFIER_H

    #include <vector>
    #include <algorithm>
    #include "presentation/Observer.h"
    #include "presentation/EventType.h"

    class EventNotifier {
        private:
            std::vector<Observer*> observers;

        public:
            void addObserver(Observer* observer);
            void removeObserver(Observer* observer);
            void notifyObservers(EventType eventType);                                                        
    };

#endif // EVENTNOTIFIER_H
