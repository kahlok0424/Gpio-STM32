/*
 * ADC.h
 *
 *  Created on: Jan 2, 2018
 *      Author: user1
 */

#ifndef ADC_H_
#define ADC_H_

#include<stdint.h>
#include "Rcc.h"
#include "GPIO.h"

#define MY_ADC1_BASE_ADDR	 0x40012000
#define MY_ADC2_BASE_ADDR	 0x40012100
#define MY_ADC3_BASE_ADDR	 0x40012200
//#define MY_ADCC_BASE_ADDR	 0x40012200

#define my_ADC1           ((AdcReg *)(MY_ADC1_BASE_ADDR))
#define my_ADC2           ((AdcReg *)(MY_ADC2_BASE_ADDR))
#define my_ADC3           ((AdcReg *)(MY_ADC3_BASE_ADDR))
//#define my_ADCC           ((AdcReg *)(MY_ADCC_BASE_ADDR))

typedef struct AdcReg AdcReg;
struct AdcReg{
	volatile uint32_t SR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMPR1;
	volatile uint32_t SMPR2;
	volatile uint32_t JOFR1;
	volatile uint32_t JOFR2;
	volatile uint32_t JOFR3;
	volatile uint32_t JOFR4;
	volatile uint32_t HTR;
	volatile uint32_t LTR;
	volatile uint32_t SQR1;
	volatile uint32_t SQR2;
	volatile uint32_t SQR3;
	volatile uint32_t JSQR;
	volatile uint32_t JDR1;
	volatile uint32_t JDR2;
	volatile uint32_t JDR3;
	volatile uint32_t JDR4;
	volatile uint32_t DR;
	//volatile uint32_t CSR;
	//volatile uint32_t CCR;
	//volatile uint32_t CDR;
};

//cr1
#define SCAN			(1<<8)
#define DISCONEN		(1<<11)
#define DISCONDEN		~(1<<11)

//cr2
#define ADON			(1<<0)
#define EOCS			(0<<10)
#define	DMAEN			(1<<8)
#define DMADISABLE		(0<<8)
#define RightAlignment	(0<<11)
#define LeftAlignment	(1<<11)
#define SINGLECONV		(0<<1)
#define CONTCONV		(1<<1)
#define SWSTART			(1<<30)

//sampling time
#define CYCLE3		0
#define CYCLE15		1
#define CYCLE28		2
#define CYCLE56		3
#define CYCLE84		4
#define CYCLE112	5
#define CYCLE144	6
#define CYCLE480	7

//resolution
#define ADC_12bit	(0<<24)
#define ADC_10bit	(1<<24)
#define ADC_8bit	(2<<24)
#define ADC_6bit	(3<<24)

//sr
#define EOC			(1<<1)
#define OVR			~(1<<5)

void ADCConfig(AdcReg *adc,int numberOfConv,int alignment,int resolution);
void ADCSamplingTime(AdcReg *adc,int channel , int sampling);
double ADCGetValue(AdcReg *adc);
void ADCStartConversion(AdcReg *adc);
void ADCSelectSequence(AdcReg *adc,int channel ,int sequence);
void adcSetChannelSamplingSequence(AdcReg *adc, int channels[], int numOfChan);

#endif /* ADC_H_ */
