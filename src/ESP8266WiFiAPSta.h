/**
 *  @file     ESP8266WiFiAPSta.h
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    Global variables & class structure
 */

#ifndef __ESP8266WIFIAPSTA_H
#define __ESP8266WIFIAPSTA_H

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAPStaConfig.h>

//
//  Global variables
//

/// Memory address of the Station SSID and password status
static const unsigned int WIFIAPSTA_EEPROM_STATUS = WIFIAPSTA_EEPROM_START;

/// Memory address of the Station SSID (string size)
static const unsigned int WIFIAPSTA_EEPROM_SSID_SIZE = WIFIAPSTA_EEPROM_START + 1;

/// Memory address of the Station password (string size)
static const unsigned int WIFIAPSTA_EEPROM_SECRET_SIZE = WIFIAPSTA_EEPROM_START + 2;

/// Memory address of the Station SSID
/// Limit size 20 bytes
static const unsigned int WIFIAPSTA_EEPROM_SSID = WIFIAPSTA_EEPROM_START + 3;

/// Memory address of the Station password
/// Limit size 20 bytes
static const unsigned int WIFIAPSTA_EEPROM_SECRET = WIFIAPSTA_EEPROM_START + 23;

/// Station status: empty ssid or password
static const unsigned char WIFIAPSTA_STATUS_EMPTY = 16;

/// Station status: SSID & password saved
static const unsigned char WIFIAPSTA_STATUS_SAVED = 24;


//
//  ESP8266WiFiAPSta structure class
//

class ESP8266WiFiAPSta {
  private:
    unsigned char staStatus;
    char staSsid[20];
    char staSecret[20];
  
    void initEEPROM();
    void initWiFi();
    void initWebServer();
    
  public:
    ESP8266WiFiAPSta();
    void handleClient();
    void init();
};

#endif