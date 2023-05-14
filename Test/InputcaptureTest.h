/**
  ******************************************************************************
  * @file    Inputcapture.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020
  * @brief   
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
#ifndef  _INPUTCAPTURE_HEADER_H
#define  _INPUTCAPTURE_HEADER_H

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
#include "InputCapture.h"
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
 void Test_IC_Init(void);							/*p*/
 
 void Test_IC_AttachPinToCaptureChannel(void);		/*p*/
 void Test_IC_DetachPinFromCaptureChannel(void);
 
 void Test_IC_SetCaptureEdge(void);					/*p*/
 uint8_t  Test_IC_GetCaptureEdge(void);				/*p*/
 
 void Test_IC_SetEdgeMode(void);					/*p*/
 uint8_t Test_IC_GetEdgeCount(void);				/*p*/
 uint8_t Test_IC_GetDataStatus(void);
 
 void  Test_IC_SetTimerResolution(void);			/*p*/
 void  Test_IC_StartInputCapture(void);				/*p*/
 void  Test_IC_StopInputCapture(void);				/*p*/
 uint16_t Test_IC_GetPeriodCount(void);				/*p*/
 uint16_t Test_IC_GetHighTimeCount(void);			/*p*/
 uint16_t Test_IC_GetLowTimeCount(void);			/*p*/
 
 void Test_IC_RegisterInputCaptureIntService(void);	/*p*/
 void Test_IC_RegisterTimerOverflowIntService(void) ;
  
/**
  * @}
  */   


#endif