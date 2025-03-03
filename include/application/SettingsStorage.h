#ifndef SETTINGS_STORAGE_H
    #define SETTINGS_STORAGE_H

    class SettingsStorage {
        public:
            static SettingsStorage& getInstance();
            int getTimerMinute();
            void setTimerMinute(int minute);

        private:
            int timerMinute;
            SettingsStorage();
            void initializeData();
    };

#endif //SETTINGS_STORAGE_H
