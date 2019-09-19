/******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: Timer_cfg.h
 *
 * Description: Header file for configurations of the TIMER0 AVR driver
 *
 * Created on: Sep 7, 2019
 *
 * Author: Ahmed Eldakhly & Hesham Hafez
 *
 *******************************************************************************/

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "Macro.h"
#include "std_types.h"

/*******************************************************************************
 *                   	 CPU Frequency configurations                          *
 *******************************************************************************/

#ifndef F_CPU
#define F_CPU 8000000UL /* 8MHz Clock frequency */
#endif
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define Timer0_Prescaler Timer0_Prescaler_64		/* Pre-Scaler  Configuration */

#define Timer0_Mode Timer0_CTCMode				/*Timer 0 Mode*/

#define OCR0_Pin_Behaviour OCR_Disconnect		/*Compare Match pin configuration*/

#define OCR0_VALUE 250u

#endif /* TIMER_CFG_H_ */
