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
  lcd_st7789_init();

  GPIO_SetBits(GPIOC, GPIO_Pin_13);
  while(1) {
    lcd_st7789_fill_screen(0xf800);
    lcd_st7789_fill_screen(0);
  }
}