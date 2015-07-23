/*******************************************************************************
* File Name: TRIGGER_TIMER.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_TRIGGER_TIMER_H) /* Pins TRIGGER_TIMER_H */
#define CY_PINS_TRIGGER_TIMER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TRIGGER_TIMER_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TRIGGER_TIMER_Write(uint8 value) ;
void    TRIGGER_TIMER_SetDriveMode(uint8 mode) ;
uint8   TRIGGER_TIMER_ReadDataReg(void) ;
uint8   TRIGGER_TIMER_Read(void) ;
uint8   TRIGGER_TIMER_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TRIGGER_TIMER_DRIVE_MODE_BITS        (3)
#define TRIGGER_TIMER_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TRIGGER_TIMER_DRIVE_MODE_BITS))

#define TRIGGER_TIMER_DM_ALG_HIZ         (0x00u)
#define TRIGGER_TIMER_DM_DIG_HIZ         (0x01u)
#define TRIGGER_TIMER_DM_RES_UP          (0x02u)
#define TRIGGER_TIMER_DM_RES_DWN         (0x03u)
#define TRIGGER_TIMER_DM_OD_LO           (0x04u)
#define TRIGGER_TIMER_DM_OD_HI           (0x05u)
#define TRIGGER_TIMER_DM_STRONG          (0x06u)
#define TRIGGER_TIMER_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TRIGGER_TIMER_MASK               TRIGGER_TIMER__MASK
#define TRIGGER_TIMER_SHIFT              TRIGGER_TIMER__SHIFT
#define TRIGGER_TIMER_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TRIGGER_TIMER_PS                     (* (reg32 *) TRIGGER_TIMER__PS)
/* Port Configuration */
#define TRIGGER_TIMER_PC                     (* (reg32 *) TRIGGER_TIMER__PC)
/* Data Register */
#define TRIGGER_TIMER_DR                     (* (reg32 *) TRIGGER_TIMER__DR)
/* Input Buffer Disable Override */
#define TRIGGER_TIMER_INP_DIS                (* (reg32 *) TRIGGER_TIMER__PC2)


#if defined(TRIGGER_TIMER__INTSTAT)  /* Interrupt Registers */

    #define TRIGGER_TIMER_INTSTAT                (* (reg32 *) TRIGGER_TIMER__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TRIGGER_TIMER_DRIVE_MODE_SHIFT       (0x00u)
#define TRIGGER_TIMER_DRIVE_MODE_MASK        (0x07u << TRIGGER_TIMER_DRIVE_MODE_SHIFT)


#endif /* End Pins TRIGGER_TIMER_H */


/* [] END OF FILE */
