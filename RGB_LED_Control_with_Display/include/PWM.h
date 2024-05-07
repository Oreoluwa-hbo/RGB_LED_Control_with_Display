#pragma once
#include <Arduino.h>
// define RGB pins
#define RED PD6
#define GREEN PD5
#define BLUE PD3

// declaring functions
void PWM_init(void);
void setDutyCycle(byte dR, byte dG, byte dB);
