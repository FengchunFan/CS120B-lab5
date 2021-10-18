/*     Author: ffan005
 *  Partner(s) Name:
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Initial, Press, Increment, Decrement, Reset, temp1, temp2} state;

void Tick(){
  
  unsigned char temp = ~PINA & 0x03;
  switch(state){
    case Start:
      state = Initial;
      break;
      
    case Initial:
      state = Press;
      
    case Press:
      if(temp == 0x03){
        state = Reset;
      } else if (temp == 0x02){
        state = temp2;
      } else if (temp == 0x01){
        state = temp1;
      }
     break;
        
    case Increment:
      if(temp == 0x01){
        state = Increment;
      } else {
        state = Press;
      }
     break;
      
    case Decrement:
      if(temp == 0x02){
        state = Decrement;
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
      if(temp == 0x03){
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
