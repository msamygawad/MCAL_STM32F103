/*****************************************************************************************************
 * FILE DESCRIPTION
 * ---------------------------------------------------------------------------------------------------
 * File name:    GPOI Programme
 * Module :      GPIO Module
 * Description:  file contains the static code for GPIO APIs provided
 * REV:  		1.0
 * DATE:			2023
 * Autor: M. Ehab
 *
 ****************************************************************************************************/

/******************************** Includes Start ****************************************************/
#include "interface_gpio.h"
#include "private_gpio.h"
/******************************** Includes End ******************************************************/

/******************************** Software Interface Implementation Start ***************************/
GPIO_ErrorHandler_Type GPIO_Init(GPIO_Config_Type *GPIO_Pin_CFG)
{
    // Enablicg Clock for GPIOx
    /*
    switch (GPIO_Pin_CFG->GPIO_Port == GPIO_PORTA)
    {
    case GPIO_PORTA:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST);
        break;
    case GPIO_PORTB:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST);
        break;
    case GPIO_PORTC:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST);
        break;
    case GPIO_PORTD:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST);
        break;

    default: return GPIO_InputErr;
        break;
    }
       */

    if (!(GPIO_Pin_CFG->GPIO_Pin_Mode >= GPIO_INPUT && GPIO_Pin_CFG->GPIO_Pin_Mode <= GPIO_OUTPUT_50_MHz))
    {
        return GPIO_InputErr;
    }
    if (!(GPIO_Pin_CFG->GPIO_Pin_Config >= GPIO_PUSH_PULL && GPIO_Pin_CFG->GPIO_Pin_Mode <= GPIO_ALTERNATE_FUNCTION_OPEN_DRAIN))
    {
        return GPIO_InputErr;
    }
    uint32_t temp_value = 0x00;                  // temp value to store the value of the mode and configuration
    temp_value |= GPIO_Pin_CFG->GPIO_Pin_Config; // ORing the configuration with the temp value
    temp_value = temp_value << 2;                // shifting the value to the left by 2 bits to stor in CNF bits
    temp_value |= GPIO_Pin_CFG->GPIO_Pin_Mode;   // ORing the mode with the temp value

    if (GPIO_Pin_CFG->GPIO_Pin <= GPIO_PIN7 && GPIO_Pin_CFG->GPIO_Pin >= GPIO_PIN0)
    {
        temp_value = temp_value << (GPIO_CRL_Offset * GPIO_Pin_CFG->GPIO_Pin); // shifting the value to the left by 4*pin number to store in the right pin
        GPIO_CRL(GPIO_Pin_CFG->GPIO_Port) |= temp_value;                     // ORing the value with the right register
    }
    else if (GPIO_Pin_CFG->GPIO_Pin <= GPIO_PIN15 && GPIO_Pin_CFG->GPIO_Pin >= GPIO_PIN8)
    {
        temp_value = temp_value << (GPIO_CRL_Offset * (GPIO_Pin_CFG->GPIO_Pin - 8));
        GPIO_CRH(GPIO_Pin_CFG->GPIO_Port) |= temp_value;
    }
    else
    {
        return GPIO_InputErr;
    }

    return GPIO_SuccessfulOperation;
}

GPIO_ErrorHandler_Type GPIO_SetPin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin, GPIO_PinLevelType GPIO_Level)
{
    // check if the pin number is valid
    if (GPIO_Pin > GPIO_PIN15 || GPIO_Pin < GPIO_PIN0)
    {
        return GPIO_InputErr;
    }

    // check if the port number is valid
    if (GPIO_Port > GPIO_PORTD || GPIO_Port < GPIO_PORTA)
    {
        return GPIO_InputErr;
    }

    if (GPIO_Level == GPIO_PinHIGH)
    {
        SET_BIT(GPIO_ODR(GPIO_Port), GPIO_Pin);
    }

    else if (GPIO_Level == GPIO_PinLOW)
    {
        CLEAR_BIT(GPIO_ODR(GPIO_Port), GPIO_Pin);
    }

    else
    {
        return GPIO_InputErr;
    }

    return GPIO_SuccessfulOperation;
}

GPIO_ErrorHandler_Type GPIO_GetPin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin)
{

    // check if the pin number is valid
    if (GPIO_Pin > GPIO_PIN15 || GPIO_Pin < GPIO_PIN0)
    {
        return GPIO_InputErr;
    }

    // check if the port number is valid
    if (GPIO_Port > GPIO_PORTD || GPIO_Port < GPIO_PORTA)
    {
        return GPIO_InputErr;
    }

    uint32_t temp_reg = GPIO_IDR(GPIO_Port);

    // check if the pin is high or low
    if (READ_BIT(temp_reg, GPIO_Pin) == GPIO_ReadHIGH)
    {
        return GPIO_ReadHIGH;
    }
    else if (READ_BIT(temp_reg, GPIO_Pin) == GPIO_ReadLOW)
    {
        return GPIO_ReadLOW;
    }
    else
    {
        return GPIO_UnknownErr;
    }
}

GPIO_ErrorHandler_Type GPIO_TogglePin(GPIO_Port_type GPIO_Port, GPIO_Pin_type GPIO_Pin)
{
    // check if the pin number is valid
    if (GPIO_Pin > GPIO_PIN15 || GPIO_Pin < GPIO_PIN0)
    {
        return GPIO_InputErr;
    }

    // check if the port number is valid
    if (GPIO_Port > GPIO_PORTD || GPIO_Port < GPIO_PORTA)
    {
        return GPIO_InputErr;
    }

    TOGGLE_BIT(GPIO_ODR(GPIO_Port), GPIO_Pin);

    return GPIO_SuccessfulOperation;
}

/******************************** Software Interface Implementation End *****************************/