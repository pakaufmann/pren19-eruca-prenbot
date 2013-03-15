/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ExtIntLdd3.c
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
**          Component name                                 : ExtIntLdd3
**          Pin                                            : PTA17/SPI0_MISO/SPI0_MOSI
**          Pin signal                                     : 
**          Generate interrupt on                          : falling edge
**          Interrupt                                      : INT_PORTA
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          Threshold level                                : 0
**     Contents    :
**         Init    - LDD_TDeviceData* ExtIntLdd3_Init(LDD_TUserData *UserDataPtr);
**         Enable  - void ExtIntLdd3_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - void ExtIntLdd3_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetVal  - bool ExtIntLdd3_GetVal(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ExtIntLdd3. */

#include "US_FrontListener.h"
#include "ExtIntLdd3.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"


typedef struct {
  bool UserEnabled;                    /* Enable/Disable device flag*/
  LDD_TUserData *UserData;             /* RTOS device data structure */
} ExtIntLdd3_TDeviceData, *ExtIntLdd3_TDeviceDataPtr; /* Device data structure type */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static ExtIntLdd3_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static ExtIntLdd3_TDeviceData * INT_PORTA__DEFAULT_RTOS_ISRPARAM;

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Init (component ExtInt_LDD)
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
LDD_TDeviceData* ExtIntLdd3_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  ExtIntLdd3_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Store the UserData pointer */
  DeviceDataPrv->UserData = UserDataPtr;
  /* Set device as Disable */
  DeviceDataPrv->UserEnabled = FALSE;
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTA__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* Clear interrupt status flag - w1c */
  PORTA_ISFR = PORT_ISFR_ISF(0x00020000);                                                   
  /* Initialization of Port Control registers */
  /* PORTA_PCR17: ISF=0,IRQC=0,MUX=1 */
  PORTA_PCR17 = (uint32_t)((PORTA_PCR17 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_IRQC(0x0F) |
                 PORT_PCR_MUX(0x06)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x01)
                ));                                                  
  /* NVIC_IPR7: PRI_30=0x80 */
  NVIC_IPR7 = (uint32_t)((NVIC_IPR7 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_30(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_30(0x80)
              ));                                                  
  /* NVIC_ISER: SETENA|=0x40000000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x40000000);                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_ExtIntLdd3_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Enable (component ExtInt_LDD)
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
void ExtIntLdd3_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  ExtIntLdd3_TDeviceData *DeviceDataPrv = (ExtIntLdd3_TDeviceData *)DeviceDataPtr;
  PORT_PDD_ClearPinInterruptFlag(ExtIntLdd3_PORTCONTROL_BASE_ADDRESS, ExtIntLdd3_PIN_INDEX);
  PORT_PDD_SetPinInterruptConfiguration(ExtIntLdd3_PORTCONTROL_BASE_ADDRESS,\
                                        ExtIntLdd3_PIN_INDEX, ExtIntLdd3_IRQ_CONFIG);

  DeviceDataPrv->UserEnabled = TRUE;   /* Set device as Enabled */
}

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Disable (component ExtInt_LDD)
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
void ExtIntLdd3_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  ExtIntLdd3_TDeviceData *DeviceDataPrv = (ExtIntLdd3_TDeviceData *)DeviceDataPtr;

  PORT_PDD_SetPinInterruptConfiguration(ExtIntLdd3_PORTCONTROL_BASE_ADDRESS,\
                                        ExtIntLdd3_PIN_INDEX, PORT_PDD_INTERRUPT_DMA_DISABLED);

  DeviceDataPrv->UserEnabled = FALSE;  /* Set device as Disabled */
}

/*
** ===================================================================
**     Method      :  ExtIntLdd3_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ExtIntLdd3_Interrupt(void)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  ExtIntLdd3_TDeviceDataPtr DeviceDataPrv = INT_PORTA__DEFAULT_RTOS_ISRPARAM;

  /* Check if device is disabled */
  if( !DeviceDataPrv->UserEnabled ){
    return;
  }

  /* Check the pin interrupt flag of the shared interrupt */
  if (PORT_PDD_GetPinInterruptFlag(ExtIntLdd3_PORTCONTROL_BASE_ADDRESS, ExtIntLdd3_PIN_INDEX)) {

    /* Clear the interrupt flag */
    PORT_PDD_ClearPinInterruptFlag(ExtIntLdd3_PORTCONTROL_BASE_ADDRESS, ExtIntLdd3_PIN_INDEX);

    /* Call OnInterrupt event */
    ExtIntLdd3_OnInterrupt(DeviceDataPrv->UserData);
  }
}
/*
** ===================================================================
**     Method      :  ExtIntLdd3_GetVal (component ExtInt_LDD)
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
bool ExtIntLdd3_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  if ((GPIO_PDD_GetPortDataInput(ExtIntLdd3_MODULE_BASE_ADDRESS) & ExtIntLdd3_PIN_MASK) != 0U) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/* END ExtIntLdd3. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
