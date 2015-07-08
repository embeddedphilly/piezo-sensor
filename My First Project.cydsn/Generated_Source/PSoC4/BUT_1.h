/*******************************************************************************
* File Name: BUT_1.h  
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

#if !defined(CY_PINS_BUT_1_H) /* Pins BUT_1_H */
#define CY_PINS_BUT_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BUT_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BUT_1_Write(uint8 value) ;
void    BUT_1_SetDriveMode(uint8 mode) ;
uint8   BUT_1_ReadDataReg(void) ;
uint8   BUT_1_Read(void) ;
uint8   BUT_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BUT_1_DRIVE_MODE_BITS        (3)
#define BUT_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BUT_1_DRIVE_MODE_BITS))
#define BUT_1_DRIVE_MODE_SHIFT       (0x00u)
#define BUT_1_DRIVE_MODE_MASK        (0x07u << BUT_1_DRIVE_MODE_SHIFT)

#define BUT_1_DM_ALG_HIZ         (0x00u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_DIG_HIZ         (0x01u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_RES_UP          (0x02u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_RES_DWN         (0x03u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_OD_LO           (0x04u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_OD_HI           (0x05u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_STRONG          (0x06u << BUT_1_DRIVE_MODE_SHIFT)
#define BUT_1_DM_RES_UPDWN       (0x07u << BUT_1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define BUT_1_MASK               BUT_1__MASK
#define BUT_1_SHIFT              BUT_1__SHIFT
#define BUT_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUT_1_PS                     (* (reg32 *) BUT_1__PS)
/* Port Configuration */
#define BUT_1_PC                     (* (reg32 *) BUT_1__PC)
/* Data Register */
#define BUT_1_DR                     (* (reg32 *) BUT_1__DR)
/* Input Buffer Disable Override */
#define BUT_1_INP_DIS                (* (reg32 *) BUT_1__PC2)


#if defined(BUT_1__INTSTAT)  /* Interrupt Registers */

    #define BUT_1_INTSTAT                (* (reg32 *) BUT_1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins BUT_1_H */


/* [] END OF FILE */
