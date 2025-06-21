#pragma once

// Hardware Configuration
const uint8_t STEP_PIN = 14;
const uint8_t DIR_PIN = 27;
const uint8_t EN_PIN = 26;
const uint8_t TOUCH_PIN = 13;
const uint8_t MODE_BUTTON_PIN = 2;
const uint8_t LED_PIN = 5;
const uint8_t SDA_PIN = 21;
const uint8_t SCL_PIN = 22;
const uint8_t UART_TX = 16;
const uint8_t UART_RX = 17;

// Stepper Parameters
const uint16_t MAX_SPEED = 1200;    // steps/s
const uint16_t ACCEL = 800;         // steps/s^2
const int32_t MOVE_DISTANCE = 300;  // steps

// Sensor Thresholds
const uint16_t DETECT_DISTANCE = 80;   // mm
const uint16_t TOUCH_THRESHOLD = 25;   // lower = more sensitive

// Operation Modes
enum OperationMode { 
  MODE_ANNOYING, 
  MODE_NORMAL 
};
