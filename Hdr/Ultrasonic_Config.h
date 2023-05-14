/**
  ******************************************************************************
  * @file    Ultrasonic_Config.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    15-July-2020
  * @brief   Configuration file for Ultrasonic sensor.
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
#ifndef  _ULTRASONIC_CONFIG_H
#define  _ULTRASONIC_CONFIG_H

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
  * @#define	Hardware Macros
  * @brief		MCU SPECIFIC HARDWARE PIN INTERFACE   
  *			NOTE!!!!: This part you have to Modify according to your hardware. 			 
  *			Ultrasonic pins are Trigger and echo
  *			Here hardware macros are defined which copy virtual port signal to
  *			actual hardware pins of MCU.These portpin you have to assign depending 
  *			upon hardware connection of your project.
  *			TRIGGER and ECHO number corresponds to bit no in sUltrasonicSensor_t structure.
  */
 
 
 #define   MCU_ULTRASONIC_TRIGGER_PIN				PORTD_PD4
 #define   MCU_ULTRASONIC_ECHO_PIN					PORTD_PD6
 
  
 /* Macro For Control pins   */
 //#define	SW_TO_HW_ULTRASONIC_TRIGGER_PIN		COPY_BIT(HW_ULTRASONIC_PORT,HW_ULTRASONIC_TRIGGER_PIN,u8UltrasonicPin,SW_ULTRASONIC_TRIGGER_BIT)
 //#define	HW_TO_SW_ULTRASONIC_ECHO_PIN		COPY_BIT(u8UltrasonicPin,SW_ULTRASONIC_ECHO_BIT,HW_ULTRASONIC_PORT,HW_ULTRASONIC_ECHO_PIN)  
  
  /** 
  * @#define	MAX/MIN 
  * @brief		Maximum and Minimum Rang of Ultrsonic Sensor.
  */
 #define   ULTASONIC_SENSOR_MAX_RANGE	(uint16_t)6400 /*400 cm in Q10.6 cm*/
 #define   ULTASONIC_SENSOR_MIN_RANGE   (uint16_t)80   /*2 cm in Q10.6 cm*/	
 
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


#endif