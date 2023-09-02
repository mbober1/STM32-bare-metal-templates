#include <stdint.h>
#include "stm32f411xe.h"

void SystemInit(void) {}

void TIM2_IRQHandler(void)
{
  GPIOB->ODR ^= GPIO_ODR_OD13;            // toggle PB13 (led)

	TIM2->SR &= ~TIM_DIER_CC1IE;            // Clear interrupt flag
  TIM2->EGR |= TIM_EGR_UG;                // Update generation
}

void init_timer(void)
{
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;     // enable TIM2 clock

  // 1s = 16MHz / 1000 ARR / 16000 PSC
  TIM2->PSC = 16000-1;
  TIM2->ARR = 1000-1;

  // Interrupt Controller
  NVIC_EnableIRQ(TIM2_IRQn);              // Enable TIM2 interrupt
  TIM2->SR &= ~TIM_DIER_CC1IE;            // Clear interrupt flag
  TIM2->DIER |= TIM_DIER_CC1IE;           // Update interrupt enable

  TIM2->EGR |= TIM_EGR_UG;                // Update generation
  TIM2->CNT = 0;                          // Clear the counter
  TIM2->CR1 |= TIM_CR1_CEN;               // Counter enable
}

void led_init(void)
{
  RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOBEN;   // PORT B clock enable
  
  GPIOB->MODER  |= GPIO_MODER_MODER13_0;  // PB13 output
  GPIOB->MODER  &= ~GPIO_MODER_MODER13_1; // PB13 output
  GPIOB->OTYPER &= ~GPIO_OTYPER_OT13;     // PB13 push-pull
}

int main(void)
{
  led_init();
  init_timer();

  while (1) {}
}