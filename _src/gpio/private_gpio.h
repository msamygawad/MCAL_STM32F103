

/*
****************************************************************************************************
* @file					:	private_gpio.h
* @author				:	M.Ehab
* @brief				:	the header file for GPIO driver for STM32 M3
****************************************************************************************************
*/

#ifndef __GPIO_H
#define __GPIO_H

/******************************** Includes Start **************************************************/
#include <stdint.h>
/******************************** Includes End ****************************************************/

/******************************** Macro Declarations Start ****************************************/

/*GPIO STM32 Adresses*/
#define GPIO_BASE_ADDRESS 0x40010800
#define GPIO_Offset 0x400
#define GPIO_CRL_Offset 4
#define GPIO_REG_Offset 0x04

/*GPIO Registers */
#define GPIOA_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * GPIO_PORTA)
#define GPIOB_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * GPIO_PORTB)
#define GPIOC_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * GPIO_PORTC)
#define GPIOD_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * GPIO_PORTD)

/*GPIO Structures*/
#define GPIOA_Type ((GPIO_TypeDef *)GPIOA_BASE_ADDRESS)
#define GPIOB_Type ((GPIO_TypeDef *)GPIOB_BASE_ADDRESS)
#define GPIOC_Type ((GPIO_TypeDef *)GPIOC_BASE_ADDRESS)
#define GPIOD_Type ((GPIO_TypeDef *)GPIOD_BASE_ADDRESS)

/*port base addresses*/
#define GPIOA GPIOA_BASE_ADDRESS
#define GPIOB GPIOB_BASE_ADDRESS
#define GPIOC GPIOC_BASE_ADDRESS
#define GPIOD GPIOD_BASE_ADDRESS

/******************************** Macro Declarations End ******************************************/

/******************************** Macro Function Declarations Start *******************************/

// GPIO Registers
#define GPIO_CRL(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 0)))
#define GPIO_CRH(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 1)))
#define GPIO_IDR(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 2)))
#define GPIO_ODR(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 3)))
#define GPIO_BSRR(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 4)))
#define GPIO_BRR(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 5)))
#define GPIO_LCKR(GPIO_PORT) (*((volatile uint32_t *)((GPIO_PORT) + GPIO_REG_Offset * 6)))

// Bit Manipulation

#define SET_Value(REG, Value) ((REG) |= Value)
#define CLEAR_Value(REG, Value) ((REG) &= (~Value))
#define SET_BIT(REG, BIT) ((REG) |= ((uint32_t)0x01 << (BIT)))
#define CLEAR_BIT(REG, BIT) ((REG) &= (~((uint32_t)0x01 << BIT)))
#define TOGGLE_BIT(REG, BIT) ((REG) ^= ((uint32_t)0x01 << BIT))
#define READ_BIT(REG, BIT) ((REG) &= (((uint32_t)0x01 << BIT)))

/******************************** Macro Function Declarations End *********************************/

/******************************** Data Type Declarations Start ************************************/




/*STM32 GPIO Registers Datatypes*/
typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;



/******************************** Data Type Declarations End **************************************/


#endif /* __GPIO_H*/