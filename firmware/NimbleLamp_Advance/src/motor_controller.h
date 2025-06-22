#pragma once
#include <TMCStepper.h>
#include "config.h"

#define DRIVER_ADDRESS 0b00 // TMC2209 Address
TMC2209Stepper driver(&Serial2, DRIVER_ADDRESS);

class MotorController {
public:
  void begin() {
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, LOW);
    
    Serial2.begin(115200, SERIAL_8N1, UART_RX, UART_TX);
    
    driver.begin();
    driver.toff(4);
    driver.blank_time(24);
    driver.rms_current(800);
    driver.microsteps(16);
    driver.pwm_autoscale(true);
  }

  void move(int32_t steps) {
    digitalWrite(DIR_PIN, steps > 0 ? HIGH : LOW);
    uint32_t steps_abs = abs(steps);
    uint32_t delay_time = 500000 / MAX_SPEED;
    
    for(uint32_t i = 0; i < steps_abs; i++) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(delay_time);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(delay_time);
    }
  }

  void triggerEscape() {
    move(MOVE_DISTANCE);
    delay(150);
    move(-MOVE_DISTANCE);
  }
};
