#include <stdio.h>
#include <LPC23xx.H>
#include "LED.h"
#include "timing.h"

int main(void)
{
    LED_Init();
    while(1)
    {
        LED_Out(0xFF);
        delay(1000);
        LED_Out(0x00);
        delay(1000);
    }
}
