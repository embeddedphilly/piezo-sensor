/*******************************************************************************
* File Name: PIEZO.h  
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

#if !defined(CY_PINS_PIEZO_H) /* Pins PIEZO_H */
#define CY_PINS_PIEZO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PIEZO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PIEZO_Write(uint8 value) ;
void    PIEZO_SetDriveMode(uint8 mode) ;
uint8   PIEZO_ReadDataReg(void) ;
uint8   PIEZO_Read(void) ;
uint8   PIEZO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PIEZO_DRIVE_MODE_BITS        (3)
#define PIEZO_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PIEZO_DRIVE_MODE_BITS))
#define PIEZO_DRIVE_MODE_SHIFT       (0x00u)
#define PIEZO_DRIVE_MODE_MASK        (0x07u << PIEZO_DRIVE_MODE_SHIFT)

#define PIEZO_DM_ALG_HIZ         (0x00u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_DIG_HIZ         (0x01u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_RES_UP          (0x02u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_RES_DWN         (0x03u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_OD_LO           (0x04u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_OD_HI           (0x05u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_STRONG          (0x06u << PIEZO_DRIVE_MODE_SHIFT)
#define PIEZO_DM_RES_UPDWN       (0x07u << PIEZO_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define PIEZO_MASK               PIEZO__MASK
#define PIEZO_SHIFT              PIEZO__SHIFT
#define PIEZO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PIEZO_PS                     (* (reg32 *) PIEZO__PS)
/* Port Configuration */
#define PIEZO_PC                     (* (reg32 *) PIEZO__PC)
/* Data Register */
#define PIEZO_DR                     (* (reg32 *) PIEZO__DR)
/* Input Buffer Disable Override */
#define PIEZO_INP_DIS                (* (reg32 *) PIEZO__PC2)


#if defined(PIEZO__INTSTAT)  /* Interrupt Registers */

    #define PIEZO_INTSTAT                (* (reg32 *) PIEZO__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins PIEZO_H */


/* [] END OF FILE */
