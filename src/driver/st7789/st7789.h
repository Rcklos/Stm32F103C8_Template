/**
 * @file st7789.h
 * @author rcklos
 * @brief 
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __DRIVER_STM32_ST7789_H__
#define __DRIVER_STM32_ST7789_H__
#define DC PBout(11)

#include "st_spi.h"
void lcd_st7789_init();
void lcd_st7789_write_data(u8 data);
void lcd_st7789_write_command(u8 cmd);
void lcd_st7789_fill_screen(u16 color);

#endif /* __DRIVER_STM32_ST7789_H__ */