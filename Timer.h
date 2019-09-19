/******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: Timer0_interface.h
 *
 * Description: Header file for the TIMER0 AVR driver
 *
 * Created on: Sep 7, 2019
 *
 * Author: Ahmed Eldakhly & Hesham Hafez
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/

#include "Timer_cfg.h"
#include "Timer_Map.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
void TIMER_init(void);

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

void TIMER_Deinit(void);


/*void Timer_delayWithButton_ms(uint32 u32DelayNumber,uint8 StopButton);*/

#endif /* TIMER_H_ */
