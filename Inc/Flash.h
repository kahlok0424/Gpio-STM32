/*
 * Flash.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user1
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "rcc.h"
#include <stdint.h>

#define FLASH_BASE_ADDR	 0x40023C00
#define flash              ((FlashReg *)(FLASH_BASE_ADDR))

#define KEY1	0x45670123
#define KEY2	0xCDEF89AB

#define FLASH_SECTOR_ERASE	(1<<1)
#define FLASH_START	(1<<16)

typedef struct FlashReg FlashReg;
struct FlashReg{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t OPTCR;
	volatile uint32_t OPTCR1;
};

int flashEraseSector(int);

#endif /* FLASH_H_ */

