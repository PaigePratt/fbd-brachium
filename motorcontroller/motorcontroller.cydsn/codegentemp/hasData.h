/*******************************************************************************
* File Name: hasData.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_hasData_H)
#define CY_ISR_hasData_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void hasData_Start(void);
void hasData_StartEx(cyisraddress address);
void hasData_Stop(void);

CY_ISR_PROTO(hasData_Interrupt);

void hasData_SetVector(cyisraddress address);
cyisraddress hasData_GetVector(void);

void hasData_SetPriority(uint8 priority);
uint8 hasData_GetPriority(void);

void hasData_Enable(void);
uint8 hasData_GetState(void);
void hasData_Disable(void);

void hasData_SetPending(void);
void hasData_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the hasData ISR. */
#define hasData_INTC_VECTOR            ((reg32 *) hasData__INTC_VECT)

/* Address of the hasData ISR priority. */
#define hasData_INTC_PRIOR             ((reg8 *) hasData__INTC_PRIOR_REG)

/* Priority of the hasData interrupt. */
#define hasData_INTC_PRIOR_NUMBER      hasData__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable hasData interrupt. */
#define hasData_INTC_SET_EN            ((reg32 *) hasData__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the hasData interrupt. */
#define hasData_INTC_CLR_EN            ((reg32 *) hasData__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the hasData interrupt state to pending. */
#define hasData_INTC_SET_PD            ((reg32 *) hasData__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the hasData interrupt. */
#define hasData_INTC_CLR_PD            ((reg32 *) hasData__INTC_CLR_PD_REG)


#endif /* CY_ISR_hasData_H */


/* [] END OF FILE */
