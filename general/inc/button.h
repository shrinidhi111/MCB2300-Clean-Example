//System libraries
#include <LPC23xx.h>

//Defines
#define INT0 !(FIO2PIN1 & 0x04)   //Macro to read the button state. The button is active low.

//Function prototypes
void button_init(void);

__irq void EINT0_ISR(void);
void button_as_interrupt(unsigned char priority);
