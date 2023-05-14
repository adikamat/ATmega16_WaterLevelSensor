/**
  ******************************************************************************
  * @file    InputCapture.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    13-Dec-2020
  * @brief   Header file for Input Capture.
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
#ifndef  _INPUTCAPTURE_H
#define  _INPUTCAPTURE_H

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
#include "InputCapture_Config.h"
#include "ATmega16_TC1.h"
#include "ATmega16_Port.h"
#include "PulseOut.h"
/**
  * @}
  */
  
/** @addtogroup Struct/Union 
  * @{
  */ 
typedef struct{
uint8_t		u8InputCaptureChannelPin;	/*!< MCU Port Pin No which acts as Input Capture */			
uint16_t	u16FirstTimeSample;			/*!< Time Stamp of  first edge either rising or falling */
uint16_t	u16SecondTimeSample;		/*!< Time Stamp of second edge either rising or falling */
uint16_t	u16ThirdTimeSample;			/*!< Time Stamp  of  third edge either rising or falling */
uint8_t		u8NoOfTimerOverFlow;		/*!< No of Overflow of InputCapture timer  */
volatile uint8_t		u8DataStatus;				/*!< Data Status of all three Time samples. IC_CAPTURED or IC_NOT_CAPTURED */
uint8_t		u8CaptureEdge;				/*!< Either IC_RISING_EDGE or IC_FALLING_EDGE */
uint8_t		u8EdgeMode;					/*!< Either IC_PULSE_MODE or IC_PERIOD_MODE */
uint8_t		u8EdgeCounter;				/*!< Keep track of how many edges are Captured */
uint8_t     u8EdgesBeforeTimerOverFlow; /*!< Keep the track of How many edges occurs before TimerOverflow.*/
uint16_t	u16HighTimeCount;			/*!< Difference between SecondTimeSample and FirstTimeSample */
uint16_t	u16LowTimeCount;			/*!< Difference between ThirdTimeSample and SecondTimeSample */
uint16_t	u16PeriodCount;			    /*!< Difference between FirstTimeSample and ThirdTimeSample */
}sInputCapture_t;
  
  /**
  * @}
  */  
  
/** @defgroup  #define Macros 
  * @{
  */
 #define  DUMMY_MCU_PIN				(uint8_t)0x00
 
/** 
  * @#define          
  * @brief      Macros for InnputCapturePin of MCU 
  */  
//#define	IC_PIN_ICP1				TC1_PIN_ICP1   /*!< This pin is mappped to ICP1 pin of MCU pin no 20*/

/** 
  * @#define          
  * @brief      Macros for DataStatus 
  */  
#define IC_DATA_NOT_CAPTURED		((uint8_t)0x00)
#define IC_DATA_CAPTURED			((uint8_t)0x01) 
#define IC_DATA_CAPTURING			((uint8_t)0x02)

/** 
  * @#define          
  * @brief        Macros for CaptureEdge
  */  
#define	IC_RISING_EDGE		((uint8_t)0x01)	
#define	IC_FALLING_EDGE		((uint8_t)0x02)
/** 
  * @#define          
  * @brief       Macros for EdgeMode
  */  
#define IC_PULSE_MODE		((uint8_t)0x01)	
#define IC_PERIOD_MODE		((uint8_t)0x02)	
#define IC_MULTIEDGE_MODE	((uint8_t)0x03)	

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

/**
  * @}
  */

/** @addtogroup External variables 
  * @{
  */ 
  
/**
  * @}
  */   

/* Prototype for calling in Initialization Function */
void IC_Init(void);
//void IC_InitStructure(void);

/* Prototype for Populating(Set Method) Input Capture structure */
void IC_AttachPinToCaptureChannel(uint8_t InputChannelPin);
void IC_DetachPinFromCaptureChannel(void);
void IC_SetCaptureEdge(uint8_t u8CaptureEdge);
void IC_SetEdgeMode(uint8_t EdgeMode);

/* Prototype for Getting(Get Method) Input Capture structure */
void	IC_SetDataStatus(uint8_t datastatus);
void	IC_SetCaptureEdge(uint8_t u8CaptureEdge);
void    IC_SetEdgeMode( uint8_t Edge);
uint8_t IC_GetEdgeCount(void);
uint8_t IC_GetDataStatus(void);
uint8_t IC_GetCaptureEdge(void);


/* Prototype for Starting / Stopping Input Capture timer  */
void  IC_SetTimerResolution(uint8_t TimerResolution);
void  IC_StartInputCapture(void);
void  IC_StopInputCaptureTimer(void);

/* Prototype  User Interface to Module  */
uint16_t IC_GetPeriodCount(void);
uint16_t IC_GetPulseCount(void);
uint16_t IC_GetLowTimeCount(void);
//uint16_t IC_GetFrequency(void);
//uint16_t IC_GetDutyCycle(void);

/* Module Interrupt Service Routine*/
void IC_CaptureInterruptService(uint8_t param);
void IC_TimerInterruptService(uint8_t param);
/*Module Interrupt Register Routine*/
void IC_RegisterTimerOverflowIntService(fpointerv_t  fun , uint8_t param);
void IC_RegisterInputCaptureIntService(fpointerv_t  fun , uint8_t param);	
	


#endif