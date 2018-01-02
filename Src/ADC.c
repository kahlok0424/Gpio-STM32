/*
 * ADC.c
 *
 *  Created on: Jan 2, 2018
 *      Author: user1
 */

#include "ADC.h"

/**
 * use: to configure ADC register
 * @parameter : adcX
 * @parameter : number of conversion
 * @parameter : alignment
 * @parameter : resolution
 */
void ADCConfig(AdcReg *adc,int numberOfConv,int alignment,int resolution){
	//ADC on
	/*adc->CR2 |= ADON;
	adc->CR2 &= ~EOCS; 				//end of conversion each regular conversion
	adc->CR2 &= DMADISABLE;			//disable DMA for single conversion mode
	adc->CR2 &= ClearAlignment;		//clear alignment
	adc->CR2 |= alignment;			//set alignment
	adc->CR2 &= SINGLECONV;			// conversion type*/
	adc->CR2 = ADON | EOCS | DMADISABLE | alignment |SINGLECONV;
	/*adc->CR1 &= ClearResolution;	//clear resolution
	adc->CR1 |= resolution;			//set resolution
	adc->CR1 |= SCAN;*/
	adc->CR1 = resolution ;
	adc->SQR1 &= ~(15<<20);			//clear number of conversion
	adc->SQR1 |= ((numberOfConv-1) <<20); //set number of conversion
	ADCSelectSequence(adc,1,1);
	ADCSelectSequence(adc,6,2);
	ADCSelectSequence(adc,10,3);
	ADCSelectSequence(adc,14,4);
}

/**
 * @parameter  : adc select
 * @parameter  : channel select
 * @parameter  : sampling time
 */
void ADCSamplingTime(AdcReg *adc,int channel , int sampling){
	if(channel <= 9){
		adc->SMPR2 &= (7<< (channel*3));
		adc->SMPR2 |= (sampling<< (channel *3));
	}
	else{
		adc->SMPR1 &= (7<< ((channel *3) - 30));
		adc->SMPR1 |= (sampling<< ((channel *3) - 30));
	}
}

/**
 * @parameter : adcX
 * @parameter : channel selection
 * @parameter : sequence of the channel
 */
void ADCSelectSequence(AdcReg *adc,int channel ,int sequence){
	if(sequence <= 6){
		adc->SQR3 &= ~(15<< (sequence-1)*5);
		adc->SQR3 |= (channel<<(sequence-1)*5);
	}
	else if(7 <= sequence || sequence <=12){
		adc->SQR2 &= ~(15<< (sequence-7)*5);
		adc->SQR2 |= (channel<<(sequence-7)*5);
	}
	else{
		adc->SQR1 &= ~(15<< (sequence-13)*5);
		adc->SQR1 |= (channel<<(sequence-13)*5);
	}
}

double ADCGetValue(AdcReg *adc){
		//adc->CR2 |= SWSTART;
	while((adc->SR & EOC) == 0);
		return adc->DR;
	}

void ADCStartConversion(AdcReg *adc){
	//adc->SR &= ~EOC;
	//adc->SR &= OVR;
	adc->CR2 |= SWSTART;
}

/**
* @desc Configure the sampling sequence of one ADC channel
* @param adc is the pointer to the registers
* @param channel is an array of channels (the first element is the first in
* sequence)
* @param numOfChan is the number of channels in the array
*/
void adcSetChannelSamplingSequence(AdcReg *adc, int channels[], int numOfChan){
	int sort =0;
	for(int i = 0; i < numOfChan ; i++){
		if(i <= 6){
				adc->SQR3 &= ~(15<< i *5); //clear sequence
				adc->SQR3 |= (channels[i]<<i*5);
			}
		else if(7 <= i || i <=12){
				adc->SQR2 &= ~(15<< (i-7) *5); //clear sequence
				adc->SQR2 |= (channels[i]<<(i-7) *5);
			}
		else{
				adc->SQR1 &= ~(15<< (i-13) *5); //clear sequence
				adc->SQR1 |= (channels[i]<<(i-13) *5);
		}
	}
}

