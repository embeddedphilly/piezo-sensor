/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "cytypes.h"
#include "tones.h"
#include "PWM_1.h"
#include "piezoelectric.h"

uint8 volume = 1;


void piezo_tone(uint16 frequency) 
{
    // duty cycle ticks is a percentage of frequency based on volume
    uint16 duty_cycle_ticks = frequency * volume / 100;
    
    // maximum duty cycle ticks must be at least 1 lower than frequency
    // to produce a vibration
    if (duty_cycle_ticks == frequency) {
        duty_cycle_ticks--;
    }
    
    // Set period to frequency value
    PWM_1_WritePeriod(frequency);
    
    // Set compare to toggle on duty cycle ticks
    PWM_1_WriteCompare(duty_cycle_ticks);
}

void piezo_volume(uint8 value)
{
    volume = value;
}
    



/* [] END OF FILE */
