/*******************************************************************************
* File Name: BUT_DEBOUNCED.c  
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
#include "BUT_DEBOUNCED.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        BUT_DEBOUNCED_PC =   (BUT_DEBOUNCED_PC & \
                                (uint32)(~(uint32)(BUT_DEBOUNCED_DRIVE_MODE_IND_MASK << (BUT_DEBOUNCED_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (BUT_DEBOUNCED_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: BUT_DEBOUNCED_Write
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
void BUT_DEBOUNCED_Write(uint8 value) 
{
    uint8 drVal = (uint8)(BUT_DEBOUNCED_DR & (uint8)(~BUT_DEBOUNCED_MASK));
    drVal = (drVal | ((uint8)(value << BUT_DEBOUNCED_SHIFT) & BUT_DEBOUNCED_MASK));
    BUT_DEBOUNCED_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: BUT_DEBOUNCED_SetDriveMode
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
void BUT_DEBOUNCED_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(BUT_DEBOUNCED__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: BUT_DEBOUNCED_Read
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
*  Macro BUT_DEBOUNCED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BUT_DEBOUNCED_Read(void) 
{
    return (uint8)((BUT_DEBOUNCED_PS & BUT_DEBOUNCED_MASK) >> BUT_DEBOUNCED_SHIFT);
}


/*******************************************************************************
* Function Name: BUT_DEBOUNCED_ReadDataReg
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
uint8 BUT_DEBOUNCED_ReadDataReg(void) 
{
    return (uint8)((BUT_DEBOUNCED_DR & BUT_DEBOUNCED_MASK) >> BUT_DEBOUNCED_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BUT_DEBOUNCED_INTSTAT) 

    /*******************************************************************************
    * Function Name: BUT_DEBOUNCED_ClearInterrupt
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
    uint8 BUT_DEBOUNCED_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(BUT_DEBOUNCED_INTSTAT & BUT_DEBOUNCED_MASK);
		BUT_DEBOUNCED_INTSTAT = maskedStatus;
        return maskedStatus >> BUT_DEBOUNCED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
