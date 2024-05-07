#include <INT0.h>

void init_INT0() {
  // Configure LED pins as output
  DDRD|= (1<<RED) | (1<<GREEN) | (1<<BLUE);

  // Configure button pin as input with pull-up resistor
  DDRD &= ~(1 << BUTTON_PIN);
  PORTD |= (1 << BUTTON_PIN);

  // Enable external interrupt on INT0
  EICRA |= (1 << ISC00);   // Any logical change on INT0 generates an interrupt request
  EIMSK |= (1 << INT0);    // Enable INT0 interrupt

  // Enable global INT0
  sei();
}


