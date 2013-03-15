/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BitsIoLdd4.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitsIO_LDD
**     Version     : Component 01.019, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-15, 11:32, # CodeGen: 11
**     Abstract    :
**         The HAL BitsIO component provides a low level API for unified
**         access to general purpose digital input/output 32 pins across
**         various device designs.
**
**         RTOS drivers using HAL BitsIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : BitsIoLdd4
**          Port                                           : PTC
**          Pins                                           : 4
**            Pin0                                         : 
**              Pin                                        : PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa
**              Pin signal                                 : LED5
**            Pin1                                         : 
**              Pin                                        : PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3
**              Pin signal                                 : LED6
**            Pin2                                         : 
**              Pin                                        : PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT
**              Pin signal                                 : LED7
**            Pin3                                         : 
**              Pin                                        : CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO
**              Pin signal                                 : LED8
**          Direction                                      : Input/Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 0
**            AutoInitialization                           : yes
**          Safe mode                                      : yes
**          Optimization for                               : speed
**     Contents    :
**         Init   - LDD_TDeviceData* BitsIoLdd4_Init(LDD_TUserData *UserDataPtr);
**         GetDir - bool BitsIoLdd4_GetDir(LDD_TDeviceData *DeviceDataPtr);
**         SetDir - void BitsIoLdd4_SetDir(LDD_TDeviceData *DeviceDataPtr, bool Dir);
**         GetVal - dword BitsIoLdd4_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void BitsIoLdd4_PutVal(LDD_TDeviceData *DeviceDataPtr, dword Val);
**         GetBit - LDD_TError BitsIoLdd4_GetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool...
**         PutBit - LDD_TError BitsIoLdd4_PutBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool...
**         SetBit - LDD_TError BitsIoLdd4_SetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**         ClrBit - LDD_TError BitsIoLdd4_ClrBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**         NegBit - LDD_TError BitsIoLdd4_NegBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**
**     (c) 2012 by Freescale
** ###################################################################*/

#ifndef __BitsIoLdd4_H
#define __BitsIoLdd4_H

/* MODULE BitsIoLdd4. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"

#include "Cpu.h"



/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define BitsIoLdd4_PRPH_BASE_ADDRESS  0x400FF080U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define BitsIoLdd4_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_BitsIoLdd4_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define BitsIoLdd4_Init_METHOD_ENABLED
#define BitsIoLdd4_GetDir_METHOD_ENABLED
#define BitsIoLdd4_SetDir_METHOD_ENABLED
#define BitsIoLdd4_GetVal_METHOD_ENABLED
#define BitsIoLdd4_PutVal_METHOD_ENABLED
#define BitsIoLdd4_GetBit_METHOD_ENABLED
#define BitsIoLdd4_PutBit_METHOD_ENABLED
#define BitsIoLdd4_SetBit_METHOD_ENABLED
#define BitsIoLdd4_ClrBit_METHOD_ENABLED
#define BitsIoLdd4_NegBit_METHOD_ENABLED

/* Definition of implementation constants */
#define BitsIoLdd4_MODULE_BASE_ADDRESS FPTC_BASE_PTR /* Name of macro used as the base address */
#define BitsIoLdd4_PORTCONTROL_BASE_ADDRESS PORTC_BASE_PTR /* Name of macro used as the base address */
#define BitsIoLdd4_PORT_MASK 0x78U     /* Mask of the allocated pin from the port */
#define BitsIoLdd4_PORT_VALID_VALUE_MASK 0x0F /* Mask of the allocated pins from the port as the first pin would be zero i.e. valid bits to be set in method PutVal */
#define BitsIoLdd4_PIN_ALLOC_0_MASK 0x08 /* Mask of the first allocated pin from the port */
#define BitsIoLdd4_PIN_ALLOC_0_INDEX 3U /* The index of the first allocated pin from the port */



LDD_TDeviceData* BitsIoLdd4_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_Init (component BitsIO_LDD)
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

bool BitsIoLdd4_GetDir(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_GetDir (component BitsIO_LDD)
**
**     Description :
**         Returns the selected direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Possible values:
**                           <false> - Input
**                           <true> - Output
** ===================================================================
*/

void BitsIoLdd4_SetDir(LDD_TDeviceData *DeviceDataPtr, bool Dir);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_SetDir (component BitsIO_LDD)
**
**     Description :
**         Sets a direction for the pins (available only if Direction =
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Dir             - Direction to set. Possible values:
**                           <false> - Input
**                           <true> - Output
**     Returns     : Nothing
** ===================================================================
*/

dword BitsIoLdd4_GetVal(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_GetVal (component BitsIO_LDD)
**
**     Description :
**         Returns the value of the Input/Output component. If the
**         direction is [input] then reads the input value of the pins
**         and returns it. If the direction is [output] then returns
**         the last written value (see <Safe mode> property for
**         limitations).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Input value
** ===================================================================
*/

void BitsIoLdd4_PutVal(LDD_TDeviceData *DeviceDataPtr, dword Val);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_PutVal (component BitsIO_LDD)
**
**     Description :
**         Specified value is passed to the Input/Output component. If
**         the direction is [input] saves the value to a memory or a
**         register, this value will be written to the pins after
**         switching to the output mode - using [SetDir(TRUE)] (see
**         <Safe mode> property for limitations). If the direction is
**         [output] it writes the value to the pins. (Method is
**         available only if the Direction = _[output]_ or
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Val             - Output value
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError BitsIoLdd4_GetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool *BitVal);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_GetBit (component BitsIO_LDD)
**
**     Description :
**         Returns the value of the specified bit/pin of the
**         Input/Output component. If the direction is [input] then it
**         reads the input value of the pin and returns it. If the
**         direction is [output] then it returns the last written value
**         (see <Safe mode> property for limitations).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Bit             - Bit/pin number to read
**       * BitVal          - The returned value: 
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin index
**                           ERR_VALUE - Invalid output parameter
** ===================================================================
*/

LDD_TError BitsIoLdd4_PutBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool Val);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_PutBit (component BitsIO_LDD)
**
**     Description :
**         Specified value is passed to the specified bit/pin of the
**         Input/Output component. If the direction is [input] it saves
**         the value to a memory or register, this value will be
**         written to the pin after switching to the output mode -
**         using [SetDir(TRUE)] (see <Safe mode> property for
**         limitations). If the direction is [output] it writes the
**         value to the pin. (Method is available only if the Direction
**         = _[output]_ or _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**         Bit             - Bit/pin number
**         Val             - A new bit value. Possible values:
**                           <false> - logical "0" (Low level)
**                           <true> - logical "1" (High level)
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid bit index
** ===================================================================
*/

LDD_TError BitsIoLdd4_SetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_SetBit (component BitsIO_LDD)
**
**     Description :
**         Sets (to one) the specified bit of the Input/Output
**         component. It is the same as [PutBit(Bit, TRUE)]. (Method is
**         available only if the Direction = _[output]_ or
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**         Bit             - Bit/pin number to set
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/

LDD_TError BitsIoLdd4_ClrBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_ClrBit (component BitsIO_LDD)
**
**     Description :
**         Clears (sets to zero) the specified bit of the Input/Output
**         component. It is the same as [PutBit(Bit, FALSE)]. (Method
**         is available only if the Direction = _[output]_ or
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**         Bit             - Bit/pin number to clear
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/

LDD_TError BitsIoLdd4_NegBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
/*
** ===================================================================
**     Method      :  BitsIoLdd4_NegBit (component BitsIO_LDD)
**
**     Description :
**         Negates (inverts) the specified bit of the Input/Output
**         component. It is the same as [PutBit(Bit,!GetBit(Bit))].
**         (Method is available only if the Direction = _[output]_ or
**         _[input/output]_).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**         Bit             - Bit/pin number to invert
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/

/* END BitsIoLdd4. */

#endif
/* ifndef __BitsIoLdd4_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
