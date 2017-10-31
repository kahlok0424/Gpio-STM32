/*
 * GPIO.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "GPIO.h"

void gpioConfig(GpioReg *Gpio,int pin,int mode, int outdriveType,int pullType,int speed){
	Gpio->mode &= ~(3 <<(pin * 2));					//clear pin mode to 0
	Gpio->mode |= mode <<(pin * 2);					//set pin mode

	Gpio->outSpeed &= ~(3 <<(pin * 2));					//clear pin speed to 0
	Gpio->outSpeed |= speed <<(pin * 2);					//set pin speed

	Gpio->pullType &= ~(3 <<(pin * 2));					//clear pin pull type to 0
	Gpio->pullType |= pullType <<(pin * 2);					//set pin pull type

	Gpio->outType &= ~(1 <<pin);					//clear pin drive type to 0
	Gpio->outType |= outdriveType <<pin ;					//set pin drive type
}

void gpioWrite(GpioReg *gpio,int pin,int state){
	if(state == 1){
		gpio->outData |= (1<<pin);
	}else{
		gpio->outData &= ~(1<<pin);
	}
}

int gpioRead(GpioReg *gpio, int pin){
	return gpio->inData & (1<<pin);
	}

void gpioLock(GpioReg *gpio,int pin){

	int lockState;

	gpio->lock = (1<<16) | (1 << pin);
	gpio->lock = (1 << pin);
	gpio->lock = (1<<16) | (1 << pin);
	lockState = gpio->lock;

}
