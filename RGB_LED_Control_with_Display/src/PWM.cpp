#include <PWM.h>

void PWM_init(void)
{
  DDRD|= (1<<RED) | (1<<GREEN) | (1<<BLUE); // set PD5, PD6, and PD3 to output
  TCCR0A = 0b10100011; // set COM0A and COM0B to 10 and WGM to 011
  TCCR0B = 0b00000011; // set the prescalar to 64 
  TCCR2A = 0b00100011; // set COM2B to 10 and WGM to 011
  TCCR2B = 0b00000011; // set the prescaler to 64


}

//set duty cycle for channel A and B
void setDutyCycle(byte R, byte G, byte B)
{
  OCR0A = R;
  OCR0B = G;
  OCR2B = B;
}