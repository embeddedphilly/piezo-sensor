/*******************************************************************************
* File Name: PIEZO.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PIEZO.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        PIEZO_PC =   (PIEZO_PC & \
                                (uint32)(~(uint32)(PIEZO_DRIVE_MODE_IND_MASK << (PIEZO_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (PIEZO_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: PIEZO_Write
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
void PIEZO_Write(uint8 value) 
{
    uint8 drVal = (uint8)(PIEZO_DR & (uint8)(~PIEZO_MASK));
    drVal = (drVal | ((uint8)(value << PIEZO_SHIFT) & PIEZO_MASK));
    PIEZO_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: PIEZO_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void PIEZO_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(PIEZO__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: PIEZO_Read
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
*  Macro PIEZO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PIEZO_Read(void) 
{
    return (uint8)((PIEZO_PS & PIEZO_MASK) >> PIEZO_SHIFT);
}


/*******************************************************************************
* Function Name: PIEZO_ReadDataReg
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
uint8 PIEZO_ReadDataReg(void) 
{
    return (uint8)((PIEZO_DR & PIEZO_MASK) >> PIEZO_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PIEZO_INTSTAT) 

    /*******************************************************************************
    * Function Name: PIEZO_ClearInterrupt
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
    uint8 PIEZO_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(PIEZO_INTSTAT & PIEZO_MASK);
		PIEZO_INTSTAT = maskedStatus;
        return maskedStatus >> PIEZO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
