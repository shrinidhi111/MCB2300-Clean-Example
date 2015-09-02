#include "IRQ.h"

void delay (unsigned int millis)
{
    delay_done = false;
    clk_cntr = 0;
    delay_ms = millis;

    while(!delay_done) {}
}
