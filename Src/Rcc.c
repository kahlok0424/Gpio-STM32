/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1EN_OFF);

void enableGpioG(){
	//un-reset gpioG
	*rccAhb1Rst &= ~(1<<6);
	//enable gpioG clock
	*rccAhb1En |= 1<<6;
}

void enableGpioA(){
	//un-reset gpioG
	*rccAhb1Rst &= ~1;
	//enable gpioG clock
	*rccAhb1En |= 1;
}

void enableGpioC(){
	//un-reset gpioG
	*rccAhb1Rst &= ~(1<<1);
	//enable gpioG clock
	*rccAhb1En |= (1<<1);
}
