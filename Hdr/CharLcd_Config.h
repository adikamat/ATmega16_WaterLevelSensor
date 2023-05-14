/**
  ******************************************************************************
  * @file    CharLCd.h
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
#ifndef  _CHARLCD_CONFIG_H
#define  _CHARLCD_CONFIG_H

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
#include "ATmega16_Port.h"
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
  * @#define   _X_BY_Y 
  * @brief     Macro for LCD Type  
  *			   X = No Of Character
  *			   Y = No of Lines in LCD
  */          
//#define  Lcd_begin(character,Line)		_character_BY_Line   
#define  _8_BY_1                1
#define  _8_BY_2                2
#define  _16_BY_1               3
#define  _16_BY_2               4
#define  _20_BY_1               5
#define  _20_BY_2               6
#define  _20_BY_4               7
#define  _40_BY_1               8
#define  _40_BY_2               9

#define  LCD_TYPE              _16_BY_2    

/** 
  * @#define	Macro to copy s/w signal to H/w port
  * @brief		MCU SPECIFIC HARDWARE PIN INTERFACE   
  *			NOTE!!!!: This part you have to Modify according to your hardware. 			 
  *			Lcd pins are DB0-DB7, RS, R/W,EN
  *			Here hardware macros are defined which copy virtual port signal to
  *			actual hardware pins of MCU.These portpin you have to assign depending 
  *			upon hardware connection of your project.
  *			SW_LCD_D0 to SW_LCD_D7 number corresponds to bit no in sCLcdData_t
  *			structure. while SW_LCD_RS and SW_LCD_RW LCD_EN bit number 
  *		corresponds to sCLcdControl_t structure.
  */
    
  
#define	 SW_LCD_D0_BIT				 0
#define	 SW_LCD_D1_BIT				 1
#define	 SW_LCD_D2_BIT				 2
#define	 SW_LCD_D3_BIT				 3
#define	 SW_LCD_D4_BIT				 4
#define	 SW_LCD_D5_BIT				 5
#define	 SW_LCD_D6_BIT				 6
#define	 SW_LCD_D7_BIT				 7
 
#define	 SW_LCD_RS_BIT				0
#define  SW_LCD_RW_BIT				1
#define  SW_LCD_EN_BIT				2
  
#define  HW_LCD_DATA_PORT			(PORTA) 
#define  HW_LCD_D0_PIN				(PA0)
#define  HW_LCD_D1_PIN				(PA1)
#define  HW_LCD_D2_PIN				(PA2)
#define  HW_LCD_D3_PIN				(PA3)
#define  HW_LCD_D4_PIN				(PA4)
#define  HW_LCD_D5_PIN				(PA5)
#define  HW_LCD_D6_PIN				(PA6)
#define  HW_LCD_D7_PIN				(PA7)

//#define  MCU_LCD_D0_PIN			PORTA_PA0
//#define  MCU_LCD_D1_PIN			PORTA_PA1
//#define  MCU_LCD_D2_PIN			PORTA_PA2
//#define  MCU_LCD_D3_PIN			PORTA_PA3
//#define  MCU_LCD_D4_PIN			PORTA_PA4
//#define  MCU_LCD_D5_PIN			PORTA_PA5
//#define  MCU_LCD_D6_PIN			PORTA_PA6
//#define  MCU_LCD_D7_PIN			PORTA_PA7



#define  HW_LCD_CONTROL_PORT		(PORTC) 
#define  HW_LCD_RS_PIN				(PC7)
#define  HW_LCD_RW_PIN				(PC6)
#define  HW_LCD_EN_PIN				(PC5)

//#define  MCU_LCD_RS_PIN			PORTC_PC7
//#define  MCU_LCD_RW_PIN			PORTC_PC6
//#define  MCU_LCD_EN_PIN			PORTC_PC5
		

#define  SW_TO_HW_LCD_D0			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D0_PIN,u8LcdData,SW_LCD_D0_BIT) 
#define  SW_TO_HW_LCD_D1			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D1_PIN,u8LcdData,SW_LCD_D1_BIT)
#define  SW_TO_HW_LCD_D2			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D2_PIN,u8LcdData,SW_LCD_D2_BIT)
#define  SW_TO_HW_LCD_D3			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D3_PIN,u8LcdData,SW_LCD_D3_BIT)
#define  SW_TO_HW_LCD_D4			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D4_PIN,u8LcdData,SW_LCD_D4_BIT)
#define  SW_TO_HW_LCD_D5			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D5_PIN,u8LcdData,SW_LCD_D5_BIT)
#define  SW_TO_HW_LCD_D6			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D6_PIN,u8LcdData,SW_LCD_D6_BIT)
#define  SW_TO_HW_LCD_D7			COPY_BIT(HW_LCD_DATA_PORT,HW_LCD_D7_PIN,u8LcdData,SW_LCD_D7_BIT)

#define	 SW_TO_HW_LCD_DATA			COPY_REG(HW_LCD_DATA_PORT,u8LcdData)	

/* Macro For Control pins   */ 
#define  SW_TO_HW_LCD_RS			COPY_BIT(HW_LCD_CONTROL_PORT,HW_LCD_RS_PIN,u8LcdControl,SW_LCD_RS_BIT)
#define  SW_TO_HW_LCD_RW			COPY_BIT(HW_LCD_CONTROL_PORT,HW_LCD_RW_PIN,u8LcdControl,SW_LCD_RW_BIT)
#define  SW_TO_HW_LCD_EN			COPY_BIT(HW_LCD_CONTROL_PORT,HW_LCD_EN_PIN,u8LcdControl,SW_LCD_EN_BIT)
 
/** 
  * @#define    
  * @brief     Custom Character Command
  */          
#define  ARROW_UP		(uint8_t)0
#define  ARROW_DOWN		(uint8_t)1
	
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