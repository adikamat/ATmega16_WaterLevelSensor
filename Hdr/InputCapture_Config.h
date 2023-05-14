/**
  ******************************************************************************
  * @file    Header.h
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
#ifndef  _INPUTCAPTURE_CONFIG_H
#define  _INPUTCAPTURE_CONFIG_H

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
  * @#define          
  * @brief       Macros for Resolution of InputCapture timer.
  */  
#define IC_TIMER_RES_P125USEC       ((uint8_t)0x01)	
#define IC_TIMER_RES_1USEC			((uint8_t)0x02)	
#define IC_TIMER_RES_8USEC			((uint8_t)0x03)
#define IC_TIMER_RES_32USEC			((uint8_t)0x04)
#define IC_TIMER_RES_128USEC		((uint8_t)0x05)	

#define IC_TIMER_RESOLUTION			(IC_TIMER_RES_1USEC)

#define  MCU_ULTRASONIC_ECHO_PIN    PORTD_PD6

  
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


#endif