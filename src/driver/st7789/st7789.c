#include "st7789.h"
#include "delay.h"

void lcd_st7789_init() 
{
  RCC->APB2ENR |= 1 << 3;  // 使能时钟
  GPIOB->CRH &= 0xFFFF0FFF;
  GPIOB->CRH |= 0x00003000;
  GPIOB->ODR |= 1 << 11;

  spi1_init();
  spi1_set_speed(SPI_BaudRatePrescaler_2);

  lcd_st7789_write_command(0x01);
  delay_us(150);
  lcd_st7789_write_command(0x11);
	delay_us(120);
	lcd_st7789_write_command(0x3A);
	lcd_st7789_write_data(0x55);
	lcd_st7789_write_command(0x36);
	lcd_st7789_write_data(0x00);
	lcd_st7789_write_command(0x21);
	lcd_st7789_write_command(0x13);
	lcd_st7789_write_command(0x29);
}

void lcd_st7789_write_data(u8 data)
{
  DC = 1;
  spi1_read_write_byte(data);
}

void lcd_st7789_write_command(u8 cmd)
{
  DC = 0;
  spi1_read_write_byte(cmd);
}

void lcd_st7789_fill_screen(u16 color)
{
  u16 i ,j;
  lcd_st7789_write_command(0x2A);
  lcd_st7789_write_data(0);
  lcd_st7789_write_data(0);
  lcd_st7789_write_data(0);
  lcd_st7789_write_data(240);
  lcd_st7789_write_command(0X2B);
  lcd_st7789_write_data(0);
  lcd_st7789_write_data(0);
  lcd_st7789_write_data(0X01);
  lcd_st7789_write_data(0X40);
  lcd_st7789_write_command(0X2C);
  for(i = 0 ; i<240 ; i++)
  {
	  for(j = 0 ; j<320 ; j++)
    {
	    lcd_st7789_write_data(color>>8);  
      lcd_st7789_write_data(color);			
	  }
	}
}