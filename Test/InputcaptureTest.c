/**
  ******************************************************************************
  * @file    Test File Input Capture.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    11-July-2020
  * @brief   Test File
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
 #include "InputcaptureTest.h"
 
/**
  * @}
  */
 
/** @addtogroup Struct/Union  variable definition and Short Name
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
  
/** @addtogroup  Module Interface Function Definition 
  * @{
  */
  
  	/*****************************************************/
  	/*		Input capture Module functions Test          */
  	/****************************************************/
  	// Test_IC_Init();							/*p*/
  	// Test_IC_AttachPinToCaptureChannel();		/*p*/
  	// Test_IC_DetachPinFromCaptureChannel();	/*p*/
  	// Test_IC_SetCaptureEdge();				/*p*/
  	// Test_IC_GetCaptureEdge();				/*p*/
  	// Test_IC_SetEdgeMode();					/*p*/
  	// Test_IC_GetEdgeCount();					/*p*/
  	// Test_IC_GetDataStatus();					/*p*/
  	// Test_IC_SetTimerResolution();			/*p*/
  	// Test_IC_StartInputCapture();				/*p*/
  	// Test_IC_StopInputCapture();				/*p*/
  	// Test_IC_GetPeriodCount();				/*p*/
  	// Test_IC_GetHighTimeCount();				/*p*/
  	// Test_IC_GetLowTimeCount();				/*p*/
  
  
  
void Test_IC_Init(void)
{
	IC_Init();											/*Pass*/
	
}

/* Prototype for Populating(Set Method) Input Capture structure */
void Test_IC_AttachPinToCaptureChannel(void)
{
	IC_AttachPinToCaptureChannel(IC_PIN_ICP1);			/*Pass*/
}

void Test_IC_DetachPinFromCaptureChannel(void)
{
	IC_DetachPinFromCaptureChannel();					/*Pass*/
}

void Test_IC_SetCaptureEdge(void)
{
	IC_SetCaptureEdge(IC_RISING_EDGE);					/*Pass*/
	IC_SetCaptureEdge(IC_FALLING_EDGE);					/*Pass*/
}

void Test_IC_SetEdgeMode(void)
{
	IC_SetEdgeMode(IC_PULSE_MODE);						/*Pass*/
	IC_SetEdgeMode(IC_PERIOD_MODE);						/*Pass*/
	
}

uint8_t  Test_IC_GetCaptureEdge(void)
{uint8_t u8Edge;
	
	extern  sInputCapture_t sInputCapture ;
	sInputCapture.u8CaptureEdge = IC_FALLING_EDGE;		/* Set Edge type */
	u8Edge = IC_GetCaptureEdge();						/*Pass for both edges*/
	return(u8Edge);
	
}

/* Prototype for Getting(Get Method) Input Capture structure */
uint8_t Test_IC_GetEdgeCount(void)
{uint8_t u8count;
	
	extern  sInputCapture_t sInputCapture ; 
	sInputCapture.u8EdgeCounter = 6 ;					/*Set Edge count */
	u8count = IC_GetEdgeCount();						/*pass */
	return(u8count);
}

uint8_t Test_IC_GetDataStatus(void)
{uint8_t u8count;
	extern  sInputCapture_t sInputCapture ; 
	sInputCapture.u8DataStatus = IC_DATA_NOT_CAPTURED ;	/*Set Data Status */
	u8count = IC_GetDataStatus();						/*pass for both status*/
	return(u8count);
}

/* Prototype for Starting / Stopping Input Capture timer  */
void  Test_IC_SetTimerResolution(void)
{
	IC_SetTimerResolution(IC_TIMER_RES_1USEC);			/*pass*/
	IC_SetTimerResolution(IC_TIMER_RES_8USEC);			/*pass*/
	IC_SetTimerResolution(IC_TIMER_RES_32USEC);			/*pass*/
	IC_SetTimerResolution(IC_TIMER_RES_128USEC);		/*pass*/
	
}

void  Test_IC_StartInputCapture(void)
{
	IC_StartInputCapture();								/*pass*/
}

void  Test_IC_StopInputCapture(void)
{
	IC_StopInputCapture();								/*pass*/
}

/* Prototype  User Interface to Module  */
uint16_t Test_IC_GetPeriodCount(void)
{uint16_t u16count =0x0000;
	extern  sInputCapture_t sInputCapture ;
	sInputCapture.u8DataStatus = IC_DATA_CAPTURED ;
	sInputCapture.u16FirstTimeSample =  300;
	sInputCapture.u16ThirdTimeSample = 1800;
	u16count = IC_GetPeriodCount();						/*pass Tested for both data status */ 
	return(u16count);
}

uint16_t Test_IC_GetHighTimeCount(void)
{uint16_t u16count;
	extern  sInputCapture_t sInputCapture ;
	sInputCapture.u8EdgeMode = IC_PERIOD_MODE;
	sInputCapture.u8CaptureEdge = IC_FALLING_EDGE ;
	sInputCapture.u8DataStatus = IC_DATA_CAPTURED;  
	sInputCapture.u16FirstTimeSample =  300;
	sInputCapture.u16SecondTimeSample =  800;
	sInputCapture.u16ThirdTimeSample = 1800;
	
	 u16count = IC_GetHighTimeCount();					/*pass*/
	 return(u16count);
}

uint16_t Test_IC_GetLowTimeCount(void)
{uint16_t u16count;
	extern  sInputCapture_t sInputCapture ;
	sInputCapture.u8EdgeMode = IC_PERIOD_MODE;
	sInputCapture.u8CaptureEdge = IC_RISING_EDGE ;
	sInputCapture.u8DataStatus = IC_DATA_CAPTURED;
	sInputCapture.u16FirstTimeSample =  300;
	sInputCapture.u16SecondTimeSample =  800;
	sInputCapture.u16ThirdTimeSample = 1800;
	u16count = IC_GetLowTimeCount();					/*pass */
	return(u16count);
}

void Test_IC_RegisterInputCaptureIntService(void)     /*pass*/
{   
	/* This function is not tested by calling in main but
	   by calling in function IC_Init(void)
	   {
	    IC_RegisterInputCaptureIntService(&IC_CaptureInterruptService ,0);
	   }
	   and observing whether interrupt jumps to IC_CaptureInterruptService 
	   function
	*/
}

void Test_IC_RegisterTimerOverflowIntService(void)
{
	/* This function is not tested by calling in main but
	   by calling in function IC_Init(void)
	   {
	   IC_RegisterTimerOverflowIntService(&IC_TimerInterruptService,0);
	   }
	   and observing whether interrupt jumps to IC_TimerInterruptService 
	   function
	*/
	
}	



/**
  * @}
 */
