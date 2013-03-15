/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ExtIntLdd9.c
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
**          Component name                                 : ExtIntLdd9
**          Pin                                            : PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO
**          Pin signal                                     : 
**          Generate interrupt on                          : rising or falling edge
**          Interrupt                                      : INT_PORTD
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          Threshold level                                : 0
**     Contents    :
**         Init   - LDD_TDeviceData* ExtIntLdd9_Init(LDD_TUserData *UserDataPtr);
**         GetVal - bool ExtIntLdd9_GetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ExtIntLdd9. */

#include "Stop.h"
#include "ExtIntLdd9.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"


typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} ExtIntLdd9_TDeviceData, *ExtIntLdd9_TDeviceDataPtr; /* Device data structure type */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static ExtIntLdd9_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static ExtIntLdd9_TDeviceData * INT_PORTD__DEFAULT_RTOS_ISRPARAM;

/*
** ===================================================================
**     Method      :  ExtIntLdd9_Init (component ExtInt_LDD)
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
LDD_TDeviceData* ExtIntLdd9_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  ExtIntLdd9_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Store the UserData pointer */
  DeviceDataPrv->UserData = UserDataPtr;
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTD__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* Clear interrupt status flag - w1c */
  PORTD_ISFR = PORT_ISFR_ISF(0x04);                                                   
  /* Initialization of Port Control registers */
  /* PORTD_PCR2: ISF=0,IRQC=9,MUX=1 */
  PORTD_PCR2 = (uint32_t)((PORTD_PCR2 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x06) |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_IRQC(0x09) |
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* NVIC_IPR7: PRI_31=0x80 */
  NVIC_IPR7 = (uint32_t)((NVIC_IPR7 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_31(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_31(0x80)
              ));                                                  
  /* NVIC_ISER: SETENA|=0x80000000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x80000000);                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_ExtIntLdd9_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  ExtIntLdd9_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ExtIntLdd9_Interrupt(void)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  ExtIntLdd9_TDeviceDataPtr DeviceDataPrv = INT_PORTD__DEFAULT_RTOS_ISRPARAM;

  /* Check the pin interrupt flag of the shared interrupt */
  if (PORT_PDD_GetPinInterruptFlag(ExtIntLdd9_PORTCONTROL_BASE_ADDRESS, ExtIntLdd9_PIN_INDEX)) {

    /* Clear the interrupt flag */
    PORT_PDD_ClearPinInterruptFlag(ExtIntLdd9_PORTCONTROL_BASE_ADDRESS, ExtIntLdd9_PIN_INDEX);

    /* Call OnInterrupt event */
    ExtIntLdd9_OnInterrupt(DeviceDataPrv->UserData);
  }
}
/*
** ===================================================================
**     Method      :  ExtIntLdd9_GetVal (component ExtInt_LDD)
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
bool ExtIntLdd9_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  if ((GPIO_PDD_GetPortDataInput(ExtIntLdd9_MODULE_BASE_ADDRESS) & ExtIntLdd9_PIN_MASK) != 0U) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/* END ExtIntLdd9. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
