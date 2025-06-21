#include <Wire.h>
#include <VL53L0X.h>
#include <Servo.h>

// Pin definitions
#define SERVO_PIN 9
#define BUTTON_PIN 2
#define LED_PIN 5

// Settings
const int DETECTION_RANGE_MM = 100;
const int SERVO_ESCAPE_ANGLE = 180;
const int SERVO_HOME_ANGLE = 90;
const unsigned long DEBOUNCE_DELAY = 50;

// Global variables
VL53L0X distanceSensor;
Servo lampServo;

bool annoyingMode = true;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize components
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  lampServo.attach(SERVO_PIN);
  lampServo.write(SERVO_HOME_ANGLE);
  
  Wire.begin();
  
  if (!distanceSensor.init()) {
    Serial.println("Sensor error!");
    while (1);
  }
  
  distanceSensor.setTimeout(500);
  distanceSensor.startContinuous();
}

void loop() {
  handleButton();
  handleDistanceSensor();
}

void handleButton() {
  int reading = digitalRead(BUTTON_PIN);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading == LOW) {
      annoyingMode = !annoyingMode;
      delay(300); // Prevent rapid toggling
    }
  }
  
  lastButtonState = reading;
}

void handleDistanceSensor() {
  int distance = distanceSensor.readRangeContinuousMillimeters();
  
  if (distanceSensor.timeoutOccurred()) {
    return;
  }

  if (distance < DETECTION_RANGE_MM) {
    if (annoyingMode) {
      triggerEscape();
    } else {
      digitalWrite(LED_PIN, LOW);
      delay(1000);
    }
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
}

void triggerEscape() {
  lampServo.write(SERVO_ESCAPE_ANGLE);
  delay(500);
  lampServo.write(SERVO_HOME_ANGLE);
}
