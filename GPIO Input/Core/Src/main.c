#include <stdint.h>
#include "stm32f411xe.h"

void SystemInit(void)
{

}

void init_interrupt(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // SYSCFG clock enable

  SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI12_PB; // PB12 as EXTI12

  EXTI->IMR |= EXTI_IMR_IM12; // unmask EXTI12

  EXTI->FTSR |= EXTI_FTSR_TR12; // falling edge trigger
  EXTI->RTSR |= EXTI_RTSR_TR12; // rising edge trigger

  NVIC_EnableIRQ(EXTI15_10_IRQn); // enable EXTI15_10 interrupt

  RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN; // SYSCFG clock disable (not needed anymore)
}

void EXTI15_10_IRQHandler(void)
{
  EXTI->PR |= EXTI_PR_PR12; // clear pending bit

  __asm("bkpt;"); // breakpoint
}

int main(void)
{
  uint32_t button;

  RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOBEN;   // PORT B clock enable

  GPIOB->MODER  &= ~GPIO_MODER_MODER12; // PB12 input

  init_interrupt(); // optional: add interrupt

  while (1)
  {
    button = GPIOB->IDR & GPIO_IDR_ID12; // read button state

    if (button == 0) // LOW state
    {
      __asm("bkpt;");
    }
    else // HIGH state
    {
    }
  }
}