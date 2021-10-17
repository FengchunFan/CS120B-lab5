
/*     Author: ffan005
 *  Partner(s) Name:
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
//After continuly failing half of the tests, I got some help from the TA


#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Initial, Press, Increment, Decrement, Reset, temp1, temp2} state;

void Tick(){
  switch(state){
    case Start:
      state = Initial;
      break;
      
    case Initial:
      state = Press;
      break;
      
    case Press:
      if((~PINA & 0x03) == 0x01){
        state = temp1;
      } else if ((~PINA & 0x03) == 0x02){
        state = temp2;
      } else if ((~PINA & 0x03) == 0x03){
        state = Reset;
      }
     break;
        
    case Increment:
      if((~PINA & 0x03) == 0x01){
        state = temp1;
      } else {
        state = Press;
      }
     break;
      
    case Decrement:
      if((~PINA & 0x03) == 0x02){
        state = temp2;
      } else {
        state = Press;
      }
     break;
      
    case temp1:
      state = Increment;
      break;
      
    case temp2:
      state = Decrement;
      break;
      
    case Reset:
      if((~PINA & 0x03) == 0x03){
        state = Reset;
      } else {
        state = Press;
      }
     break;
      
    default:
      state = Start;
      break;
  }
  
  switch(state){
    case Start:
      PORTC = 0x07;
      break;
      
    case Initial:
      PORTC = 0x07;
      break;
      
    case Press:
      break;
      
    case Increment:
      break;
    
    case Decrement:
      break;
      
    case temp1:
      if(PORTC < 0x09){
        PORTC = PORTC + 1;
      }
      break;
      
    case temp2:
      if(PORTC > 0x00){
        PORTC = PORTC - 1;
      }
     break;
      
    case Reset:
      PORTC = 0x00;
      break;
      
    default:
      PORTC = 0x07;
      break;
  }
}

int main(void){
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00;
  while (1) {
Tick();
}
  return 1;
}
