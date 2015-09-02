/*
 * This clean example program is made by Lars Jansen
 * GitHub repository: https://github.com/Lars-/MCB2300-Clean-Example
 */

//System files
#include <stdio.h>
#include <LPC23xx.H>

//User files
#include "program.h"
#include "LCD.h"
#include "LED.h"
#include "IRQ.h"
#include "timing.h"

int main(void)
{
    //Variables
    unsigned int i = 0;	             //Start counter i at 0
    char counter[7];                 //Make a char array to display the counter on the screen later

    //Initialisation
    lcd_init();                      //Initialise the LCD screen
    lcd_clear();                     //Clear the LCD screen
    lcd_print("Counter: 0000000");   //Print init text to the screen

    LED_Init();                      //Initialise the LEDs

    T0_Init();

    //Do forever
    while(1)
    {
        LED_Out(LED_ALL);            //Turn on all LEDs
        delay(500);                 //Wait one second

        LED_Out(LED_NONE);           //Turn on none LEDs (so turn them all off)
        delay(500);                 //Wait one second

        i++;                         //Count i
        set_cursor(9,0);             //Clear is not needed, just overwrite
        sprintf(counter, "%07d", i); //Cast the counter to a 7 char array (lcd_print doesn't support ints)
        lcd_print(counter);          //Print the array

        //Little (and simple) protection for char array overflow
        if(i == 9999999)
        {
            i = 0;
        }
    }
}
