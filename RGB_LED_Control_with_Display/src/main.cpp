/*
Oreoluwa Adegbesan
NET 3001 Final Project
*/

#include <Arduino.h>
#include <avr_debugger.h>
#include <LCD.h>
#include <USART.h>
#include <PWM.h>
#include <INT0.h>
#include"Segment.h"
#include"ShiftReg.h"

#define BUZZER_PIN 7


char text[MAX_TEXT];
uint8_t R, G, B;
void set_RGB(void);


byte digits[ARRAY_SIZE_DECIMAL] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 }; 

		
int main()
{
    #ifdef __DEBUG__
      dbg_start();
    #endif
    
    
	// initialize USART/LCD controller
  	USART_init();
	LCD_init();

    //initialize interrupt
    init_INT0();

    //initialize PWM on Timer0 and Timer2
	PWM_init();

    init_shift(DATA,CLOCK,LATCH);
	memset(text, 0, MAX_TEXT);	
	DDRD |= 1<< BUZZER_PIN; // setting buzzer to output

    while(1)
    {
        //count from 0 to 9 on 7 segment display
        for(int i=0; i<ARRAY_SIZE_DECIMAL; i++)
        {
        displyValue(digits[i]);
        _delay_ms(500);
        }
        //Turn on buzzer to signal user to enter RGB values
        PORTD |= 1<<BUZZER_PIN;
        _delay_ms(500);
        PORTD &= ~(1<<BUZZER_PIN); //turn off buzzer
        
        set_RGB(); // call set_RGB function
         
        /* Wait 3 seconds then clear screen */
        delayMs(5000);		// Wait 5 seconds
        LCD_command(0x80);  // Move to first line
        LCD_command(1);	 	// Clear screen25
        memset(text, 0, MAX_TEXT);
    }
}

void set_RGB()
{
    memset(text, 0, MAX_TEXT);
    /* Display Prompt*/
    USART_send_string("\nType valid values for R G B color (use space between values): ");
    LCD_string("Current Values: "); // LCD display
    USART_get_string(text);
    // Parse text and generate numeric values for red, green and blue
	// Makes sure the values do not go over 255 or under 0 and checks if the correct number of values have been added
    char *i = strtok(text, " ");
    if (i == NULL) {
        USART_send_string("\nError: no values provided\n");
        return;
    }
    R = atoi(i) % 256;
    i = strtok(NULL, " ");
    if (i == NULL) {
        USART_send_string("\nError: not enough values provided\n");
        return;
    }
    G = atoi(i) % 256;
    i = strtok(NULL, " ");
    if (i == NULL) {
        USART_send_string("\nError: not enough values provided\n");
        return;
    }
    B = atoi(i) % 256;
    i = strtok(NULL, " ");
    if (i != NULL) {
        USART_send_string("\nError: too many values provided\n");
        return;
    }

    // Display RGB values on LCD screen
    sprintf(text, "R%d G%d B%d", R, G, B);
    LCD_command(0xC0); // Move to second line
    LCD_string(text); // display values
}

// Interrupt service routine function
ISR(INT0_vect) {
	setDutyCycle(R, G, B); 
}
