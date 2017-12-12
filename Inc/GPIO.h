/*
 * GPIO.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define GPIOA_BASE_ADR        0x40020000
#define GPIOB_BASE_ADR        0x40020400
#define GPIOC_BASE_ADR        0x40020800
#define GPIOD_BASE_ADR        0x40020c00
#define GPIOE_BASE_ADR        0x40021000
#define GPIOF_BASE_ADR        0x40021400
#define GPIOG_BASE_ADR        0x40021800
#define GPIOH_BASE_ADR        0x40021c00
#define GPIOI_BASE_ADR        0x40022000

/*#define GPIO_MODE_OFF         0x0
#define GPIO_OUTPUT_SPEED     0x8
#define GPIO_PP_OD            0x4
#define GPIO_PUPD             0xc
#define GPIO_ODR             0x14*/

typedef struct GpioReg GpioReg;
#define GpioA   ((GpioReg *)(GPIOA_BASE_ADR))
#define GpioB   ((GpioReg *)(GPIOB_BASE_ADR))
#define GpioC   ((GpioReg *)(GPIOC_BASE_ADR))
#define GpioD   ((GpioReg *)(GPIOD_BASE_ADR))
#define GpioE   ((GpioReg *)(GPIOE_BASE_ADR))
#define GpioF   ((GpioReg *)(GPIOF_BASE_ADR))
#define GpioG   ((GpioReg *)(GPIOG_BASE_ADR))
#define GpioH   ((GpioReg *)(GPIOH_BASE_ADR))
#define GpioI   ((GpioReg *)(GPIOI_BASE_ADR))

struct GpioReg{
	volatile uint32_t mode;         //0h
	volatile uint32_t outType;      //4h
	volatile uint32_t outSpeed;     //8h
	volatile uint32_t pullType;     //ch
	volatile uint32_t inData;       //10h
	volatile uint32_t outData;      //14h
	volatile uint32_t BSRR;         //18h
	volatile uint32_t lock;         //1ch
	volatile uint32_t altFuncLo;    //20h
	volatile uint32_t altFuncHi;    //24h
};

//GPIO MODE
#define GPIO_MODE_IN       0
#define GPIO_MODE_OUT      1
#define GPIO_MODE_AF      2
#define GPIO_MODE_AN      3

//GPIO SPEED
#define GPIO_SPD_LOW        0
#define GPIO_SPD_MEDIUM     1
#define GPIO_SPD_HIGH       2
#define GPIO_SPD_VERY_HIGH  3

//GPIO out drive mode
#define GPIO_OTYPE_PP         0
#define GPIO_OTYPE_OD         1

//GPIO pull type
#define GPIO_PUPD_NO_PULL     0
#define GPIO_PUPD_PULL_UP     1
#define GPIO_PUPD_PULL_DOWN   2
#define GPIO_PUPD_RESERVE     3

//GPIO alternate function
#define AF0      0x0000
#define AF1      0x0001
#define AF2      0x0010
#define AF3      0x0011
#define AF4      0x0100
#define AF5      0x0101
#define AF6      0x0110
#define AF7      7
#define AF8      0x1000
#define AF9      0x1001
#define AFa      0x1010
#define AFb      0x1011
#define AFc      0x1100
#define AFd      0x1101
#define AFe      0x1110
#define AFf      0x1111


#define SET_PIN(gpio,pinNum)            gpio->BSRR = (1<<pinNum)
#define RESET_PIN(gpio,pinNum)          gpio->BSRR = (1<<(16+pinNum))

void gpioConfig(GpioReg *gpio,int pin ,int mode ,int outDriveType, int pullType , int speed);
void gpioWrite(GpioReg *gpio,int pin,int state);
int gpioRead(GpioReg *gpio, int pin);
void gpioLock(GpioReg *gpio,int pin);
void gpioAlfConfig(GpioReg *gpio,int pin,int func);
void gpioConfigAltFuncNum(GpioReg *Gpio,int pin,int func);


#endif /* GPIO_H_ */
