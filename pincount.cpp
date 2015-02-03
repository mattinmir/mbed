#include "Timeout.h"
#include "mbed.h"
#include "EAOLED.h"
#include "TextDisplay.h"
#include "DigitalIn.h"


EAOLED oled(p5, p6, p7, p8, p25);

Timeout timeout;
volatile bool finished = false;
void attimeout()
{
    finished = true;    
}

DigitalIn iopin(p5);

int main()
{
    timeout.attach(&attimeout, 5);
    pin
    oled.cls();
    while(!finished)
    {
        
    }
   
    return 0;
}
    
