/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADR        0x40023800
#define RCC_AHB1RST_OFF     0x10
#define RCC_AHB1EN_OFF      0x30

//export variables to other modules
extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAHB1En;

void enableGpioG(void);
void enableGpioA(void);
void enableGpioB(void);

#endif /* RCC_H_ */
