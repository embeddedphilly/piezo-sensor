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

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    

    int state = 0;
    int set = 0;
    int read_val = 0;
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        
        if(BUT_DEBOUNCED_Read() == 0) {
            set = 0;
        }
        read_val = BUT_DEBOUNCED_Read();
        if(set == 0 && BUT_DEBOUNCED_Read() == 1) {
            set = 1;
            if(state == 1) {
                state = 0;
                PWM_1_WritePeriod(200);
                PWM_1_WriteCompare(100);
            } else {
                state = 1;
                PWM_1_WritePeriod(178);
                PWM_1_WriteCompare(89);
            }
        }
        
    }
}

/* [] END OF FILE */
