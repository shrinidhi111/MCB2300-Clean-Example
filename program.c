/*
 * This clean example program is made by Lars Jansen
 * GitHub repository: https://github.com/Lars-/MCB2300-Clean-Example
 */

//System files
#include <stdio.h>
#include <LPC23xx.H>

//User files
#include "LCD.h"
#include "LED.h"
#include "timing.h"

int main(void)
{
    //Variables
    unsigned int i = 0;	             //Start counter i at 0
    char counter[7];                 //Make a char array to display the counter on the screen later

    //Initialisation
    lcd_init();                      //Initialise the LCD screen
    lcd_clear();                     //Clear the LCD screen

    LED_Init();                      //Initialise the LEDs

    //Do forever
    while(1)
    {
        LED_Out(LED_ALL);            //Turn on all LEDs
        delay(1000);                 //Wait one second

        LED_Out(LED_NONE);           //Turn on none LEDs (so turn them all off)
        delay(1000);                 //Wait one second

        i++;                         //Count i
        lcd_clear();                 //Clear the LCD
        lcd_print("Counter: ");
        sprintf(counter, "%07d", i); //Cast the counter to a 7 char array (lcd_print doesn't support ints)
        lcd_print(counter);          //Print the array

        //Little (and simple) protection for char array overflow
        if(i == 9999999)
        {
            i = 0;
        }
    }
}
