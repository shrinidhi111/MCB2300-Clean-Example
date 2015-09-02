/******************************************************************************/
/* IRQ.C: IRQ Handler                                                         */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <LPC23xx.h>                    /* LPC23xx definitions                */
#include <stdbool.h>
#include "IRQ.h"

bool delay_done = false;
unsigned int delay_ms = 0;
int clk_cntr = 0;

void T0_init(void)
{
    /* Enable and setup timer interrupt, start timer */
    T0MR0 = 11999; /* 1msec = 12000-1 at 12.0 MHz */
    T0MCR = 3; /* Interrupt and Reset on MR0 */
    T0TCR = 1; /* Timer0 Enable */
    VICVectAddr4 = (unsigned long)T0_IRQHandler;/* Set Interrupt Vector */
    VICVectCntl4 = 15; /* use it for Timer0 Interrupt */
    VICIntEnable = (1 << 4); /* Enable Timer0 Interrupt */
}

/* Timer0 IRQ: Executed periodically                                          */
__irq void T0_IRQHandler (void)
{
    if (clk_cntr >= delay_ms)
    {
        delay_done = true;
    }
    else
    {
        delay_done = false;
        clk_cntr++;
    }

    T0IR        = 1;                      /* Clear interrupt flag               */
    VICVectAddr = 0;                      /* Acknowledge Interrupt              */
}
