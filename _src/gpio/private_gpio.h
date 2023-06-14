

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
/******************************** Includes End ****************************************************/

/******************************** Macro Declarations Start ****************************************/

/*GPIO STM32 Adresses*/
#define GPIO_BASE_ADDRESS 0x40010800
#define GPIO_Offset 0x400
#define GPIO_CRL_Offset 4

/*GPIO Registers */
#define GPIOA_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * 0)
#define GPIOB_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * 1)
#define GPIOC_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * 2)
#define GPIOD_BASE_ADDRESS (GPIO_BASE_ADDRESS + GPIO_Offset * 3)

/*GPIO Structures*/
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE_ADDRESS)

/*GPIO Modes*/
#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT_10_MHz 1
#define GPIO_MODE_OUTPUT_2_MHz 2
#define GPIO_MODE_OUTPUT_50_MHz 3
#define GPIO_MODE_OUTPUT 3 // GPIO Output with MAX speed

/*GPIO INPUT Configurations*/
#define GPIO_CFG_INPUT_Analog_mode 0 // input mode analog
#define GPIO_CFG_INPUT_Floating 1    // input mode floating
#define GPIO_CFG_INPUT_PUPD 2        // input mode pull up / pull down

/*GPIO OUTPUt Configurations*/
#define GPIO_CFG_OUTPUT_PP 0 // output mode push pull
#define GPIO_CFG_OUTPUT_OD 1 // output mode open drain
#define GPIO_CFG_AF_PP 2     // alternate function push pull
#define GPIO_CFG_AF_OD 3     // alternate function open drain

/*GPIO Values*/
#define LOW 0
#define HIGH 1

/*GPIO Pins*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

/*GPIO Ports*/
#define PA 0
#define PB 1
#define PC 2
#define PD 3

/******************************** Macro Declarations End ******************************************/

/******************************** Macro Function Declarations Start *******************************/
/******************************** Macro Function Declarations End *********************************/

/******************************** Data Type Declarations Start ************************************/

/* Standard Data Types*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;

/*STM32 GPIO Registers Datatypes*/
typedef struct
{
    volatile u32 CRL;
    volatile u32 CRH;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 BRR;
    volatile u32 LCKR;
} GPIO_TypeDef;

/******************************** Data Type Declarations End **************************************/

/******************************** Software Interface Declarations Start ***************************/
void GPIO_Init(u32 GPIOx, u32 GPIO_Pin, u8 GPIO_Mode, u8 GPIO_CFG); // Intiate  GPIO functionality
void GPIO_Init_Port(u32 GPIOx, u8 GPIO_Mode, u8 GPIO_CFG);         // Intiate  GPIO Port functionality

void GPIO_SetPin(u32 GPIOx, u32 GPIO_Pin, u32 GPIO_Value); // Set GPIO Pin Output Value HIGH, LOW
void GPIO_SetPort(u32 GPIOx, u32 GPIO_Value);              // Set GPIO Port Output Value HIGH, LOW

u32 GPIO_GetPin(u32 GPIOx, u32 GPIO_Pin);                           // Get GPIO Pin Input Value
u32 GPIO_GetPort(u32 GPIOx);                                        // Get GPIO Port Input Value

void GPIO_TogglePin(u32 GPIOx, u32 GPIO_Pin);                       // Toggle GPIO Pin Output Value
void GPIO_TogglePort(u32 GPIOx);                                    // Toggle GPIO Port Output Value
/******************************** Software Interface Declarations End *****************************/

#endif /* __GPIO_H*/