/*
 * Name: S.Kiruthika
 * Date of Submission: 23-06-2024
 * Description: Multiple patterns on LEDs controlled by switches
  
 * Sample Execution:
 
 * Upon giving the power supply, all 8 LEDs should be OFF.
 * press switch-1 on the Digital Keypad, LEDs should glow according to the pattern-1*
 * Press switch-2, LEDs should glow according to the pattern-2*
 * Press switch-3, LEDs should glow according to the pattern-3*
 * Press switch-4, LEDs should glow according to the pattern-4*
    
 *pattern-1: The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.
 *pattern-2: The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change.
 *pattern-3: The LEDs should blink alternately.
 *pattern-4: The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF,
             after first 4 LEDs will be OFF, next 4 LEDs will be ON.
 
 
*/


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


static void init_config(void) {
    /* Turn off LEDs initially */
    LED_ARRAY1 = 0x00;
    
    /* Configure as Output Port */
    LED_ARRAY1_DDR = 0x00;

    /* Initialize digital keypad */
    init_digital_keypad();
}

void main(void) {
    unsigned char key;
    // Global variables
     volatile unsigned char flag = 0;
     volatile unsigned int state = 0;
     volatile unsigned int i = 0;
     volatile unsigned int delay_counter = 0;
     const unsigned int delay_limit = 20000;
    init_config();

    while (1) 
    {
        key = read_digital_keypad(STATE);

        if (key == SW1 && flag != 1) 
        {
            flag = 1; // Set flag for switch 1
            i = 0;    // Reset sequence counter
        } 
        else if (key == SW2 && flag != 2) 
        {
            flag = 2; // Set flag for switch 2
            i = 0;    // Reset sequence counter
        } 
        else if (key == SW3 && flag != 3) 
        {
            flag = 3; // Set flag for switch 3
            state = 0; // Reset state
        } 
        else if (key == SW4 && flag != 4) 
        {
            flag = 4; // Set flag for switch 4
            state = 0; // Reset state
        }

        // Non-blocking delay
        if (delay_counter < delay_limit) 
        {
            delay_counter++;
        } 
        else 
        {
            delay_counter = 0; // Reset the delay counter
            
            if (flag == 1) 
            {
                // Sequence for switch 1 press
                if (i <= 7) 
                {
                    LED_ARRAY1 |= (1 << i); // Turn ON LEDs from Top to Bottom
                    i++;
                } 
                else if (i > 7 && i <= 15) 
                {
                    LED_ARRAY1 &= ~(1 << (i - 8)); // Turn OFF LEDs from Top to Bottom
                    i++;
                } 
                else if (i > 15 && i <= 23) 
                {
                    LED_ARRAY1 |= (1 << (7 - (i - 16))); // Turn ON LEDs from Bottom to Top
                    i++;
                } 
                else if (i > 23 && i < 32) 
                {
                    LED_ARRAY1 &= ~(1 << (7 - (i - 24))); // Turn OFF LEDs from Bottom to Top
                    i++;
                } 
                else 
                {
                    i = 0;
                }                
            } 
            else if (flag == 2) 
            {
                // Sequence for switch 2 press
                if (i <= 7) 
                {
                    LED_ARRAY1 |= (1 << i); // Turn ON LEDs from Top to Bottom
                    i++;
                } 
                else if (i > 7 && i <= 15) 
                {
                    LED_ARRAY1 &= ~(1 << (i - 8)); // Turn OFF LEDs from Top to Bottom
                    i++;
                } 
                else 
                {
                    i = 0;
                }
            } 
            else if (flag == 3) 
            {
                // Sequence for switch 3 press
                if (state == 0) 
                {
                    LED_ARRAY1 = 0x55; // condition to Turn OFF 1st set of alternate LEDs
                    state = 1;
                    i++;
                } 
                else 
                {
                    LED_ARRAY1 = 0xAA; // condition to Turn OFF 2nd set of alternate LEDs
                    state = 0;
                    i++;
                }                
            } 
            else if (flag == 4) 
            {
                // Sequence for switch 4 press
                if (state == 0) 
                {
                    LED_ARRAY1 = 0x0F; // condition to Turn ON first Nibble
                    state = 1;
                    i++;
                } 
                else 
                {
                    LED_ARRAY1 = 0xF0; //condition to Turn ON second Nibble
                    state = 0;
                    i++;
                }
            }
        }
    }
    return;
}
