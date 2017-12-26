/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */

#ifndef TIMER_H_
#define TIMER_H_

#include<stdint.h>
#include "Rcc.h"
#include "GPIO.h"

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

#define CCPC	1
#define CC1P	~(1<<1)
#define CC1E	1
#define OC1M	4
#define MOE		(1<<15)
#define OC1FE	(1<<2)

void initTimer8(int value,int presc);
void initTimer8Chn1();
void initTimer8Chn3();
void initTimer8Chn4();
void forceOutCompareChannel1High();
void forceOutCompareChannel1Low();
void toggleOutCompareChannel1WithForce();
void configureTimer8();

//MOE: Main output enable
#define MOEEnable		(1<<15)

// Output Polarity CC1 (active/low)
#define OUTPUT_ACTIVEHIGH		(0<<1)
#define	OUTPUT_ACTIVELOW		(1<<1)
//CC1E: Capture/Compare 1 output enable
#define OUTPUT_Off		0
#define OUTPUT_ON		1

//Bit 7 ARPE: Auto-reload preload enable
#define ARPE_ENABLE		(1<<7)
#define	ARPE_DISABLE	(0<<7)

#endif /* TIMER_H_ */
