#include <LPC23xx.H>
#include <stdbool.h>

#include "timing.h"

void ToneGen_init(void)
{
    SCS |= (1 << 0);
    FIO0DIR  |= (1 << 26);
    FIO0MASK = 0x00000000;
}

void ToneGen_on (void)
{
    FIO0SET |= (1 << 26);
}

void ToneGen_off (void)
{
    FIO0CLR |= (1 << 26);
}

/*
 * Please note, at this moment a frequency of 700 is the samen as 1000 due to rounding of the var frequency_in_ms in delay
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

    duration_ms = duration_ms / frequency_in_ms;         //We have a millisecond twice
    for (i = 0; i < duration_ms; i++)
    {
        ToneGen_on();
        delay(frequency_in_ms);
        ToneGen_off();
        delay(frequency_in_ms);
    }
}
