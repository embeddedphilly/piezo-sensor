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

int state = STATE_READY;

void cap_sense_update_volume(void);
uint16 curPos, oldPos;

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    
    piezo_stop();
    piezo_tone(4400);
    
    CapSense_Start();	

    /* Initialize baselines */ 
    CapSense_InitializeAllBaselines();

    piezo_tempo(100);
       
    uint16 melody_simple[] = {
        C4, WHOLE,      D4, WHOLE,
        E4, WHOLE,      F4, WHOLE,
        G4, WHOLE,      A4, WHOLE,
        B4, WHOLE,      C5, WHOLE
    };
    
    //piezo_melody(melody_simple, 16);
    
    uint16* tune;
    int tune_counter = 0;
    
    int note, tone;

    // CHANGE THIS FOR NEW TUNE
    tune = melody_simple;
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        
        cap_sense_update_volume();
        /*
        if(state == STATE_READY) {
            tone = tune[tune_counter++];
            note = tune[tune_counter++];
            
            //piezo_tone(tone);
            piezo_play(tone, note);
            state = STATE_PLAY;
        }
        */
    }

}

void cap_sense_update_volume(void)
{
    /* Update all baselines */
    CapSense_UpdateEnabledBaselines();
        
   	/* Start scanning all enabled sensors */
    CapSense_ScanEnabledWidgets();
    
    /* Wait for scanning to complete */
	while(CapSense_IsBusy() != 0)
	{
		/* Loop until condition true */
	}
    
    /* Find Slider Position */
    curPos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);    
    
    /* Reset position */
    if(curPos == 0xFFFFu)
    {
        curPos = 0u;
    }
                
    /* Move bargraph */
    if (curPos != oldPos)
    {
        oldPos = curPos;
        volume = curPos*MAX_SLIDER/MAX_VOLUME;  
        piezo_volume(10*volume);
    }
}


/* [] END OF FILE */
