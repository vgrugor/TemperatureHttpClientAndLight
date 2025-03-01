#include "application/Scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(int capacity) : capacity(capacity), taskCount(0) {
    tasks = new Task[capacity];
}

Scheduler::~Scheduler() {
    delete[] tasks;
}

void Scheduler::addTask(unsigned long interval, std::function<void()> callback, bool repeat) {
    if (taskCount < capacity) {
        tasks[taskCount] = {interval, 0, callback, repeat};
        taskCount++;
    }
}

void Scheduler::run() {
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
