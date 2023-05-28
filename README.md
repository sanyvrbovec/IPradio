# IPradioSany

ESP8266 IP Radio with I2C Display, OTA Support, and IP Audio Streaming
This repository contains the code for an ESP8266-based IP radio with an I2C display, OTA (Over-The-Air) support, and IP audio streaming. It allows you to connect to a Wi-Fi network, stream audio from internet radio stations, and display information on a connected I2C display.

Setup
Hardware Requirements
To set up the project, you will need the following hardware:

ESP8266 board (e.g., NodeMCU)
I2C display (128x64 pixels, SSD1306 compatible)
Speaker or audio output device
Circuit Connections
Connect the components as follows:

Connect the ESP8266 board to your computer via USB for power and programming.
Connect the I2C display to the ESP8266 board using the I2C interface. Make sure to connect the SDA pin to the SDA pin on the ESP8266 and the SCL pin to the SCL pin.
Connect the audio output of the ESP8266 board to your speaker or audio output device.
Software Requirements
To compile and upload the code to the ESP8266 board, you will need the following software:

Arduino IDE: https://www.arduino.cc/en/software
ESP8266 core for Arduino: https://github.com/esp8266/Arduino
Install the Arduino IDE and the ESP8266 core for Arduino by following the instructions provided on their respective websites.

Libraries
The following libraries are required for the code to work correctly. Install them in your Arduino IDE by navigating to Sketch -> Include Library -> Manage Libraries and searching for each library by name.

ESP8266WiFi
ESP8266HTTPClient
WiFiClient
Wire
Adafruit GFX Library
Adafruit SSD1306
ESP8266mDNS
WiFiUdp
ArduinoOTA
ESP8266Audio
AudioFileSourceICYStream
AudioOutputI2S
Configuration
Before uploading the code to the ESP8266 board, you need to make some configurations:

Open the code file main.ino in the Arduino IDE.
Modify the following lines to set your Wi-Fi credentials:
cpp
Copy code
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
Replace "YourWiFiSSID" with the SSID of your Wi-Fi network and "YourWiFiPassword" with the corresponding password.

Customize the list of radio stream URLs:
cpp
Copy code
String radioLinks[] = {
  "http://stream-url-1",
  "http://stream-url-2",
  // Add more stream URLs here
};
Replace "http://stream-url-1", "http://stream-url-2", etc., with the URLs of the internet radio streams you want to include. You can add or remove URLs as needed.

Uploading the Code
Connect the ESP8266 board to your computer.
In the Arduino IDE, select the correct board model by going to Tools -> Board and choosing the appropriate ESP8266 board.
Select the correct port by going to Tools -> Port and selecting the port to which your ESP8266 board is connected.
Click on the "Upload" button in the Arduino IDE to compile and upload the code to the ESP8266 board.
Usage
After successfully uploading the code, disconnect the ESP8266 board from your computer and power it using an external power source or a USB power adapter.
The ESP8266 board will attempt to connect to the Wi-Fi network you configured. The status will be displayed on the I2C display.
Once connected, the ESP8266 board will start playing the first radio stream in the list. The currently playing radio stream will be displayed on the I2C display.
To switch to the next radio stream, press the corresponding button or implement your own control logic in the loop() function.
To perform OTA updates, follow the instructions in the "OTA Support" section below.
OTA Support
This project includes Over-The-Air (OTA) support, allowing you to update the firmware on the ESP8266 board wirelessly.

To perform an OTA update:

Make sure the ESP8266 board and your computer are connected to the same Wi-Fi network.
Obtain the IP address assigned to the ESP8266 board by checking the serial monitor output after the board connects to Wi-Fi.
Open the Arduino IDE and go to Sketch -> Upload Using Programmer to compile the sketch without uploading it.
After the compilation finishes, go to Sketch -> Export Compiled Binary and save the compiled binary file (.bin) in a convenient location.
Install an OTA-capable firmware uploader tool on your computer, such as ESP8266 Sketch Data Upload, to upload the compiled binary file to the ESP8266 board using OTA.
Open the OTA firmware uploader tool and enter the IP address of the ESP8266 board, along with the appropriate port and authentication details if required.
Upload the compiled binary file using the OTA firmware uploader tool. The ESP8266 board will receive the firmware update and perform the OTA update process automatically.
Monitor the progress and status of the OTA update on the I2C display.
Pinout
The following pinout is used in this project:

SDA: I2C data pin for communication with the I2C display
SCL: I2C clock pin for communication with the I2C display
Speaker: Connect the audio output pin of the ESP8266 board to your speaker or audio output device
Please refer to the documentation of your ESP8266 board for the specific pin numbers corresponding to these functions.

Recommended DAC Chip
To enhance the audio quality, you can connect an external DAC (Digital-to-Analog Converter) chip to the ESP8266 board. The code provided in this repository does not utilize a specific DAC chip, as it directly uses the ESP8266's built-in I2S interface for audio output.

However, one of the most cost-effective DAC chips that you can use with the ESP8266 board is the PCM5102A. It provides high-quality audio output and can be easily connected to the ESP8266's I2S interface.

When using an external DAC chip, make sure to modify the circuit connections and code accordingly to establish the communication between the ESP8266 board and the DAC chip.

Credits
Author: Nenad Dobrijević

This project is based on the ESP8266 Arduino core and various libraries, including the ESP8266WiFi library, Adafruit GFX Library, Adafruit SSD1306 library, and ESP8266Audio library.

License
This project is licensed under the MIT License. Feel free to modify and distribute the code according to the terms of the license.




