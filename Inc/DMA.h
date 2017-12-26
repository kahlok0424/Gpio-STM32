/*
 * DMA.h
 *
 *  Created on: Dec 19, 2017
 *      Author: user1
 */

#ifndef DMA_H_
#define DMA_H_

#include <stdint.h>
#include "rcc.h"
#include "USART.h"

#define DMA1_BASE_ADR             0x40026000
#define DMA2_BASE_ADR             0x40026400
#define dma1                    ((DmaReg *)(DMA1_BASE_ADR))
#define dma2                    ((DmaReg *)(DMA2_BASE_ADR))

typedef struct DmaStreamReg DmaStreamReg;
struct DmaStreamReg{
	volatile uint32_t CR;               //control
	volatile uint32_t NDTR;       		 //reload
	volatile uint32_t PAR;				 //current value
	volatile uint32_t M0AR;		     //calibration
	volatile uint32_t M1AR;
	volatile uint32_t FCR;
};

typedef struct DmaReg DmaReg;
struct DmaReg{
	volatile uint32_t LISR;               //control
	volatile uint32_t HISR;       		 //reload
	volatile uint32_t LICR;				 //current value
	volatile uint32_t HICR;		     //calibration
	DmaStreamReg s[8];
};

//DMA interrupt status register (xISR)
#define DMA_FEIF	1
#define DMA_DMEIF	(1<<2)
#define DMA_TEIF	(1<<3)
#define DMA_HTIF	(1<<4)
#define DMA_TCIF	(1<<5)

#define dmaStreamHasTransferCompleted(d,s)  	dmaStreamCheckFlag(d,s,DMA_TCIF)
#define dmaStreamHasHalfTransferCompleted(d,s)  dmaStreamCheckFlag(d,s,DMA_HCIF)
#define dmaStreamIsTransferError(d,s)  			dmaStreamCheckFlag(d,s,DMA_TEIF)
#define dmaStreamIsDirectModeError(d,s)  		dmaStreamCheckFlag(d,s,DMA_DMEIF)
#define dmaStreamIsFIFOError(d,s)  				dmaStreamCheckFlag(d,s,DMA_FEIF)

//SxFCR register
#define FIFO_QUARTER 		0
#define FIFO_HALF 			1
#define FIFO_THREE_QUARTER 	(1<<1)
#define FIFO_FULL 			(3<<1)

//SxCr register
#define StreamEN	1
#define DMAFlowControl	(0<<5)
#define MemoryPointerIn (1<<10)
#define LowPrio			(0<<17)
#define MediumPrio		(1<<17)
#define HighPrio		(1<<17)
#define VHPrio			(3<<16)
#define MBURST_SINGLE	(0<<23)
#define MBURST_INCR4	(1<<23)
#define MBURST_INCR8	(1<<24)
#define MBURST_INCR16	(3<<24)

//Data Transfer Direction
#define Peripheral_To_Memory	(0<<6)
#define Memory_To_Peripheral	(1<<6)
#define Memory_To_Memory		(1<<7)

//Channel Selection
#define channel_0	(0<<25)
#define channel_1	(1<<25)
#define channel_2	(1<<26)
#define channel_3	(3<<26)
#define channel_4	(1<<27)
#define channel_5	(5<<27)
#define channel_6	(6<<27)
#define channel_7	(7<<27)


//PSIZE
#define PSIZE_ONEBYTE	(0<<12)
#define PSIZE_HALFWORD	(1<<12)
#define PSIZE_WORD		(2<<12)

//MSIZE
#define MSIZE_onebyte		(0<<14)
#define MSIZE_halfword	(1<<14)
#define MSIZE_word		(2<<14)


void dmaInitForUsart1(char *str);
int dmaStreamCheckFlag(DmaReg *dma , int streamNum , int flag);
void dmaUsart1SendByte(char *str);

#endif /* DMA_H_ */
