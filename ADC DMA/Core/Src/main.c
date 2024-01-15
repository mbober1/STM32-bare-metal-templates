#include <stdint.h>
#include "stm32f411xe.h"

void SystemInit(void)
{

}

void init_adc(void)
{

}


int main(void)
{
  volatile uint16_t adc;

  RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN; // PORT A clock enable
  RCC->APB2ENR  |= RCC_APB2ENR_ADC1EN;  // ADC1 clock enable

  GPIOA->MODER  |= GPIO_MODER_MODE0;    // PA0 analog

  ADC1->CR2     |= ADC_CR2_ADON;        // Enable ADC
  ADC1->SQR1    &= ~ADC_SQR1_L_0;       // 1 conversion
  ADC1->SQR3    &= ~ADC_SQR3_SQ1;       // 1st conversion - IN0
  ADC1->SMPR2   |= ADC_SMPR2_SMP0;      // channel 0 - 480 cycles of sampling time

  ADC1->CR1     &= (~ADC_CR1_RES);      // 12bit
  // ADC1->CR1     |= ADC_CR1_RES_0;       // 10bit

  while (1)
  {
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start conversion of regular channels
    adc = (uint16_t)ADC1->DR;
  }
}