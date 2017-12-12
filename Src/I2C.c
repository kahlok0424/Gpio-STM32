/*
 * I2C.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user1
 */

#include "I2C.h"
#include "GPIO.h"

void I2C_masterTransmit(){


}

void initI2C3(){
	enableI2C(3);
	//To enable gpio pin for i2c
	gpioConfig(GpioA,8,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioA , 8 ,AF4);
	gpioConfig(GpioC,9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioC , 9 ,AF4);

	i2c3->CR2 &= ~(0x3f);
	i2c3->CR2 |= 0xa;              //clock speed
	i2c3->CCR &= ~(1<<15);
	i2c3->TRISE &= ~(7<<0);
	i2c3->TRISE |= (4<<0);
}

void initI2C2(int slaveAddress){
	enableI2C(2);
	//To enable gpio pin for i2c
	gpioConfig(GpioF,0,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioF , 0 ,AF4);
	gpioConfig(GpioF,1,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
	gpioAlfConfig(GpioF , 1 ,AF4);

	i2c2->OAR1 &= ~(1<<15);
	i2c2->OAR1 &= ~(0x7f<<1);
	i2c2->OAR1 |= (slaveAddress <<1);

}
