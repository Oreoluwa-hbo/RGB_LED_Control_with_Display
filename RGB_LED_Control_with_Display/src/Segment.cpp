#include"Segment.h"
#include"ShiftReg.h"


void displyValue(byte value)
{
    //set latch to low
      PORTB&=~(1<<LATCH);
      //shift the data in shift register
      myShiftOut(DATA, CLOCK, LSBFIRST, value);
      //set the latch to high again
      PORTB|=(1<<LATCH);
}
