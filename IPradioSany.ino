/*
  Autor: Nenad Dobrijević
  Opis: ESP8266 IP radio s I2C display-em, OTA podrškom i reprodukcijom IP audio strima
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA>
#include <ESP8266Audio.h>
#include <AudioFileSourceICYStream.h>
#include <AudioOutputI2S.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C display setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// WiFi credentials
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Radio stream URLs
String radioLinks[] = {
  "http://stream-url-1",
  "http://stream-url-2",
  // Add more stream URLs here
};
const int numRadioLinks = sizeof(radioLinks) / sizeof(radioLinks[0]);

int currentRadioIndex = 0;

// Audio output setup
AudioFileSourceICYStream *file;
AudioOutputI2S *out;
AudioConnection *patchCord;

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize I2C display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);

  // Setup OTA
  ArduinoOTA.onStart([]() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("OTA update in progress...");
    display.display();
  });
  ArduinoOTA.onEnd([]() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("OTA update completed");
    display.display();
    delay(2000);
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("OTA update: ");
    display.print(progress / (total / 100));
    display.print("%");
    display.display();
  });
  ArduinoOTA.onError([](ota_error_t error) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("OTA update error");
    display.display();
    delay(2000);
  });
  ArduinoOTA.begin();

  // Setup audio output
  Audio.begin();
  out = new AudioOutputI2S();
  patchCord = new AudioConnection(*file, 0, *out, 0);

  // Start radio streaming
  playRadioStream();
}

void loop() {
  ArduinoOTA.handle();
  // Add any additional functionality or logic here
}

void playRadioStream() {
  if (WiFi.status() == WL_CONNECTED) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Connecting to radio...");
    display.display();

    HTTPClient http;
    http.begin(radioLinks[currentRadioIndex]);

    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Playing radio stream");
        display.display();

        WiFiClient *stream = http.getStreamPtr();
        file = new AudioFileSourceICYStream(stream, new AudioOutputI2S());
        file->RegisterMetadataCB(MetadataReceived);

        Audio.start(file);
        while (file->isRunning()) {
          // Add any additional code or controls here while streaming is in progress
          delay(100);
        }

        // Stream ended
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Stream ended");
        display.display();
        delay(2000);

      } else {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Failed to connect");
        display.display();
        delay(2000);
      }
    } else {
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.println("Connection failed");
      display.display();
      delay(2000);
    }

    http.end();
  }
}

void changeRadioStream() {
  currentRadioIndex = (currentRadioIndex + 1) % numRadioLinks;
  playRadioStream();
}

void MetadataReceived(void *client, const char *name, const char *value) {
  // Process metadata if needed
  // You can extract song title, artist, etc. from the metadata
}

