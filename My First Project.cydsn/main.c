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
#include "piezoelectric.h"
#include "tones.h"
#include "notes.h"
#include "state.h"

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();

    piezo_tempo(100);
       
    uint16 melody_simple[] = {
        C4, WHOLE,      D4, WHOLE,
        E4, WHOLE,      F4, WHOLE,
        G4, WHOLE,      A4, WHOLE,
        B4, WHOLE,      C5, WHOLE
    };
    
    piezo_melody(melody_simple, 16);
    
    uint16* tune;
    int tune_counter = 0;
    
    int state = STATE_READY;
    
    int note, tone;

    // CHANGE THIS FOR NEW TUNE
    tune = melody_simple;
    
    
    
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        
        if(state == STATE_READY) {
            tone = tune[tune_counter++];
            note = tune[tune_counter++];
            
            piezo_tone(tone);
            piezo_play(note);
            state = STATE_PLAY;
        }
    }
}

/* [] END OF FILE */
