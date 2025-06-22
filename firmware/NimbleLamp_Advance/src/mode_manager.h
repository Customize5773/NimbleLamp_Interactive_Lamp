#pragma once
#include "config.h"

class ModeManager {
public:
  OperationMode currentMode = MODE_ANNOYING;

  void checkToggle() {
    // Button press detection
    if(digitalRead(MODE_BUTTON_PIN) == LOW) {
      if(millis() - last_toggle > 300) {
        toggleMode();
      }
    }
  }

  void toggleMode() {
    currentMode = (currentMode == MODE_ANNOYING) ? MODE_NORMAL : MODE_ANNOYING;
    last_toggle = millis();
    updateLED();
  }

  void updateLED() {
    digitalWrite(LED_PIN, (currentMode == MODE_ANNOYING) ? HIGH : LOW);
  }

private:
  uint32_t last_toggle = 0;
};
