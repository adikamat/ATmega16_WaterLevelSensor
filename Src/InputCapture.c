/**
  ******************************************************************************
  * @file    InputCapture.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    13-Dec-2020
  * @brief   All Input Capture functions are defined here.
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
//#include "System.h"

/** 
  * @brief  Application specific header  
  */
#include "InputCapture.h"
#include "ATmega16_TC1.h"
#include "Ultrasonic.h"

/**
  * @}
  */
 
/** @addtogroup Struct/Union definition and Short Name
  * @{
  */ 
  
 sInputCapture_t	sInputCapture;
 extern char		ObjectRangeAscii[7];
 
/**
  * @}
  */   
  
  
/** @addtogroup static variable 
  * @{
  */ 
  
/**
  * @}
  */   
/** @addtogroup static function 
  * @{
  */ 
  
/**
  * @}
  */   
  
/** @addtogroup variable declaration 
  * @{
  */ 
uint8_t	u8TimerResolution  =  IC_TIMER_RESOLUTION;

/**
  * @}
  */      
/** @addtogroup  Static Function Definition 
  * @{
  */ 
  
  /**
  * @}
  */     
  
/** @addtogroup  Module Interface Function Definition 
  * @{
  */

/** @brief				Initialize Input Capture Structure.
  * 
  * @details			 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None 
  * @test	Tested OK.
  */
 void IC_InitStructure(void)
 {	 /* Clear all Structure */
	 sInputCapture.u8InputCaptureChannelPin = MCU_ULTRASONIC_ECHO_PIN;
	 sInputCapture.u16FirstTimeSample = 0x0000;
	 sInputCapture.u16SecondTimeSample = 0x0000;
	 sInputCapture.u16ThirdTimeSample = 0x0000;
	 sInputCapture.u8NoOfTimerOverFlow = 0x00;
	 sInputCapture.u8DataStatus= IC_DATA_NOT_CAPTURED;
	 sInputCapture.u8CaptureEdge = IC_RISING_EDGE;
	 sInputCapture.u8EdgeMode = IC_PULSE_MODE;
	 sInputCapture.u8EdgeCounter = 1;
	 sInputCapture.u16HighTimeCount = 0x0000;
	 sInputCapture.u16LowTimeCount = 0x0000;
	 sInputCapture.u16PeriodCount= 0x0000;
}

/** @brief			Initialize Module data structure. 		
  * 
  * @details			 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None 
  * @test	Tested OK.
  */
void IC_Init(void)
{ /* Initialize  Input Capture Module*/
		/*!< Initialize Module Data Structure */
		IC_InitStructure();	
	    /* Set the SRF setting according to Init Structure */	
		IC_AttachPinToCaptureChannel(MCU_ULTRASONIC_ECHO_PIN);
		IC_SetCaptureEdge(sInputCapture.u8CaptureEdge);
		IC_SetEdgeMode(sInputCapture.u8EdgeMode);
		/* Register Capture Interrupt Service */
		IC_RegisterInputCaptureIntService(&IC_CaptureInterruptService ,0);
		IC_RegisterTimerOverflowIntService(&IC_TimerInterruptService,0);
	   /* Enable Input Capture Interrupt */
	   	TC1_EnableInputCaptureInterrupt();
	   /* Enable Timer Interrupt */ 
	   /*TC1_EnableTimerInterrupt();*/
	   TC1_EnableTimerInterrupt();
	   /* Start Timer */
	  // IC_SetTimerResolution(IC_TIMER_RES_1USEC);
} 


/** @brief			Attach one of the MCU InputCapture Pin to Channel .
  *			
  * @details		 
  * @PreCondition	None
  * @PostCondition  None 
  * @param			InputChannelPin
  * @description	PORTx_Pxy  where x is A/B/C/D and y is 0 to 7
  * @retval			None 
  * @test	Tested OK.
  */ 
void IC_AttachPinToCaptureChannel(uint8_t InputChannelPin)
{  
	sInputCapture.u8InputCaptureChannelPin = InputChannelPin;
	TC1_SetInputCapturePin(sInputCapture.u8InputCaptureChannelPin);	
} 
/** @brief					
  * 
  * @details		DetachPinFromCaptureChannel. 
  * @PreCondition	Pin should be attached.
  * @PostCondition  None 
  * @param			Channel
  * @description	Channel No
  * @retval			None 
  * @test	Tested OK.
  */ 
void IC_DetachPinFromCaptureChannel(void)
{	 	
	sInputCapture.u8InputCaptureChannelPin = DUMMY_MCU_PIN;
}


/** @brief			 				
  * 
  * @details		Set DataStatus. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	has Value IC_DATA_NOT_CAPTURED or IC_DATA_CAPTURED or
  *					IC_DATA_CAPTURING
  * @retval			None 
  * @test	Tested OK.
  */ 

void IC_SetDataStatus(uint8_t datastatus)
{
	sInputCapture.u8DataStatus = datastatus ;
}

/** @brief			IC_SetCaptureMode 				
  * 
  * @details			Set Capture Mode. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8CaptureEdge
  * @description	has Value IC_RISING_EDGE or IC_FALLING_EDGE
  * @retval			None 
  * @test	Tested OK.
  */ 
void IC_SetCaptureEdge(uint8_t u8CaptureEdge)
{   /* Set Capture Edge */
	sInputCapture.u8CaptureEdge = u8CaptureEdge;
	/* Call Driver Function*/
	if(u8CaptureEdge == IC_RISING_EDGE)
	 {		
		TC1_SetInputCaptureEdge(TC1_INPUT_CAPTURE_RISING_EDGE);
	 }
	else if(u8CaptureEdge == IC_FALLING_EDGE) 	 
	 {
		TC1_SetInputCaptureEdge(TC1_INPUT_CAPTURE_FALLING_EDGE);
	 }
 } 
  
/** @brief				IC_SetEdgeMode 				
  * 
  * @details			Set Edge Mode. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			Edge
  * @description	has Value IC_PULSE_MODE / IC_PEROD_MODE /IC_MULTIEDGE_MODE.
  *					In IC_PULSE_MODE two edges are capture, they are either 
  *					rising - falling and falling - rising.In IC_PEROD_MODE 
  *					three edges are captured, they are rising- falling - rising 
  *					or falling-rising-falling. In IC_MULTIEDGE_MODE either 
  *					rising edge or falling	edges are captured
  * @retval			None 
  * @test	Tested OK.
  */ 
void  IC_SetEdgeMode( uint8_t Edge)
{      /* Set Edge Mode */
	   sInputCapture.u8EdgeMode = Edge;
} 
/** @brief				Count how many edges either rising or falling 				
  * 
  * @details			Get EdgeCounter value. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None.
  * @retval			u8EdgeCounter;
  * @test	Tested OK.
  */ 
uint8_t IC_GetEdgeCount(void)
{
	return(sInputCapture.u8EdgeCounter);
}
/** @brief				IC_GetDataStatus 				
  * 
  * @details			Get Data Status. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None.
  * @description	None
  * @retval			uint8_t: IC_DATA_CAPTURED or IC_DATA_NOT_CAPTURED or
  *					IC_DATA_CAPTURING
  * @test	Tested OK.
  */ 
uint8_t IC_GetDataStatus(void)
{
	return(sInputCapture.u8DataStatus);
}
/** @brief				IC_GetCaptureMode				
  * 
  * @details			Get Capture Mode. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None.
  * @retval			uint8_t: IC_RISING_EDGE or IC_FALLING_EDGE
  * @test	Tested OK.
  */ 
uint8_t IC_GetCaptureEdge(void)
{
	return(sInputCapture.u8CaptureEdge);
}

/** @brief				IC_TimerResolution 				
  * 
  * @details			Set Timer resolution of Input capture module.
  * @PreCondition	None
  * @PostCondition  None
  * @param			TimerResolution
  * @description	It has following values.
  *					IC_
  *					IC_TIMER_RES_1USEC
  *					IC_TIMER_RES_8USEC
  *					IC_TIMER_RES_32USEC
  *					IC_TIMER_RES_128USEC
  * @retval			None
  * @test	Tested OK.
  */
 void  IC_SetTimerResolution(uint8_t u8Resolution)
 { /* Check Parameter*/
	 if(u8Resolution == IC_TIMER_RES_P125USEC)
	 { 
		 TC1_SetClockPrescalar(TC1_CLK_DIRECT_NO_PRESCALAR);
		 u8TimerResolution = IC_TIMER_RES_P125USEC;
	 }
	else if(u8Resolution == IC_TIMER_RES_1USEC)
	 { /* Call Timer1 Driver*/
		 TC1_SetClockPrescalar(TC1_CLK_IO_BY_8);
		 u8TimerResolution = IC_TIMER_RES_1USEC;
	 }
	 else if(u8Resolution == IC_TIMER_RES_8USEC)
	 {/* Call Timer1 Driver*/
		 TC1_SetClockPrescalar(TC1_CLK_IO_BY_64);
		 u8TimerResolution = IC_TIMER_RES_8USEC;
	 }
	 else if(u8Resolution == IC_TIMER_RES_32USEC)
	 {/* Call Timer1 Driver*/
		 TC1_SetClockPrescalar(TC1_CLK_IO_BY_256);
		 u8TimerResolution = IC_TIMER_RES_32USEC;
	 }
	 else if(u8Resolution == IC_TIMER_RES_128USEC)
	 {/* Call Timer1 Driver*/
		 TC1_SetClockPrescalar(TC1_CLK_IO_BY_1024);
		 u8TimerResolution = IC_TIMER_RES_128USEC;
	 }
	 else
	 { /* If here means Wrong parameter */
	 }
 }

/** @brief				IC_StartInputCapture				
  * 
  * @details			Start InputCapture Timer
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None.
  * @retval			None
  * @test	Tested OK.
  */
 void  IC_StartInputCapture(void)
 {  /* Start Input capture when Data Status is IC_DATA_CAPTURED */
	 if(sInputCapture.u8DataStatus == IC_DATA_CAPTURED)
	 {	 /* Clear time stamp  field as new Capture begins */
		 sInputCapture.u16FirstTimeSample = 0 ;
		 sInputCapture.u16SecondTimeSample = 0 ; 
		 sInputCapture.u16ThirdTimeSample = 0 ;
		 /*Clear all Time count fields */
		  sInputCapture.u16HighTimeCount = 0 ;
		  sInputCapture.u16PeriodCount = 0 ;
		  sInputCapture.u16LowTimeCount = 0 ;
	 }
 }
 
 /** 
  * @brief			IC_StopInputCapture			
  * 
  * @details		Stop InputCapture Timer
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None.
  * @retval			None
  * @test	Tested OK.
  */
 void  IC_StopInputCaptureTimer(void)
 {	 /*  We Stop TC1 Timer*/
	 TC1_StopClock();
 }
  
/** 
  * @brief			IC_GetPeriod 				
  * 
  * @details		Get the Period of the signal.That is time stamp between     
  *					two Consecutive rising edge or falling edge i.e first 
  *					and third.Maximum and Minimum frequency detection depends
  *					upon timer resolution.
  *					Timer Resolution  MaxCount  MaxPeriod   MinCount MinPeriod
  *					                            MSEC				USEC
  *					1 USEC			  65536     65.536        2      2
  *					8 USEC            65536     524.288       2      16
  *					                            SEC					 USEC
  *					32 USEC			  65536		2.097152      2      64
  *					128 USEC          65536     8.388608	  2      256
  *					sample. 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None
  * @retval			uint16_t Period of Signal usec  
  * @test	Tested OK.
  */
uint16_t IC_GetPeriodCount(void)
{
/* If Data  is Acquired then only we need to return Period */
if((sInputCapture.u8DataStatus == IC_DATA_CAPTURED) &&
    (sInputCapture.u8EdgeMode == IC_PERIOD_MODE)) 
{	
	/* Case 1  : All three edges are within Timer overflow. 3rd > 2nd > 1st
					 No Of Timer overflow = 0	*/
	if(sInputCapture.u8EdgesBeforeTimerOverFlow == 3 &&
	    sInputCapture.u8NoOfTimerOverFlow == 0)
	{
	 sInputCapture.u16HighTimeCount = (sInputCapture.u16SecondTimeSample -
	                                   sInputCapture.u16FirstTimeSample);
									   
	 sInputCapture.u16LowTimeCount	= (sInputCapture.u16ThirdTimeSample -
									   sInputCapture.u16SecondTimeSample);	
	}
	/* Case 2  : First and second edge are within Timer overflow but third
						 edge occurs after timer overflow. 3rd > 2nd 
						  No Of Timer overflow =  1*/
	if(sInputCapture.u8EdgesBeforeTimerOverFlow == 2 &&
		sInputCapture.u8NoOfTimerOverFlow == 1)
	{
	 sInputCapture.u16HighTimeCount = (sInputCapture.u16SecondTimeSample -
										sInputCapture.u16FirstTimeSample);
										
	 sInputCapture.u16LowTimeCount	= ((sInputCapture.u8NoOfTimerOverFlow *
									   65535 - sInputCapture.u16SecondTimeSample)
									   + sInputCapture.u16SecondTimeSample);
	 
	}
	/* Case 3  : First edge is within Timer overflow while second and third
						 edge occurs after timer overflow .
						  No Of Timer overflow =  1*/
	if(sInputCapture.u8EdgesBeforeTimerOverFlow == 1 &&
		sInputCapture.u8NoOfTimerOverFlow == 1)
	{
	 sInputCapture.u16HighTimeCount	= ((sInputCapture.u8NoOfTimerOverFlow *
	 65535 - sInputCapture.u16FirstTimeSample) + sInputCapture.u16SecondTimeSample);	
		
	 sInputCapture.u16LowTimeCount = (sInputCapture.u16ThirdTimeSample -
	 sInputCapture.u16SecondTimeSample);

	}
	/* Case 4  :  First edge occurs within first timer overflow. Second
				  edge occurs between first timer overflow and second timer
				  overflow while third edge occurs between second and third
				  timer overflow   No Of Timer overflow =  2*/ 	
	if(sInputCapture.u8EdgesBeforeTimerOverFlow == 3 &&
		sInputCapture.u8NoOfTimerOverFlow == 2 )
	{
		
	}
		
 }
   /* Update Total Period Count */
		sInputCapture.u16PeriodCount =	(sInputCapture.u16HighTimeCount +
		sInputCapture.u16LowTimeCount) ;
   /* Reset sInputCapture.u8EdgesBeforeTimerOverFlow and
	  u8NoOfTimerOverFlow */
		sInputCapture.u8EdgesBeforeTimerOverFlow = 0;
		sInputCapture.u8NoOfTimerOverFlow = 0;
		return(sInputCapture.u16PeriodCount);
} 

/** 
  * @brief				IC_GetPulseCount				
  * 
  * @details		Get the High Period of the signal.This depends upon whether
  *					Edge mode is Pulse mode or Period Mode. If Pulse mode and
  *					capture edge is	rising edge then count is difference between
  *					SecondTimeSample and first.In pulse mode falling edge is
  *					not valid.If Edge mode is period then we have two cases
  *					A)Capture Edge is rising: In this case count is between
  *					SecondTimeSample and first
  *					B)Capture Edge is falling :In this case count is between
  *					ThirdTimeSample and Second
  *					  
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None
  * @retval			uint16_t  High time in msec or usec ?
  * @test	Tested OK.
  */
uint16_t IC_GetPulseCount(void)
{	
	/* If Data  is Acquired then only we need to return Period */
	if((sInputCapture.u8DataStatus = IC_DATA_CAPTURED))
	{	if(sInputCapture.u8EdgeMode == IC_PULSE_MODE)
		{	  /* We don't check Rising pulse or falling pulse because
				in both cases we need to take difference */
			if(sInputCapture.u16SecondTimeSample > sInputCapture.u16FirstTimeSample)
			{  /* No Timer over flow occurs both the edge 1st and 2nd are within 
				  Timer Overflow */
				sInputCapture.u16HighTimeCount =
				sInputCapture.u16SecondTimeSample - sInputCapture.u16FirstTimeSample ;
			}  
			else if(sInputCapture.u16FirstTimeSample > sInputCapture.u16SecondTimeSample )
			{  /* In this case timer overflow occurs. First edge is within timer
				  over flow while second edge is after timer overflow*/
				sInputCapture.u16HighTimeCount =
				((65535) - sInputCapture.u16FirstTimeSample) + 
				 sInputCapture.u16SecondTimeSample ;
				
			}
			 else{}
		 }
	   } /* End of Pulse Mode */
	return(sInputCapture.u16HighTimeCount);
} 

/** 
  * @brief			IC_GetLowTimeCount 				
  * 
  * @details		Get the Low Period of the signal.This depends upon whether
  *					Edge mode is Pulse mode or Period Mode. If Pulse mode and
  *					capture edge is	falling edge then count is difference between
  *					SecondTimeSample and first.In pulse mode rising edge is
  *					not valid.If Edge mode is period then we have two cases
  *					A)Capture Edge is rising: In this case count is between
  *					ThirdTimeSample and second
  *					B)Capture Edge is falling :In this case count is between
  *					SecondTimeSample and first.
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None
  * @retval			uint16_t  Low time in msec or usec ?
  * @test	Tested OK.
  */
uint16_t IC_GetLowTimeCount(void)
{
	/* If Data  is Acquired then only we need to return Period */
	if((sInputCapture.u8DataStatus = IC_DATA_CAPTURED) &&
	   (sInputCapture.u8NoOfTimerOverFlow == 0))
	{	
		if(sInputCapture.u8EdgeMode == IC_PULSE_MODE)
		{
	    sInputCapture.u16LowTimeCount = 
		sInputCapture.u16SecondTimeSample - sInputCapture.u16FirstTimeSample ;
		}
		if(sInputCapture.u8EdgeMode == IC_PERIOD_MODE)
		{
			if(sInputCapture.u8CaptureEdge == IC_RISING_EDGE )
			{
			sInputCapture.u16LowTimeCount =
			sInputCapture.u16ThirdTimeSample - sInputCapture.u16SecondTimeSample;
			}
			if(sInputCapture.u8CaptureEdge == IC_FALLING_EDGE)
			{
			sInputCapture.u16LowTimeCount =
			sInputCapture.u16SecondTimeSample - sInputCapture.u16FirstTimeSample ;
			}
		}
	}
	else
	{
	}
	return(sInputCapture.u16LowTimeCount);
} 

/** 
  * @brief			Interrupt Service Routine for IC module.			
  * 
  * @details		For every rising and falling interrupt this service routine
  *					is called.For Pulse mode we look for two edges and for
  *					period mode we look for three edges.When required timestamp
  *					two for pulse and three for period is acquired, we set
  *					u8DataStatus = IC_DATA_CAPTURED.
  *					u8EdgeCounter is set to 1 in initialization.This
  *					counter keeps the track of how many edges has occured.When
  *					first edge occurs we call StartInputCapture() which inturn
  *					start timer. Following cases are captured in this service
  *					routine
  *					EDGE MODE    CAPTURE EDGE  DESCRIPTION
  *					PULSE        RISING EDGE    What we are detecting is Rising
  *											   Pulse.LOWTOHIGH-DELAY-HIGHTOLOW
  *											   LOWTOHIGH is rising Edge
  *				    PULSE        FALLING EDGE  What we are detecting is Falling
  *											   pulse HIGHTOLOW-DELAY-LOWTOHIGH
  *											   HIGHTOLOW is falling edge.
  *					PERIOD       RISING EDGE   What we are detecting is
  *											   LOWTOHIGH-DELAY-HIGHTOLOW-DELAY-
  *											   LOWTOHIGH
  *					PERIOD      FALLING EDGE   What we are detecting is
  *											   HIGHTOLOW-DELAY-LOWTOHIGH-DELAY-
  *											   HIGHTOLOW						   
  *					FIRST TIME STAMP:						   
  *					Whether it is rising or falling we need to capture first 
  *					time stamp and reverse edge for next detection.This is done
  *					in if(sInputCapture.u8EdgeCounter == 1){} block , we also
  *					set u8EdgeCounter =2 for next detection of edge.
  *					SECOND TIME STAMP:
  *					For 2nd edge there are two cases 
  *					CASE1 Pulse mode:	We capture 2nd time stamp. 
  *										reset u8EdgeCounter= 1. 
  *										stop timer and reset it's value to 0.
  *										set u8DataStatus = IC_DATA_CAPTURED.
  *					CASE1 Period mode:  We capture 2nd time stamp.
  *									    We reverse the edge for third edge
  *									    detection.
  *									    set u8EdgeCounter = 3
  *					THIRD TIME STAMP:   
  *										We capture 3nd time stamp.
  *										reset u8EdgeCounter= 1.
  *										stop timer and reset it's value to 0.
  *										set u8DataStatus = IC_DATA_CAPTURED
  *					                
  * @PreCondition	None
  * @PostCondition  None
  * @param			param
  * @description	 
  * @retval			None  
  * @test	Tested OK.
  */
void IC_CaptureInterruptService(uint8_t param)
{	 
  if(sInputCapture.u8DataStatus == IC_DATA_NOT_CAPTURED)	
  {    /* Increment if Timer Overflow has not occurred */
		   if(sInputCapture.u8EdgeMode == IC_PERIOD_MODE && 
			  sInputCapture.u8NoOfTimerOverFlow == 0) 
		   {    
				sInputCapture.u8EdgesBeforeTimerOverFlow ++;
		   }
   
	   if(sInputCapture.u8EdgeCounter == 1)
	   {     /* Store Time Stamp into First timeSample. We need not check EdgeMode
			 to be pulse mode or Period mode because for each mode we need to 
			 capture first edge */
	          /* Start Timer */
	          IC_SetTimerResolution(IC_TIMER_RES_1USEC);
	   		  sInputCapture.u16FirstTimeSample =  TC1_GetCaptureReg();
   		  /* Reverse the Edge */
		   if(sInputCapture.u8CaptureEdge == IC_RISING_EDGE)
				IC_SetCaptureEdge(IC_FALLING_EDGE);
		   else if	(sInputCapture.u8CaptureEdge == IC_FALLING_EDGE)	
				IC_SetCaptureEdge(IC_RISING_EDGE);
		   else {}		
		  /*Increment Edge Counter So that we can capture Second Edge */ 
		  sInputCapture.u8EdgeCounter = 2;
	   }
	   else if(sInputCapture.u8EdgeCounter == 2)
	   {/* Store Time Stamp into SecondTimeSample */
		   sInputCapture.u16SecondTimeSample = TC1_GetCaptureReg();
		   /* We need to check for Period mode and need to reverse the edge */
		   if(sInputCapture.u8EdgeMode == IC_PERIOD_MODE) 
			{  	/* Reverse the Edge */
				   if(sInputCapture.u8CaptureEdge == IC_RISING_EDGE)
						IC_SetCaptureEdge(IC_FALLING_EDGE);
				   else if	(sInputCapture.u8CaptureEdge == IC_FALLING_EDGE)
						IC_SetCaptureEdge(IC_RISING_EDGE);
				   else 
					{
					}
					sInputCapture.u8EdgeCounter = 3;
			}
			else if(sInputCapture.u8EdgeMode == IC_PULSE_MODE)
			{	/* We are in PULSE_MODE and we have captured two edges reset edge
				  Counter, Change Edge Mode, Stop timer and Clear timer count*/
			     /* We have to set Edge to initial Condition */
				   if(sInputCapture.u8CaptureEdge == IC_RISING_EDGE)
						IC_SetCaptureEdge(IC_FALLING_EDGE);
				   else if	(sInputCapture.u8CaptureEdge == IC_FALLING_EDGE)	
						IC_SetCaptureEdge(IC_RISING_EDGE);
				   else {}		
 					sInputCapture.u8EdgeCounter = 1;
				/*Set Data Status to IC_DATA_CAPTURED */
					sInputCapture.u8DataStatus = IC_DATA_CAPTURED ;
					/* Stop Capture */
					  IC_StopInputCaptureTimer();  
					 /* Clear Timer Count */
					 TC1_SetTimerReg(0x0000) ;
			}
			else
			{
				/* if we come here means error */
			}
	    } /* We are in PERIOD_MODE , need to capture third edge */
	   else if(sInputCapture.u8EdgeCounter == 3 &&
			   sInputCapture.u8EdgeMode == IC_PERIOD_MODE)
	   {   /* Store Time Stamp into ThirdTimeSample */
		   sInputCapture.u16ThirdTimeSample = TC1_GetCaptureReg();
		   /* Set EdgeMode to Initial Condition */
		   if(sInputCapture.u8CaptureEdge == IC_RISING_EDGE)
				IC_SetCaptureEdge(IC_FALLING_EDGE);
		   else if	(sInputCapture.u8CaptureEdge == IC_FALLING_EDGE)
				IC_SetCaptureEdge(IC_RISING_EDGE);
		   else {}
		   /*  Reset the Edge Counter */
		   sInputCapture.u8EdgeCounter = 1;
		   /*Set Data Status to IC_CAPTURED */
		   sInputCapture.u8DataStatus = IC_DATA_CAPTURED ;
		   /* Stop Input Capture timer as we have captured all data*/
		      IC_StopInputCaptureTimer();  
			  /* Clear Timer Count */
			 TC1_SetTimerReg(0x0000) ;
	   }
	   else
	   { /* if control Comes here means Error*/
	   }
  }/* End of DATA_NOT_CAPTURE*/
}

/** 
  * @brief			IC_TimerInterruptService			
  * 
  * @details		Timer Interrupt routine is entered in following two cases.
  *					PULSE MODE:
  *					TARGET PRESENT:
  *					If time count exceed 65535 then timer overflow.
  *					This case arises when falling edge or rising edge does not
  *					fall within	this count.However this  will not arise 
  *					for ultrasonic sensor,this is because for maximum range
  *					400cm  and 1 usec resolution and velocity of sound velocity
  *					0.033cm/usec, to travel 400cm it will take 400cm/0.033
  *					= 1212.21 usec. With 1 usec resolution timer count will be 
  *					1212 well within 65535.So timer will never overflow.As we 
  *					are clearing timer count after capturing second edge.
  *					TARGET BEYOND 400cm:
  *					If target is beyond 400cm sensor echo pin will not go down
  *					i.e we will not get falling edge and in this case we will
  *					get timer overflow. We do following
  *					1 Stop timer and clear reg
  *					2 Set u8DataStatus = IC_DATA_NOT_CAPTURED
  *					3 Clear all time stamp and count
  *					PERIOD MODE:
  *					In period mode, if third edge does not fall within 65535
  *					count then we get timer overflow.Following table 
  *					shows what is maximum period we with respect to timer
  *					resolution.
  *					Timer Resolution  MaxCount  MaxPeriod   MinCount MinPeriod
  *					                            MSEC				USEC
  *					1 USEC			  65536     65.536        2      2
  *					8 USEC            65536     524.288       2      16
  *					                            SEC					 USEC
  *					32 USEC			  65536		2.097152      2      64
  *					128 USEC          65536     8.388608	  2      256
  *					If signal period is more than above listed period then
  *					timer overflow occurs.
  *					   
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	None
  * @retval			None 
  * @test	Not Tested.  
  */
void IC_TimerInterruptService(uint8_t param)
{	/* Check Mode */
	if((sInputCapture.u8EdgeMode == IC_PULSE_MODE ||
	    sInputCapture.u8EdgeMode == IC_PERIOD_MODE) &&
	   (sInputCapture.u8DataStatus == IC_DATA_NOT_CAPTURED))
	{  
		/*Timer Overflow occurs  increment counter */
		 sInputCapture.u8NoOfTimerOverFlow ++;
	}
}


/** 
  * @brief				IC_RegisterInputCaptureIntService				
  * 
  * @details			This function register capture interrupt service 
  *						routine to TC1 module.    
  * @PreCondition	None
  * @PostCondition  None
  * @param			fun
  * @description	This is function pointer to InputCaptureInterrupt Service
  * @param			param
  * @description	This is uint8_t additional parameter user can use.
  * @retval			None  
  * @test	Tested OK. Tested via  IC_init() fucntion. 
  */

void IC_RegisterInputCaptureIntService(fpointerv_t  fun , uint8_t param)	
{
	TC1_RegisterInputCaptureInterruptService(fun, param);
}

/** 
  * @brief			IC_RegisterInputCaptureTimerService				
  * 
  * @details		This function register capture interrupt service
  *					routine to TC1 module.    
  * @PreCondition	None
  * @PostCondition  None
  * @param			fun
  * @description	This is function pointer to Timer Interrupt Service
  * @param			param
  * @description	This is uint8_t additional parameter user can use.
  * @retval			None 
  * @test	 Not Tested via  IC_init() fucntion.
  */

void IC_RegisterTimerOverflowIntService(fpointerv_t  fun , uint8_t param)	
{
	TC1_RegisterTimerInterruptService(fun,param);
}

/**
  * @}
 */
