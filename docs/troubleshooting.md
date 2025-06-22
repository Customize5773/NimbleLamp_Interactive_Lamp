# Common Problem Solutions

## Motor Doesn't Move
**Symptoms**:
- Stepper vibrates but does not rotate
- Buzzing sound from the driver

**Fixes**:
1. Check the motor connections:
- Wiring sequence: A+, A-, B+, B-
- Use multimeter for continuity
2. Set the driver current:
  
```cpp
driver.rms_current(800); // In mA
```
3. Make sure the EN pin is active LOW


## VL53L0X Sensor Error
**Symptoms**:
- Distance reading = 0 or 8190
- "Sensor timeout" message


**Fix**:
1. Check the I²C wiring:
- SDA → GPIO21
- SCL → GPIO22
- VCC → 5V
2. Add a 4.7kΩ pull-up resistor
3. Change the I²C address if necessary:
```cpp
distanceSensor.setAddress(0x30);
```

## Unresponsive Touch Sensor
**Symptoms**:
- Touch is not detected
- False positive


**Calibration**:
1. Read the baseline value:
```ino
Serial.println(touchRead(13));
```
2. Set the threshold in config.h:
```cpp
const uint16_t TOUCH_THRESHOLD = 25; // Lower for more sensitivity
```

## 4. ESP32 Restarts on Its Own
**Symptom**:
- MCU reset while motor is on
- Random crashes
- Motor vibration solution
