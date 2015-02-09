#include "Timeout.h"
#include "mbed.h"
#include "EAOLED.h"
#include "TextDisplay.h"
#include "DigitalIn.h"


EAOLED oled(p5, p6, p7, p8, p25);

DigitalIn pin0(p11);
DigitalIn pin1(p28);
DigitalIn pin2(p29);
DigitalIn pin3(p30);

void attimeout(void);
Timeout timeout;
volatile bool finished = false;

int main()
{
    oled.cls();
    
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0; 
    int slave0 = 0;
    int slave1 = 0;
    int slave2 = 0;
    int slave3 = 0;
    
    timeout.attach(&attimeout, 1);
    while(!finished)
    {
        if (pin0 != slave0)
        {
            count0++;
            slave0 = pin0;
        }
        if (pin1 != slave1)
        {
            count1++;
            slave1 = pin1;
        }
        if (pin2 != slave2)
        {
            count2++;
            slave2 = pin2;
        }
        if (pin3 != slave3)
        {
            count3++;
            slave3 = pin3;
        }
    }
    oled.cls();
    oled.locate(0,0);
    oled.printf("p0: %d", count0/2);
    oled.locate(0,2);
    oled.printf("p1: %d", count1/2);
    oled.locate(0,4);
    oled.printf("p2: %d", count2/2);
    oled.locate(0,6);
    oled.printf("p3: %d", count3/2);
    return 0;
}

void attimeout()
{
    finished = true;    
}

    
