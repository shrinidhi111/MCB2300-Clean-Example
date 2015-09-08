//System libraries
#include <LPC23xx.H>

/*
 * Function: LED_init
 * Description: Sets the right registers so that the LEDs work.
 *
 * Parameters in:  none
 * Parameters out: none
 */
void LED_init(void)
{
    PINSEL10 = 0;                         /* Disable ETM interface, enable LEDs */
    FIO2DIR  = 0x000000FF;                /* P2.0..7 defined as Outputs         */
    FIO2MASK = 0x00000000;
}

/*
 * Function: LED_on
 * Description: Turns on one LED.
 *
 * Parameters in:
 *    num: the LED number (0 - 7)
 *
 * Parameters out: none
 */
void LED_on (unsigned int num)
{
    FIO2SET = (1 << num);
}

/*
 * Function: LED_off
 * Description: Turns off one LED.
 *
 * Parameters in:
 *    num: the LED number (0 - 7)
 *
 * Parameters out: none
 */
void LED_off (unsigned int num)
{
    FIO2CLR = (1 << num);
}

/*
 * Function: LED_out
 * Description: Reset all LEDs to the provided hexadecimal number
 *
 * Parameters in:
 *    value: LED string (see example) (0x00 - 0xFF)
 *
 * Parameters out: none
 *
 * Example:
 *    LED string: 01010101
 *    In Hex:     0x55
 *    Call LED_out(0x55); to turn every odd led on.
 */
void LED_out(unsigned int value)
{
    FIO2CLR = 0xFF;                       /* Turn off all LEDs                  */
    FIO2SET = (value & 0xFF);             /* Turn on requested LEDs             */
}
