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
    Scheduler(int capacity) : capacity(capacity), taskCount(0) {
        tasks = new Task[capacity];
    }

    ~Scheduler() {
        delete[] tasks;
    }

    void addTask(unsigned long interval, std::function<void()> callback, bool repeat = true) {
        if (taskCount < capacity) {
            tasks[taskCount] = {interval, 0, callback, repeat};
            taskCount++;
        }
    }

    void run() {
        unsigned long currentTime = millis();
        for (int i = 0; i < taskCount; i++) {
            if (currentTime - tasks[i].lastRun >= tasks[i].interval) {
                tasks[i].callback();
                tasks[i].lastRun = currentTime;

                if (!tasks[i].repeat) {
                    // Удаляем задачу, если она не повторяется
                    for (int j = i; j < taskCount - 1; j++) {
                        tasks[j] = tasks[j + 1];
                    }
                    taskCount--;
                    i--;
                }
            }
        }
    }
};
