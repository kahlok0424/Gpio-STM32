/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADR + RCC_AHB1EN_OFF);

void enableTimer8(void){
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
	//un-reset gpioA
	*rccAhb1Rst &= ~1;
	//enable gpioG clock
	*rccAhb1En |= 1;
}

void enableGpioC(){
	//un-reset gpioC
	*rccAhb1Rst &= ~(1<<2);
	//enable gpioG clock
	*rccAhb1En |= (1<<2);
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

void enableDMA(int dmaBitNumber){
	rcc->AHB1RSTR &= ~(1<< dmaBitNumber);
	rcc->AHB1ENR |= 1<< dmaBitNumber;
}

void enableADC(int AdcNum){
	rcc->APB2RSTR &= ~(1<<8);
	rcc->APB2ENR |= (1<< (7+AdcNum));
}

void enableWWDG(){
	rcc->APB1RSTR &= ~(1<<11);
	rcc->APB1ENR |= (1<<11 );
}
