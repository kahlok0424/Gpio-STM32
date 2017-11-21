/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */

#ifndef TIMER_H_
#define TIMER_H_

#include<stdint.h>

#define TIMER8_BASE_ADDR	 0x40010400
#define timer8              ((TimerReg *)(TIMER8_BASE_ADDR))

typedef struct TimerReg TimerReg;
struct TimerReg{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
};

void initTimer8(int value,int presc);

#endif /* TIMER_H_ */
