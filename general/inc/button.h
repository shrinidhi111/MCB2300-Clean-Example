//System libraries
#include <LPC23xx.h>

//Defines
#define INT0 !(FIO2PIN1 & 0x04)   //Macro to read the button state. The button is active low.

//Function prototypes
void button_init(void);
