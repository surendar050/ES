#include <lpc214x.h>

unsigned int i;

unsigned char phase[4] = {
    0x09,
    0x0C,
    0x06,
    0x03
};

void delay()
{
    for(i = 0; i < 50000; i++);
}

int main()
{
    unsigned int j;

    IO0DIR |= 0x0F;

    while(1)
    {
        // Clockwise rotation
        for(j = 0; j < 4; j++)
        {
            IO0PIN = (IO0PIN & ~0x0F) | phase[j];
            delay();
        }

        // Anticlockwise rotation
        for(j = 4; j > 0; j--)
        {
            IO0PIN = (IO0PIN & ~0x0F) | phase[j-1];
            delay();
        }
    }
}