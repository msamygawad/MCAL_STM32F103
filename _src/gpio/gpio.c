

/*
****************************************************************************************************
* @file					:	gpio.c
* @author				:	M.Ehab
* @brief				:	the file contains static code for GPIO driver for STM32 M3
****************************************************************************************************
*/

/******************************** Includes Start **************************************************/
#include "private_gpio.h"
/******************************** Includes End ****************************************************/

/******************************** Software Interface Implementation Start ***************************/
void GPIO_Init_PIN(u32 GPIOx, u32 GPIO_Pin, u8 GPIO_Mode, u8 GPIO_CFG)
{
    /* Enablicg Clock for GPIOx
        if (GPIOx == PA)
        {
            RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
            RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST);
        }
        else if (GPIOx == PB)
        {
            RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
            RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST);
        }
        else if (GPIOx == PC)
        {
            RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
            RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST);
        }
        else if (GPIOx == PD)
        {
            RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
            RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST);
        }
    */
    u32 temp_value = 0x00;        // temp value to store the value of the mode and configuration
    temp_value |= GPIO_CFG;       // ORing the configuration with the temp value
    temp_value = temp_value << 2; // shifting the value to the left by 2 bits to stor in CNF bits
    temp_value |= GPIO_Mode;      // ORing the mode with the temp value

    if (GPIO_Pin <= PIN7)
    {
        temp_value = temp_value << GPIO_CRL_Offset * GPIO_Pin; // shifting the value to the left by 4*pin number to store in the right pin
        switch (GPIOx)
        {
        case PA:
            GPIOA->CRL |= temp_value;
            break;
        case PB:
            GPIOB->CRL |= temp_value;
            break;
        case PC:
            GPIOC->CRL |= temp_value;
            break;
        case PD:
            GPIOD->CRL |= temp_value;
            break;
        }
    }
    else
    {
        temp_value = temp_value << GPIO_CRL_Offset * (GPIO_Pin - 8);
        switch (GPIOx)
        {
        case PA:
            GPIOA->CRH |= temp_value;
            break;
        case PB:
            GPIOB->CRH |= temp_value;
            break;
        case PC:
            GPIOC->CRH |= temp_value;
            break;
        case PD:
            GPIOD->CRH |= temp_value;
            break;
        }
    }
}

void GPIO_Init_Port(u32 GPIOx, u8 GPIO_Mode, u8 GPIO_CFG)
{
    /* Enablicg Clock for GPIOx
    if (GPIOx == PA)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST);
    }
    else if (GPIOx == PB)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST);
    }
    else if (GPIOx == PC)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST);
    }
    else if (GPIOx == PD)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
        RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST);
    }
*/
    u32 temp_value = 0x00;
    temp_value |= GPIO_CFG;
    temp_value = temp_value << 2;
    temp_value |= GPIO_Mode;
    switch (GPIOx)
    {
    case PA:
        for (u8 i = 0; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOA->CRL |= temp_value;
        }
        for (u8 i = 8; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOA->CRH |= temp_value;
        }
        break;
    case PB:
        for (u8 i = 0; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOB->CRL |= temp_value;
        }
        for (u8 i = 8; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOB->CRH |= temp_value;
        }
        break;
    case PC:
        for (u8 i = 0; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOC->CRL |= temp_value;
        }
        for (u8 i = 8; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOC->CRH |= temp_value;
        }
        break;
    case PD:
        for (u8 i = 0; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOD->CRL |= temp_value;
        }
        for (u8 i = 8; i < 8; i++)
        {
            temp_value = temp_value << GPIO_CRL_Offset * i;
            GPIOD->CRH |= temp_value;
        }
        break;
    }
}

void GPIO_SetPin(u32 GPIOx, u32 GPIO_Pin, u32 GPIO_Value)
{

    u32 temp_value = 0x01;

    if (GPIO_Value == HIGH)
    {
        /* Check on the Required PORT Number */
        temp_value |= ((u32)0x01 << (GPIO_Pin));
        switch (GPIOx)
        {
        case PA:
            GPIOA->ODR |= temp_value;
            break;
        case PB:
            GPIOB->ODR |= temp_value;
            break;
        case PC:
            GPIOC->ODR |= temp_value;
            break;
        case PD:
            GPIOD->ODR |= temp_value;
            break;
        }
    }

    else if (GPIO_Value == LOW)
    {
        temp_value &= (~((u32)0x01 << GPIO_Pin));
        switch (GPIOx)
        {
        case PA:
            GPIOA->ODR &= (~((u32)0x01 << GPIO_Pin));
            break;
        case PB:
            GPIOB->ODR &= (~((u32)0x01 << GPIO_Pin));
            break;
        case PC:
            GPIOC->ODR &= (~((u32)0x01 << GPIO_Pin));
            break;
        case PD:
            GPIOD->ODR &= (~((u32)0x01 << GPIO_Pin));
            break;
        }
    }
}

void GPIO_SetPort(u32 GPIOx, u32 GPIO_Value)
{
    switch (GPIOx)
    {
    case PA:
        GPIOA->ODR |= GPIO_Value;
        break;
    case PB:
        GPIOB->ODR |= GPIO_Value;
        break;
    case PC:
        GPIOC->ODR |= GPIO_Value;
        break;
    case PD:
        GPIOD->ODR |= GPIO_Value;
        break;
    }
}




u32 GPIO_GetPin(u32 GPIOx, u32 GPIO_Pin)
{
    u32 temp_value = 0x00;
    switch (GPIOx)
    {
    case PA:
        temp_value = GPIOA->IDR;
        break;
    case PB:
        temp_value = GPIOB->IDR;
        break;
    case PC:
        temp_value = GPIOC->IDR;
        break;
    case PD:
        temp_value = GPIOD->IDR;
        break;
    }
    temp_value = temp_value >> GPIO_Pin;
    temp_value &= (u32)0x01;
    return temp_value;
}

u32 GPIO_GetPort(u32 GPIOx)
{
    u32 temp_value = 0x00;
    switch (GPIOx)
    {
    case PA:
        temp_value = GPIOA->IDR;
        break;
    case PB:
        temp_value = GPIOB->IDR;
        break;
    case PC:
        temp_value = GPIOC->IDR;
        break;
    case PD:
        temp_value = GPIOD->IDR;
        break;
    }
    return temp_value;
}

void GPIO_TogglePort(u32 GPIOx)
{
    switch (GPIOx)
    {
    case PA:
        GPIOA->ODR ^= 0xFFFFFFFF;
        break;
    case PB:
        GPIOB->ODR ^= 0xFFFFFFFF;
        break;
    case PC:
        GPIOC->ODR ^= 0xFFFFFFFF;
        break;
    case PD:
        GPIOD->ODR ^= 0xFFFFFFFF;
        break;
    }
}

void GPIO_TogglePin(u32 GPIOx, u32 GPIO_Pin)
{
    switch (GPIOx)
    {
    case PA:
        GPIOA->ODR ^= ((u32)0x01 << GPIO_Pin);
        break;
    case PB:
        GPIOB->ODR ^= ((u32)0x01 << GPIO_Pin);
        break;
    case PC:
        GPIOC->ODR ^= ((u32)0x01 << GPIO_Pin);
        break;
    case PD:
        GPIOD->ODR ^= ((u32)0x01 << GPIO_Pin);
        break;
    }
}



/******************************** Software Interface Implementation End *****************************/