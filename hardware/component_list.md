# NimbleLamp Advance - Component List  
**Version:** 1.0  
**Project Type:** ESP32 + Stepper Motor System  

## Core Electronics  
| Component | Specs | Qty | Notes |  
|-----------|-------|-----|-------|  
| **MCU Board** | ESP32 DevKit v1 | 1 | 38 GPIO, Dual-Core 240MHz |  
| **Stepper Driver** | TMC2209 (UART) | 1 | SilentStepStick form factor |  
| **Stepper Motor** | NEMA 17 (17HS19-2004S) | 1 | 1.2A, 0.4N·m torque |  
| **Distance Sensor** | VL53L0X Time-of-Flight | 1 | Range: 30-2000mm |  
| **Power Supply** | 12V 3A DC | 1 | For motors/LEDs |  
| **Buck Converter** | LM2596S | 1 | 12V→5V for logic |  

## Input/Output  
| Component | Specs | Qty | Notes |  
|-----------|-------|-----|-------|  
| Tactile Button | 6×6mm THT | 1 | Mode toggle |  
| MOSFET | IRLB8721 | 1 | For LED control |  
| LED Strip | WS2812B 60LED/m | 1 | 12V addressable |  
| Capacitor | 100µF 25V | 2 | Motor noise filtering |  

## Connectivity  
| Component | Specs | Qty | Notes |  
|-----------|-------|-----|-------|  
| JST Connectors | 2-4 pin | 6 | Motor/sensor wiring |  
| Terminal Block | 5.08mm pitch | 2 | Power input |  
| Dupont Wires | M-M, M-F, F-F | 20 | Prototyping |  

## Mechanical/Housing  
| Component | Specs | Qty | Notes |  
|-----------|-------|-----|-------|  
| Timing Belt | GT2 6mm width | 1m | Motion transfer |  
| Pulley | GT2 20T 5mm bore | 2 | For NEMA 17 |  
| Linear Rail | MGN9H 200mm | 1 | Smooth movement |  
| 3D Printed Parts | PETG/PLA | - | - |  

## Recommended Retailers  
- [Pololu (TMC2209)](https://www.pololu.com/product/3132)  
- [Adafruit (VL53L0X)](https://www.adafruit.com/product/3317)  
- [Amazon (NEMA17)](https://amzn.to/3N7j2Bp)  
