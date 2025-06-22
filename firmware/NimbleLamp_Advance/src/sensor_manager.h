#pragma once
#include <Wire.h>
#include <VL53L0X.h>
#include "config.h"

class SensorManager {
public:
  void begin() {
    Wire.begin(SDA_PIN, SCL_PIN);
    if(!distanceSensor.begin()) {
      Serial.println("VL53L0X init failed!");
      while(1);
    }
    distanceSensor.startContinuous();
  }

  bool handDetected() {
    uint16_t dist = distanceSensor.readRangeContinuousMillimeters();
    return (dist > 0 && dist < DETECT_DISTANCE);
  }

  bool touchDetected() {
    static uint32_t last_touch = 0;
    uint16_t touch_value = touchRead(TOUCH_PIN);
    
    if(touch_value < TOUCH_THRESHOLD) {
      if(millis() - last_touch > 500) {
        last_touch = millis();
        return true;
      }
    }
    return false;
  }

private:
  VL53L0X distanceSensor;
};
