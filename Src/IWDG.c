/*
 * IWDG.c
 *
 *  Created on: Jan 9, 2018
 *      Author: user1
 */

#include<stdint.h>
#include "IWDG.h"

void configIWDG(int presacle ,int reload){
	while((my_IWDG->SR & PVU) == 1);
	my_IWDG->KR = IWDG_configKey;
	my_IWDG->PR = presacle;
	while((my_IWDG->SR & RVU) == 1);
	my_IWDG->KR = IWDG_configKey;
	my_IWDG->RLR = reload;
}

void IWDGstart(){
	my_IWDG->KR = IWDG_startKey;
}

void IWDGreset(){
	my_IWDG->KR = IWDG_clearKey;
}


void configWWDG(int prescale ,int counter){
	my_WWDG->CFR = (prescale<<7);
	my_WWDG->CR = (T6|counter);
}

void WwdgEnableInterrupt(){
	my_WWDG->CFR |= EWI;
}

void WWDGstart(){
	my_WWDG->CR |= WWDGactive;
	my_WWDG->CR |= T6;
}

void WWDGsetWindowValue(int value){
	my_WWDG->CFR &= ~(0x7f);
	my_WWDG->CFR |= (T6|value);
}

void WWDGrefreshAndReload(int counter){
	my_WWDG->CR = (T6|counter);
}
