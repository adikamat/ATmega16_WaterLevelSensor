/**
  ******************************************************************************
  * @file   Usart_config .h
  * @author  GRT/AMK
  * @version V1.0
  * @date    26-Aug-2022
  * @brief   This is  config file for Usart Module.
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
#ifndef  _USART_CONFIG_H
#define  _USART_CONFIG_H

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

/* Buffer Size*/
#define TX_BUFFER_SIZE		7
#define RX_BUFFER_SIZE      7

/* Polling or Interrupt */
#define POLLING				 (0x01)
#define INTERRUPT		 	(0x02)
  
#define TX_RX_METHODS         POLLING
  
  
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