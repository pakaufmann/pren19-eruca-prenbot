/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ExtIntLdd1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt_LDD
**     Version     : Component 02.151, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-15, 11:32, # CodeGen: 11
**     Abstract    :
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**          Component name                                 : ExtIntLdd1
**          Pin                                            : PTD0/SPI0_PCS0/TPM0_CH0
**          Pin signal                                     : EncoderMotorASig
**          Generate interrupt on                          : both edges
**          Interrupt                                      : INT_PORTD
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          Threshold level                                : 0
**     Contents    :
**         Init    - LDD_TDeviceData* ExtIntLdd1_Init(LDD_TUserData *UserDataPtr);
**         Enable  - void ExtIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - void ExtIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetVal  - bool ExtIntLdd1_GetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __ExtIntLdd1_H
#define __ExtIntLdd1_H

/* MODULE ExtIntLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"
#include "PORT_PDD.h"
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define ExtIntLdd1_PRPH_BASE_ADDRESS  0x400FF0C0U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define ExtIntLdd1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_ExtIntLdd1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define ExtIntLdd1_Init_METHOD_ENABLED
#define ExtIntLdd1_Enable_METHOD_ENABLED
#define ExtIntLdd1_Disable_METHOD_ENABLED
#define ExtIntLdd1_GetVal_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define ExtIntLdd1_OnInterrupt_EVENT_ENABLED

/* Definition of implementation constants */
#define ExtIntLdd1_PIN_INDEX 0x00U     /* Index of the used pin from the port */
#define ExtIntLdd1_PIN_MASK 0x01U      /* Mask of the used pin from the port */
#define ExtIntLdd1_MODULE_BASE_ADDRESS PTD_BASE_PTR /* Name of macro used as the base address */
#define ExtIntLdd1_PORTCONTROL_BASE_ADDRESS PORTD_BASE_PTR /* Name of macro used as the base address */
#define ExtIntLdd1_IRQ_CONFIG PORT_PDD_INTERRUPT_ON_RISING_FALLING /* Static IRQ configuration */

LDD_TDeviceData* ExtIntLdd1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  ExtIntLdd1_Init (component ExtInt_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void ExtIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ExtIntLdd1_Enable (component ExtInt_LDD)
**
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

void ExtIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ExtIntLdd1_Disable (component ExtInt_LDD)
**
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

/* {Default RTOS Adapter} ISR function prototype */
void ExtIntLdd1_Interrupt(void);
/*
** ===================================================================
**     Method      :  ExtIntLdd1_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool ExtIntLdd1_GetVal(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ExtIntLdd1_GetVal (component ExtInt_LDD)
**
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
/* END ExtIntLdd1. */

#endif
/* ifndef __ExtIntLdd1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
