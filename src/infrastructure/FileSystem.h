#include <LittleFS.h>

class FileSystem {
public:
    FileSystem() {
        LittleFS.begin();
    }

    bool writeFile(const String& path, const String& data) {
        File file = LittleFS.open(path, "w");
        if (!file) {
            return false;
        }
        file.print(data);
        file.close();
        return true;
    }

    String readFile(const String& path) {
        File file = LittleFS.open(path, "r");
        if (!file) {
            return "";
        }
        String data = file.readString();
        file.close();
        return data;
    }

    bool deleteFile(const String& path) {
        return LittleFS.remove(path);
    }

    bool fileExists(const String& path) {
        return LittleFS.exists(path);
    }
};
