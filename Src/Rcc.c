/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1EN_OFF);

void enableTimer8(){
	rcc->APB2ENR |= (1<<1);
	rcc->APB2RSTR &= ~(1<<1);
}

void enableI2C(int value){
	rcc->APB1ENR |= (1<< (20+value));
	rcc->APB2RSTR &= ~(1<< (20+value));
}

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

void enableGpio(int Gpiox){
	//un-reset gpioG
	rcc->AHB1RSTR &= ~(1<<6);
	//enable gpioG clock
	rcc->AHB1ENR |= 1<<6;
}

void enableRNG(void){
	//un-reset RNG
    rcc->AHB2RSTR &= ~(1 << 6);
    //Start clock of RNG
    rcc->AHB2ENR |= (1<<6);
}

void enableUSART1(void){
	rcc->APB2RSTR &= ~(1<<4);
	rcc->APB2ENR |= 1<<4;
}
