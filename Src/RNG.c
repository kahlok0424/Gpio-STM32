/*
 * RNG.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user1
 */

#include "RNG.h"

/**
 * start generating random number
 */
void generateRandomNumber(){
	RNG->CR |= RNG_RNGEN;
}

/**
 * Find out if RNG has encountered any error.
 * Return:
 * 0 if not ready
 * 1 if random number is ready
 */
int isRandomNumberReady(){
	return RNG->SR & RNG_DRDY;
}

/**
 * Find out if RNG has encountered any error.
 * Return:
 * 0 if no error
 * 1 if any error
 */
int isAnyError(){
return RNG->SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLOCK);
}

int isFaultyRandomSequence(){
return RNG->SR & (RNG_FAULTY_SEQUENCE);
}

int getRandomNumber(){
	do{
	  generateRandomNumber();
	  while(!isRandomNumberReady());
	  }while(isFaultyRandomSequence());

    return RNG->DR;
}

void getRandomNumberByInterrupt(){
	RNG->CR |= RNG_RNGEN | RNG_IE;
}
