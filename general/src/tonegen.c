//System libraries
#include <LPC23xx.H>
#include <stdbool.h>

//User libraries
#include "timing.h"

/*
 * Function: ToneGen_init
 * Description: Initialises the tone generator
 *
 * Parameters in:  none
 * Parameters out: none
 */
void ToneGen_init(void)
{
    SCS      |= (1 << 0);    //Set the GPIOM bit to enable port 0 and 1
    FIO0DIR  |= (1 << 26);   //Set P0.26 (tonegenerator) as output
}

/*
 * Function: ToneGen_on
 * Description: Apply a HIGH signal to the tone generator
 *
 * Parameters in:  none
 * Parameters out: none
 */
void ToneGen_on (void)
{
    FIO0SET  |= (1 << 26);
}

/*
 * Function: ToneGen_off
 * Description: Apply a LOW signal to the tone generator
 *
 * Parameters in:  none
 * Parameters out: none
 */
void ToneGen_off (void)
{
    FIO0CLR  |= (1 << 26);
}

/*
 * Function: ToneGen
 * Description: Apply a HIGH signal to the tone generator
 *
 * Parameters in:
 *     frequency: The frequency at which the tonegenerator should beep
 *   duration_ms: The duration (in ms) of the beep
 *
 * Parameters out: none
 *
 * Important remark: This function needs improvement. It works until 1kHz and there is a problem with rounding.
 */
void ToneGen(int frequency, int duration_ms)
{
    int i;
    double frequency_in_ms;
    if(frequency > 1000)
    {
        frequency = 1000;                                //Because at this moment, our delay function can't get any lower than 1ms
    }

    frequency_in_ms = (double)1000/(double)frequency;    //Hz to ms

    duration_ms = duration_ms / frequency_in_ms;         //Calculate the duration of the beep
    for (i = 0; i < duration_ms; i++)
    {
        //Rapidly switch the state of the tonegenerator to generate a square wave
        ToneGen_on();
        delay(frequency_in_ms);
        ToneGen_off();
        delay(frequency_in_ms);
    }
}
