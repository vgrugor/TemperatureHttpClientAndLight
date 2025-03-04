#ifndef SCHEDULER_H
    #define SCHEDULER_H

    #include <functional>
    #include <Arduino.h>

    class Scheduler {
        private:
            struct Task {
                String taskId;
                unsigned long interval;
                unsigned long lastRun;
                std::function<void()> callback;
                bool repeat;
            };

            Task* tasks;
            int taskCount;
            int capacity;

        public:
            Scheduler(int capacity);
            ~Scheduler();
            void addTask(String taskId, unsigned long interval, std::function<void()> callback, bool repeat = true);
            void run();
    };

#endif // SCHEDULER_H
