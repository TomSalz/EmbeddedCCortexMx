/*
 * main.h
 *
 *  Created on: 05.07.2022
 *      Author: Tim
 */

#ifndef MAIN_H_
#define MAIN_H_


#define MAX_TASKS					4U
#define DUMMY_XPSR					0x01000000U

/* some stack memory calculations */
#define SIZE_TASK_STACK 			1024U
#define SIZE_SCHEDULER_STACK		1024U

#define SRAM_START 					0x20000000U
#define SRAM_SIZE					((96) * (1024))
#define SRAM_END					((SRAM_START) + (SRAM_SIZE))

#define T1_STACK_START				SRAM_END
#define T2_STACK_START				((SRAM_END) - (SIZE_TASK_STACK))
#define T3_STACK_START				((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START				((SRAM_END) - (3 * SIZE_TASK_STACK))
#define SCHEDULER_STACK_START		((SRAM_END) - (4 * SIZE_TASK_STACK))

#define TICK_HZ						1000U

#define HSI_CLOCK					16000000U
#define SYSTICK_TIME_CLK			HSI_CLOCK


void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);

void init_systick_timer(uint32_t tick_hz);
__attribute__ ((naked)) void init_scheduler_stack(uint32_t stack_start_addr);
void save_psp_value(uint32_t current_stack_psp_value);
void init_task_stack(void);
void enable_processor_faults(void);
uint32_t get_psp_value(void);
void update_next_task(void);
__attribute__ ((naked)) void switch_sp_to_psp(void);


#endif /* MAIN_H_ */
