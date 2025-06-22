#include "config.h"
#include "motor_controller.h"
#include "sensor_manager.h"
#include "mode_manager.h"
#include "utilities.h"

MotorController motor;
SensorManager sensors;
ModeManager mode;

void setup() {
  Serial.begin(115200);
  initGPIO();
  motor.begin();
  sensors.begin();
  
  Serial.println("\nNimbleLamp Advance v1.0");
  Serial.println("======================");
}

void loop() {
  mode.checkToggle();
  
  if(sensors.touchDetected()) {
    mode.toggleMode();
  }
  
  if(sensors.handDetected()) {
    if(mode.currentMode == MODE_ANNOYING) {
      motor.triggerEscape();
    } else {
      digitalWrite(LED_PIN, LOW);
      delay(1000);
      mode.updateLED();
    }
  }
  
  printStatus();
  delay(10);
}
