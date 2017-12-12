/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADR        0x40023800
#define RCC_AHB1RST_OFF     0x10
#define RCC_AHB1EN_OFF      0x30
#define rcc                 ((RccReg *)(RCC_BASE_ADR))

//export variables to other modules
extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAHB1En;

void enableGpioG(void);
void enableGpioA(void);
void enableGpioB(void);
void enableGpioC(void);
void enableGpio(int Gpiox);
void enableRNG(void);
void enableTimer8();
void enableI2C(int value);
void enableUSART1(void);

typedef struct RccReg RccReg;
struct RccReg{
	volatile uint32_t CR;            //0h
	volatile uint32_t PLLCFGR;       //4h
	volatile uint32_t CFGR;          //8h
	volatile uint32_t CIR;           //ch
	volatile uint32_t AHB1RSTR;      //10h
	volatile uint32_t AHB2RSTR;      //14h
	volatile uint32_t AHB3RSTR;      //18h
	volatile uint32_t reserved1;     //1ch
	volatile uint32_t APB1RSTR;      //20h
	volatile uint32_t APB2RSTR;      //24h
	volatile uint32_t reserved2[2];  //28h //2ch
	volatile uint32_t AHB1ENR;       //30h
	volatile uint32_t AHB2ENR;       //34h
	volatile uint32_t AHB3ENR;       //38h
	volatile uint32_t reserved3;     //3ch
	volatile uint32_t APB1ENR;       //40h
	volatile uint32_t APB2ENR;       //44h
	volatile uint32_t reserved4[2];  //48h //4ch
	volatile uint32_t AHB1LPENR;     //50h
	volatile uint32_t AHB2LPENR;     //54h
	volatile uint32_t AHB3LPENR;     //58h
	volatile uint32_t reserved5;     //5ch
	volatile uint32_t APB1LPENR;     //60h
	volatile uint32_t APB2LPENR;     //64h
	volatile uint32_t reserved6[2];  //68h //6ch
	volatile uint32_t BDCR;          //70h
	volatile uint32_t CSR;           //74h
	volatile uint32_t reserved7[2];  //78h //7ch
	volatile uint32_t SSCGR;         //80h
	volatile uint32_t PLLI2SCFGR;    //84h
};

#define MCO_HSI_SRC        0
#define MCO_LSE_SRC        1
#define MCO_HSE_SRC        2
#define MCO_PLL_SRC        3

#define MCO_DIV_NO_DIV     0
#define MCO_DIV_BY_2       4
#define MCO_DIV_BY_3       5
#define MCO_DIV_BY_4       6
#define MCO_DIV_BY_5       7

#define rccSelectMco1Src(x)       {                                \
                                    (rcc->CFGR &= ~(3<<21));       \
                                    (rcc->CFGR |= (x<<21));        \
                                  }

#define rccMCo1Prescaler(x)       {                                \
	                                (rcc->CFGR &= ~(7<<24));       \
	                                (rcc->CFGR |= (x<<24));        \
                                  }

#endif /* RCC_H_ */
