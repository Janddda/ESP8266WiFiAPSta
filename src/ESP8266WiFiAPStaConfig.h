/**
 *  @file     ESP8266WiFiAPStaConfig.h
 *  @version  0.1
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    Some user parameters
 *  @details  Please define your parameters before including this library
 */

#ifndef __ESP8266WIFIAPSTACONFIG_H
#define __ESP8266WIFIAPSTACONFIG_H

#ifndef _WIFIAPSTA_AP_SSID
#define _WIFIAPSTA_AP_SSID
/// Default access point SSID
static const char *WIFIAPSTA_AP_SSID = "ESP8266WiFiAPSta";
#endif

#ifndef _WIFIAPSTA_AP_SECRET
#define _WIFIAPSTA_AP_SECRET
/// Default access point password
static const char *WIFIAPSTA_AP_SECRET = "I<3C0ff33!";
#endif

#ifndef _WIFIAPSTA_AP_CHANNEL
#define _WIFIAPSTA_AP_CHANNEL
/// Default access point channel
static const unsigned char WIFIAPSTA_AP_CHANNEL = 4;
#endif

#ifndef _WIFIAPSTA_AP_HIDDEN
#define _WIFIAPSTA_AP_HIDDEN
/// Hide access point SSID
static const unsigned char WIFIAPSTA_AP_HIDDEN = 0;
#endif

#ifndef _WIFIAPSTA_WEB_PORT
#define _WIFIAPSTA_WEB_PORT
/// Default port for the web server
static const unsigned int WIFIAPSTA_WEB_PORT = 9999;
#endif

#endif