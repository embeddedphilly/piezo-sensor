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

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();

    piezo_tempo(100);
    
    //uint16 melody[] = {A4, B4, C4, 0, F4, 0, G4}; 
    
    uint16 melody[] = {
      E4, E4, 0, E4, 
      0, C4, E4, 0,
      G4, 0, 0,  0,
      G4, 0, 0, 0, 

      C4, 0, 0, G4, 
      0, 0, E4, 0, 
      0, A4, 0, B4, 
      0, A4, A4, 0, 

      G4, E4, G4, 
      A4, 0, F4, G4, 
      0, E4, 0,C4, 
      D4, B4, 0, 0,

      C4, 0, 0, G4, 
      0, 0, E4, 0, 
      0, A4, 0, B4, 
      0, A4, A4, 0, 

      G4, E4, G4, 
      A4, 0, F4, G4, 
      0, E4, 0,C4, 
      D4, B4, 0, 0
    };
    
    uint16 melody_simple[] = {
        C4, WHOLE,      D4, WHOLE,
        E4, WHOLE,      F4, WHOLE,
        G4, WHOLE,      A4, WHOLE,
        B4, WHOLE,      C5, WHOLE
    };
    
    piezo_melody(melody_simple, 16);
    
    
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        
    }
}

/* [] END OF FILE */
