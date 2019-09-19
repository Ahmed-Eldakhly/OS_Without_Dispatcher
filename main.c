/*****************************************************************************
 * Module 	  : OS Scheduler
 *
 * File name  : Scheduler.c
 *
 * Created on : Sep 16, 2019
 *
 * Author     : Ahmed Eldakhly
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "DIO.h"
#include "Scheduler.h"

/*******************************************************************************
 *               	     	  Functions Prototype                              *
 *******************************************************************************/
void Task1(void);
void Task2(void);
void Task3(void);

/*******************************************************************************
 *                   			 Main function                                *
 *******************************************************************************/
u32 main (void)
{
	DIO_SetPinDirection(DIO_PIN12,OUTPUT);
	DIO_SetPinDirection(DIO_PIN13,OUTPUT);
	DIO_SetPinDirection(DIO_PIN14,OUTPUT);
	SOS_Init();
	SET_BIT(SREG,I);
	SOS_Create_Task(SOS_PRIORITY_0,500,Task1);
	SOS_Create_Task(SOS_PRIORITY_1,1000,Task2);
	SOS_Create_Task(SOS_PRIORITY_2,1500,Task3);

	SOS_Run();
}

/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/
void Task1(void)
{
	/*static uint8 counter=0;*/
	static uint8 Task1_Flag = 0u;
	Task1_Flag ^= 1u;
	if(Task1_Flag == 1u)
	{
		DIO_WritePin(DIO_PIN12,HIGH);
	}
	else
	{
		DIO_WritePin(DIO_PIN12,LOW);
	}
	/*	counter++;
	if(counter == 9u)
	{
		SOS_DeInit();
	}
	 */

}
void Task2(void)
{
	static uint8 counter = 0;
	static uint8 Task2_Flag = 0u;
	Task2_Flag ^= 1u;
	if(Task2_Flag == 1u)
	{
		DIO_WritePin(DIO_PIN13,HIGH);
	}
	else
	{
		DIO_WritePin(DIO_PIN13,LOW);
	}
	//SOS_Delete_Task(Task1);
	counter++;
	if(counter == 3u)
	{
		SOS_DeInit();
	}

}
void Task3(void )
{

	static uint8 Task3_Flag = 0u;
	Task3_Flag ^= 1u;
	if(Task3_Flag == 1u)
	{
		DIO_WritePin(DIO_PIN14,HIGH);
	}
	else
	{
		DIO_WritePin(DIO_PIN14,LOW);
	}
	SOS_Delete_Task(Task1);
}
