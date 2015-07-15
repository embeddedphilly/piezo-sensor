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
#include <project.h>
#include "cytypes.h"
#include "tones.h"
#include "notes.h"
#include "PWM_1.h"
#include "piezoelectric.h"

uint8 volume = 1;
uint8 tempo = 120;

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
    
void piezo_tempo(uint8 bpm)
{
    tempo = bpm;
}

void piezo_stop()
{
    PWM_1_WriteCompare(0);
}

void piezo_play(uint16 frequency, uint8 note)
{
    // figure out the duration of this note (in ms), given the current tempo
    uint16 duration = 60000/tempo/note;

    piezo_tone(frequency);
    CyDelay(duration);
    piezo_stop();
}

void piezo_rest(uint8 note)
{
    // figure out the duration of this note (in ms), given the current tempo (which is in bps)
    uint16 duration = 60000/tempo/note;
    piezo_stop();
    CyDelay(duration);
}

void piezo_melody(uint16* frequencies, uint8 num, uint8 note_type)
{
    uint8 i;
    for (i=0; i<num; i++)
    {
        if (frequencies[i] == 0)
        {
            piezo_rest(note_type);
        }
        else 
        {
            piezo_play(frequencies[i], note_type);
        }
    }
}

/* [] END OF FILE */
