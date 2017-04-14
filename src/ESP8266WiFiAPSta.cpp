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
 *  Do nothing
 */
ESP8266WiFiAPSta::ESP8266WiFiAPSta() {
}

/**
 *  Init all required modules
 */
void ESP8266WiFiAPSta::init() {
  initEEPROM();
  initWiFi();
  initWebServer();
}

/**
 *  Read data from EEPROM
 */
void ESP8266WiFiAPSta::initEEPROM() {
  staStatus = EEPROM.read(WIFIAPSTA_EEPROM_STATUS);
  staSsid[0] = '\0';
  staSecret[0] = '\0';
  
  // If data are stored in EEPROM
  if(staStatus == WIFIAPSTA_STATUS_SAVED) {
    unsigned char ssidSize = (unsigned char) EEPROM.read(WIFIAPSTA_EEPROM_SSID_SIZE);
    unsigned char secretSize = (unsigned char) EEPROM.read(WIFIAPSTA_EEPROM_SECRET_SIZE);
    if(ssidSize > 0 && secretSize > 0) {
      for(unsigned char i = 0; i < ssidSize; i++) {
        staSsid[i] = (char) EEPROM.read(WIFIAPSTA_EEPROM_SSID + i);
      }
      staSsid[ssidSize] = '\0';
      for(unsigned char i = 0; i < secretSize; i++) {
        staSecret[i] += (char) EEPROM.read(WIFIAPSTA_EEPROM_SECRET + i);
      }
      staSecret[secretSize] = '\0';
    } else {
      EEPROM.write(WIFIAPSTA_EEPROM_STATUS, WIFIAPSTA_STATUS_EMPTY);
      EEPROM.commit();
      staStatus = WIFIAPSTA_STATUS_EMPTY;
    }
  } 
  // if not existing status, clear all data
  else if(staStatus != WIFIAPSTA_STATUS_EMPTY) {
    EEPROM.write(WIFIAPSTA_EEPROM_STATUS, WIFIAPSTA_STATUS_EMPTY);
    EEPROM.commit();
    staStatus = WIFIAPSTA_STATUS_EMPTY;
  }
}


/**
 *  Init the wireless module
 */
void ESP8266WiFiAPSta::initWiFi() {
  WiFi.mode(WIFI_AP_STA);
  
  // Start access point
  WiFi.softAP(WIFIAPSTA_AP_SSID, WIFIAPSTA_AP_SECRET, WIFIAPSTA_AP_CHANNEL, WIFIAPSTA_AP_HIDDEN);
  
  // Start station if data connection exists
  if(staStatus == WIFIAPSTA_STATUS_SAVED) {
    WiFi.begin(staSsid, staSecret);
  }
}

/**
 *  Handle all http request and start web server
 */
void ESP8266WiFiAPSta::initWebServer() {
  WiFiAPStaServer.on("/", []() {
    WiFiAPStaServer.send(200, "text/plain", "I like coffee!");
  });
  
  WiFiAPStaServer.onNotFound([]() {
    WiFiAPStaServer.send(404, "text/plain", "No more coffee :'(");
  });
  
  WiFiAPStaServer.begin();
}

/**
 *  Handle client http connection
 */
void ESP8266WiFiAPSta::handleClient() {
  WiFiAPStaServer.handleClient();
}


//
//  Getters, setters & EEPROM stuffs
//

