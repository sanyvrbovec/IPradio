# IPradioSany

IPradioSany is an ESP8266-based IP radio project that utilizes an I2C display, OTA (Over-The-Air) update support, and allows for adding new radio stream links. The code provided in this repository allows you to build a WiFi-connected radio device with the ability to switch between different radio streams.

## Hardware Requirements
- ESP8266 development board
- I2C display (e.g., SSD1306)
- Speaker or audio output device
- Internet connection

## Pin Configuration
The following pin configuration is used in the IPradioSany code:

- Display:
  - SDA: Connect to the SDA pin of your ESP8266 board
  - SCL: Connect to the SCL pin of your ESP8266 board

## Library Dependencies
The IPradioSany code relies on the following libraries:
- ESP8266WiFi: Enables WiFi connectivity.
- ESP8266HTTPClient: Allows making HTTP requests to retrieve radio streams.
- Adafruit_GFX: Provides graphics utilities for the display.
- Adafruit_SSD1306: Supports communication with the I2C display.
- ESP8266mDNS: Enables mDNS (Multicast DNS) for OTA updates.
- WiFiUdp: Provides UDP (User Datagram Protocol) support for OTA updates.
- ArduinoOTA: Enables Over-The-Air updates for the ESP8266.

Make sure to install these libraries in your Arduino IDE before uploading the code.

## Configuration
To configure the IPradioSany project, you need to modify the following variables in the code:

- WiFi Credentials:
  - `ssid`: Set this to your WiFi network name (SSID).
  - `password`: Set this to your WiFi network password.

- Radio Stream URLs:
  - `radioLinks[]`: This array holds the URLs of the radio stream sources. Add or remove URLs as needed, ensuring they are in quotation marks and separated by commas.

## Usage
1. Connect your ESP8266 board and I2C display according to the provided pin configuration.

2. Open the `IPradioSany.ino` file in the Arduino IDE.

3. Install the necessary libraries mentioned in the "Library Dependencies" section.

4. Modify the WiFi credentials and radio stream URLs in the code to match your specific setup.

5. Upload the code to your ESP8266 board.

6. Open the Serial Monitor in the Arduino IDE to monitor the device's progress and debug if needed.

7. Once the code is uploaded, the device will connect to the specified WiFi network and start playing the radio stream.

8. Use the buttons or additional logic to control the radio, switch between different streams, or add any desired functionality.

## Contributing
Contributions to the IPradioSany project are welcome! If you encounter any issues, have suggestions for improvements, or want to add new features, please feel free to submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).




