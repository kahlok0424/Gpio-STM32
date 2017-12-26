/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */

#include "Timer.h"
#include "Common.h"

void initTimer8(int value,int presc){
	enableTimer8();

	timer8->CR1 &= ~(3<<5);
	timer8->CR1 &= ~(1<<4);   //set at upcounter
	timer8->CR1 |= (1<<7);
	timer8->CR1 &= ~(1<<1);

	timer8->PSC &= ~(0xffff);         //prescaler
	timer8->PSC |= presc;

	timer8->ARR &= 0;     //clear auto reload value
	timer8->ARR |= value;  //set auto reload value

	timer8->SMCR &= ~(7<<0);  //select clock source

	timer8->CR1 |= (1<<0);     //enable clock
}

void initTimer8Chn1(){
	gpioConfig(GpioC,6,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioC,6,AF3);
}

void initTimer8Chn3(){
	gpioConfig(GpioC,8,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioC,8,AF3);
}

void initTimer8Chn4(){
	gpioConfig(GpioC,9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioC,9,AF3);
}

void configureTimer8(){
	enableTimer8();

	timer8->CR2 &= ~CCPC;	//no auto preload
	timer8->CCER &= CC1P;
	timer8->CCER |= CC1E;
	timer8->CCMR1 |= OC1FE;

	timer8->BDTR |= MOE;
}

void forceOutCompareChannel1High(){
	timer8->CCMR1 &= ~(7<<OC1M);
	timer8->CCMR1 |= (5<<OC1M);
}

void forceOutCompareChannel1Low(){
	timer8->CCMR1 &= ~(7<<OC1M);
	timer8->CCMR1 |= (4<<OC1M);
}

void toggleOutCompareChannel1WithForce(){
	forceOutCompareChannel1High();
	forceOutCompareChannel1Low();
}
