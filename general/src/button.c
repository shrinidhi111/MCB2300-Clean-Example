//System libraries
#include <LPC23xx.h>

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
    FIO2DIR0 = 0xFF;    //Set button pin as input
}
