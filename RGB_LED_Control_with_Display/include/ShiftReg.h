#pragma once
#include<Arduino.h>

#define LATCH PB3// pins 3 of Arduino for Latch pin of shift register
#define CLOCK PB4// pins 4 of Arduino for clock pin of shift register 
#define DATA PB2   // pins 2 of Arduino for data pin of shift register



void init_shift(byte dataPin, byte clockPin, byte latchPin);

//function to generate a byte from a serial data in shift register
void myShiftOut(byte dataPin, byte clockPin, byte bitOrder, byte val);
