/*
 * I2C.h
 *
 *  Created on: Nov 28, 2017
 *      Author: user1
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define I2C1_BASE_ADDR			0x40005400
#define i2c1              		((I2CReg *)(I2C1_BASE_ADDR))
#define I2C2_BASE_ADDR			0x40005800
#define i2c2	   				 ((I2CReg *)(I2C2_BASE_ADDR))
#define I2C3_BASE_ADDR			0x40005C00
#define i2c3                    ((I2CReg *)(I2C3_BASE_ADDR))

typedef struct I2CReg I2CReg;
struct I2CReg{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
};

void initI2C3();
void initI2C2(int slaveAddress);

#endif /* I2C_H_ */
