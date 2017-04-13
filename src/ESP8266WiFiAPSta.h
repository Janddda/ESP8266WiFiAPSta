/**
 *  @file     ESP8266WiFiAPSta.h
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    Global variables & class structure
 */

#ifndef __ESP8266WIFIAPSTA_H
#define __ESP8266WIFIAPSTA_H

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAPStaConfig.h>


//
//  ESP8266WiFiAPSta structure class
//

class ESP8266WiFiAPSta {
  private:
    void initWiFi();
    void initWebServer();
    
  public:
    ESP8266WiFiAPSta();
    void handleClient();
};

#endif