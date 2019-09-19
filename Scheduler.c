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
#include "Scheduler.h"
#include "DIO.h"
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile uint32 TimerTich=0;
StrSosTaskConfig_t SOS_TasksArray[MAX_TASKS];
/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/
/*******************************************************************************
 * Function Name:	ISR
 *
 * Description: 	Interrupt service routine
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
ISR(TIMER0_COMP_vect)
{

	TimerTich++;
	/*for loop to check on all tasks to determine which one needs to convert to ready state*/
	for(uint8 counter=0; counter<MAX_TASKS; counter++)
	{
		/*check if any task exists in this priority index*/
		if(SOS_TasksArray[counter].TaskFunction_ptr != NULL_PTR)
		{
			/*check if any task needs to convert to ready state*/
			if(((TimerTich) % (SOS_TasksArray[counter].TaskPeriodicity)) == 0u)
			{

				SOS_TasksArray[counter].TaskState = SOS_READY;

			}
			else
			{
				/*Do Nothing*/
			}
		}
	}
}
/*******************************************************************************
 * Function Name:	SOS_Init
 *
 * Description: 	Initialize the SOS Driver
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SOS_Init(void)
{
	/*Initialize TIMER0 */
	TIMER_init();
	/*for loop to initialize all tasks in tasks array*/
	for (uint8 counter=0; counter<MAX_TASKS;   counter++)
	{
		SOS_TasksArray[counter].TaskPeriodicity = 0u;
		SOS_TasksArray[counter].TaskState=SOS_WAITING;
		SOS_TasksArray[counter].TaskFunction_ptr = NULL_PTR;
	}
}

/*******************************************************************************
 * Function Name:	SOS_Create_Task
 *
 * Description: 	Create New task in scheduler
 *
 * Inputs:			-Task priority 		(EnmSchedulerTaskPriority_t enum)
 * 					-Task Periodicity 	(uint16)
 * 					-Task Function 		(pointer to function)
 *
 * Outputs:			NULL
 *
 * Return:			Status check if execution occurs correctly
 *******************************************************************************/
EnmCreateTaskStatus_t SOS_Create_Task(EnmSchedulerTaskPriority_t a_Priority,uint16 a_TaskPeriodicity,void (*TaskFunction_ptr)(void))
{
	 /*return status to check if task enters to scheduler*/
	EnmCreateTaskStatus_t ReturnVal;
	/*check if task has same priority of entered task or not*/
	if(SOS_TasksArray[a_Priority].TaskFunction_ptr == NULL_PTR)
	{
		/*add task to scheduler*/
		SOS_TasksArray[a_Priority].TaskFunction_ptr = TaskFunction_ptr;
		SOS_TasksArray[a_Priority].TaskPeriodicity=a_TaskPeriodicity;
		SOS_TasksArray[a_Priority].TaskState=SOS_WAITING;
		ReturnVal = OK;
	}
	else
	{
		ReturnVal = TASK_PRIORITY_RESERVED;
	}

	return ReturnVal;
}

/*******************************************************************************
 * Function Name:	SOS_Delete_Task
 *
 * Description: 	this function delete selected exist task
 *
 * Inputs:			pointer to function that selected to delete
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SOS_Delete_Task (void (*a_DeletedFunction_ptr)(void))
{
	/*for loop get task that wanted to be deleted from scheduler*/
	for(uint8 counter = 0; counter<MAX_TASKS; counter++)
	{
		/*Check on the task that wanted to be deleted from scheduler*/
		if(SOS_TasksArray[counter].TaskFunction_ptr == a_DeletedFunction_ptr)
		{
			SOS_TasksArray[counter].TaskFunction_ptr = NULL_PTR;
			SOS_TasksArray[counter].TaskState=SOS_WAITING;
			SOS_TasksArray[counter].TaskPeriodicity = 0u;;
			break;
		}
		else
		{
			/*Do Nothing*/
		}
	}
}

/*******************************************************************************
 * Function Name:	SOS_Run
 *
 * Description: 	this function execute ready tasks
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SOS_Run (void)
{

	while(1)
	{
		/*loop for searching about ready tasks in scheduler to execute*/
		for(uint8 counter=0; counter<MAX_TASKS; counter++)
		{
			/*check if the task state is ready*/
			if(SOS_TasksArray[counter].TaskState == SOS_READY)
			{
				/*switch task state to Running State*/
				SOS_TasksArray[counter].TaskState = SOS_RUNNING;
				SOS_TasksArray[counter].TaskFunction_ptr();
				/*switch task state to waiting State*/
				SOS_TasksArray[counter].TaskState = SOS_WAITING;
			}
			else
			{
				/*Do Nothing*/
			}
		}
	}
}

/*******************************************************************************
 * Function Name:	SOS_DeInit
 *
 * Description: 	Disable the SOS Driver
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void SOS_DeInit (void)
{
	/*Stop TIMER0 */
	TIMER_Deinit();
	/*for loop to Reinitialize all tasks in tasks array*/
	for (uint8 counter=0; counter<MAX_TASKS;   counter++)
	{
		SOS_TasksArray[counter].TaskPeriodicity=0;
		SOS_TasksArray[counter].TaskState=SOS_WAITING;
		SOS_TasksArray[counter].TaskFunction_ptr=NULL_PTR;
	}
}


