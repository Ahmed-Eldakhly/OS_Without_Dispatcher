/*
 * DIO_interface.h
 *
 *  Created on: Aug 17, 2019
 *      Author: hp
 */

#ifndef DIO_H_
#define DIO_H_
#include "DIO_Map.h"
#include "std_types.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_H_ */
