#pragma once


#define CLIENT_SSID ""
#define CLIENT_PASS ""

//*USE PACKAGE.JSON TO CHANGE VERSION NUMBER, wled.h line 272 WLED_CODENAME for WLED version*/

#define WLED_DISABLE_IR

#define USERMOD_BATTERY_12V_TOTAL_CAPACITY 80000  // For an 80Ah battery (80000mAh)
#define USERMOD_BATTERY_MEASUREMENT_PIN 3

//#define MAX_LEDS 1500       // Maximum total LEDs. More than 1500 might create a low memory situation on ESP8266.
#define MDNS_NAME "engine"    // mDNS hostname, ie: *.local

//VERSION UPDATES:
//1.03-6
//SETTINGS: commented out 2D config and time and macros button
//added contact BLS warning on settings and security updates page
//enabled usermod_battery in plaformio_override.ini
//updated static ip
