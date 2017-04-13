/**
 *  @file     ESP8266WiFiAPSta.cpp
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    
 */

#include <ESP8266WiFiAPSta.h>

//
// Global variables
//

/// Web resource server
ESP8266WebServer WiFiAPStaServer(WIFIAPSTA_WEB_PORT);

//
//  Methods
//

/**
 *  Main constructor
 *  Init all required modules
 */
ESP8266WiFiAPSta::ESP8266WiFiAPSta() {
  initWiFi();
  initWebServer();
}

/**
 *  Init the access point
 */
void ESP8266WiFiAPSta::initWiFi() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(WIFIAPSTA_AP_SSID, WIFIAPSTA_AP_SECRET, WIFIAPSTA_AP_CHANNEL, WIFIAPSTA_AP_HIDDEN);
}

/**
 *
 */
void ESP8266WiFiAPSta::initWebServer() {
  WiFiAPStaServer.on("/", []() {
    WiFiAPStaServer.send(200, "text/plain", "I like coffee!");
  });
}


//
//  Getters, setters & EEPROM stuffs
//

