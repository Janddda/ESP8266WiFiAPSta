/**
 *  @file     ESP8266WiFiAPSta.cpp
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    
 */

#include "ESP8266WiFi.h"
#include <ESP8266WiFiAPSta.h>
#include <ESP8266WiFiAPStaConfig.h>

//
//  Methods
//

/**
 *  Main constructor
 *  Init all required modules
 */
ESP8266WiFiAPSta::ESP8266WiFiAPSta() {
  initWiFi();
}

/**
 *  Init the access point
 */
void ESP8266WiFiAPSta::initWiFi() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(WIFIAPSTA_AP_SSID, WIFIAPSTA_AP_SECRET, WIFIAPSTA_AP_CHANNEL, WIFIAPSTA_AP_HIDDEN);
}


//
//  Getters, setters & EEPROM stuffs
//

