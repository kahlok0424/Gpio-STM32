/*
 * IWDG.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user1
 */

#ifndef IWDG_H_
#define IWDG_H_

#include<stdint.h>
#include "Rcc.h"

#define IWDG_BASE_ADDR	 0x40003000

#define my_IWDG           ((IwdgReg *)(IWDG_BASE_ADDR))

typedef struct IwdgReg IwdgReg;
struct IwdgReg{
	volatile uint32_t KR;
	volatile uint32_t PR;
	volatile uint32_t RLR;
	volatile uint32_t SR;
};

#define WWDG_BASE_ADDR	 0x40002C00

#define my_WWDG           ((WwdgReg *)(IWDG_BASE_ADDR))

typedef struct WwdgReg WwdgReg;
struct WwdgReg{
	volatile uint32_t CR;
	volatile uint32_t CFR;
	volatile uint32_t SR;
};

#define RVU		(1<<1)
#define PVU		(1<<0)

#define IWDG_configKey		0x5555
#define IWDG_clearKey		0xAAAA
#define IWDG_startKey		0xCCCC

#define IWDG_PRS_DIV4		0
#define IWDG_PRS_DIV8		1
#define IWDG_PRS_DIV16		2
#define IWDG_PRS_DIV32		3
#define IWDG_PRS_DIV64		4
#define IWDG_PRS_DIV128		5
#define IWDG_PRS_DIV256		6
//#define IWDG_PRS_DIV256		7

//WWDG
#define WWDGactive	(1<<7)
#define EWI			(1<<9)
#define T6			(1<<6)

#define WWDG_TB_DIV1		0
#define WWDG_TB_DIV2		1
#define WWDG_TB_DIV4		2
#define WWDG_TB_DIV8		3

void configIWDG(int presacle ,int reload);
void IWDGstart();
void IWDGreset();

void configWWDG(int prescale ,int counter);
void WwdgEnableInterrupt();
void WWDGstart();
void WWDGsetWindowValue(int value);
void WWDGrefreshAndReload(int counter);
#endif /* IWDG_H_ */
