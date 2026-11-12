#include <lpc214x.h>

void delay()
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

// External Interrupt Service Routine
void EXT0_ISR(void) __irq
{
    IO0PIN ^= (1 << 10);  // Toggle LED

    EXTINT = 0x01;        // Clear interrupt flag

    VICVectAddr = 0x00;   // End of interrupt
}

int main()
{
    // Configure LED
    IO0DIR |= (1 << 10);

    // Configure P0.1 as EINT0
    PINSEL0 |= 0x0000000C;

    // Trigger interrupt on falling edge
    EXTMODE = 0x01;
    EXTPOLAR = 0x00;

    // Clear pending interrupt
    EXTINT = 0x01;

    // Enable EINT0 in VIC
    VICIntSelect &= ~(1 << 14);
    VICIntEnable |= (1 << 14);

    // Assign ISR to EINT0
    VICVectCntl0 = 0x20 | 14;
    VICVectAddr0 = (unsigned long)EXT0_ISR;

    while(1)
    {
        // Main program runs continuously
    }
}