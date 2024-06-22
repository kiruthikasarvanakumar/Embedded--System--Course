/*
 * Name: S.Kiruthika
 * Date of Submission: 21-06-2024
 * Description: Embedded C program to display a pattern on the LEDs.
                This program will toggle the LEDs at PORTD
 */

#include <xc.h>
#include "main.h"

// Configuration Bit settings
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

// Function Prototypes
static void init_config(void);

// Function: init_config()
// Description: This function is used to setup initial peripheral
// configuration, like setting port directions, initializing port values

static void init_config(void) {
    LED_ARRAY1_DDR = 0x00; // Set PORTB direction to output
    LED_ARRAY1 = 0x00;     // Initialize all LEDs to be off
}

void main(void) {
    unsigned int wait = 0;
    unsigned char i = 0;

    init_config();

    while (1) {
        if (wait++ == 50000) {
            wait = 0;

            // Condition to turn on LEDs from top to bottom
            if (i <= 7) {
                LED_ARRAY1 |= (1 << i); 
                i++;
            }
            // Condition to turn off LEDs from top to bottom
            else if (i > 7 && i <= 15) {
                LED_ARRAY1 &= ~(1 << (i - 8)); 
                i++;
            }
            // Condition to turn on LEDs from bottom to top
            else if (i > 15 && i <= 23) {
                LED_ARRAY1 |= (1 << (7 - (i - 16))); 
                i++;
            }
            // Condition to turn off LEDs from bottom to top
            else if (i > 23 && i < 32) {
                LED_ARRAY1 &= ~(1 << (7 - (i - 24))); 
                i++;
            }
            // Reset the sequence
            else {
                i = 0;
                LED_ARRAY1 = 0x00; // Turn off all LEDs
            }
        }
    }

    return;
}
