# NimbleLamp Advance Firmware

## Fitur Utama

- **Driver Motor Cerdas**
  - Konfigurasi TMC2209 via UART
  - Microstepping 1/16 untuk gerakan halus
  - Proteksi termal & under-voltage

- **Multi-Sensing Terintegrasi**
  - Time-of-Flight sensor (VL53L0X) untuk deteksi presisi
  - Touch sensor kapasitif (built-in ESP32)
  - Tombol fisik sebagai fail-safe

- **Manajemen Mode**
  - Sistem toggle mode dengan debouncing
  - Indikator LED visual
  - Touch sensor sebagai alternatif kontrol

- **Optimasi ESP32**
  - Manajemen memori
  - Pemantauan heap secara real-time
  - Efisiensi daya

## Wiring Diagram

| Komponen       | ESP32 Pin   |
| -------------- | ----------- |
| TMC2209 STEP   | GPIO14      |
| TMC2209 DIR    | GPIO27      |
| TMC2209 EN     | GPIO26      |
| TMC2209 UART   | GPIO16/17   |
| VL53L0X SDA    | GPIO21      |
| VL53L0X SCL    | GPIO22      |
| Touch Sensor   | GPIO13      |
| Mode Button    | GPIO2       |
| LED Control    | GPIO5       |

## Instalasi

### Install Library

```bash
pio lib install "adafruit/Adafruit VL53L0X"
pio lib install "teemuatlut/TMCStepper"
```
### Sensor Calibration
```cpp
// Add in setup()
Serial.println("Calibrating...");
delay(1000);
uint16_t base_touch = touchRead(TOUCH_PIN);
Serial.printf("Base touch: %d\n", base_touch);
```
## Repair Notes

### Physical Mechanisms
- Use belt drives or gears for motion transfer
- Add limit switch for homing position

### Faster Motor Response
```cpp
// Di motor_controller.h
const uint16_t ACCEL_STEPS = 50;

void move(int32_t steps) {
  // ... previous code
  for(uint32_t i = 0; i < steps_abs; i++) {
    if(i < ACCEL_STEPS) 
      delay_time = 500000 / (MAX_SPEED * (i / float(ACCEL_STEPS)));
  }
}
```

### Power Saving
```cpp
void sleep() {
  digitalWrite(EN_PIN, HIGH);
  driver.toff(0);
}
```
