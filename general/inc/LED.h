#define    LED0       0x01
#define    LED1       0x02
#define    LED2       0x04
#define    LED3       0x08
#define    LED4       0x10
#define    LED5       0x20
#define    LED6       0x40
#define    LED7       0x80

#define    LED_ALL    LED0 | LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7
#define    LED_NONE   0x00

void LED_Init (void);
void LED_On (unsigned int num);
void LED_Off (unsigned int num);
void LED_Out (unsigned int value);
