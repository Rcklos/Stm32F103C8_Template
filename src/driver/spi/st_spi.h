#ifndef __DRIVER_STM32_SPI_H__
#define __DRIVER_STM32_SPI_H__
#include <stm32f10x.h>

void spi1_init(void);
void spi1_set_speed(u8 speed);
u8 spi1_read_write_byte(u8 data);

#endif /* __DRIVER_STM32_SPI_H__ */