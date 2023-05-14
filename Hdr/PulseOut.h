/**
  ******************************************************************************
  * @file    PulseOut.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    18-Aug-2021
  * @brief   Header file for Pulse Out Functionality.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2020 Machine Control</center></h2>
  ******************************************************************************
 */
#ifndef  _PULSEOUT_H
#define  _PULSEOUT_H

/** @addtogroup  Header
  * @{
  */
  
/** 
  * @brief  system header  
  */
#include "System.h"
/** 
  * @brief  Application specific header  
  *			We require PortHeader and Timer Header.
  */
#include "ATmega16_TC0.h"
#include "ATmega16_TC1.h"
#include "ATmega16_Port.h"
/**
  * @}
  */
  
/** @addtogroup Struct/Union 
  * @{
  */ 
typedef struct{
uint8_t		u8McuPin;		/*!< MCU Port Pin No on which pulse is generated */
uint8_t		u8PulseType;	/*!< Rising edge or Falling edge pulse*/
uint8_t		u8Unit		;	/*!< Shows whether duration is in micro/milli sec.*/
uint16_t	u16Duration;	/*!< Duration for which pulse is generated */
uint16_t	u16RepeatCount;	/*!< No of times pulse is repeated on McuPin */
uint16_t	u16InterPulseDelay;/*!<Time difference between two consecutive pulse*/
uint8_t		u8TimerResolution; /*!<Which Timer resolution to be used */   
}sPulseOut_t;
/**
  * @}
  */  
  
/** @defgroup  #define Macros 
  * @{
  */
  #define  U		(uint8_t)0x01   /*!< time duration in Microsecond */
  #define  M		(uint8_t)0x02   /*!< time duration in Millisecond */
  #define  S		(uint8_t)0x03   /*!< time duration in Second */  
  /* Resolution Macros */
  #define  _P125_USEC	(uint8_t)1
  #define  _P0625_USEC	(uint8_t)2
  #define  _P5_USEC		(uint8_t)3
  #define  _1_USEC		(uint8_t)4
  #define  _4_USEC		(uint8_t)5
  #define  _8_USEC		(uint8_t)6
  #define  _16_USEC		(uint8_t)7
  #define  _32_USEC		(uint8_t)8
  #define  _64_USEC		(uint8_t)9
  #define  _128_USEC	(uint8_t)10
  
  
  
  #define  RISING_EDGE		(uint8_t)0x01   /*!< Rising edge pulse 
											   LOW TO HIGH --DELAY--HIGH TO LOW
											    */
  #define  FALLING_EDGE		(uint8_t)0x02   /*!< Falling edge 
											  HIGH TO LOW --DELAY--LOW TO HIGH
											  */	
  
  #define	_10USEC			(uint8_t)0x01
  #define	_15USEC			(uint8_t)0x02
  #define	_20USEC			(uint8_t)0x10  
  
 #define  DUMMY_MCU_PIN     (uint8_t)0x00
/**
  * @}
  */  

  /** @defgroup  Function Macros 
  * @{
  */
 
/**
  * @}
  */
  
/** @defgroup  Inline Function  
  * @{
  */
 
/**
  * @}
  */ 
  
/** @defgroup  typedef Module specific  
  * @{
  */
 
     
/**
  * @}
  */  
  
/** @addtogroup Enum 
  * @{
  */


/**
  * @}
  */
  
/** @addtogroup Function Prototype
  * @{
  */  
/* Initialization */
void PO_InitStructure(void);
void PO_Init(void);
/*Pulse parameters */
void PO_SetPulseParameter(uint8_t mcupin,uint16_t duration,uint8_t unit, 
						 uint8_t pulsetype);
void PO_SetRepeatPulseParameter(uint8_t mcupin,uint16_t duration,uint8_t unit,
								uint8_t pulsetype,uint16_t repeatCount,
								uint16_t interpulsedelay);
/* Generation of Pulse */
void PO_GeneratePulseInt(void);
void PO_GeneratePulseSw	(uint8_t mcuPin,uint8_t delay,uint8_t pulseType);
/* Interrupt Register Function */
void PO_RegisterTimerOverflowIntService(fpointerv_t  fun , uint8_t param);
/* Interrupt Service routines */
void PO_PulseInterruptService(uint8_t mcupin);
void PO_RepeatPulseInterruptService(uint8_t mcupin);	

/**
  * @}
  */

  
/** @addtogroup External variables 
  * @{
  */ 
  
/**
  * @}
  */   

#endif