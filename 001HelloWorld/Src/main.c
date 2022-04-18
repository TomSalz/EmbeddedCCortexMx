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
/**
 * General settings
 * Disable the Floating point unit under Project -> Properties -> C/C++Build -> Settings -> MCU-Settings
 * Set Floating-Point Unit to "None"
 * Set Floating-Point ABI to "Software Implementation"
 *
 * Enable the SWV Debugging
 * Got to Run -> Debug Configurations.. -> <Project> -> Debugger
 * Enable the Serial Wire Viewer (SWV)
 * Add the SWV View Window -> Show View -> SWV -> SWV ITM Data Console and Start the Trace (big red button)
 * Enable in the SWV Data Console Settings the ITM Stimulus port bit 0
 */
int main(void)
{
    /* Loop forever */
	printf("Hello World\n");
	for(;;);
}
