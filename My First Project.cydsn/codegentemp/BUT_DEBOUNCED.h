/*******************************************************************************
* File Name: BUT_DEBOUNCED.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BUT_DEBOUNCED_H) /* Pins BUT_DEBOUNCED_H */
#define CY_PINS_BUT_DEBOUNCED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BUT_DEBOUNCED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BUT_DEBOUNCED_Write(uint8 value) ;
void    BUT_DEBOUNCED_SetDriveMode(uint8 mode) ;
uint8   BUT_DEBOUNCED_ReadDataReg(void) ;
uint8   BUT_DEBOUNCED_Read(void) ;
uint8   BUT_DEBOUNCED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BUT_DEBOUNCED_DRIVE_MODE_BITS        (3)
#define BUT_DEBOUNCED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BUT_DEBOUNCED_DRIVE_MODE_BITS))
#define BUT_DEBOUNCED_DRIVE_MODE_SHIFT       (0x00u)
#define BUT_DEBOUNCED_DRIVE_MODE_MASK        (0x07u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)

#define BUT_DEBOUNCED_DM_ALG_HIZ         (0x00u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_DIG_HIZ         (0x01u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_RES_UP          (0x02u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_RES_DWN         (0x03u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_OD_LO           (0x04u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_OD_HI           (0x05u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_STRONG          (0x06u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)
#define BUT_DEBOUNCED_DM_RES_UPDWN       (0x07u << BUT_DEBOUNCED_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define BUT_DEBOUNCED_MASK               BUT_DEBOUNCED__MASK
#define BUT_DEBOUNCED_SHIFT              BUT_DEBOUNCED__SHIFT
#define BUT_DEBOUNCED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUT_DEBOUNCED_PS                     (* (reg32 *) BUT_DEBOUNCED__PS)
/* Port Configuration */
#define BUT_DEBOUNCED_PC                     (* (reg32 *) BUT_DEBOUNCED__PC)
/* Data Register */
#define BUT_DEBOUNCED_DR                     (* (reg32 *) BUT_DEBOUNCED__DR)
/* Input Buffer Disable Override */
#define BUT_DEBOUNCED_INP_DIS                (* (reg32 *) BUT_DEBOUNCED__PC2)


#if defined(BUT_DEBOUNCED__INTSTAT)  /* Interrupt Registers */

    #define BUT_DEBOUNCED_INTSTAT                (* (reg32 *) BUT_DEBOUNCED__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins BUT_DEBOUNCED_H */


/* [] END OF FILE */
