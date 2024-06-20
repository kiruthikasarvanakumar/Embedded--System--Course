/*
 * Name: S.Kiruthika
 * Date of Submission : 20-06-2024
 * Description: Implement LED train pattern on leds
 */

#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 * configuration, like setting port directions, initializing port values
 */
static void init_config(void) {
    LED_ARRAY1_DDR = 0x00; // Set direction to o/p
    LED_ARRAY1 = 0x01;     // Set initial port value to the first LED on
}

void main(void) 
{
    unsigned int wait = 0;
    unsigned char i = 1;   // 1 for left to right, 0 for right to left
    
    init_config();

    while (1) 
    {
        if(wait++ == 50000)
        {
            wait = 0;

            // Update LED state
            if (i) 
            {
                // Left to right
                LED_ARRAY1 <<= 1;
                if (LED_ARRAY1 == 0) 
                {
                    LED_ARRAY1 = 0x80; // Reset to the last LED
                    i = 0; // Change direction to right to left
                }
            } 
            else 
            {
                // Right to left
                LED_ARRAY1 >>= 1;
                if (LED_ARRAY1 == 0) 
                {
                    LED_ARRAY1 = 0x01; // Reset to the first LED
                    i = 1; // Change direction to left to right
                }
            }
        }
    }
    return;
}

