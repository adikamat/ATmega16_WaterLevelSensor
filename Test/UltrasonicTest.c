/**
  ******************************************************************************
  * @file    UltrasonicTest.c
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

/**
  * @}
  */
 
/** @addtogroup Struct/Union  variable defination and Short Name
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
/** @addtogroup static fucntion declaration
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
  
/** @addtogroup  Module Interface Function Defination 
  * @{
  */
  
  /*****************************************************/
  /*		Ultrasonic Module functions Test             */
  /****************************************************/
  
  //Ultra_SetMaxRange(400);   /*p*/
  //Ultra_SetMinRange(350);   /* P*/ /*  test this  after setting Max range*/
  
  //Ultra_SetMaxRange(369);
  //Ultra_DisplayMaxRange();
  //Ultra_SetMinRange(169);
  //Ultra_DisplayMinRange();
  //Ultra_CalculateObjectRange();
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);
  //Ultra_CalculateObjectRange(23207);
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);
  //Ultra_CalculateObjectRange(23324);
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);
  //Ultra_CalculateObjectRange(117);
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);
  //Ultra_CalculateObjectRange(17142);
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);
  //Ultra_CalculateObjectRange(18600);
  //Ultra_DisplayObjectRange();
  //_delay_ms(2500);



void	Test_Ultra_Init(void)
{
	Ultra_Init(mcuTriggerPin,mcuEchoPin);
}
void	Test_Ultra_SendPulse(void)
{
	Ultra_SendPulse();
}
/* Display related Function */
void	Test_Ultra_DisplayObjectRange(void)
{
	Ultra_DisplayObjectRange();
}
void	Test_Ultra_DisplayMaxRange(void)
{
	Ultra_DisplayMaxRange();
}
void	Test_Ultra_DisplayMinRange(void)
{
	Ultra_DisplayMinRange();
}
/* Range related Functions */
void	Test_Ultra_SetMaxRange(void)
{
	Ultra_SetMaxRange(Range);
}
void	Test_Ultra_SetMinRange(void)
{
	Ultra_SetMinRange(Range);
}
uint16_t	Test_Ultra_GetObjectRange(void)
{
	Ultra_GetObjectRange();
}
uint16_t	Test_Ultra_GetMaxDetectionRange(void)
{
	Ultra_GetMaxDetectionRange();
}
uint16_t	Test_Ultra_GetMinDetectionRange(void)
{
	Ultra_GetMinDetectionRange();	
}
/* Object status related Function */
uint8_t	Test_Ultra_IsObjectInRange(void)
{
	Ultra_IsObjectInRange();
}
uint8_t	Test_Ultra_IsCollision(void)
{
	Ultra_IsCollision();	
}
uint8_t	Test_Ultra_IsObjectAboveRange(void)
{
	Ultra_IsObjectAboveRange();
}

void	Test_Ultra_ConvertDistanceToAscii(void)
{
	Ultra_ConvertDistanceToAscii(uint16_t  Distance, char Array[]);
	
}


/**
  * @}
 */
