#include <LPC23xx.h>

#include "button.h"

void button_init(void)
{
    PINSEL10 = 0; // Disable ETM interface, enable LEDs
    FIO2DIR0 = 0xFF;
    PINMODE4 = 0x0020AAAA;
}
