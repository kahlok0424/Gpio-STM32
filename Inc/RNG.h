/*
 * RNG.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user1
 */

#ifndef RNG_H_
#define RNG_H_

#include <stdint.h>

#define RNG_BASE_ADR        0x50060800
#define RNG                 ((RngReg *)(RNG_BASE_ADR))

typedef struct RngReg RngReg;
struct RngReg{
	volatile uint32_t CR;       //0h
	volatile uint32_t SR;      //4h
    volatile uint32_t DR;      //8h
};

//SR
#define RNG_FAULTY_SEQUENCE  (1<<2)
#define RNG_FAULTY_CLOCK     (1<<1)
#define RNG_DRDY              1
//CR
#define RNG_RNGEN            (1<<2)
#define RNG_IE              (1<<3)

void generateRandomNumber();
int isRandomNumberReady();
int isAnyError();
int isFaultyRandomSequence();
int getRandomNumber();
void getRandomNumberByInterrupt();


#endif /* RNG_H_ */
