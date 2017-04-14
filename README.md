# ESP8266WiFiAPSta [![Build Status](https://travis-ci.org/nhuhoai/ESP8266WiFiAPSta.svg?branch=master)](https://www.github.com/nhuhoai/ESP8266WiFiAPSta)

ESP8266 library for WiFi in AP+Sta mode + Web server config

## How-to use

1. Clone the project into your Arduino libraries directory
2. Open the example ESP8266WiFiAPSta
3. Verify and upload on your ESP8266
4. Use your phone (or device with WiFi) and connect to this network
  - SSID: ESP8266WiFiAPSta
  - Password: I<3Coffee!
5. Site map
  - / (root page) : just a text
  - /Config : Config your station mode, first input is the SSID, the second one
    is the password
  - /AP/SSID : Display the access point SSID
  - /AP/Secret : Display the access point password
  - /STA/SSID : Display the current station SSID
  - /STA/Secret : Display the current station secret
  - /STA/IP : Display the current station local address (0.0.0.0 means ESP8266
    is not connected)