#include <stdbool.h>

extern bool delay_done;
extern unsigned int delay_ms;
extern int clk_cntr;

void T0_Init(void);
__irq void T0_IRQHandler (void);
