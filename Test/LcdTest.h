/**
  ******************************************************************************
  * @file    header.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    15-July-2020
  * @brief   This file provides templete for header.
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
#ifndef  _LCDTEST_H
#define  _LCDTEST_H

/** @addtogroup  Header
  * @{
  */
  
/** 
  * @brief  system header  
  */

/** 
  * @brief  Application specific header  
  */
#include "CharLcd.h"
#include <util/delay.h>  
/**
  * @}
  */
  
/** @addtogroup Struct/Union 
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
/* Basic Command */ 
void Test_Lcd_WriteCommand(void);		/*P*/
void Test_Lcd_WriteData(void);			/*P*/
/* Initialization */
void Test_Lcd_DisplayClear(void);
void Test_Lcd_CursorHome(void);
void Test_Lcd_HwInit(void);				/*P*/
void Test_Lcd_LcdInit(void);			/*P*/
/*  Function related to Cursor */
void Test_Lcd_SetCursor(void);			/*P*/
void Test_Lcd_SetCursorPosition(void);	/*P*/
void Test_Lcd_CursorOn(void);			/*P*/
void Test_Lcd_CursorOff(void);			/*P*/
/* Function Related to Printing Ascii Char */
void Test_Lcd_Printf(void);				/*P*/
/* function Related to Blink */
void Test_Lcd_BlinkOn(void);			/*P*/
void Test_Lcd_BlinkOff(void);			/*P*/
/* Function Related to Display */
void Test_Lcd_DisplayOn(void);			/*P*/
void Test_Lcd_DisplayOff(void);			/*P*/
/* Function Related to Scrolling */
void Test_Lcd_ScrollDisplayLeft(void);	/*P*/
void Test_Lcd_ScrollDisplayRight(void);	/*P*/
void Test_Lcd_AutoScroll(void);
void Test_Lcd_NoAutoScroll(void);
/* Function Related to Text Direction */
void Test_Lcd_TextLeftToRight(void);	/*p*/
void Test_Lcd_TextRightToLeft(void);	/*p*/
/* Custom Character Commands */
void Test_Lcd_CreateCustomChar(void);	/*p*/
void Test_Lcd_PrintCustomChar(void);	/*p*/

/**
  * @}
  */

  



#endif