/**
  ******************************************************************************
  * @file    PulseOutTest.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    11-July-2020
  * @brief   Test file for Pulse Module.
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
  *******************************************************************************/
  
#include "PulseOut.h"

/******************************************************************
	   PulseOut Module functions Test  
******************************************************************/
//Test_PO_InitStructure();					/*p*/
//Test_PO_SetMcuPin();						/*p*/
//Test_PO_SetPulseParameter();				/*p*/
//Test_PO_SetRepeatPulseParameter();		/*p*/
//Test_PO_InitPulse();						/*p*/
//Test_PO_GeneratePulse();					/*p*/
//Test_PO_RepeatPulse();

void Test_PO_GenertePulse(uint8_t mcupin,uint16_t duration,uint8_t unit,ePinDir_t pinvalue)
{  /*  Duration		Type				Result  
	    0-31 		usec				pass
		32-255		usec				pass
		256-2000	usec				pass
		1-2			msec				pass
		3-8			msec				pass
		9-32		msec				pass
	*/	
	//PO_GenertePulse(mcupin,duration,unit,pinvalue);
}

void Test_PO_InitStructure(void)
{
	PO_InitStructure();				/*p*/
}

void Test_PO_SetMcuPin(void)
{
	PO_SetMcuPin(PORTB_PB0);		/*p*/
	PO_SetMcuPin(PORTB_PB3);		/*p*/
	PO_SetMcuPin(PORTB_PB5);		/*p*/
	
	PO_SetMcuPin(PORTA_PA1);		/*p*/
	PO_SetMcuPin(PORTA_PA2);		/*p*/
	PO_SetMcuPin(PORTA_PA7);		/*p*/
	
	PO_SetMcuPin(PORTD_PD4);		/*p*/
	PO_SetMcuPin(PORTD_PD6);		/*p*/
	PO_SetMcuPin(PORTD_PD2);		/*p*/
}

void Test_PO_SetPulseParameter(void)
{
	PO_SetPulseParameter(1268,U,RISING_EDGE);			/*p*/
	PO_SetPulseParameter(668,M,FALLING_EDGE);			/*p*/
	PO_SetPulseParameter(6268,S,RISING_EDGE);			/*p*/
		
}

void Test_PO_SetRepeatPulseParameter(void)
{
	PO_SetRepeatPulseParameter(10,29);			/*p*/
	PO_SetRepeatPulseParameter(1294,1369);		/*p*/
}

void Test_PO_Init(void)
{
	PO_SetMcuPin(PORTB_PB0);			
	PO_Init();								/*p*/
	PO_SetMcuPin(PORTD_PD6);	
	PO_Init();								/*p*/
	PO_SetMcuPin(PORTA_PA7);
	PO_Init();								/*p*/
}

void Test_PO_GeneratePulse(void)
{
	/*  Duration	Type    			Result  
	    0-31 		usec				pass
		32-255		usec				pass
		256-2000	usec				pass
		1-2			msec				pass
		3-8			msec				pass
		9-32		msec				pass
	*/	
	PO_GeneratePulseInt();				/*p*/
}

void Test_PO_RepeatPulse(void)
{
		PO_RepeatPulse();	
}

void Test_PO_RegisterTimerOverflowIntService(void)
{   /* This function is not tested by calling in main but
	   by calling in function PO_Init(void)
	   {
	    PO_RegisterTimerOverflowIntService(&PO_PulseInterruptService,0);
	   }
	   and observing whether interrupt jumps to PO_PulseInterruptService
	   function
	*/
}


void Test_PO_RepeatPulseInterruptService(void)
{/* This function is not tested by calling in main but
	   by calling in function PO_Init(void)
	   {
	    PO_RegisterTimerOverflowIntService(&PO_RepeatPulseInterruptService,0);
	   }
	   and observing whether interrupt jumps to PO_RepeatPulseInterruptService 
	   function
	*/
}




