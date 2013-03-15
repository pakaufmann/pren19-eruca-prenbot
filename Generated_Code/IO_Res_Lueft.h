/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : IO_Res_Lueft.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : BitsIO
**     Version     : Component 02.108, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-15, 11:32, # CodeGen: 11
**     Abstract    :
**         This component "BitsIO" implements a multi-bit input/output.
**         It uses selected pins of one 1-bit to 8-bit port.
**     Settings    :
**         Port name                   : PTC
**
**         Bit mask of the port        : 0x0078
**         Number of bits/pins         : 4
**         Single bit numbers          : 0 to 3
**         Values range                : 0 to 15
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         Port data register          : GPIOC_PDOR [0x400FF080]
**         Port control register       : GPIOC_PDDR [0x400FF094]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    58   |   PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa
**                    1      |    61   |   PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3
**                    2      |    62   |   PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT
**                    3      |    63   |   CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO
**             ----------------------------------------------------
**
**         Optimization for            : speed
**     Contents    :
**         GetDir - bool IO_Res_Lueft_GetDir(void);
**         SetDir - void IO_Res_Lueft_SetDir(bool Dir);
**         GetVal - byte IO_Res_Lueft_GetVal(void);
**         PutVal - void IO_Res_Lueft_PutVal(byte Val);
**         GetBit - bool IO_Res_Lueft_GetBit(byte Bit);
**         PutBit - void IO_Res_Lueft_PutBit(byte Bit, bool Val);
**         SetBit - void IO_Res_Lueft_SetBit(byte Bit);
**         ClrBit - void IO_Res_Lueft_ClrBit(byte Bit);
**         NegBit - void IO_Res_Lueft_NegBit(byte Bit);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __IO_Res_Lueft_H
#define __IO_Res_Lueft_H

/* MODULE IO_Res_Lueft. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "BitsIoLdd4.h"

#include "Cpu.h"




/*
** ===================================================================
**     Method      :  IO_Res_Lueft_GetDir (component BitsIO)
**
**     Description :
**         This method returns direction of the component.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the component (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define IO_Res_Lueft_GetDir() (BitsIoLdd4_GetDir(BitsIoLdd4_DeviceData))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_SetDir (component BitsIO)
**
**     Description :
**         This method sets direction of the component.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_SetDir(Dir) (BitsIoLdd4_SetDir(BitsIoLdd4_DeviceData, (Dir)))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_GetVal (component BitsIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 15)
** ===================================================================
*/
#define IO_Res_Lueft_GetVal() ((byte)BitsIoLdd4_GetVal(BitsIoLdd4_DeviceData))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_PutVal (component BitsIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pins
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 15)
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_PutVal(Val) (BitsIoLdd4_PutVal(BitsIoLdd4_DeviceData, ((dword)(Val))))

bool IO_Res_Lueft_GetBit(byte Bit);
/*
** ===================================================================
**     Method      :  IO_Res_Lueft_GetBit (component BitsIO)
**
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 3)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_PutBit (component BitsIO)
**
**     Description :
**         This method writes the new value to the specified bit
**         of the output value.
**           a) direction = Input  : sets the value of the specified
**                                   bit; this operation will be
**                                   shown on output after the
**                                   direction has been switched to
**                                   output (SetDir(TRUE);)
**           b) direction = Output : directly writes the value of the
**                                   bit to the appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit (0 to 3)
**         Val        - New value of the bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_PutBit(Bit,Val) ((void)BitsIoLdd4_PutBit(BitsIoLdd4_DeviceData, (Bit), (Val)))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_SetBit (component BitsIO)
**
**     Description :
**         This method sets (sets to one) the specified bit of the
**         output value.
**         [ It is the same as "PutBit(Bit,TRUE);" ]
**           a) direction = Input  : sets the specified bit to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to set (0 to 3)
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_SetBit(Bit) ((void)BitsIoLdd4_SetBit(BitsIoLdd4_DeviceData, (Bit)))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_ClrBit (component BitsIO)
**
**     Description :
**         This method clears (sets to zero) the specified bit
**         of the output value.
**         [ It is the same as "PutBit(Bit,FALSE);" ]
**           a) direction = Input  : sets the specified bit to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   beenswitched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to clear (0 to 3)
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_ClrBit(Bit) ((void)BitsIoLdd4_ClrBit(BitsIoLdd4_DeviceData, (Bit)))

/*
** ===================================================================
**     Method      :  IO_Res_Lueft_NegBit (component BitsIO)
**
**     Description :
**         This method negates (inverts) the specified bit of the
**         output value.
**           a) direction = Input  : inverts the specified bit;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly inverts the value
**                                   of the appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to invert (0 to 31)
**     Returns     : Nothing
** ===================================================================
*/
#define IO_Res_Lueft_NegBit(Bit) ((void)BitsIoLdd4_NegBit(BitsIoLdd4_DeviceData, (Bit)))

/* END IO_Res_Lueft. */

#endif 
/* ifndef __IO_Res_Lueft_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
