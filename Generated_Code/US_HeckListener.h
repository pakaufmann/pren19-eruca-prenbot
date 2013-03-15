/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : US_HeckListener.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt
**     Version     : Component 02.104, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-15, 11:32, # CodeGen: 11
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : INT_PORTA
**         User handling procedure     : US_HeckListener_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       36            |  PTA16/SPI0_MOSI/SPI0_MISO
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 16
**         Bit mask of the port        : 0x00010000
**
**         Signal edge/level           : falling
**         Priority                    : 2
**         Pull option                 : off
**         Initial state               : Disabled
**
**
**         Port data register          : GPIOA_PDOR [0x400FF000]
**         Port control register       : GPIOA_PDDR [0x400FF014]
**     Contents    :
**         Enable  - void US_HeckListener_Enable(void);
**         Disable - void US_HeckListener_Disable(void);
**         GetVal  - bool US_HeckListener_GetVal(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __US_HeckListener_H
#define __US_HeckListener_H

/* MODULE US_HeckListener. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "ExtIntLdd4.h"

#include "Cpu.h"




/*
** ===================================================================
**     Method      :  US_HeckListener_Enable (component ExtInt)
**
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define US_HeckListener_Enable() (ExtIntLdd4_Enable(ExtIntLdd4_DeviceData))

/*
** ===================================================================
**     Method      :  US_HeckListener_Disable (component ExtInt)
**
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define US_HeckListener_Disable() (ExtIntLdd4_Disable(ExtIntLdd4_DeviceData))

/*
** ===================================================================
**     Method      :  US_HeckListener_GetVal (component ExtInt)
**
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
#define US_HeckListener_GetVal() (ExtIntLdd4_GetVal(ExtIntLdd4_DeviceData))

void ExtIntLdd4_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END US_HeckListener. */

#endif 
/* ifndef __US_HeckListener_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
