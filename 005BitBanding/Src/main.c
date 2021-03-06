/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ALIAS_BASE 0x22000000U
#define BITBAND_BASE 0x20000000U

int main(void)
{
	/* some pointer to an address in SRAM */
	uint8_t *ptr = (uint8_t*)0x20000200;

	/* set initial value */
	*ptr = 0xff;

	/* normal method */
	*ptr &= ~( 1 << 7);

	/* reset the value to 0xff */
	*ptr = 0xff;

	/* bit band method */
	/*
	 * calculate the alias address used for bit banding
	 * alias_addr = alias_base + (32* (bit_band_memory_addr - bit_band_base )) + bit * 4
	 */
	/* get the alias address of the 7th bit of the pointer address
	 * cast the value at the end */
	uint8_t *alias_addr = (uint8_t *) (ALIAS_BASE+(32 * (0x20000200-BITBAND_BASE))+7*4);

	/* clear the 7th bit of of the pointer with the alias address by
	 * dereference the pointer and write the value zero (0)*/
	*alias_addr = 0;

    /* Loop forever */
	for(;;);
}
