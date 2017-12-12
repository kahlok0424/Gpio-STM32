/*
 * Flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user1
 */

#include "Flash.h"


int flashEraseSector(int sectorNum){
	int check =0;
	flash->KEYR = KEY1;
	flash->KEYR = KEY2;

	flash->CR = (sectorNum << 3 )| FLASH_SECTOR_ERASE | FLASH_START;

	while(check ==0){
		if((flash->SR & (1<<16))==0){
			return 1;
		}
		else{
			return 0;
		}
	}
}
