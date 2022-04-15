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
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* This function is executed in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	/* enable IRQ3 interrupt */
	*pISER0 |= ( 1 << 3 );

	/* generate an interrupt from software for IRQ3 */
	*pSTIR = ( 3 & 0x1FF );
}


void change_access_level_unprivilage(void)
{
	/* read the CONTROL register value */
	__asm volatile ("MRS R0, CONTROL");
	/* modify the R0 value to set the UNPRIVILEGED MODE bit */
	/* We can achieve this with an OR operation for bit 1 */
	__asm volatile ("ORR R0,R0,#0x01");
	/* write the new value from R0 to the CONTROL register */
	__asm volatile ("MSR CONTROL, R0");
}


/* This function is executed in THREAD MODE of the processor and starts in PRIVILEGED ACCESS LEVEL */
int main(void)
{
	printf("Main function in THREAD MODE - before the interrupt.\n");

	change_access_level_unprivilage();

	generate_interrupt();

	printf("Main function in THREAD MODE - after the interrupt.\n");

    /* Loop forever */
	for(;;);
}

/* This function (ISR) executes in HANDLER MODE of the processor */
void EXTI22_RTC_WKUP_IRQHandler(void)
{
	printf("In HANDLER MODE - ISR\n");
}

void HardFault_Handler(void)
{
	printf("In HARD FAULT HANDLER\n");
	printf("Hard fault detected\n");
	while(1);
}