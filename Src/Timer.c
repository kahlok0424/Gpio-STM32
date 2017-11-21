/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */
#include "GPIO.h"
#include "Timer.h"

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
