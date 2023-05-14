/**
  ******************************************************************************
  * @file    System.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    19-Sept-2020
  * @brief   This file includes Global Declaration.
  *          
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

#ifndef  _SYSTEM_H
#define  _SYSTEM_H

/** @addtogroup  Header
  * @{
  */
#include "Std_Types.h"
//#include "iom16.h"
#include <avr/io.h>
/** 
  * @brief  Platform Spacific header  
  */
 
/** 
  * @brief  Compiler specific header  
  */

/**
  * @}
  */
 
  /** @addtogroup Switches 
  * @{
  */ 


/**
  * @}
  */  

 
 /** @addtogroup Enum 
  * @{
  */ 
 /** \enum   eClock 
 *  Define all clock values for MCU 
 */
//typedef enum
//{
#define CLOCK_8_MHZ					1
#define CLOCK_11_059_MHZ			2 
#define CLOCK_12_MHZ				3 
#define CLOCK_16_MHZ				4

#define MCU_CLOCK					CLOCK_8_MHZ	

/**
  * @}
  */  

 /** @defgroup  typedef   
  * @{
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
  *  Ram Check 
  */	
#define RAM_CHECK_PATTERN1		0xAA
#define RAM_CHECK_PATTERN2		0x55 
/**
  *  Define Time
  */
#define NANO_SEC     		            ((uint32_t)1000000000)
#define MICRO_SEC			            ((uint32_t)1000000)
#define MILLI_SEC     	                ((uint32_t)1000)
#define CONVERT_SEC_TO_MILLISEC(a)	 	((uint32_t)(a * 1000 ))
#define CONVERT_MILLISEC_TO_MICROSEC(a)	((uint32_t)(a * 1000 ))
#define CONVERT_MICROSEC_TO_NANOSEC(a)	((uint32_t)(a * 1000 ))

//#define F_CPU 8000000UL
/**
  *  Bit No
  */
#define BIT0    ((uint8_t)0)
#define BIT1    ((uint8_t)1)
#define BIT2    ((uint8_t)2)
#define BIT3    ((uint8_t)3)
#define BIT4    ((uint8_t)4)
#define BIT5    ((uint8_t)5)
#define BIT6    ((uint8_t)6)
#define BIT7    ((uint8_t)7)
#define BIT8    ((uint8_t)8)
#define BIT9    ((uint8_t)9)
#define BIT10   ((uint8_t)10)
#define BIT11   ((uint8_t)11)
#define BIT12   ((uint8_t)12)
#define BIT13   ((uint8_t)13)
#define BIT14   ((uint8_t)14)
#define BIT15   ((uint8_t)15)	
#define BIT16   ((uint8_t)16)
#define BIT17   ((uint8_t)17)
#define BIT18   ((uint8_t)18)
#define BIT19   ((uint8_t)19)
#define BIT20   ((uint8_t)20)
#define BIT21   ((uint8_t)21)
#define BIT22   ((uint8_t)22)
#define BIT23   ((uint8_t)23)	
#define BIT24   ((uint8_t)24)
#define BIT25   ((uint8_t)25)
#define BIT26   ((uint8_t)26)
#define BIT27   ((uint8_t)27)
#define BIT28   ((uint8_t)28)
#define BIT29   ((uint8_t)29)
#define BIT30   ((uint8_t)30)
#define BIT31   ((uint8_t)31)	

/**
  *ZERO
  */
#define U8ZERO   	(0x00)
#define u16ZERO   	(0x0000)
#define u32ZERO   	(0x00000000 )
/**
  * Return Value for Function
  */
#define  SUCCESS	(uint8_t)1
#define  FAIL		(uint8_t)0

#define  TRUE		(uint8_t)1
#define  FALSE		(uint8_t)0

/**
  * Device State 
  */
#define  DEVICE_ON			(uint8_t)1
#define  DEVICE_OFF			(uint8_t)0

/**
  * For dubug purpose only 
  */

#define STOP  asm("NOP");


/**
  * @}
  */
 
/** @defgroup  Function Macros 
  * @{
  */

/**
  * Bit manipulation Macros
  */
#define SET_BIT(Reg,bitno)                       (Reg = (Reg)|(1 << (bitno)))
#define ISBITSET(Reg,bitno)   					((Reg)&(1<<bitno))
#define CLR_BIT(Reg,bitno)                       (Reg = (Reg) & (~(1 << (bitno))))
#define ISBITCLR(Reg,bitno)						(~(Reg) & (1<<(bitno)))
#define COPY_REG(Reg1,Reg2)		                (Reg1 = Reg2 )
#define SET_REG(Reg,Val)						(Reg = Val)
#define REG_SHIFT_LEFT(Reg,shiftno)   	        (Reg = Reg << shiftno)
#define REG_SHIFT_RIGHT(Reg,shiftno)   	        (Reg = Reg >> shiftno)
#define ON(DevicePort, DeviceID)                SET_BIT(DevicePort,DeviceID)
#define OFF(DevicePort, DeviceID)               CLR_BIT(DevicePort,DeviceID)
#define SET_SIGNAL_HIGH(SignalPort,Signal)      SET_BIT(SignalPort,Signal)
#define SET_SIGNAL_LOW(SignalPort,Signal)       CLR_BIT(SignalPort,Signal)
#define IS_TRUE(Reg)                           (Reg > 0x00)
#define IS_FALSE(Reg)                          (Reg<= 0x00)
#define IS_POSITIVE(Reg)					   (Reg > 0x00)	
#define IS_NEGATIVE(Reg)					   (Reg < 0x00)	
/* Reg2 bit2 is copied to Reg1 Bit1 */
#define COPY_BIT(Reg1,bit1,Reg2,bit2)		if(ISBITSET(Reg2,bit2))\
												SET_BIT(Reg1,bit1);\
											else\
												CLR_BIT(Reg1,bit1);
/**
  * @}
  */
  
/** @defgroup  Inline Function  
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

/** @addtogroup Function Prototype
  * @{
  */ 

/**
  * @}
  */   
#endif  /* GLOBAL_TYPES_H */ 
