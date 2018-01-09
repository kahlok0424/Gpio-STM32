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
