/*******************************************************************************
* File Name: PIEZO_PIN.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PIEZO_PIN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PIEZO_PIN_PC =   (PIEZO_PIN_PC & \
                                (uint32)(~(uint32)(PIEZO_PIN_DRIVE_MODE_IND_MASK << (PIEZO_PIN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PIEZO_PIN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PIEZO_PIN_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void PIEZO_PIN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PIEZO_PIN_DR & (uint8)(~PIEZO_PIN_MASK));
    drVal = (drVal | ((uint8)(value << PIEZO_PIN_SHIFT) & PIEZO_PIN_MASK));
    PIEZO_PIN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PIEZO_PIN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PIEZO_PIN_DM_STRONG     Strong Drive 
*  PIEZO_PIN_DM_OD_HI      Open Drain, Drives High 
*  PIEZO_PIN_DM_OD_LO      Open Drain, Drives Low 
*  PIEZO_PIN_DM_RES_UP     Resistive Pull Up 
*  PIEZO_PIN_DM_RES_DWN    Resistive Pull Down 
*  PIEZO_PIN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PIEZO_PIN_DM_DIG_HIZ    High Impedance Digital 
*  PIEZO_PIN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PIEZO_PIN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PIEZO_PIN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PIEZO_PIN_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro PIEZO_PIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PIEZO_PIN_Read(void) 
{
    return (uint8)((PIEZO_PIN_PS & PIEZO_PIN_MASK) >> PIEZO_PIN_SHIFT);
}


/*******************************************************************************
* Function Name: PIEZO_PIN_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 PIEZO_PIN_ReadDataReg(void) 
{
    return (uint8)((PIEZO_PIN_DR & PIEZO_PIN_MASK) >> PIEZO_PIN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PIEZO_PIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: PIEZO_PIN_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 PIEZO_PIN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PIEZO_PIN_INTSTAT & PIEZO_PIN_MASK);
		PIEZO_PIN_INTSTAT = maskedStatus;
        return maskedStatus >> PIEZO_PIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
