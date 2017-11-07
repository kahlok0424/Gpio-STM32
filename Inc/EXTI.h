/*
 * EXT.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user1
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>

#define EXTI_BASE_ADR     0x40013c00
#define Exti              ((ExtiReg *)(EXTI_BASE_ADR))

typedef struct ExtiReg ExtiReg;
struct ExtiReg{
	volatile uint32_t IMR;            //interrupt mask
	volatile uint32_t EMR;       	 //event mask
	volatile uint32_t RTSR;			 //Rising trigger selection register
	volatile uint32_t FTSR;		     //Falling trigger selection register
	volatile uint32_t SWIER;	     //Software interrupt event register
	volatile uint32_t PR;		     //pending register
};

#define SYSC_BASE_ADR     0x40013800
#define Sysc              ((SyscfgReg *)(SYSC_BASE_ADR))

typedef struct SyscfgReg SyscfgReg;
struct SyscfgReg{
	volatile uint32_t MEMRMP;            //interrupt mask
	volatile uint32_t PMC;       	 //event mask
	volatile uint32_t EXTICR1;			 //Rising trigger selection register
	volatile uint32_t EXTICR2;		     //Falling trigger selection register
	volatile uint32_t EXTICR3;	     //Software interrupt event register
	volatile uint32_t EXTICR4;		     //pending register
	volatile uint32_t CMPCR;		     //pending register
};

#define PA 0x0000
#define PB 0x0001

#define extiIntrMaskEnable(pin)            (Exti->IMR |= (1 << pin))
#define extiIntrMaskDisable(pin)           (Exti->IMR &= ~(1 << pin))
#define extiEventMaskEnable(pin)           (Exti->EMR |= (1 << pin))
#define extiEventMaskDisable(pin)          (Exti->EMR &= ~(1 << pin))
#define extiEnableRisingTrigger(pin)       (Exti->RTSR |= (1 << pin))
#define extiDisableRisingTrigger(pin)      (Exti->RTSR &= ~(1 << pin))
#define extiEnableFallingTrigger(pin)      (Exti->FTSR |= (1 << pin))
#define extiDisableFallingTrigger(pin)     (Exti->FTSR &= ~(1 << pin))
#define resetPending(pin)                  (Exti->PR |= (1 << pin))
#define syscfgEnableExtIntr1(PA)           (Sysc->EXTICR1 = PA)

#endif /* EXTI_H_ */
