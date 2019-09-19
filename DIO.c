/*
 * DIO_Prog.c
 *
 *  Created on: Aug 1PIN7, 2PIN019
 *      Author: hp
 */

#include "DIO.h"

#include "DIO_Map.h"
#include "Macro.h"
#include "std_types.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinValue==HIGH)
	{
		if((PinNum>=DIO_PIN0)&&(PinNum<=DIO_PIN7))
		{
			SET_BIT(DIO_PORTA,PinNum);
		}
		else if((PinNum>=DIO_PIN8)&&(PinNum<=DIO_PIN15))
		{
			SET_BIT(DIO_PORTB,(PinNum-DIO_PIN8));
		}
		else if((PinNum>=DIO_PIN16)&&(PinNum<=DIO_PIN23))
		{
			SET_BIT(DIO_PORTC,(PinNum-DIO_PIN16));
		}
		else if((PinNum>=DIO_PIN24)&&(PinNum<=DIO_PIN31))
		{
			SET_BIT(DIO_PORTD,(PinNum-DIO_PIN24));
		}
	}
	else if(PinValue==DIO_PIN0)
	{

		if((PinNum>=DIO_PIN0)&&(PinNum<=DIO_PIN7))
		{
			CLEAR_BIT(DIO_PORTA,PinNum);
		}
		else if((PinNum>=DIO_PIN8)&&(PinNum<=DIO_PIN15))
		{
			CLEAR_BIT(DIO_PORTB,(PinNum-DIO_PIN8));
		}
		else if((PinNum>=DIO_PIN16)&&(PinNum<=DIO_PIN23))
		{
			CLEAR_BIT(DIO_PORTC,(PinNum-DIO_PIN16));
		}
		else if((PinNum>=DIO_PIN24)&&(PinNum<=DIO_PIN31))
		{
			CLEAR_BIT(DIO_PORTD,(PinNum-DIO_PIN24));

		}
	}

}
uint8 DIO_ReadPin(uint8 PinNum)
{
	if((PinNum>=DIO_PIN0)&&(PinNum<=DIO_PIN7))
	{
		return GET_BIT(DIO_PINA,PinNum);
	}
	else if((PinNum>=DIO_PIN8)&&(PinNum<=DIO_PIN15))
	{
		return GET_BIT(DIO_PINB,(PinNum-DIO_PIN8));
	}
	else if((PinNum>=DIO_PIN16)&&(PinNum<=DIO_PIN23))
	{
		return GET_BIT(DIO_PINC,(PinNum-DIO_PIN16));
	}
	else if((PinNum>=DIO_PIN24)&&(PinNum<=DIO_PIN31))
	{
		return GET_BIT(DIO_PIND,(PinNum-DIO_PIN24));
	}
	return DIO_PIN8;
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection==INPUT)
	{
		if((PinNum>=DIO_PIN0)&&(PinNum<=DIO_PIN7))
		{
			CLEAR_BIT(DIO_DDRA,PinNum);
		}
		else if((PinNum>=DIO_PIN8)&&(PinNum<=DIO_PIN15))
		{
			CLEAR_BIT(DIO_DDRB,(PinNum-DIO_PIN8));
		}
		else if((PinNum>=DIO_PIN16)&&(PinNum<=DIO_PIN23))
		{
			CLEAR_BIT(DIO_DDRC,(PinNum-DIO_PIN16));
		}
		else if((PinNum>=DIO_PIN24)&&(PinNum<=DIO_PIN31))
		{
			CLEAR_BIT(DIO_DDRD,(PinNum-DIO_PIN24));
		}
	}
	else if(PinDirection==OUTPUT)
	{
		if((PinNum>=DIO_PIN0)&&(PinNum<=DIO_PIN7))
		{
			SET_BIT(DIO_DDRA,PinNum);
		}
		else if((PinNum>=DIO_PIN8)&&(PinNum<=DIO_PIN15))
		{
			SET_BIT(DIO_DDRB,(PinNum-DIO_PIN8));
		}
		else if((PinNum>=DIO_PIN16)&&(PinNum<=DIO_PIN23))
		{
			SET_BIT(DIO_DDRC,(PinNum-DIO_PIN16));
		}
		else if((PinNum>=DIO_PIN24)&&(PinNum<=DIO_PIN31))
		{
			SET_BIT(DIO_DDRD,(PinNum-DIO_PIN24));
		}
	}


}
