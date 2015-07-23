/*******************************************************************************
* File Name: TRIGGER_TIMER.c  
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
#include "TRIGGER_TIMER.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        TRIGGER_TIMER_PC =   (TRIGGER_TIMER_PC & \
                                (uint32)(~(uint32)(TRIGGER_TIMER_DRIVE_MODE_IND_MASK << (TRIGGER_TIMER_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (TRIGGER_TIMER_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: TRIGGER_TIMER_Write
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
void TRIGGER_TIMER_Write(uint8 value) 
{
    uint8 drVal = (uint8)(TRIGGER_TIMER_DR & (uint8)(~TRIGGER_TIMER_MASK));
    drVal = (drVal | ((uint8)(value << TRIGGER_TIMER_SHIFT) & TRIGGER_TIMER_MASK));
    TRIGGER_TIMER_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TRIGGER_TIMER_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TRIGGER_TIMER_DM_STRONG     Strong Drive 
*  TRIGGER_TIMER_DM_OD_HI      Open Drain, Drives High 
*  TRIGGER_TIMER_DM_OD_LO      Open Drain, Drives Low 
*  TRIGGER_TIMER_DM_RES_UP     Resistive Pull Up 
*  TRIGGER_TIMER_DM_RES_DWN    Resistive Pull Down 
*  TRIGGER_TIMER_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TRIGGER_TIMER_DM_DIG_HIZ    High Impedance Digital 
*  TRIGGER_TIMER_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TRIGGER_TIMER_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(TRIGGER_TIMER__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: TRIGGER_TIMER_Read
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
*  Macro TRIGGER_TIMER_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TRIGGER_TIMER_Read(void) 
{
    return (uint8)((TRIGGER_TIMER_PS & TRIGGER_TIMER_MASK) >> TRIGGER_TIMER_SHIFT);
}


/*******************************************************************************
* Function Name: TRIGGER_TIMER_ReadDataReg
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
uint8 TRIGGER_TIMER_ReadDataReg(void) 
{
    return (uint8)((TRIGGER_TIMER_DR & TRIGGER_TIMER_MASK) >> TRIGGER_TIMER_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TRIGGER_TIMER_INTSTAT) 

    /*******************************************************************************
    * Function Name: TRIGGER_TIMER_ClearInterrupt
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
    uint8 TRIGGER_TIMER_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(TRIGGER_TIMER_INTSTAT & TRIGGER_TIMER_MASK);
		TRIGGER_TIMER_INTSTAT = maskedStatus;
        return maskedStatus >> TRIGGER_TIMER_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
