/*
 * NVIC.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user1
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

#define NVIC_BASE_ADR     0xE000E100
#define Nvic              ((NvicReg *)(NVIC_BASE_ADR))

typedef struct NvicReg NvicReg;
struct NvicReg{
	volatile uint32_t ISER[3];               //Interrupt set enable (0h)
	volatile uint32_t reserved1[29];
	volatile uint32_t ICER[3];       		 //Interrupt clear enable (80h)
	volatile uint32_t reserved2[29];
	volatile uint32_t ISPR[3];				//Interrupt set-pending (110h)
	volatile uint32_t reserved3[29];
	volatile uint32_t ICPR[3];				//Interrupt clear-pending (180h)
	volatile uint32_t reserved4[29];
	volatile uint32_t IABR[3];             //Interrupt clear-pending (200h)
	volatile uint32_t reserved5[61];
	volatile uint32_t IPR[21];             //Interrupt priority (300h)
	volatile uint32_t reserved6[683];
	volatile uint32_t STIR[3];				//(e00h)
};

#define nvicEnableIrq(irqNum)              (Nvic->ISER[irqNum >> 5] |= 1 << (irqNum & 0x1f) )
#define nvicDisableIrq(irqNum)             (Nvic->ICER[irqNum >> 5] |= 1 << (irqNum & 0x1f) )
#define nvicSetPriority(irqNum,priority)   (Nvic->IPR[irqNum >> 2] |= priority << ((irqNum & 0x3) * 8 + 4))

#define nvicTriggerSoftwareInterrupt        (((NvicReg *)(NVIC_BASE_ADR)))

#endif /* NVIC_H_ */
