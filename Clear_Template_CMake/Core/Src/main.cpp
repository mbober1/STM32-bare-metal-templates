#include <stdint.h>
#include "stm32f411xe.h"

volatile uint32_t tick;

void SysTick_Handler()
{
  tick++;
}

void SystemInit(void)
{

}

void delay(uint32_t time)
{
  uint32_t start = tick;
  while (start + time > tick);
}

int main(void)
{
  SysTick_Config(16000); // 16MHz / 16000 = 1ms

  while (1)
  {
  }
}