#include <stdint.h>
#include "stm32f411xe.h"

volatile uint32_t tick;


void SystemInit(void)
{

}

/*
 * Systick interrupt handler
 *   increment tick
*/
void SysTick_Handler()
{
  tick++;
}

/*
 * Delay blocking function
 *   time - delay in ms
 */
void delay(uint32_t time)
{
  uint32_t start = tick;
  while (start + time > tick);
}

int main(void)
{
  SysTick_Config(16000); // 16MHz / 16000 = 1ms

  RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOBEN;   // PORT B clock enable

  GPIOB->MODER  |= GPIO_MODER_MODER13_0;  // PB13 output (first bit)
  GPIOB->MODER  &= ~GPIO_MODER_MODER13_1; // PB13 output (second bit)
  GPIOB->OTYPER &= ~(GPIO_OTYPER_OT13);   // PB13 push-pull 

  while (1)
  {
    GPIOB->BSRR = GPIO_BSRR_BR13; // reset PB13
    delay(100);

    GPIOB->BSRR = GPIO_BSRR_BS13; // set PB13
    delay(100);
  }
}