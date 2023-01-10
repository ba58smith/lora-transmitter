#ifndef _CONFIG_H_
#define _CONFIG_H_

// Un-comment only one of the following units, to set all the configuration variables
// for that unit (defined below). If you change this, the first upload to the transmitter
// must be with //#define LORA_SETUP_REQUIRED in main.cpp UN-commented. Upload it, it will
// write the LORA_NODE_ADDRESS to EEPROM, then RE-comment that line, and upload again.
//#define BESSIE
//#define GARDEN
#define BOAT

// Network must be the same (2) for all of my units to communicate w/ each other.
// After re-writing the receiver code, this will change to some other unique identifier.
#define LORA_NETWORK_ID 14

// Used to set the recipient address for all LoRa transmissions.
// My base station's address is 2200. Valid transmitter addresses are 2201-2240.
#define LORA_BASE_STATION_ADDRESS 2200UL

// Un-comment and change the baud rate below to change it.
// #define LORA_BAUD_RATE 115200ULL     // default 115200

// Configure each of the variables below for each transmitter

#ifdef BESSIE
String TRANSMITTER_NAME = "Bessie";
#define TIME_TO_SLEEP 890 // 890 seconds == 14 minutes and 50 seconds
#define LORA_NODE_ADDRESS 2201UL
// Measured values of the two voltage divider resistors
#define R1_VALUE 9400.0
#define R2_VALUE 2144.0
// This will be different for each transmitter device, and must be calculated from actual
// measurements taken of the source voltage, to get the final voltage correct. Calibrate
// at 12.60 for known input voltage.
#define VOLTAGE_CALIBRATION 1.038

#define LOW_VOLTAGE_ALARM_VALUE 12.20
#define LOW_VOLTAGE_ALARM_CODE 1
#define LOW_VOLTAGE_EMAIL_INTERVAL 90 // In MINUTES
#define LOW_VOLTAGE_ALARM_MAX_EMAILS 5

#define HIGH_VOLTAGE_ALARM_VALUE 14.00
#define HIGH_VOLTAGE_ALARM_CODE 3
#define HIGH_VOLTAGE_EMAIL_INTERVAL 15 // In MINUTES, not seconds
#define HIGH_VOLTAGE_ALARM_MAX_EMAILS 7

#endif

#ifdef GARDEN
String TRANSMITTER_NAME = "Garden";
#define TIME_TO_SLEEP 900 // In seconds
#define LORA_NODE_ADDRESS 2202UL
#define R1_VALUE 9500.0
#define R2_VALUE 2145.0
#define VOLTAGE_CALIBRATION 1.0144

#define LOW_VOLTAGE_ALARM_VALUE 13.00 // "12V" LiFeO4 battery
#define LOW_VOLTAGE_ALARM_CODE 1
#define LOW_VOLTAGE_EMAIL_INTERVAL 90 // In MINUTES
#define LOW_VOLTAGE_ALARM_MAX_EMAILS 5

#define HIGH_VOLTAGE_ALARM_VALUE 14.60
#define HIGH_VOLTAGE_ALARM_CODE 3
#define HIGH_VOLTAGE_EMAIL_INTERVAL 15 // In MINUTES, not seconds
#define HIGH_VOLTAGE_ALARM_MAX_EMAILS 7
#endif

#ifdef BOAT
String TRANSMITTER_NAME = "Boat";
#define TIME_TO_SLEEP 880 // 880 seconds == 14 minutes and 40 seconds
#define LORA_NODE_ADDRESS 2203UL
#define R1_VALUE 9480.0
#define R2_VALUE 2158.0
#define VOLTAGE_CALIBRATION 1.020

#define LOW_VOLTAGE_ALARM_VALUE 12.20
#define LOW_VOLTAGE_ALARM_CODE 1
#define LOW_VOLTAGE_EMAIL_INTERVAL 90 // In MINUTES
#define LOW_VOLTAGE_ALARM_MAX_EMAILS 5

#define HIGH_VOLTAGE_ALARM_VALUE 14.35 // 14.40 is max recommended charge voltage for AGM batteries
                                       // https://cloreautomotive.com/agm-batteries-what-you-need-to-know/
#define HIGH_VOLTAGE_ALARM_CODE 3
#define HIGH_VOLTAGE_EMAIL_INTERVAL 15 // In MINUTES, not seconds
#define HIGH_VOLTAGE_ALARM_MAX_EMAILS 7
#endif

#endif // #ifndef _CONFIG_H_
