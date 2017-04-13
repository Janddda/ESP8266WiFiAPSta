/**
 *  @file     ESP8266WiFiAPSta.ino
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    Demo with the AP+Sta mode on ESP8266 & Web server config
 */

#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAPSta.h>

ESP8266WiFiAPSta WiFiAPSta;

/**
 *  
 */
void setup() {
  
}

/**
 *  
 */
void loop() {
  WiFiAPSta.handleClient();
}
