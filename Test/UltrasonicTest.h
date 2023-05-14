/**
  ******************************************************************************
  * @file    UltrasonicTest.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020
  * @brief   Header file for Character Liquid crystal display.
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
#ifndef  _HEADER_H
#define  _HEADER_H

/** @addtogroup  Header
  * @{
  */
  
/** 
  * @brief  system header  
  */

/** 
  * @brief  Application specific header  
  */

/**
  * @}
  */
  
/** @addtogroup Struct/Union 
  * @{
  */ 
  
  /**
  * @}
  */  
  
/** @defgroup  #define Macros 
  * @{
  */
  
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

/**
  * @}
  */

  
/** @addtogroup External variables 
  * @{
  */ 
  
/**
  * @}
  */   
void		Test_Ultra_Init(void);
void		Test_Ultra_SendPulse(void);
/* Display related Function */
void		Test_Ultra_DisplayObjectRange(void);
void		Test_Ultra_DisplayMaxRange(void);
void		Test_Ultra_DisplayMinRange(void);
/* Range related Functions */
void		Test_Ultra_SetMaxRange(void);
void		Test_Ultra_SetMinRange(void);
uint16_t	Test_Ultra_GetObjectRange(void);
uint16_t	Test_Ultra_GetMaxDetectionRange(void);
uint16_t	Test_Ultra_GetMinDetectionRange(void);

/* Object status related Function */
uint8_t		Test_Ultra_IsObjectInRange(void);
uint8_t		Test_Ultra_IsCollision(void);
uint8_t		Test_Ultra_IsObjectAboveRange(void);
void		Test_Ultra_ConvertDistanceToAscii(void);



#endif