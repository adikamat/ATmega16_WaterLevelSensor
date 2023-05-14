/**
  * @defgroup  Port Port
  * @{
  */	
  
/** 
  * @ingroup   Port
  * @brief   Drivers for Port
  * @defgroup  PortSource   ATmega16_Port.c
  * @{
  */	  

/**
  * @author  GRT/AMK
  * @version V1.0
  * @date    18-NOV-2020
  
  */
  

#include "ATmega16_Port.h"
/**
  * @ingroup PortSource
  * @defgroup PortSourcevariables  PortVariables 
  * @{
  */
  
/**
  * @ingroup PortSourcevariables
  * @defgroup Port StaticVariables  StaticVariables
  * @{
  */
 
/** @}*/  

/**
  * @ingroup PortSourcevariables
  * @defgroup PortVariables   Variables 
  * @{
  */

/** @}*/  

/**
 * @ingroup PortSourcevariables
 * @defgroup  PortArray  Array
 * @{
 */ 
 

/** @} */ /* End of Array Group*/
/** @} */ /* End of Sourcevariables Group*/

/************************** End of ModuleVariables ****************************/
/**
  * @ingroup PortSource
  * @defgroup PortFunction  PortFunctions
  * @{
  */
  

/**
  * @ingroup PortFunction
  * @defgroup PortStaticFucntions   StaticFucntions 
  * @{
  */


/** @}*/  

/**
  * @ingroup  PortFunction
  * @defgroup PortInterfaceFunctions   Functions 
  * @{
  */


/** 
  * @brief	Function takes McuPin parameter and return PortNumber
  * @pre	None
  * @post	None.
  * @param	McuPin
  * @brief	Valid Mcu pin no of PORTA/PORTB/PORTC/PORTD.
  * 
  *         Valid Mcu pin is formed using syntax  PORTX_PXY  
  *			Where X = A,B,C,D  and  Y = 0 to 7
  *			So for PortB and pin 6, parameter McuPin is PORTB_PB6     
  * @retval	Software Port Macro Number
  *				@verbatim
  *		        Port Macro		Return Value
  * 			PORTA_			1
  * 			PORTB_			2
  * 			PORTC_			3
  * 			PORTD_			4
  * 			PORT_ERROR      0
  *				@endverbatim			
  * @test	Tested OK.All valid Mcupin tested and got correct PortNo.	
  */
uint8_t GetPort(uint8_t McuPin)
{	/* Check for Valid Mcu pin for each port and return
	   corresponding  software port no.
	*/
	/* Check for PORTB Pins */
	if(McuPin >= PORTB_START && McuPin <= PORTB_END)
			return ((uint8_t)PORTB_);
	 /* Check for PORTD Pins */
	if(McuPin >= PORTD_START && McuPin <= PORTD_END)
			return ((uint8_t)PORTD_);
	/* Check for PORTC Pins */
	if(McuPin >= PORTC_START && McuPin <= PORTC_END)
			return ((uint8_t)PORTC_);
	/* Check for PORTA Pins */
	if(McuPin >= PORTA_START && McuPin <= PORTA_END)
			return ((uint8_t)PORTA_);
   /* Error in Mcupin no */			
	 return( PORT_ERROR);	
}  
  
/** 	
  * @brief	Function takes McuPin parameter and return bit no of Port
  * 
  *			Function takes Mcupin as parameter and  first find corresponding
  *			port number by calling function GetPort().It then find bit number
  *			of that port. For ex calling GetPinNumber(PORTC_PC5). First PORTC
  *			number is found which is 3 and then PC5 bit number is found which
  *			is 5. So in short function returns bit number 5 of PORTC. 
  * @pre	None
  * @post	None
  * @param	McuPin
  * @brief	Valid Mcu pin no of PORTA/PORTB/PORTC/PORTD.
  *
  *         Valid Mcu pin is formed using syntax  PORTX_PXY
  *			Where X = A,B,C,D  and  Y = 0 to 7
  *			So for PortB and pin 6, parameter McuPin is PORTB_PB6
  * @retval	Bit no of corresponding Port between 0 to 7
  * @test	Tested OK.All valid Mcupin tested and got correct BitNo of Port.	
  */
uint8_t GetPinNumber(uint8_t McuPin)
{uint8_t Port,PinNo = 0;
	/* Get Port */
	Port = GetPort(McuPin);
	/*Check Port A */
	if(Port == PORTA_)
		PinNo = (PORTA_END) - McuPin;  
		/*Check Port B */
	else if (Port == PORTB_)	
	 	PinNo =  McuPin - (PORTB_START);  
		 /*Check Port C */
	else if (Port == PORTC_)
		PinNo =  McuPin - (PORTC_START);
		/*Check Port D */
	else if (Port == PORTD_)
		PinNo =  McuPin - (PORTD_START) ;
	else{}
		return (PinNo);	
		
}

/** 
  * @brief	Set Pin direction of port either PIN_IN or PIN_OUT	
  * @pre	None
  * @post	Mcupin direction is set.
  * @param	McuPin
  * @brief	Valid Mcu pin no of PORTA/PORTB/PORTC/PORTD.
  *
  *         Valid Mcu pin is formed using syntax  PORTX_PXY
  *			Where X = A,B,C,D  and  Y = 0 to 7
  * @param	Direction
  * @brief	This has Value PORT_IN or PORT_OUT
  * @retval	None
  * @test	Tested OK.All valid Mcupin for PORT_IN and PORT_OUT direction tested.	
  */
void Port_SetPinDirection(uint8_t McuPin,ePinDir_t Direction )
{ uint8_t  Port,PinNo;
		/* Get Port */
		Port = GetPort(McuPin); 
		/* Get Pin No */
		PinNo = GetPinNumber(McuPin);	
		/* Set Pin Direction of PORTX.If Pin Direction is OUT SET Corresponding
			bit in DDRX (X = A/B/C/D) Register. If Pin Direction is IN  RESET
			Corresponding bit in DDRX Register 
			*/ 
		if( Port == PORTA_)
		{	if (Direction == PIN_IN)
				DDRA &=  ~((uint8_t)0x01 << PinNo) ;
			else  
				DDRA |=  ((uint8_t)0x01 << PinNo) ;		 
		}
		if( Port == PORTB_)
		{	if (Direction == PIN_IN)
			DDRB &=  ~((uint8_t)0x01 << PinNo) ;
			else
			DDRB |=  ((uint8_t)0x01 << PinNo) ;
		}
		if( Port == PORTC_)
		{	if (Direction == PIN_IN)
			DDRC &=  ~((uint8_t)0x01 << PinNo) ;
			else
			DDRC |=  ((uint8_t)0x01 << PinNo) ;
		}
		if( Port == PORTD_)
		{	if (Direction == PIN_IN)
			DDRD &=  ~((uint8_t)0x01 << PinNo) ;
			else
			DDRD |=  ((uint8_t)0x01 << PinNo) ;
		}
}
/** 
  * @brief	Set Entire Port Pin direction either IN or OUT	
  * @pre	None
  * @post	Entire Mcu Port direction is set either IN or OUT.
  * @param	McuPort
  * @brief	This is having value PORTX_ 
  *			where X is either A,B,C,D 
  * @param	Direction
  * @brief	This has Value PORT_IN or PORT_OUT
  * @retval	None
  * @test	Not Tested.	
  */
void Port_SetPortDirection(uint8_t McuPort,ePortDir_t Direction )
{
	if( McuPort == PORTA_)
	{	if (Direction == PORT_IN)
			DDRA = 0x00 ;
		else
			DDRA = 0xff ;
	}
	if( McuPort == PORTB_)
	{	if (Direction == PORT_IN)
			DDRB =  0x00 ;
		else
			DDRB =  0xff ;
	}
	if( McuPort == PORTC_)
	{	if (Direction == PORT_IN)
			DDRC =  0x00 ;
		else
			DDRC =  0xff ;
	}
	if( McuPort == PORTD_)
	{	if (Direction == PORT_IN)
			DDRD = 0x00;
		else
			DDRD = 0xff ;
	}
}

/**
  * @brief	Set Pin Value either HIGH or LOW	
  * @pre	PortPin direction should be configured as PORT_OUT  
  * @post	PortPin is either HIGH or LOW.
  * @param	McuPin
  * @param	McuPin
  * @brief	Valid Mcu pin no of PORTA/PORTB/PORTC/PORTD.
  *
  *         Valid Mcu pin is formed using syntax  PORTX_PXY
  *			Where X = A,B,C,D  and  Y = 0 to 7
  * @param	PinValue 
  * @brief	This has Value PIN_LOW or PIN_HIGH
  * @retval	None
  * @test	Tested OK.All valid Mcupin tested and written for PORT_LOW or PORT_HIGH.	
  */
void Port_WritePin(uint8_t McuPin, uint8_t PinValue )
{uint8_t  Port,PinNo;
		/* Get Port */
		Port = GetPort(McuPin); 
		/* Get Pin No */
		PinNo = GetPinNumber(McuPin);	
		/* Set Pin Value of PORTX.If Value is HIGH SETCorresponding
			bit in PORTX (X = A/B/C/D) Register. If Pin Value is LOW RESET 
			Corresponding bit in PORTX Register 
			*/ 
		if( Port == PORTA_)
		{	if (PinValue == PIN_LOW)
				PORTA &=  ~((uint8_t)0x01 << PinNo) ;
			else  
				PORTA |=  ((uint8_t)0x01 << PinNo) ;		 
		}
		if( Port == PORTB_)
		{	if (PinValue == PIN_LOW)
			PORTB &=  ~((uint8_t)0x01 << PinNo) ;
			else
			PORTB |=  ((uint8_t)0x01 << PinNo) ;
		}
		if( Port == PORTC_)
		{	if (PinValue == PIN_LOW)
			PORTC &=  ~((uint8_t)0x01 << PinNo) ;
			else
			PORTC |=  ((uint8_t)0x01 << PinNo) ;
		}
		if( Port == PORTD_)
		{	if (PinValue == PIN_LOW)
			PORTD &=  ~((uint8_t)0x01 << PinNo) ;
			else
			PORTD |=  ((uint8_t)0x01 << PinNo) ;
		}
}

/**
  * @brief	Read Pin Value either HIGH or LOW	
  * @pre	Port pin should be configured as PORT_IN
  * @post	McuPin state is read
  * @param	McuPin
 * @brief	Valid Mcu pin no of PORTA/PORTB/PORTC/PORTD.
 *
 *         Valid Mcu pin is formed using syntax  PORTX_PXY
 *			Where X = A,B,C,D  and  Y = 0 to 7
  * @retval	PortPin state  PIN_LOW or PIN_HIGH
  * @test	Tested OK.All Port tested for input 0xAA and 0x55 PinValue.	
  */
uint8_t Port_ReadPin(uint8_t McuPin)
{uint8_t  Port,PinNo, PinValue= 0 ;
		/* Get Port */
		Port = GetPort(McuPin); 
		/* Get Pin No */
		PinNo = GetPinNumber(McuPin);	
		/*  Read PINX Register into PinValue. Check bit of PinValue for PinNo. 
			If 1 return HIGH else return LOW. 
		*/ 
		if( Port == PORTA_)
		{	  PinValue  = PINA  ;
		}
		if( Port == PORTB_)
		{	PinValue  = PINB  ;
		}
		if( Port == PORTC_)
		{	PinValue  = PINC  ;
		}
		if( Port == PORTD_)
		{	PinValue  = PIND  ;
		}
		PinValue &= ((uint8_t)0x01 << PinNo);
		
		 if (PinValue)
			return (PIN_HIGH) ;
		 else
			return(PIN_LOW);
}

/** 
  * @brief	Set  all Pins of Port to Value either HIGH or LOW	
  * @pre	Entire Port Direction should be PORT_OUT 
  * @post	None
  * @param	McuPort
  * @brief	This is software Port Macro having value PORTX_
  *			where X is either A,B,C,D 
  * @param	PortValue 
  * @brief	This is any Value of  type uin8_t  
  * @retval	None
  * @test	Tested OK.All Port tested for 0xAA and 0x55 Value.	
  
  */
void Port_WritePort(uint8_t McuPort,uint8_t PortValue )
{	
	if( McuPort == PORTA_)
	{	 PORTA = PortValue;
	}
	if( McuPort == PORTB_)
	{	PORTB = PortValue;
	}
	if( McuPort == PORTC_)
	{	PORTC = PortValue;
	}
	if( McuPort == PORTD_)
	{	PORTD = PortValue;
	}
}

/** 
  * @brief	Read all Pins of Port, a return Value is Combination of HIGH and LOW	
  * @pre	Call Port_SetPortDirection(McuPort,PORT_IN)  before calling
  *			this function.
  * @post	None
  * @param	McuPort
  * @brief	This is software Port Macro having value PORTX_ 
  *			where X is either A,B,C,D. 
  * @retval	PortValue of entire port  of type uin8_t. 
  * @Test	Tested OK.All Port tested for input value 0xAA and 0x55.	
  */
uint8_t Port_ReadPort(uint8_t McuPort)
{uint8_t PortValue = 0x00 ;
	
	if( McuPort == PORTA_)
	{	  PortValue = PINA ;
	}
	if( McuPort == PORTB_)
	{	PortValue = PINB ;
	}
	if( McuPort == PORTC_)
	{	PortValue = PINC ;
	}
	if( McuPort == PORTD_)
	{	PortValue = PIND ;
	}
	return(PortValue);
}
/** @}*/  /* End of PortInterfaceFunction  Group */
/** @}*/  /* End of PortFunction  Group */
/** @}*/  /* End of PortSource Group*/
/** @}*/  /* End of Port Group*/