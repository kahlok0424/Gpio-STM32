/*
 * USART.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user1
 */

#include<stdint.h>
#include "USART.h"

void usartParityConfig(int en,int odd){
	if(en==1){
		usart1->CR1 |= ParityEnable;
	}
	else{
		usart1->CR1 &= ~(ParityEnable);
	}

	if(odd == ODD){
		usart1->CR1 |= OddParity;
	}
	else{
		usart1->CR1 &= ~(OddParity);
	}
}

void usartBaudConfig(int overSampling, int mantissa,int fraction){
	if(overSampling == OVER8){
		usart1->CR1 |= OverSampling;
		usart1->BRR &= ~(1<<3);  //this bit must be kept cleared when OVER8
		}
	else{
		usart1->CR1 &= ~(OverSampling);
	}

	usart1->BRR &= ~(0xffff<<0);
	usart1->BRR |= (fraction<<0);
	usart1->BRR |= (mantissa<<4);
}

void usartSend(uint8_t *data){

	usartReceiveDisable();
	usartTransmitEnable();

	usart1->DR = *data;
}

void usartTransmit(uint8_t *data,int size){
	while(size-- > 0){
		usartSend(data);
		while((usart1->SR & TxeBit) == 0);
		data++;
	}
	while((usart1->SR & TcBit) == 0);
}

void usartStopBitSelect2(){

	usart1->CR2 &= ~(3<<StopBit);
	usart1->CR2 |= (2<<StopBit);
	usart1->CR2 |= (2<<StopBit);
}

void usartReceive(char *data){
	*(data) = usartGetData();
	while(*(data) != 10){   //wait for enter to be pressed
	data++;
	*(data) = usartGetData();
	}
}

uint8_t usartGetData(){
	while(usart1->SR & RXNEbit ==0);
	return usart1->DR;
}
