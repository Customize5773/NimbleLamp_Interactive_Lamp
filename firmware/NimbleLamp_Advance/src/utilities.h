#pragma once
#include "config.h"

void initGPIO() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED_PIN, HIGH);
}

void printStatus() {
  static uint32_t last_print = 0;
  if(millis() - last_print > 2000) {
    Serial.printf("Mode: %s | Mem: %d\n", 
                 ModeManager.currentMode == MODE_ANNOYING ? "Annoying" : "Normal",
                 ESP.getFreeHeap());
    last_print = millis();
  }
}
