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

#if !defined(STATE_H)
#define STATE_H

    #define STATE_READY 1
    #define STATE_PLAY  2
    
    /* CapSense Slider resoluton is set to 127 (7 bits)*/
    #define MAX_SLIDER 127
    #define MAX_VOLUME 5

    extern int state;
    extern int volume;

#endif /* !define STATE_H */

/* [] END OF FILE */
