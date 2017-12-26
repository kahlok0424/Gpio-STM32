/*
 * USART.H
 *
 *  Created on: Dec 12, 2017
 *      Author: user1
 */

#ifndef USART_H_
#define USART_H_

#include<stdint.h>

#define USART1_BASE_ADDR	 0x40011000
#define usart1             ((UsartReg *)(USART1_BASE_ADDR))

typedef struct UsartReg UsartReg;
struct UsartReg{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t CR4;
};

#define EVEN			0
#define ODD				1
#define OVER8			1
#define OVER16			0

#define Mbit			(1<<12)
#define UsartEn 		(1<<13)
#define ParityEnable 	(1<<10)
#define OddParity		(1<<9)
#define TxEn			(1<<3)
#define RxEn			(1<<2)
#define OverSampling	(1<<15)
#define StopBit			12
#define TcBit			(1<<6)
#define TxeBit			(1<<7)
#define RXNEbit			(1<<5)

#define usartEnable()			(usart1->CR1 |= UsartEn)
#define MbitSelect8()			(usart1->CR1 &= ~(Mbit))
#define MbitSelect9()			(usart1->CR1 |=  (Mbit))
#define usartTransmitEnable()	(usart1->CR1 |= TxEn)
#define usartTransmitDisable()	(usart1->CR1 &= ~(TxEn))
#define usartReceiveEnable()	(usart1->CR1 |= RxEn)
#define usartReceiveDisable()	(usart1->CR1 &= ~(RxEn))
#define DMATransmitEN			(1<<7)

#define uart1EnableDmaTx()		(usart1->CR3 |= DMATransmitEN)

void usartParityConfig(int en,int odd);
void usartBaudConfig(int overSampling, int mantissa,int fraction);
void usartSend(uint8_t *data);
void usartStopBitSelect2();
void usartTransmit(uint8_t *data,int size);
uint8_t usartGetData();
void usartReceive(char *data);
void serialPrint(char *format,...);

#endif /* USART_H_ */
