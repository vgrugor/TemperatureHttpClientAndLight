#include "application/scheduler/Scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(int capacity) : taskCount(0), capacity(capacity) {
    tasks = new Task[capacity];
}

Scheduler::~Scheduler() {
    delete[] tasks;
}

void Scheduler::addTask(String taskId, unsigned long interval, std::function<void()> callback, bool repeat) {
    for (int i = 0; i < taskCount; i++) {
        if (!taskId.isEmpty() && tasks[i].taskId == taskId) {
            tasks[i].interval = interval;
            tasks[i].lastRun = millis();
            tasks[i].callback = callback;
            tasks[i].repeat = repeat;

            return;
        }
    }

    if (taskCount < capacity) {
        tasks[taskCount] = {taskId, interval, millis(), callback, repeat};
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
