#pragma once
#include <Arduino.h>

// Defines Variables
#define RS DDB1 // Register Select is connected to PB4
#define EN DDB0 // Enable pin is connected to PB2

#define P0 PC0 // P0 is connected to PC0
#define P1 PC1 // P0 is connected to PC1
#define P2 PC2 // P0 is connected to PC2
#define P3 PC3 // P0 is connected to PC3

// Functions Prototypes
void delayMs(uint16_t ms);

// initialize the library with the numbers of the interface pins
void LCD_nibble_write(uint8_t data, uint8_t control);
void LCD_command(uint8_t command);
void LCD_data(uint8_t data);
void LCD_init(void);
void PORTS_init(void);
void LCD_string(char *str);