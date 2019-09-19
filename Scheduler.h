/*****************************************************************************
 * Module 	  : OS Scheduler
 *
 * File name  : Scheduler.h
 *
 * Created on : Sep 16, 2019
 *
 * Author     : Ahmed Eldakhly
 ******************************************************************************/

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "Scheduler_cfg.h"
#include "avr/interrupt.h"
#include "Timer.h"

/*******************************************************************************
 *                  	       Types Declaration                               *
 *******************************************************************************/

/*************************** EnmSchedulerTaskState_t ***************************/
typedef enum
{
	SOS_READY,
	SOS_RUNNING,
	SOS_WAITING
}EnmSchedulerTaskState_t;

/*************************** EnmSchedulerTaskState_t ***************************/
typedef enum
{
	SOS_PRIORITY_0,
	SOS_PRIORITY_1,
	SOS_PRIORITY_2,
	SOS_PRIORITY_3,
	SOS_PRIORITY_4,
	SOS_PRIORITY_5,
	SOS_PRIORITY_6,
	SOS_PRIORITY_7,
	SOS_PRIORITY_8,
	SOS_PRIORITY_9
}EnmSchedulerTaskPriority_t;

/*************************** EnmCreateTaskStatus_t ***************************/
typedef enum
{
OK,
TASK_PRIORITY_RESERVED
}EnmCreateTaskStatus_t;

/***************************** StrSosTaskConfig_t ****************************/
typedef struct
{
	EnmSchedulerTaskState_t TaskState;
	uint16 TaskPeriodicity;
	void (*TaskFunction_ptr)(void);
}StrSosTaskConfig_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

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
void SOS_Init(void);

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
EnmCreateTaskStatus_t SOS_Create_Task(EnmSchedulerTaskPriority_t a_Priority,uint16 a_TaskPeriodicity,void (*TaskFunction_ptr)(void));

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
void SOS_Run (void);

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
void SOS_Delete_Task (void (*a_DeletedFunction_ptr)(void));

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
void SOS_DeInit (void);



#endif /* SCHEDULER_H_ */
