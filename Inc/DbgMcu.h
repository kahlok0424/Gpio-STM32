/*
 * DbgMcu.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */

#ifndef DBGMCU_H_
#define DBGMCU_H_

#define  DBGMCU_APB2_FZ			(*(uint32_t *)(0xE004200C))
#define DBG_TIM1_STOP           1
#define DBG_TIM8_STOP           (1 << 1)

#define haltTimer8onDebug()		(DBGMCU_APB2_FZ |= DBG_TIM8_STOP)
#define haltTimer1onDebug()		(DBGMCU_APB2_FZ |= DBG_TIM1_STOP)

#define runTimer8onDebug()		(DBGMCU_APB2_FZ &= ~(DBG_TIM8_STOP))
#define runTimer1onDebug()		(DBGMCU_APB2_FZ &= ~(DBG_TIM1_STOP))

#endif /* DBGMCU_H_ */
