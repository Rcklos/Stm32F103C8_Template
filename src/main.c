#include <stm32f10x.h>

int main(void) {
  // 启动GPIOC的RCC时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  // 配置LED引脚
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // 关灯
  // GPIO_SetBits(GPIOC, GPIO_Pin_13);
  // 开灯
  GPIO_ResetBits(GPIOC, GPIO_Pin_13);
  while(1) {
    
  }
}