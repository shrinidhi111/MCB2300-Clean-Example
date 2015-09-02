#include <LPC23xx.h>

#include "button.h"

void button_init(void){
	FIO2DIR = (0 << 10);      //Set bit 10 to 0 (to make it an input)
	PINSEL10 = 0;
}
