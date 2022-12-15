#include <stm32f10x.h>
#include <delay.h>

void led_init() {
  // 启动GPIOC的RCC时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  // 配置LED引脚
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void) {
  unsigned int led = 0;

  led_init();
  delay_init();

  while(1) {
    // 清空
    GPIOC->ODR &= (~GPIO_Pin_13);
    // 亮灭
    GPIOC->ODR |= (led << 13);
    led = !led;
    delay_ms(500);
  }
}