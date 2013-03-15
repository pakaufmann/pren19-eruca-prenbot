/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BitsIoLdd2.c
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
**          Component name                                 : BitsIoLdd2
**          Port                                           : PTE
**          Pins                                           : 4
**            Pin0                                         : 
**              Pin                                        : PTE2/SPI1_SCK
**              Pin signal                                 : US_Front
**            Pin1                                         : 
**              Pin                                        : PTE3/SPI1_MISO/SPI1_MOSI
**              Pin signal                                 : US_Heck
**            Pin2                                         : 
**              Pin                                        : PTE4/SPI1_PCS0
**              Pin signal                                 : US_Rechts_Front
**            Pin3                                         : 
**              Pin                                        : PTE5
**              Pin signal                                 : US_Links_Heck
**          Direction                                      : Output
**          Initialization                                 : 
**            Init. direction                              : Output
**            Init. value                                  : 15
**            AutoInitialization                           : yes
**          Safe mode                                      : yes
**          Optimization for                               : speed
**     Contents    :
**         Init   - LDD_TDeviceData* BitsIoLdd2_Init(LDD_TUserData *UserDataPtr);
**         GetDir - bool BitsIoLdd2_GetDir(LDD_TDeviceData *DeviceDataPtr);
**         GetVal - dword BitsIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         PutVal - void BitsIoLdd2_PutVal(LDD_TDeviceData *DeviceDataPtr, dword Val);
**         GetBit - LDD_TError BitsIoLdd2_GetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool...
**         PutBit - LDD_TError BitsIoLdd2_PutBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool...
**         SetBit - LDD_TError BitsIoLdd2_SetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**         ClrBit - LDD_TError BitsIoLdd2_ClrBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**         NegBit - LDD_TError BitsIoLdd2_NegBit(LDD_TDeviceData *DeviceDataPtr, byte Bit);
**
**     (c) 2012 by Freescale
** ###################################################################*/

/* MODULE BitsIoLdd2. */

#include "BitsIoLdd2.h"


typedef struct {
  LDD_TUserData *UserDataPtr;          /* Pointer to user data */
} BitsIoLdd2_TDeviceData;              /* Device data structure type */

typedef BitsIoLdd2_TDeviceData *BitsIoLdd2_TDeviceDataPtr ; /* Pointer to the device data structure. */

static const uint32_t BitsIoLdd2_PIN_MASK_MAP[4U] = {
   0x04U, 0x08U, 0x10U, 0x20U
};                                     /* Map of masks for each pin */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static BitsIoLdd2_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;


/*
** ===================================================================
**     Method      :  BitsIoLdd2_Init (component BitsIO_LDD)
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
LDD_TDeviceData* BitsIoLdd2_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  BitsIoLdd2_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */

  /* Configure pin directions */
  /* GPIOE_PDDR: PDD|=0x3C */
  GPIOE_PDDR |= GPIO_PDDR_PDD(0x3C);                                                   

  /* Set initialization value */
  /* GPIOE_PDOR: PDO|=0x3C */
  GPIOE_PDOR |= GPIO_PDOR_PDO(0x3C);                                                   
  /* Initialization of Port Control register */
  /* PORTE_PCR2: ISF=0,MUX=1 */
  PORTE_PCR2 = (uint32_t)((PORTE_PCR2 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTE_PCR3: ISF=0,MUX=1 */
  PORTE_PCR3 = (uint32_t)((PORTE_PCR3 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTE_PCR4: ISF=0,MUX=1 */
  PORTE_PCR4 = (uint32_t)((PORTE_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTE_PCR5: ISF=0,MUX=1 */
  PORTE_PCR5 = (uint32_t)((PORTE_PCR5 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  

  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_BitsIoLdd2_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}
/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetDir (component BitsIO_LDD)
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
bool BitsIoLdd2_GetDir(LDD_TDeviceData *DeviceDataPtr)
{

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  return (bool)TRUE;                   /* Pin is fixed to GPO mode */
}
/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetVal (component BitsIO_LDD)
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
dword BitsIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  dword portData;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  portData = GPIO_PDD_GetPortDataOutput(BitsIoLdd2_MODULE_BASE_ADDRESS) & BitsIoLdd2_PORT_MASK;


  return portData >> BitsIoLdd2_PIN_ALLOC_0_INDEX; /* Return port data shifted with the offset of the first allocated pin*/
}
/*
** ===================================================================
**     Method      :  BitsIoLdd2_PutVal (component BitsIO_LDD)
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
void BitsIoLdd2_PutVal(LDD_TDeviceData *DeviceDataPtr, dword Val)
{
  /* Store the raw value of the port, set according to the offset of the first allocated pin */
  dword rawVal;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Calculate the raw data to be set (i.e. shifted to left according to the first allocated pin) */
  rawVal = (Val & BitsIoLdd2_PORT_VALID_VALUE_MASK) << BitsIoLdd2_PIN_ALLOC_0_INDEX; /* Mask and shift output value */

  /* Set port data by toggling the different bits only */
  GPIO_PDD_TogglePortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS,
      (GPIO_PDD_GetPortDataOutput(BitsIoLdd2_MODULE_BASE_ADDRESS) ^ rawVal) & BitsIoLdd2_PORT_MASK);
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetBit (component BitsIO_LDD)
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
LDD_TError BitsIoLdd2_GetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool *BitVal)
{
  uint32_t mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 3U) {
    return ERR_PARAM_MASK;
  }

  /* Bit value returned - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (NULL == BitVal) {
    return ERR_VALUE;
  }

  mask = BitsIoLdd2_PIN_MASK_MAP[Bit];

  if ((GPIO_PDD_GetPortDataOutput(BitsIoLdd2_MODULE_BASE_ADDRESS) & mask) != 0U) {
    *BitVal = (bool)TRUE;
  }
  else {
    *BitVal = (bool)FALSE;
  }

  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_PutBit (component BitsIO_LDD)
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
LDD_TError BitsIoLdd2_PutBit(LDD_TDeviceData *DeviceDataPtr, byte Bit, bool Val)
{
  uint32_t mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 3U) {
    return ERR_PARAM_MASK;
  }

  mask = BitsIoLdd2_PIN_MASK_MAP[Bit];

  if (Val) {
    GPIO_PDD_SetPortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS, mask);
  } else { /* !Val */
    GPIO_PDD_ClearPortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS, mask);
  } /* !Val */

  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_SetBit (component BitsIO_LDD)
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
LDD_TError BitsIoLdd2_SetBit(LDD_TDeviceData *DeviceDataPtr, byte Bit)
{
  uint32_t mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 3U) {
    return ERR_PARAM_MASK;
  }

  mask = BitsIoLdd2_PIN_MASK_MAP[Bit];
  GPIO_PDD_SetPortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS, mask);

  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_ClrBit (component BitsIO_LDD)
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
LDD_TError BitsIoLdd2_ClrBit(LDD_TDeviceData *DeviceDataPtr, byte Bit)
{
  uint32_t mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 3U) {
    return ERR_PARAM_MASK;
  }

  mask = BitsIoLdd2_PIN_MASK_MAP[Bit];
  GPIO_PDD_ClearPortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS, mask);

  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_NegBit (component BitsIO_LDD)
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
LDD_TError BitsIoLdd2_NegBit(LDD_TDeviceData *DeviceDataPtr, byte Bit)
{
  uint32_t mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 3U) {
    return ERR_PARAM_MASK;
  }

  mask = BitsIoLdd2_PIN_MASK_MAP[Bit];
  GPIO_PDD_TogglePortDataOutputMask(BitsIoLdd2_MODULE_BASE_ADDRESS, mask);

  return ERR_OK;
}



/* END BitsIoLdd2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
