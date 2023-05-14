#include "ATmega16_Port.h"

void Test_GetPort(void)
{
	uint8_t Port =7;
/* Port B  Value 2 */
Port =  GetPort(1);
Port =7;
Port =  GetPort(2);
Port =7;
Port =  GetPort(3);
Port =7;
Port =  GetPort(4);
Port =7;
Port =  GetPort(5);
Port =7;
Port =  GetPort(6);
Port =7;
Port =  GetPort(7);
Port =7;
Port =  GetPort(8);
Port =7;

/* Port D  Value 4 */
Port =  GetPort(14);
Port =7;
Port =  GetPort(15);
Port =7;
Port =  GetPort(16);
Port =7;
Port =  GetPort(17);
Port =7;
Port =  GetPort(18);
Port =7;
Port =  GetPort(19);
Port =7;
Port =  GetPort(20);
Port =7;
Port =  GetPort(21);
Port =7;

/* Port A  Value 1 */
Port =  GetPort(33);
Port =7;
Port =  GetPort(34);
Port =7;
Port =  GetPort(35);
Port =7;
Port =  GetPort(36);
Port =7;
Port =  GetPort(37);
Port =7;
Port =  GetPort(38);
Port =7;
Port =  GetPort(39);
Port =7;
Port =  GetPort(40);
Port =7;

/* Port C  Value 3 */
Port =  GetPort(22);
Port =7;
Port =  GetPort(23);
Port =7;
Port =  GetPort(24);
Port =7;
Port =  GetPort(25);
Port =7;
Port =  GetPort(26);
Port =7;
Port =  GetPort(27);
Port =7;
Port =  GetPort(28);
Port =7;
Port =  GetPort(29);
}

void Test_GetPinNumber(void)
{
	uint8_t	PinNo =0 ;
/* Port B*/
PinNo = GetPinNumber(1);
PinNo = GetPinNumber(2);
PinNo = GetPinNumber(3);
PinNo = GetPinNumber(4);
PinNo = GetPinNumber(5);
PinNo = GetPinNumber(6);
PinNo = GetPinNumber(7);
PinNo = GetPinNumber(8);
/* Port D*/
PinNo = GetPinNumber(14);
PinNo = GetPinNumber(15);
PinNo = GetPinNumber(16);
PinNo = GetPinNumber(17);
PinNo = GetPinNumber(18);
PinNo = GetPinNumber(19);
PinNo = GetPinNumber(20);
PinNo = GetPinNumber(21);

/* Port C*/
PinNo = GetPinNumber(22);
PinNo = GetPinNumber(23);
PinNo = GetPinNumber(24);
PinNo = GetPinNumber(25);
PinNo = GetPinNumber(26);
PinNo = GetPinNumber(27);
PinNo = GetPinNumber(28);
PinNo = GetPinNumber(29);

/* Port A*/
PinNo = GetPinNumber(40);
PinNo = GetPinNumber(39);
PinNo = GetPinNumber(38);
PinNo = GetPinNumber(37);
PinNo = GetPinNumber(36);
PinNo = GetPinNumber(35);
PinNo = GetPinNumber(34);
PinNo = GetPinNumber(33);
}

void Test_Port_SetPinDirection(void)
{  
	/* PortB  IN */
	Port_SetPinDirection(1,PORT_IN);
	Port_SetPinDirection(2,PORT_IN);
	Port_SetPinDirection(3,PORT_IN);
	Port_SetPinDirection(4,PORT_IN);
	Port_SetPinDirection(5,PORT_IN);
	Port_SetPinDirection(6,PORT_IN);
	Port_SetPinDirection(7,PORT_IN);
	Port_SetPinDirection(8,PORT_IN);
	
	///* PortB  OUT */
	Port_SetPinDirection(1,PORT_OUT);
	Port_SetPinDirection(2,PORT_OUT);
	Port_SetPinDirection(3,PORT_OUT);
	Port_SetPinDirection(4,PORT_OUT);
	Port_SetPinDirection(5,PORT_OUT);
	Port_SetPinDirection(6,PORT_OUT);
	Port_SetPinDirection(7,PORT_OUT);
	Port_SetPinDirection(8,PORT_OUT);
	
	/* PortD  IN */
	Port_SetPinDirection(14,PORT_IN);
	Port_SetPinDirection(15,PORT_IN);
	Port_SetPinDirection(16,PORT_IN);
	Port_SetPinDirection(17,PORT_IN);
	Port_SetPinDirection(18,PORT_IN);
	Port_SetPinDirection(19,PORT_IN);
	Port_SetPinDirection(20,PORT_IN);
	Port_SetPinDirection(21,PORT_IN);
	
	/* PortD  OUT */
	Port_SetPinDirection(14,PORT_OUT);
	Port_SetPinDirection(15,PORT_OUT);
	Port_SetPinDirection(16,PORT_OUT);
	Port_SetPinDirection(17,PORT_OUT);
	Port_SetPinDirection(18,PORT_OUT);
	Port_SetPinDirection(19,PORT_OUT);
	Port_SetPinDirection(20,PORT_OUT);
	Port_SetPinDirection(21,PORT_OUT);
	
	
	/* PortC  IN */
	Port_SetPinDirection(22,PORT_IN);
	Port_SetPinDirection(23,PORT_IN);
	Port_SetPinDirection(24,PORT_IN);
	Port_SetPinDirection(25,PORT_IN);
	Port_SetPinDirection(26,PORT_IN);
	Port_SetPinDirection(27,PORT_IN);
	Port_SetPinDirection(28,PORT_IN);
	Port_SetPinDirection(29,PORT_IN);
	
	/* PortC  OUT */
	Port_SetPinDirection(22,PORT_OUT);
	Port_SetPinDirection(23,PORT_OUT);
	Port_SetPinDirection(24,PORT_OUT);
	Port_SetPinDirection(25,PORT_OUT);
	Port_SetPinDirection(26,PORT_OUT);
	Port_SetPinDirection(27,PORT_OUT);
	Port_SetPinDirection(28,PORT_OUT);
	Port_SetPinDirection(29,PORT_OUT);
	
	/* PortA  IN */
	Port_SetPinDirection(40,PORT_IN);
	Port_SetPinDirection(39,PORT_IN);
	Port_SetPinDirection(38,PORT_IN);
	Port_SetPinDirection(37,PORT_IN);
	Port_SetPinDirection(36,PORT_IN);
	Port_SetPinDirection(35,PORT_IN);
	Port_SetPinDirection(34,PORT_IN);
	Port_SetPinDirection(33,PORT_IN);
	
	/* PortA  OUT */
	Port_SetPinDirection(40,PORT_OUT);
	Port_SetPinDirection(39,PORT_OUT);
	Port_SetPinDirection(38,PORT_OUT);
	Port_SetPinDirection(37,PORT_OUT);
	Port_SetPinDirection(36,PORT_OUT);
	Port_SetPinDirection(35,PORT_OUT);
	Port_SetPinDirection(34,PORT_OUT);
	Port_SetPinDirection(33,PORT_OUT);

}

void Test_Port_WritePin(void)
{
	/* Port B */
	Port_SetPinDirection(1,PORT_OUT);
	Port_SetPinDirection(2,PORT_OUT);
	Port_SetPinDirection(3,PORT_OUT);
	Port_SetPinDirection(4,PORT_OUT);
	Port_SetPinDirection(5,PORT_OUT);
	Port_SetPinDirection(6,PORT_OUT);
	Port_SetPinDirection(7,PORT_OUT);
	Port_SetPinDirection(8,PORT_OUT);
	
	Port_WritePin(1,PORT_HIGH);
	Port_WritePin(2,PORT_HIGH);
	Port_WritePin(3,PORT_HIGH);
	Port_WritePin(4,PORT_HIGH);
	Port_WritePin(5,PORT_HIGH);
	Port_WritePin(6,PORT_HIGH);
	Port_WritePin(7,PORT_HIGH);
	Port_WritePin(8,PORT_HIGH);
	/* Port B */
	Port_WritePin(1,PORT_LOW);
	Port_WritePin(2,PORT_LOW);
	Port_WritePin(3,PORT_LOW);
	Port_WritePin(4,PORT_LOW);
	Port_WritePin(5,PORT_LOW);
	Port_WritePin(6,PORT_LOW);
	Port_WritePin(7,PORT_LOW);
	Port_WritePin(8,PORT_LOW);
	
	/* Port D */
	Port_SetPinDirection(14,PORT_OUT);
	Port_SetPinDirection(15,PORT_OUT);
	Port_SetPinDirection(16,PORT_OUT);
	Port_SetPinDirection(17,PORT_OUT);
	Port_SetPinDirection(18,PORT_OUT);
	Port_SetPinDirection(19,PORT_OUT);
	Port_SetPinDirection(20,PORT_OUT);
	Port_SetPinDirection(21,PORT_OUT);
	
	Port_WritePin(14,PORT_HIGH);
	Port_WritePin(15,PORT_HIGH);
	Port_WritePin(16,PORT_HIGH);
	Port_WritePin(17,PORT_HIGH);
	Port_WritePin(18,PORT_HIGH);
	Port_WritePin(19,PORT_HIGH);
	Port_WritePin(20,PORT_HIGH);
	Port_WritePin(21,PORT_HIGH);
	/* Port D */
	Port_WritePin(14,PORT_LOW);
	Port_WritePin(15,PORT_LOW);
	Port_WritePin(16,PORT_LOW);
	Port_WritePin(17,PORT_LOW);
	Port_WritePin(18,PORT_LOW);
	Port_WritePin(19,PORT_LOW);
	Port_WritePin(20,PORT_LOW);
	Port_WritePin(21,PORT_LOW);
	
	/* Port C */
	Port_SetPinDirection(22,PORT_OUT);
	Port_SetPinDirection(23,PORT_OUT);
	Port_SetPinDirection(24,PORT_OUT);
	Port_SetPinDirection(25,PORT_OUT);
	Port_SetPinDirection(26,PORT_OUT);
	Port_SetPinDirection(27,PORT_OUT);
	Port_SetPinDirection(28,PORT_OUT);
	Port_SetPinDirection(29,PORT_OUT);
	
	Port_WritePin(22,PORT_HIGH);
	Port_WritePin(23,PORT_HIGH);
	Port_WritePin(24,PORT_HIGH);
	Port_WritePin(25,PORT_HIGH);
	Port_WritePin(26,PORT_HIGH);
	Port_WritePin(27,PORT_HIGH);
	Port_WritePin(28,PORT_HIGH);
	Port_WritePin(29,PORT_HIGH);
	/* Port C */
	Port_WritePin(22,PORT_LOW);
	Port_WritePin(23,PORT_LOW);
	Port_WritePin(24,PORT_LOW);
	Port_WritePin(25,PORT_LOW);
	Port_WritePin(26,PORT_LOW);
	Port_WritePin(27,PORT_LOW);
	Port_WritePin(28,PORT_LOW);
	Port_WritePin(29,PORT_LOW);
	
	/* Port A */
	Port_SetPinDirection(40,PORT_OUT);
	Port_SetPinDirection(39,PORT_OUT);
	Port_SetPinDirection(38,PORT_OUT);
	Port_SetPinDirection(37,PORT_OUT);
	Port_SetPinDirection(36,PORT_OUT);
	Port_SetPinDirection(35,PORT_OUT);
	Port_SetPinDirection(34,PORT_OUT);
	Port_SetPinDirection(33,PORT_OUT);
	
	Port_WritePin(40,PORT_HIGH);
	Port_WritePin(39,PORT_HIGH);
	Port_WritePin(38,PORT_HIGH);
	Port_WritePin(37,PORT_HIGH);
	Port_WritePin(36,PORT_HIGH);
	Port_WritePin(35,PORT_HIGH);
	Port_WritePin(34,PORT_HIGH);
	Port_WritePin(33,PORT_HIGH);
	/* Port A */
	Port_WritePin(40,PORT_LOW);
	Port_WritePin(39,PORT_LOW);
	Port_WritePin(38,PORT_LOW);
	Port_WritePin(37,PORT_LOW);
	Port_WritePin(36,PORT_LOW);
	Port_WritePin(35,PORT_LOW);
	Port_WritePin(34,PORT_LOW);
	Port_WritePin(33,PORT_LOW);
}

void Test_Port_WritePort(void )
{  
	/* Port B */
	
	Port_SetPinDirection(1,PORT_OUT);
	Port_SetPinDirection(2,PORT_OUT);
	Port_SetPinDirection(3,PORT_OUT);
	Port_SetPinDirection(4,PORT_OUT);
	Port_SetPinDirection(5,PORT_OUT);
	Port_SetPinDirection(6,PORT_OUT);
	Port_SetPinDirection(7,PORT_OUT);
	Port_SetPinDirection(8,PORT_OUT);
	Port_WritePort(PORTB_,0xAA);
	Port_WritePort(PORTB_,0x55);
	/* Port D */
	Port_SetPinDirection(14,PORT_OUT);
	Port_SetPinDirection(15,PORT_OUT);
	Port_SetPinDirection(16,PORT_OUT);
	Port_SetPinDirection(17,PORT_OUT);
	Port_SetPinDirection(18,PORT_OUT);
	Port_SetPinDirection(19,PORT_OUT);
	Port_SetPinDirection(20,PORT_OUT);
	Port_SetPinDirection(21,PORT_OUT);
	Port_WritePort(PORTD_,0xAA);
	Port_WritePort(PORTD_,0x55);
	/* Port C */
	Port_SetPinDirection(22,PORT_OUT);
	Port_SetPinDirection(23,PORT_OUT);
	Port_SetPinDirection(24,PORT_OUT);
	Port_SetPinDirection(25,PORT_OUT);
	Port_SetPinDirection(26,PORT_OUT);
	Port_SetPinDirection(27,PORT_OUT);
	Port_SetPinDirection(28,PORT_OUT);
	Port_SetPinDirection(29,PORT_OUT);
	Port_WritePort(PORTC_,0xAA);
	Port_WritePort(PORTC_,0x55);
	/* Port A */
	Port_SetPinDirection(40,PORT_OUT);
	Port_SetPinDirection(39,PORT_OUT);
	Port_SetPinDirection(38,PORT_OUT);
	Port_SetPinDirection(37,PORT_OUT);
	Port_SetPinDirection(36,PORT_OUT);
	Port_SetPinDirection(35,PORT_OUT);
	Port_SetPinDirection(34,PORT_OUT);
	Port_SetPinDirection(33,PORT_OUT);
	Port_WritePort(PORTA_,0xAA);
	Port_WritePort(PORTA_,0x55);
}

void Test_Port_ReadPin(void)
{
	uint8_t pinval=0;
	/* PortB */
	Port_SetPinDirection(1,PORT_IN);
	Port_SetPinDirection(2,PORT_IN);
	Port_SetPinDirection(3,PORT_IN);
	Port_SetPinDirection(4,PORT_IN);
	Port_SetPinDirection(5,PORT_IN);
	Port_SetPinDirection(6,PORT_IN);
	Port_SetPinDirection(7,PORT_IN);
	Port_SetPinDirection(8,PORT_IN);
	
	pinval = Port_ReadPin(1);
	pinval = Port_ReadPin(2);
	pinval = Port_ReadPin(3);
	pinval = Port_ReadPin(4);
	pinval = Port_ReadPin(5);
	pinval = Port_ReadPin(6);
	pinval = Port_ReadPin(7);
	pinval = Port_ReadPin(8);
	/* Port D */
	Port_SetPinDirection(14,PORT_IN);
	Port_SetPinDirection(15,PORT_IN);
	Port_SetPinDirection(16,PORT_IN);
	Port_SetPinDirection(17,PORT_IN);
	Port_SetPinDirection(18,PORT_IN);
	Port_SetPinDirection(19,PORT_IN);
	Port_SetPinDirection(20,PORT_IN);
	Port_SetPinDirection(21,PORT_IN);
	
	pinval = Port_ReadPin(14);
	pinval = Port_ReadPin(15);
	pinval = Port_ReadPin(16);
	pinval = Port_ReadPin(17);
	pinval = Port_ReadPin(18);
	pinval = Port_ReadPin(19);
	pinval = Port_ReadPin(20);
	pinval = Port_ReadPin(21);
	/* Port C */
	Port_SetPinDirection(22,PORT_IN);
	Port_SetPinDirection(23,PORT_IN);
	Port_SetPinDirection(24,PORT_IN);
	Port_SetPinDirection(25,PORT_IN);
	Port_SetPinDirection(26,PORT_IN);
	Port_SetPinDirection(27,PORT_IN);
	Port_SetPinDirection(28,PORT_IN);
	Port_SetPinDirection(29,PORT_IN);
	pinval = Port_ReadPin(22);
	pinval = Port_ReadPin(23);
	pinval = Port_ReadPin(24);
	pinval = Port_ReadPin(25);
	pinval = Port_ReadPin(26);
	pinval = Port_ReadPin(27);
	pinval = Port_ReadPin(28);
	pinval = Port_ReadPin(29);
	/* Port A */
	Port_SetPinDirection(40,PORT_IN);
	Port_SetPinDirection(39,PORT_IN);
	Port_SetPinDirection(38,PORT_IN);
	Port_SetPinDirection(37,PORT_IN);
	Port_SetPinDirection(36,PORT_IN);
	Port_SetPinDirection(35,PORT_IN);
	Port_SetPinDirection(34,PORT_IN);
	Port_SetPinDirection(33,PORT_IN);
	pinval = Port_ReadPin(40);
	pinval = Port_ReadPin(39);
	pinval = Port_ReadPin(38);
	pinval = Port_ReadPin(37);
	pinval = Port_ReadPin(36);
	pinval = Port_ReadPin(35);
	pinval = Port_ReadPin(34);
	pinval = Port_ReadPin(33);
	
}

void Test_Port_ReadPort(void)
{
	/* Port B */
	uint8_t PortVal =0;
	Port_SetPinDirection(1,PORT_IN);
	Port_SetPinDirection(2,PORT_IN);
	Port_SetPinDirection(3,PORT_IN);
	Port_SetPinDirection(4,PORT_IN);
	Port_SetPinDirection(5,PORT_IN);
	Port_SetPinDirection(6,PORT_IN);
	Port_SetPinDirection(7,PORT_IN);
	Port_SetPinDirection(8,PORT_IN);
	PortVal = Port_ReadPort(PORTB_);
	PortVal =0;
	/* Port D */
	Port_SetPinDirection(14,PORT_IN);
	Port_SetPinDirection(15,PORT_IN);
	Port_SetPinDirection(16,PORT_IN);
	Port_SetPinDirection(17,PORT_IN);
	Port_SetPinDirection(18,PORT_IN);
	Port_SetPinDirection(19,PORT_IN);
	Port_SetPinDirection(20,PORT_IN);
	Port_SetPinDirection(21,PORT_IN);
	
	PortVal = Port_ReadPort(PORTD_);
	PortVal =0;
	/* Port C */
	Port_SetPinDirection(22,PORT_IN);
	Port_SetPinDirection(23,PORT_IN);
	Port_SetPinDirection(24,PORT_IN);
	Port_SetPinDirection(25,PORT_IN);
	Port_SetPinDirection(26,PORT_IN);
	Port_SetPinDirection(27,PORT_IN);
	Port_SetPinDirection(28,PORT_IN);
	Port_SetPinDirection(29,PORT_IN);
	PortVal= Port_ReadPort(PORTC_);
	PortVal =0;
	
	/* Port A */
	Port_SetPinDirection(40,PORT_IN);
	Port_SetPinDirection(39,PORT_IN);
	Port_SetPinDirection(38,PORT_IN);
	Port_SetPinDirection(37,PORT_IN);
	Port_SetPinDirection(36,PORT_IN);
	Port_SetPinDirection(35,PORT_IN);
	Port_SetPinDirection(34,PORT_IN);
	Port_SetPinDirection(33,PORT_IN);
	PortVal=Port_ReadPort(PORTA_);

	
}