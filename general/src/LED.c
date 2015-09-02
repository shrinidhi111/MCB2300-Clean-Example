#include <LPC23xx.H>

/* Function that initializes LEDs                                             */
void LED_init(void)
{
    PINSEL10 = 0;                         /* Disable ETM interface, enable LEDs */
    FIO2DIR  = 0x000000FF;                /* P2.0..7 defined as Outputs         */
    FIO2MASK = 0x00000000;
}

/* Function that turns on requested LED                                       */
void LED_on (unsigned int num)
{
    FIO2SET = (1 << num);
}

/* Function that turns off requested LED                                      */
void LED_off (unsigned int num)
{
    FIO2CLR = (1 << num);
}

/* Function that outputs value to LEDs                                        */
void LED_out(unsigned int value)
{
    FIO2CLR = 0xFF;                       /* Turn off all LEDs                  */
    FIO2SET = (value & 0xFF);             /* Turn on requested LEDs             */
}
