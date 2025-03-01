#ifndef SCHEDULER_H
    #define SCHEDULER_H

    #include <functional>

    class Scheduler {
        private:
            struct Task {
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

            void addTask(unsigned long interval, std::function<void()> callback, bool repeat = true);
            void run();
    };

#endif // SCHEDULER_H
