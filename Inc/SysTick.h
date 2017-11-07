/*
 * SysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user1
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SYSTICK_BASE_ADR             0xE000E010
#define SysTicker                    ((SysTickReg *)(SYSTICK_BASE_ADR))

#define SysTick_EN                   1
#define SysTick_INTR_EN              ( 1 << 1)
#define SysTick_PROC_CLK_SRC         ( 1 << 2)
#define SysTick_CNTR_OVERFLOW        ( 1 << 16)

typedef struct SysTickReg SysTickReg;
struct SysTickReg{
	volatile uint32_t CTRL;               //control
	volatile uint32_t LOAD;       		 //reload
	volatile uint32_t VAL;				 //current value
	volatile uint32_t CALIB;		     //calibration
};

#define sysTickEnable()              (SysTicker->CTRL |= SysTick_EN)
#define sysTickDisable()             (SysTicker->CTRL &= ~SysTick_EN)
#define sysTickIntrEnable()          (SysTicker->CTRL |= SysTick_INTR_EN)
#define sysTickIntrDisable()         (SysTicker->CTRL &= ~SysTick_INTR_EN)
#define sysTickReload(x)             (SysTicker->LOAD =(x))
#define sysTickReadCounter()         (SysTicker->VAL)
#define sysTickClearCounter()        (SysTicker->VAL = 0xbadface)
//set systick to run at processor speed
#define sysTickRunAtFullSpeed()      (SysTicker->CTRL |= SysTick_PROC_CLK_SRC)
//set systick to run at prescale speed
#define sysTickPrescaledSpeed()      (SysTicker->CTRL &= ~SysTick_PROC_CLK_SRC)
//check timer has expired
#define sysTickHasExpired()           (SysTicker->CTRL & SysTick_CNTR_OVERFLOW)


#endif /* SYSTICK_H_ */
