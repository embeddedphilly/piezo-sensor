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

#if !defined(PIEZOELECTRIC_H) /* PIEZOELECTRIC_H */
#define PIEZOELECTRIC_H
    
#include "cytypes.h"
    
/***************************************
*        Function Prototypes             
***************************************/   
    
void piezo_tone(uint16 frequency);
void piezo_volume(uint8 value);
void piezo_tempo(uint8 bpm);
void piezo_stop();
void piezo_play(uint16 frequency, uint8 note);
void piezo_rest(uint8 note);
void piezo_melody(uint16* frequencies, uint8 num);
    
#endif /* !define PIEZOELECTRIC_H */

/* [] END OF FILE */
