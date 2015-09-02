#include <LPC23xx.h>

#define INT0 !(FIO2PIN1 & 0x04)

void button_init(void);
