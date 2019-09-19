/******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: TImer0_Prog.c
 *
 * Description: Source file for the TIMER0 AVR driver
 *
 * Created on: Sep 7, 2019
 *
 * Author: Ahmed Eldakhly & Hesham Hafez
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "Macro.h"
#include "std_types.h"
#include "Timer.h"
#include "Timer_Map.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	TIMER_init
 *
 * Description: 	Initialize the TIMER0 Driver Registers
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/

void TIMER_init(void)
{
	/**************************** CTC Mode Init ***************************************/
	TIMER_TCCR0 &= (~((1<<WGM00)|(1<<WGM01)));			/*Clear WGM00 & WGM01 Bits in TCCR0 Registers*/
	TIMER_TCCR0 |= (1<<WGM01);							/*Set WGM01 Bit*/
	/**************************** OCR0 Value ***************************************/
	TIMER_OCR0   = OCR0_VALUE;
	/**************************** Pre-Scaler Bit Init ***************************************/
	TIMER_TCCR0 &= (~((1<<CS00)|(1<<CS01)|(1<<CS02)));	/*Clear CS00 & CS01 & CS02 Bits in TCCR0 Registers*/
	TIMER_TCCR0 |= (1<<CS01);							/*Set CS01 Bit ----> pre-scaler = 8*/
	TIMER_TCCR0 |= (1<<CS00);							/*Set CS01 Bit ----> pre-scaler = 8*/
	TIMER_TIMSK |= (1u<<OCIE);

}

/*******************************************************************************
 * Function Name:	TIMER_Deinit
 *
 * Description: 	Disable the TIMER0 Driver Registers
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void TIMER_Deinit(void)
{
	/**************************** Pre-Scaler Bit DeInit ***************************************/
	TIMER_TCCR0 &= (~((1<<CS00)|(1<<CS01)|(1<<CS02)));	/*Clear CS00 & CS01 & CS02 Bits in TCCR0 Registers*/
	/**************************** OCR0 Value **************************************************/
	TIMER_OCR0=LOW;
}


