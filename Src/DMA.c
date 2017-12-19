/*
 * DMA.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user1
 */

#include "DMA.h"
#include <stdint.h>

/**
 * DMA2.stream2.channel4 = USART1.Rx
 * DMA2.stream7.channel4 = USART1.Tx
 *
 * PSIZE = 1byte
 * MSIZE = 1byte
 *
 * MBURST = in 8 beats increment
 * FIFO_BURST = 1/2 threshold
 *
 * PINC = no
 * MINC = yes
 *
 * Circular mode = no
 * Double Buffer = no
 *
 * priority = high
 *
 * flow controller = DMA
 *
 * Transfer direction = memory-to-peripheral (Tx)
 * Transfer direction = peripheral-to-memory (Rx)
 *
 */

void dmaInitForUsart1(){
	char *str = "hello";

	dma2->s[2].CR &= ~(StreamEN);
	dma2->s[2].CR = DMAFlowControl | MemoryPointerIn | PSIZE_ONEBYTE | MSIZE_onebyte | HighPrio | channel_4 | MBURST_INCR8;
	dma2->s[2].FCR = FIFO_HALF;
	dma2->s[2].CR |= Peripheral_To_Memory;
	dma2->s[7].CR &= ~(StreamEN);
	dma2->s[7].CR = DMAFlowControl | MemoryPointerIn | PSIZE_ONEBYTE | MSIZE_onebyte | HighPrio | channel_4 | MBURST_INCR8;
	dma2->s[7].FCR = FIFO_HALF;
	dma2->s[7].CR |= Memory_To_Peripheral;
	dma2->s[2].PAR = &(usart1->DR);
	dma2->s[7].PAR = &(usart1->DR);

	dma2->s[2].M0AR = str;
	dma2->s[7].M0AR = str;

	dma2->s[7].NDTR = 5;

	dma2->s[2].CR |= StreamEN;
	dma2->s[7].CR |= StreamEN;
}

int dmaStreamCheckFlag(DmaReg *dma , int streamNum , int flag){
	int isUpper16 =FALSE;
	volatile uint32_t *intrStatusReg = &dma->LISR;
	if(streamNum >= 4){
		intrStatusReg = &dma->HISR;
		streamNum -= 4;
	}
	if(streamNum >= 2){
		streamNum -= 2;
		isUpper16 = TRUE;
	}

	return *intrStatusReg & (DMA_TCIF<< ( 6* streamNum ));
}

void dmaSetAddressAndSize(uint32_t memoryAddr ,uint32_t peripheralAddr,uint32_t size){

}

