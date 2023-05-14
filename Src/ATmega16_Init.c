/**
  ******************************************************************************
  * @file    Source file name.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    11-July-2020
  * @brief   ModuleDescription.
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
#include "InputCapture.h"
#include "PulseOut.h"
#include "Ultrasonic.h"
#include "Usart.h"
/**
  * @}
  */
 
/** @addtogroup Struct/Union definition and Short Name
  * @{
  */ 
  
 
 
/**
  * @}
  */   
  
  
/** @addtogroup static variable 
  * @{
  */ 
  
/**
  * @}
  */   
/** @addtogroup static fucntion 
  * @{
  */ 
  
/**
  * @}
  */   
  
/** @addtogroup variable declaration 
  * @{
  */ 
 
/**
  * @}
  */      
/** @addtogroup  Static Function Defination 
  * @{
  */ 
  
  /**
  * @}
  */     
  
/** @addtogroup  Module Interface Function Definition 
  * @{
  */
  
/** 				
  * @brief			
  * @PreCondition	
  * @PostCondition  
  * @param			
  * @description	
  * @retval			
  */
void Init_System(void)
{    
	/* Disable Global interrupt */   
	 asm("CLI");
	
	/************************************/
	/* Initialize HAL Modules.  */
	/************************************/
	
	/* Initialize Pulse Module */
	//	PO_Init();
	/* Initialize Input Capture module */
		IC_Init();
	/* Initialize Usart Module */
	//	Usart_Init();
		
	/************************************/
	/* Initialize Application Modules.  */
	/************************************/
	  /*Initialize LCD module */
		Lcd_HwInit();
		Lcd_LcdInit();
	    //Ultra_DisplayRangeText();
		//Ultra_DisplayMaxText();
		//Ultra_DisplayMinText();
		///Ultra_DisplayCmText();	
	/* Initialize Ultrasonic Sensor HC-SR04  */
	  // Ultra_Init();     
	   
	/* Enable Global Interrupt */	
	asm("SEI");
}

/**
  * @}
 */
