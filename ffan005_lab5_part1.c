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

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00;

unsigned char tmpA = 0x00;
unsigned char output = 0x00;
    /* Insert your solution below */
    while (1) {
    tmpA = PINA;
    output = 0x00;
    if((tmpA&0x00)==0x00){
output = 0x40;
}
    if(((tmpA&0x01)==0x01) || ((tmpA&0x02)==0x02)){
output = 0x60;
}
    if(((tmpA&0x03)==0x03) || ((tmpA&0x04)==0x04)){
output = 0x70;
}
    if(((tmpA&0x05)==0x05) || ((tmpA&0x06)==0x06)){
output = 0x38;
}
    if(((tmpA&0x07)==0x07) || ((tmpA&0x08)==0x08) || ((tmpA&0x09)==0x09)){
output = 0x3C;
}
    if(((tmpA&0x0A)==0x0A) || ((tmpA&0x0B)==0x0B) || ((tmpA&0x0C)==0x0C)){
output = 0x3E;
}
    if(((tmpA&0x0D)==0x0D) || ((tmpA&0x0E)==0x0E) || ((tmpA&0x0F)==0x0F)){
output = 0x3F;
}

PORTC = output;
    }
    return 1;
}
