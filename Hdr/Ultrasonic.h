/**
  ******************************************************************************
  * @file    Ultrasonic.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    15-July-2020
  * @brief   Header file for Ultrasonic Sensor
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
#ifndef  _ULTRASONIC_H
#define  _ULTRASONIC_H

/** @addtogroup  Header
  * @{
  */
  
/** 
  * @brief  system header  
  */
#include "System.h"
/** 
  * @brief  Application specific header  
  */
#include "Ultrasonic_Config.h"
/**
  * @}
  */
  
/** @addtogroup Struct/Union 
  * @{
  */ 
/** 
  * @struct  sUltrasonicSensor_t
  * @brief   Ultrasonic sensor             
  */ 
typedef struct{
uint8_t						u8UltrsonicTriggerPin;	/* Hardware Pins where trigger pin is connected */
uint8_t						u8UltrsonicEchoPin;		/* Hardware Pins where echo pin is connected */
uint16_t					u16DetectionRangeMax;	/* Maximum Detection Range set by user in cm  in Q10.6 format*/
uint16_t					u16DetectionRangeMin;	/* Minimum Detection Range set by user in cm  in Q10.6 format */
}sUltrasonicSensor_t;

/** 
  * @struct  sObjectStatus_t
  * @brief   Object status            
  */ 
typedef struct{
uint8_t bAboveMaxRange	:1;	/* Object beyond set Maximum range */
uint8_t bInRange		:1;	/* Object is between set Maximum  and  set Min range */
uint8_t bBelowMinRange	:1;	/* Object is below set Min range */
uint8_t bCollision      :1; /* Set to 1 if object is below min Range */
uint8_t Reserved		:4;
}sObjectRangeStatus_t;

typedef union{
sObjectRangeStatus_t    sObjectRangeStatus;
uint8_t					u8ObjectRangeStatus;
}uObjectRangeStatus_t; 

typedef union{
uObjectRangeStatus_t  uObjectRangeStatus;
uint16_t			  u161006ObjectRange;/* Actual Object Range	in Q10.6 format*/
}sObjectStatus_t;

  /**
  * @}
  */  
 
 /** @addtogroup External variables 
  * @{
  */ 
extern sUltrasonicSensor_t			sUltrasonicSensor;
extern sObjectStatus_t				sObjectStatus;
extern char	ObjectRangeAscii[7];
/**
  * @}
  */    
  
/** @defgroup  #define Macros 
  * @{
  */

 /** 
  * @#define	 
  * @brief		 Short Names for Virtual Ultrasonic Port 
  */		
#define u8UltrsonicTriggerPin			sUltrasonicSensor.u8UltrsonicTriggerPin 
#define u8UltrsonicEchoPin				sUltrasonicSensor.u8UltrsonicEchoPin 	
#define u16DetectionRangeMax			sUltrasonicSensor.u16DetectionRangeMax
#define u16DetectionRangeMin			sUltrasonicSensor.u16DetectionRangeMin

/** 
  * @#define	 
  * @brief		 Short Names for Object Status
  */		
#define u16ObjectRange			sObjectStatus.u161006ObjectRange

#define	bAboveMaxRange			sObjectStatus.uObjectRangeStatus.sObjectRangeStatus.bAboveMaxRange
#define ABOVE_MAX_RANGE_BIT		0

#define	bInRange				sObjectStatus.uObjectRangeStatus.sObjectRangeStatus.bInRange
#define IN_RANGE_BIT			1

#define	bBelowMinRange			sObjectStatus.uObjectRangeStatus.sObjectRangeStatus.bBelowMinRange
#define BELOW_RNAGE_BIT         2

#define bCollision				sObjectStatus.uObjectRangeStatus.sObjectRangeStatus.bCollision
#define COLLISION_BIT			3

#define ObjectRangeStatus		sObjectStatus.uObjectRangeStatus.u8ObjectRangeStatus




/** 
  * @#define	 
  * @brief		 Max and Min values for Q10.6 format unsigned.
  */			
#define Q10_6_MAX		1023
#define Q10_6_MIN       0

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
  
/** @defgroup  typedef Module spacific  
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

void		Ultra_Init(void); 
void		Ultra_SendPulse(void);
void		Ultra_ClrearObjectRangeAscii(void);
/* Display related Function */
void		Ultra_DisplayObjectRange(void);
void		Ultra_DisplayMaxRange(void);
void		Ultra_DisplayMinRange(void);

void		Ultra_DisplayRangeText(void);
void		Ultra_DisplayMaxText(void);
void		Ultra_DisplayMinText(void);
void		Ultra_DisplayCmText(void);
/* Range related Functions */
void		Ultra_SetMaxRange(uint16_t Range);
void		Ultra_SetMinRange(uint16_t Range);
uint8_t		Ultra_GetObjectRange(void);
uint16_t	Ultra_GetMaxDetectionRange(void);
uint16_t	Ultra_GetMinDetectionRange(void);
/* Object status related Function */
uint8_t		Ultra_IsObjectInRange(void); 
uint8_t		Ultra_IsCollision(void);
uint8_t		Ultra_IsObjectAboveRange(void);
void		Ultra_ConvertDistanceToAscii(uint16_t  Distance, char Array[]);



/** 
  * @}
  */

  
#endif
