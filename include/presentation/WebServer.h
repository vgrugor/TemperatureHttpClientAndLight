#ifndef WEB_SERVER_FACADE_H
    #define WEB_SERVER_FACADE_H

    #include <Arduino.h>
    #include <ESPAsyncWebServer.h>
    #include "infrastructure/web/WebSocket.h"
    #include "infrastructure/fs/FileSystem.h"

    class WebServer {
        private:
            AsyncWebServer server;
            WebSocket& webSocket;
            FileSystem& fileSystem;
            void handleRoot(AsyncWebServerRequest* request);

        public:
            WebServer(WebSocket& webSocket, FileSystem& fileSystem);
            void begin();
            void handleClient();
    };

#endif // WEB_SERVER_FACADE_H
