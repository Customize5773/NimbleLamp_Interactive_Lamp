# Circuit Architecture - Signal Flow  

```mermaid  
flowchart TD  
    PSU[12V Power Supply] --> BUCK[LM2596 Buck Converter]  
    BUCK -->|5V| ESP32[ESP32 Dev Board]  
    BUCK -->|5V| TMC2209[Stepper Driver]  
    
    subgraph Motor Control  
        TMC2209 -->|STEP| ESP32_GPIO14  
        TMC2209 -->|DIR| ESP32_GPIO27  
        TMC2209 -->|EN| ESP32_GPIO26  
        TMC2209 --> MOTOR[NEMA17 Stepper]  
    end  

    subgraph Sensing  
        ESP32_GPIO21 -->|SDA| VL53L0X[Distance Sensor]  
        ESP32_GPIO22 -->|SCL| VL53L0X  
        ESP32_GPIO13 --> TOUCH[Capacitive Pad]  
        ESP32_GPIO2 --> BUTTON[Mode Switch]  
    end  

    subgraph Lighting  
        ESP32_GPIO5 --> MOSFET[IRLB8721 Gate]  
        MOSFET -->|Drain| LED_STRIP[12V LED Strip]  
    end  

    subgraph Power Management  
        PSU -->|12V| VMOT[TMC2209 VMOT]  
        PSU -->|12V| VLED[LED Strip +12V]  
        CAP[100µF Cap] -->|Across| VMOT_GND  
    end
```

## Key Connection Details  

### Power Distribution  
```  
12V Input  
├── Buck Converter (12V→5V)  
│   ├── ESP32 Vin  
│   ├── TMC2209 VIO  
│   └── VL53L0X VCC  
├── TMC2209 VMOT (with 100µF cap)  
└── LED Strip +12V  
```  

### GPIO Mapping  
| Function | ESP32 Pin | Connected To |  
|----------|-----------|-------------|  
| Stepper STEP | GPIO14 | TMC2209 STEP |  
| Stepper DIR | GPIO27 | TMC2209 DIR |  
| Stepper ENABLE | GPIO26 | TMC2209 EN |  
| I²C SDA | GPIO21 | VL53L0X SDA |  
| I²C SCL | GPIO22 | VL53L0X SCL |  
| Touch Sensor | GPIO13 | Copper Pad |  
| Mode Button | GPIO2 | Tactile Switch |  
| LED Control | GPIO5 | MOSFET Gate |  

### Protection Measures  
1. **Motor Noise Suppression:**  
   - 100µF electrolytic capacitor between VMOT and GND  
   - 0.1µF ceramic capacitor across motor coils  
2. **Logic Level Safety:**  
   - 330Ω resistor on all ESP32 signal lines  
   - TVS diodes on I²C lines  
3. **ESD Protection:**  
   - 1MΩ resistor on touch sensor line  

## Design Notes  
- Keep motor power wiring separate from logic signals  
- Use twisted pairs for stepper motor connections  
- Maintain <5cm wire length for VL53L0X I²C lines  
- MOSFET requires heatsink for >1A LED loads

## Wiring

![Wiring](https://github.com/user-attachments/assets/a88b62b1-997f-49d0-9da5-b5811551ef9d)
