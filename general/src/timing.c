//System libraries
#include <LPC23xx.h>
#include <stdbool.h>
#include <stdio.h>

//User libraries
#include "timing.h"

//Global variables
bool delay_done = false;
unsigned int delay_ms = 0;
int clk_cntr = 0;

/*
 * Function: T0_init
 * Description: Enable and setup timer interrupt, start timer 0
 *
 * Parameters in:  none
 * Parameters out: none
 */
void T0_init(void)
{
    T0MR0 = 11999;           //1msec = 12000-1 at 12.0 MHz
    T0MCR = 3;               //Interrupt and Reset on MR0
    T0TCR = 1;               //Timer0 Enable
    VICVectAddr4 = (unsigned long)T0_IRQHandler; //Set Interrupt Vector
    VICIntEnable = (1 << 4); //Enable Timer0 Interrupt
}

/*
 * Function: T0_IRQHandler
 * Description: Function that will be executed every millisecond.
 *              This function is only used for the delay function.
 *
 * Parameters in:  none
 * Parameters out: none
 */
__irq void T0_IRQHandler (void)
{
    if (clk_cntr >= delay_ms)        //Check if the counter is bigger than the requested delay
    {
        delay_done = true;           //If so, set the delay_done flag
    }
    else
    {
        delay_done = false;          //If not, unset the delay_done flag
        clk_cntr++;                  //Increment the counter with 1. This happens every ms.
    }

    T0IR        = 1;                 //Clear interrupt flag
    VICVectAddr = 0;                 //Acknowledge Interrupt
}

/*
 * Function: delay
 * Description: This function delays the microcontroller
 *
 * Parameters in:
 *    millis: The amount of milliseconds to delay
 *
 * Parameters out: none
 */
void delay (unsigned int millis)
{
    delay_done = false;     //Unset the delay_done flag
    clk_cntr = 0;           //Reset the counter (which is used in the timer)
    delay_ms = millis;      //Set the amount of milliseconds

    while(!delay_done) {}   //Wait until the delay_done flag is set
}
