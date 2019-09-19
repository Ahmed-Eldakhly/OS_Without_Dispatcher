/******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: TIMER0_MemoryMaping.h
 *
 * Description: Header file for maping the TIMER0 Registers and Pins
 *
 * Created on: Sep 7, 2019
 *
 * Author: Ahmed Eldakhly & Hesham Hafez
 *
 *******************************************************************************/

#ifndef TIMER_MAP_H_
#define TIMER_MAP_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/*******************************************************************************
 *                      Pre-Scaler Macros                                      *
 *******************************************************************************/
#define Timer0_OFF 0
#define Timer0_Prescaler_1 		1
#define Timer0_Prescaler_8 		8
#define Timer0_Prescaler_64 	64
#define Timer0_Prescaler_256 	256
#define Timer0_Prescaler_1024 	1024

/*******************************************************************************
 *                      Timer Mode Macros                                      *
 *******************************************************************************/
#define Timer0_NormalMode 				0
#define Timer0_PWM_PhaseCorrectMode 	1
#define Timer0_CTCMode 					2
#define Timer0_FastPWMMode 				3

/*******************************************************************************
 *                      OCR0 Pin Configurations Macros                                    *
 *******************************************************************************/
/* Normal&CTC mode */
#define OCR_Disconnect 0
#define OCR_Toggel 1
#define OCR_Clear 2
#define OCR_Set 3

/* Fast PWM */
#define OCR_Disconnect 0
#define OCR_ClearUpcounting_SetDowncounting 4
#define OCR_SetUpcounting_ClearDowncounting 6

/* Fast Compare Match */
#define OCR_Disconnect 0
#define OCR_ClearCompare_SetOverflow 7
#define OCR_SetCompare_ClearOverflow 9


/*******************************************************************************
 *                          Mapped Registers                                   *
 *******************************************************************************/
#define TIMER_TCCR0 (*(volatile uint8*)0x53)	/*Timer/Counter Control Register – TCCR0*/
#define TIMER_TCNT0 (*(volatile uint8*)0x52)	/*Timer/Counter Register – TCNT0*/
#define TIMER_OCR0  (*(volatile uint8*)0x5C)	/*Output Compare Register – OCR0*/
#define TIMER_TIMSK (*(volatile uint8*)0x59)	/*Timer/Counter Interrupt Mask Register – TIMSK*/
#define TIMER_TIFR  (*(volatile uint8*)0x58)    /*Timer/Counter Interrupt Flag Register – TIFR*/

/*******************************************************************************
 *                          Registers Pins                                     *
 *******************************************************************************/

/**************************** TCCR0 PINS ***************************************/
#define FOC0 	7	/*Bit 7 – FOC0: Force Output Compare*/
#define WGM00 	6	/*Bit 6 – WGM00: Waveform Generation Mode*/
#define COM01 	5	/*Bit 5 – COM01: Compare Match Output Mode*/
#define COM00 	4	/*Bit 4 – COM00: Compare Match Output Mode*/
#define WGM01 	3	/*Bit 3 – WGM01: Waveform Generation Mode*/
#define CS02 	2	/*Bit 2 – CS02: Clock Select*/
#define CS01 	1	/*Bit 1 – CS01: Clock Select*/
#define CS00 	0	/*Bit 0 – CS00: Clock Select*/

/**************************** TIMSK PINS ***************************************/
#define OCIE 1		/*Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TOIE 0		/*Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable*/

/**************************** TIFR PINS ***************************************/
#define OCF0 1		/*Bit 1 – OCF0: Output Compare Flag 0*/
#define TOV0 0		/*Bit 0 – TOV0: Timer/Counter0 Overflow Flag*/

#endif /* TIMER_MAP_H_ */
