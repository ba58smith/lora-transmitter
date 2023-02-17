// Use board "wemos lolin32"

#include <Arduino.h>
#include "functions.h"
#include "reyax_lora.h"
#include "analog_reader.h"
#include "config.h"

#define uS_TO_S_FACTOR 1000000ULL  // Conversion factor for micro seconds to seconds

/**
 * Before building, look at all of the #define options in config.h. At the very least,
 * make sure you un-comment the correct #define for the name of the transmitter that this code is
 * going to be used for.
 * 
 * If you change the #defined transmitter or the NETWORK_ID (in config.h):
 * Un-comment "#define LORA_SETUP_REQUIRED" below, upload and run once, then comment out "#define LORA_SETUP_REQUIRED".
 * That will prevent writing the NETWORK_ID and NODE_ADDRESS to EEPROM every run.
 */
//#define LORA_SETUP_REQUIRED

// Used to power the LoRa radio on and off.
uint8_t lora_pin = 15;

uint8_t voltage_measurement_pin = 32;

ReyaxLoRa lora(lora_pin);

VoltageSensor voltage_sensor(voltage_measurement_pin);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  // For Serial Monitor display of debug messages
  Serial.begin(115200);

  lora.initialize();

#ifdef LORA_SETUP_REQUIRED
  lora.one_time_setup();
#endif

  // Add the appropriate "set" method(s) here to change most of
  // the LoRa parameters, if desired. If you do, use the appropriate 
  // AT command to display the result of the change, to make sure it changed. 
  // EXAMPLE: lora->set_output_power(10);
  //          lora->send_and_reply("AT+CRFOP?");

  // Read the battery voltage and send it to the base station
  lora.send_data(voltage_sensor.reported_voltage());
  
  // Don't turn it off too soon
  delay(2000);
 
  // Turn off the LoRa to save battery
  lora.turn_off();
  
  // BAS: replace all of this with the new "hibernate()"" code in lora-pool-transmitter
  // Get ready to "hibernate"
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  prepare_hibernation();
  esp_deep_sleep_start();
  
} // setup()

void loop() {} // does nothing
