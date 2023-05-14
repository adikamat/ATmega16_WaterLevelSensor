/**
  * @brief   Header file for ATmega16 Ports.
  * @ingroup Port
  * @defgroup PortHeader   ATmega16_Port.h
  * @{
  */
/**
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020

  * 
  * 
  */
#ifndef  _ATMEGA16_PORT_H
#define  _ATMEGA16_PORT_H

#include "System.h"


/**
  * @ingroup  PortHeader
  * @defgroup  PortTypedef  Typedef
  * @{
  */ 


  
/** @} */   /* End of Typedef Group*/

/**
  * @ingroup PortHeader
  * @defgroup  PortEnum  Enum
  * @{
  */ 
/**
  * @brief  This enum is for Pin Direction and has value PIN_OUT and PIN_IN. 
  *  
  */  
typedef enum
{ PIN_OUT = 0,
  PIN_IN 	
}ePinDir_t;

/**
  * @brief  This eum is for Port Direction and has value PORT_OUT and PORT_IN. 
  *  
  */  
/** 
  * @enum	ePortDir_t 
  * @brief  Enum for Port Direction.  
  */           
typedef enum
{ PORT_OUT = 0,
  PORT_IN 	
}ePortDir_t;  

/** @} */ /* End of Enum group*/


/**
  * @ingroup PortHeader
  * @defgroup  PortFunctionMacro  FunctionMacro
  * @{
  */ 


/** @} */ /* End of Function Macro  Group */

/**
 * @ingroup PortHeader
 * @defgroup  PortStructure Structure
 * @{
 */ 
 
/** @} */  /* End of Structure Group*/


/**
 * @ingroup MNHeader
 * @defgroup  MNUnion  Union
 * @{
 */ 

/** @} */ /* End of Union Group*/


/**
 * @ingroup MNHeader
 * @defgroup  MNMacro Macro
 * @{
 */ 


/** 
  * @brief    Mcu Pin value either 0 or 1
  */          
#define PIN_LOW			(uint8_t)0	///< Mcu pin is LOW.
#define PIN_HIGH		(uint8_t)1	///< Mcu pin is HIGH.		


/** 
  * @brief    Mcu Port Macros are defined 
  */          

#define PORTA_			(uint8_t)1 ///< PPORT A  Value.
#define PORTB_			(uint8_t)2 ///< PPORT B  Value.
#define PORTC_			(uint8_t)3 ///< PPORT C  Value.
#define PORTD_			(uint8_t)4 ///< PPORT D  Value.
#define PORT_ERROR      (uint8_t)0 ///< Error value for PORT. 
/** 
  * @brief	Mcu Port pin Macros are defined.PORTX stand for PortName as defined
  *			in MCU sfr file	and Y is Bit name Like PA0 PC7 etc as defined in Mcu
  *			sfr file.Combine macro PORTX_PXY define hardware pin of MCU PORT.
  *			Where  X= A,B,C,D  Y=  0 to 7  
  */          
 
 /* PORT B				Mcu Hw Pin*/
#define PORTB_PB0	(uint8_t)1 ///< This is Hardware pin Number 1 of PORTB
#define PORTB_PB1	(uint8_t)2 ///< This is Hardware pin Number 2 of PORTB
#define PORTB_PB2	(uint8_t)3 ///< This is Hardware pin Number 3 of PORTB
#define PORTB_PB3	(uint8_t)4 ///< This is Hardware pin Number 4 of PORTB
#define PORTB_PB4	(uint8_t)5 ///< This is Hardware pin Number 5 of PORTB
#define PORTB_PB5	(uint8_t)6 ///< This is Hardware pin Number 6 of PORTB
#define PORTB_PB6	(uint8_t)7 ///< This is Hardware pin Number 7 of PORTB
#define PORTB_PB7	(uint8_t)8 ///< This is Hardware pin Number 8 of PORTB
/* PORT D */
#define PORTD_PD0	(uint8_t)14 ///< This is Hardware pin Number 14 of PORTD
#define PORTD_PD1	(uint8_t)15 ///< This is Hardware pin Number 15 of PORTD
#define PORTD_PD2	(uint8_t)16 ///< This is Hardware pin Number 16 of PORTD
#define PORTD_PD3	(uint8_t)17 ///< This is Hardware pin Number 17 of PORTD
#define PORTD_PD4	(uint8_t)18 ///< This is Hardware pin Number 18 of PORTD
#define PORTD_PD5	(uint8_t)19 ///< This is Hardware pin Number 19 of PORTD
#define PORTD_PD6	(uint8_t)20 ///< This is Hardware pin Number 20 of PORTD
#define PORTD_PD7	(uint8_t)21 ///< This is Hardware pin Number 21 of PORTD
/* PORT C */
#define PORTC_PC0	(uint8_t)22 ///< This is Hardware pin Number 22 of PORTC
#define PORTC_PC1	(uint8_t)23 ///< This is Hardware pin Number 23 of PORTC
#define PORTC_PC2	(uint8_t)24 ///< This is Hardware pin Number 24 of PORTC
#define PORTC_PC3	(uint8_t)25 ///< This is Hardware pin Number 25 of PORTC
#define PORTC_PC4	(uint8_t)26 ///< This is Hardware pin Number 25 of PORTC
#define PORTC_PC5	(uint8_t)27 ///< This is Hardware pin Number 27 of PORTC
#define PORTC_PC6	(uint8_t)28 ///< This is Hardware pin Number 28 of PORTC
#define PORTC_PC7	(uint8_t)29 ///< This is Hardware pin Number 29 of PORTC
/* PORT C */
#define PORTA_PA0	(uint8_t)40 ///< This is Hardware pin Number 40 of PORTA
#define PORTA_PA1	(uint8_t)39 ///< This is Hardware pin Number 39 of PORTA
#define PORTA_PA2	(uint8_t)38 ///< This is Hardware pin Number 38 of PORTA 
#define PORTA_PA3	(uint8_t)37 ///< This is Hardware pin Number 37 of PORTA
#define PORTA_PA4	(uint8_t)36 ///< This is Hardware pin Number 36 of PORTA
#define PORTA_PA5	(uint8_t)35 ///< This is Hardware pin Number 35 of PORTA
#define PORTA_PA6	(uint8_t)34 ///< This is Hardware pin Number 34 of PORTA
#define PORTA_PA7	(uint8_t)33 ///< This is Hardware pin Number 33 of PORTA
 
 /** 
   * @brief    Each Port has rang of Numbers  
   */           
#define PORTA_START		(uint8_t)33 ///< This is First pin Number  of PORTA
#define PORTA_END		(uint8_t)40 ///< This is Last pin Number  of PORTA

#define PORTB_START		(uint8_t)1 ///< This is First pin Number  of PORTB
#define PORTB_END		(uint8_t)8 ///< This is First pin Number  of PORTB

#define PORTC_START		(uint8_t)22 ///< This is First pin Number  of PORTC
#define PORTC_END		(uint8_t)29 ///< This is First pin Number  of PORTC

#define PORTD_START		(uint8_t)14 ///< This is First pin Number  of PORTD
#define PORTD_END		(uint8_t)21 ///< This is First pin Number  of PORTD
  
/** @} */   /* End of Macro Group*/
/** @} */ /* End of TimerHeader Group */



/* Function Prototype */

uint8_t GetPort(uint8_t McuPin);
uint8_t GetPinNumber(uint8_t McuPin);
/* Set pin or port Direction */
void Port_SetPinDirection(uint8_t McuPin,ePinDir_t Direction);
void Port_SetPortDirection(uint8_t McuPort,ePortDir_t Direction);
/* Read Write PortPin */
void Port_WritePin(uint8_t McuPin,uint8_t PinValue);
uint8_t Port_ReadPin(uint8_t McuPin);
/* Read Write Port */
void Port_WritePort(uint8_t McuPort,uint8_t PortValue);
uint8_t Port_ReadPort(uint8_t McuPort);




#endif