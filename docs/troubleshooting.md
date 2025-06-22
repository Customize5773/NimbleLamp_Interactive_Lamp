# Common Issues and Solutions

## 1. Motor Not Moving
**Symptoms**:
- Stepper vibrates but doesn't rotate
- Buzzing sound from driver

**Solutions**:
1. Check motor connections:
   - Wire sequence: A+, A-, B+, B-
   - Use multimeter for continuity test
2. Adjust driver current:
   ```cpp
   driver.rms_current(800); // In mA
   ```
3. Ensure EN pin is set to LOW

## 2. VL53L0X Sensor Error
**Symptoms**:
- Distance reading = 0 or 8190
- "Sensor timeout" message

**Solutions**:
1. Check I²C wiring:
   - SDA → GPIO21
   - SCL → GPIO22
   - VCC → 5V
2. Add 4.7kΩ pull-up resistors
3. Change I²C address if needed:
   ```cpp
   distanceSensor.setAddress(0x30);
   ```

## 3. Touch Sensor Unresponsive
**Symptoms**:
- Touches not detected
- False positives

**Calibration**:
1. Read baseline value:
   ```arduino
   Serial.println(touchRead(13));
   ```
2. Adjust threshold in config.h:
   ```cpp
   const uint16_t TOUCH_THRESHOLD = 25; // Lower for more sensitivity
   ```

## 4. ESP32 Random Restarts
**Symptoms**:
- MCU resets when motor activates
- Random crashes

**Solutions**:
1. Add 1000µF capacitor to buck converter input
2. Separate motor and logic grounds
3. Limit motor current:
   ```cpp
   driver.rms_current(700); // Reduce from default
   ```

## 5. LED Strip Flickering
**Symptoms**:
- Unstable LED lighting
- Inconsistent colors

**Solutions**:
1. Add 330µF capacitor near LED strip
2. Ensure proper ground connection
3. Check MOSFET rating:
   - Use IRLB8721 for >2A loads
   - Add heatsink

## 6. Mechanical Issues
**Common Symptoms**:
- Jerky movement
- Noisy operation

**Solutions**:
1. Lubricate linear rail with grease
2. Adjust GT2 belt tension
3. Calibrate steps/mm:
   ```cpp
   const int32_t MOVE_DISTANCE = 250; // Adjust as needed
   ```
