//System libraries
#include <LPC23xx.h>

//Just for this example
#include "timing.h"

//Defines
#include "button.h"

/*
 * Function: button_init
 * Description: Sets the right registers so that the INT0 button works.
 *
 * Parameters in:  none
 * Parameters out: none
 */
void button_init(void)
{
    FIO2DIR1 &= ~(1 << 2);   //Set button pin as input
}

/*
 * Function: EINT0_ISR
 * Description: This function will be called when the button is pressed while
 *              configured as interrupt
 *
 * Parameters in:  none
 * Parameters out: none
 */
__irq void EINT0_ISR(void)   // interrupt service routine
{
    //Place your code here
		FIO2PIN0=0xF0;

    EXTINT |= (1 << 0);     // clears EINT0 interrupt flag
    VICVectAddr = 0;        // Update interrupt priority hardware
};

/*
 * Function: button_as_interrupt
 * Description: This function configures the button as interrupt
 *
 * Parameters in:
 *      priority: value from 0 to 15. 0 is the highest priority.
 *
 * Parameters out: none
 */
void button_as_interrupt(unsigned char priority)
{
    if(priority > 15)
    {
        priority = 15;
    }

    FIO2DIR1 &= ~(1 << 2);                     //Set button pin as input
    PINSEL4  |=  (1 << 20);                    //Set button function as EINT0
    PINSEL4  &= ~(1 << 21);
    EXTMODE  |=  (1 << 0);                     //Select egde-sensitive EINT0
    EXTPOLAR &= ~(1 << 0);                     //Set on falling edge
    EXTINT   |=   0x01;                        //Clears EINT0 interrupt flag
    VICVectPriority14 = priority;              //Set the desired priority
    VICIntEnable  |= (1 << 14);                //Enable interrupt source 14 (EINT0)
    VICVectAddr14 = (unsigned long) EINT0_ISR; //Address of Interrupt Service Routine
}