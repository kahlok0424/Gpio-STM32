/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#include "GPIO.h"
#include "Rcc.h"
#include "RNG.h"
#include <stdio.h>
#include "NVIC.h"
#include "SysTick.h"
#include "EXTI.h"
#include "Timer.h"
#include "DbgMcu.h"
#include "I2C.h"
#include "Flash.h"
#include "USART.h"
#define red_led     14
#define green_led   13
#define blue_button 0

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

int buttonPress =0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
extern void initialise_monitor_handles(void);
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
  initialise_monitor_handles();
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  //gpio config for usart
  //enableRcc();
  enableGpioA();
  gpioConfig(GpioA,9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_HIGH);
  gpioConfig(GpioA,10,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_HIGH);
  gpioConfig(GpioA,6,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_HIGH);
  gpioAlfConfig(GpioA , 9 ,AF7);
  gpioAlfConfig(GpioA , 10 ,AF7);

  //usart config
  enableUSART1();
  MbitSelect9();
  usartStopBitSelect2();
  usartBaudConfig(OVER16, 0x30,0xd);
  usartParityConfig(1,ODD);
  usartEnable();
  usartTransmitDisable();
  usartReceiveEnable();

  //other exercise
  /*enableGpioG();
  enableGpioC();
  enableGpio(GpioF);
  gpioConfig(GpioA,blue_button,GPIO_MODE_IN,0,GPIO_PUPD_NO_PULL,0);
  gpioConfig(GpioG,red_led,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_HIGH);
  gpioLock(GpioG,red_led);
  gpioConfig(GpioG,green_led,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_HIGH);
  gpioLock(GpioG,green_led);
  */
  //initTimer8(5000,17999);
  //haltTimer8onDebug();
  //runTimer8onDebug();

/*
  enable I2C event interrupt
  nvicEnableIrq(31);
  nvicSetPriority(31,8);
  disable I2C event interrupt
  nvicDisableIrq(31);
*/

  //RNG
/*
  enableRNG();
  enable RNG interrupt
  nvicEnableIrq(80);
  nvicSetPriority(80,4);
  getRandomNumberByInterrupt();
*/

  //systick
  /*sysTickPrescaledSpeed();
  sysTickReload(11250000);
  sysTickClearCounter();
  sysTickEnable();
  sysTickIntrEnable();*/

  //external interrupt
  /*sysTickDisable();
  nvicEnableIrq(6);
  nvicSetPriority(6,9);
  extiIntrMaskEnable(blue_button);
  extiDisableFallingTrigger(blue_button);
  extiEnableRisingTrigger(blue_button);*/

  //rcc clock output
  /*gpioConfig(GpioA,8,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_PUPD_NO_PULL,GPIO_SPD_VERY_HIGH);
  gpioAlfConfig(GpioA , 8 ,AF0);
  rccSelectMco1Src(MCO_HSE_SRC);
  rccMCo1Prescaler(MCO_DIV_BY_5);*/

  //enable i2c
  /*initI2C3();
  initI2C2(0x1f);
  i2c3->CR1 |= (1<<0); //enable peripheral
  i2c3->CR1 |= (1<<8);*/

  char data[256];
  //usartReceive(data);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //usartReceive(data);
	  //*data = usartGetData();
	  usartReceive(&data);
	  //printf("%c\n",data);
	  //usartTransmit("j",1);
	  //usartTransmit("KL",2);
	  //usartTransmit("HELLO WOLRD!\n",14);

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
//	  int num = getRandomNumber();
//	  printf("(%d) 0x%d\n",i++,num);
	  //__WFI();
    //printf("%d\n",buttonPress)

    //blink using systick
    /*while(!sysTickHasExpired());
    gpioWrite(GpioG,red_led,1);
    while(!sysTickHasExpired());
    gpioWrite(GpioG,red_led,0);*/

    //blink
/*	volatile int blue_button_state;

    gpioWrite(GpioG,red_led,1);
	HAL_Delay(300);
	gpioWrite(GpioG,red_led,0);
	HAL_Delay(300);
	gpioConfig(GpioG,red_led,GPIO_MODE_IN,0,GPIO_PUPD_NO_PULL,0);
	gpioConfig(GpioG,green_led,GPIO_MODE_IN,0,GPIO_PUPD_NO_PULL,0);

	blue_button_state = gpioRead(GpioA,blue_button);
	if(blue_button_state ==1){
		//gpioWrite(GpioG,green_led,1);
		SET_PIN(GpioG,green_led);
	}else{
		//gpioWrite(GpioG,green_led,0);
		RESET_PIN(GpioG,green_led);
	}*/
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void EXTI0_IRQHandler(void){
	resetPending(blue_button);
	buttonPress++;
}

void My_SysTick_Handler(void){
	static int led_state =0;
	//just do nothing but reading the CTRL register to clear the counterflag
	volatile int flags = SysTicker->CTRL;
	gpioWrite(GpioG,red_led, (led_state = !led_state));
}

//Enable this for RNG
/*void HASH_RNG_IRQHandler(void){
	volatile int rand = RNG->DR;
}*/

void wait500ms(void){
	while(!(timer8->SR & 1));
	timer8->SR &= ~1;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
