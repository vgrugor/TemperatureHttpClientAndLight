#ifndef WEB_CLIENT_H
    #define WEB_CLIENT_H

    #include <ESP8266HTTPClient.h>
    #include <WiFiClient.h>

    class WebClient {
        private:
            WiFiClient wifiClient;

        public:
            String get(const String& url);
            String post(const String& url, const String& data);
    };

#endif // WEB_CLIENT_H
