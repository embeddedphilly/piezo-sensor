/*******************************************************************************
* File Name: LED_2.h  
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

#if !defined(CY_PINS_LED_2_H) /* Pins LED_2_H */
#define CY_PINS_LED_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_2_Write(uint8 value) ;
void    LED_2_SetDriveMode(uint8 mode) ;
uint8   LED_2_ReadDataReg(void) ;
uint8   LED_2_Read(void) ;
uint8   LED_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_2_DRIVE_MODE_BITS        (3)
#define LED_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED_2_DRIVE_MODE_BITS))
#define LED_2_DRIVE_MODE_SHIFT       (0x00u)
#define LED_2_DRIVE_MODE_MASK        (0x07u << LED_2_DRIVE_MODE_SHIFT)

#define LED_2_DM_ALG_HIZ         (0x00u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_DIG_HIZ         (0x01u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_RES_UP          (0x02u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_RES_DWN         (0x03u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_OD_LO           (0x04u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_OD_HI           (0x05u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_STRONG          (0x06u << LED_2_DRIVE_MODE_SHIFT)
#define LED_2_DM_RES_UPDWN       (0x07u << LED_2_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define LED_2_MASK               LED_2__MASK
#define LED_2_SHIFT              LED_2__SHIFT
#define LED_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_2_PS                     (* (reg32 *) LED_2__PS)
/* Port Configuration */
#define LED_2_PC                     (* (reg32 *) LED_2__PC)
/* Data Register */
#define LED_2_DR                     (* (reg32 *) LED_2__DR)
/* Input Buffer Disable Override */
#define LED_2_INP_DIS                (* (reg32 *) LED_2__PC2)


#if defined(LED_2__INTSTAT)  /* Interrupt Registers */

    #define LED_2_INTSTAT                (* (reg32 *) LED_2__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins LED_2_H */


/* [] END OF FILE */
