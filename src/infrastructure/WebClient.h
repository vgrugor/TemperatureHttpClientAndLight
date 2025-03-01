#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class WebClient {
private:
    WiFiClient wifiClient;

public:
    String get(const String& url) {
        HTTPClient http;
        http.begin(wifiClient, url);

        int httpCode = http.GET();
        String payload = "";

        if (httpCode == HTTP_CODE_OK) {
            payload = http.getString();
        }

        http.end();
        return payload;
    }

    String post(const String& url, const String& data) {
        HTTPClient http;
        http.begin(wifiClient, url);
        http.addHeader("Content-Type", "application/json");

        int httpCode = http.POST(data);
        String payload = "";

        if (httpCode == HTTP_CODE_OK) {
            payload = http.getString();
        }

        http.end();
        return payload;
    }
};
