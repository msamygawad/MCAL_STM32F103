/************************************************************************************************************************
 * FILE DESCRIPTION
 * -----------------------------------------------------------------------------------------------------------------------
 * File name:    GPOI Interface
 * Module :      GPIO Module
 * Description:  Header to be included in any other module to use GPIO APIs provided here
 * REV:  		1.0
 * DATE:			2023
 * Autor: M. Ehab
 *
 ************************************************************************************************************************/

#ifndef __INTERFACE_GPIO_H
#define __INTERFACE_GPIO_H

/******************************** Includes Start **************************************************/

// standard data types
#include <stdint.h>

/******************************** Includes End ****************************************************/

/******************************** Data Type Declarations Start ************************************/
/*GPIO Pins*/
typedef enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15
} GPIO_Pin_type;

/*GPIO Ports*/
typedef enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD
} GPIO_Port_type;

/*GPIO Pin Mode*/
typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT_10_MHz,
    GPIO_OUTPUT_2_MHz,
    GPIO_OUTPUT_50_MHz
} GPIO_Pin_Mode_type;

/*GPIO Pin Configuration*/
typedef enum
{
    // Output Configuration
    GPIO_PUSH_PULL,
    GPIO_OPEN_DRAIN,
    GPIO_ALTERNATE_FUNCTION_PUSH_PULL,
    GPIO_ALTERNATE_FUNCTION_OPEN_DRAIN,
    // Input Configuration
    GPIO_ANALOG_MODE = 0,
    GPIO_FLOATING,
    GPIO_PULL_UP_PULL_DOWN

} GPIO_Pin_Config_type;

/*GPIO Output Level*/
typedef enum
{
    GPIO_PinLOW,
    GPIO_PinHIGH
} GPIO_PinLevelType;



typedef struct
{
    GPIO_Pin_type GPIO_Pin;
    GPIO_Port_type GPIO_Port;
    GPIO_Pin_Mode_type GPIO_Pin_Mode;
    GPIO_Pin_Config_type GPIO_Pin_Config;
    GPIO_PinLevelType GPIO_PinLevel;
} GPIO_Config_Type;


/*GPIO Error Handler*/
typedef enum
{
    GPIO_ReadLOW,
    GPIO_ReadHIGH,
    GPIO_SuccessfulOperation,
    GPIO_InputErr,
    GPIO_UnknownErr
} GPIO_ErrorHandler_Type;
/******************************** Data Type Declarations End **************************************/

/******************************** Software Interface Declarations Start ***************************/

/*******************************************************************************
 * NAME : GPIO_Init
 * ID : 0x00
 * SYNC/ASYNC : SYNC (Automatically Enables Clock For GPIOx)
 * REENTRANCY : Reentrant
 * PARAMETER/IN : Struct of type GPIO_Config_Type with configuration parameters
 * PARAMETER/OUT :
 * PARAMETER/IN-OUT : N/A
 * RETURN VALUE :  GPIO_Successful Operation | GOIP_InputErr
 * DESCRIPTION : Initializes GPIOx configuration x:(Port A,B,C,D,E,F,G)
 *******************************************************************************/
GPIO_ErrorHandler_Type GPIO_Init(GPIO_Config_Type *GPIO_Pin_CFG);

/*******************************************************************************
 * NAME : GPIO_SetPin
 * ID : 0x01
 * SYNC/ASYNC : SYNC (Must Initialize GPIOx First)
 * REENTRANCY : Reentrant
 * PARAMETER/IN : Port Number, Pin Number, Pin Level
 * PARAMETER/OUT :
 * PARAMETER/IN-OUT : N/A
 * RETURN VALUE :  GPIO_Successful Operation | GOIP_InputErr
 * DESCRIPTION : Sets GPIO Pin Output Value
 *******************************************************************************/
GPIO_ErrorHandler_Type GPIO_SetPin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin, GPIO_PinLevelType GPIO_Level);

/*******************************************************************************
 * NAME : GPIO_GetPin
 * ID : 0x03
 * SYNC/ASYNC : SYNC (Must Initialize GPIOx First)
 * REENTRANCY : Reentrant
 * PARAMETER/IN : Port Number, Pin Number
 * PARAMETER/OUT :
 * PARAMETER/IN-OUT : N/A
 * RETURN VALUE :  ReadHIGH | ReadLOW | GPIO_UnkownErr| GOIP_InputErr
 * DESCRIPTION :    Reads GPIO Pin Input Value
 *******************************************************************************/
GPIO_ErrorHandler_Type GPIO_GetPin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin); // Get GPIO Pin Input Value

/*******************************************************************************
 * NAME : GPIO_GetPin
 * ID : 0x04
 * SYNC/ASYNC : SYNC (Must Initialize GPIOx First)
 * REENTRANCY : Reentrant
 * PARAMETER/IN : Port Number, Pin Number
 * PARAMETER/OUT :
 * PARAMETER/IN-OUT : N/A
 * RETURN VALUE :  GPIO_Successful Operation | GOIP_InputErr
 * DESCRIPTION :    Toggles GPIO Pin Output Value
 *******************************************************************************/
GPIO_ErrorHandler_Type GPIO_TogglePin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin); // Toggle GPIO Pin Output Value

/******************************** Software Interface Declarations End *****************************/

#endif // __INTERFACE_GPIO_H