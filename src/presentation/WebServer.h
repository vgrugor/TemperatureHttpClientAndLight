#include <ESP8266WebServer.h>
#include "infrastructure/FileSystem.h"

class WebServer {
private:
    ESP8266WebServer server;
    FileSystem& fileSystem;

    void handleRoot() {
        String html = fileSystem.readFile("/index.html");
        if (html.length() > 0) {
            server.send(200, "text/html", html);
        } else {
            server.send(404, "text/plain", "File not found");
        }
    }

public:
    WebServer(FileSystem& fileSystem) : fileSystem(fileSystem), server(80) {}

    void begin() {
        server.on("/", HTTP_GET, [this]() { handleRoot(); });
        server.begin();
    }

    void handleClient() {
        server.handleClient();
    }
};