/**
  ******************************************************************************
  * @file    TC0.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    20-NOV-2020
  * @brief   Driver for Timer/Counter0.
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

#include "ATmega16_TC0.h"
#include "ATmega16_Int.h"
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
/** @addtogroup static function 
  * @{
  */ 

  /** 
  *@Var		FunctionNo
  *@brief   Variable hold the no for, which ClockResolution function was called.
  *			No and called function  relation is as follows.
  *			FunctionNo		 Function Called
  *				0			TC0_SetClockResolution_P125USEC_8MHZ()
  *				1			TC0_SetClockResolution_1USEC_8MHZ()
  *				2			TC0_SetClockResolution_8USEC_8MHZ()
  *				3			TC0_SetClockResolution_32USEC_8MHZ()
  *				4			TC0_SetClockResolution_128USEC_8MHZ()
 */
			
 static uint8_t  TC0_FunctionNo = 0 ; /* This is default value*/
/**
  * @}
  */   
  
/** @addtogroup variable declaration 
  * @{
  */ 
  extern uint8_t  u8IntParam [NO_OF_INT_VECT];
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

  /** @fn			TC0_SetClearTimerOnCompareMode		
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[6:3] register WGM00:WGM01
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8CTCTop
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple modes for CTC,it is there for code clarity. 
  *					TC0_TOP_OCR0
  */
 void    TC0_SetClearTimerOnCompareMode(uint8_t u8CTCTop)
 {
	  if(u8CTCTop == TC0_TOP_OCR0)
	  {      /* WGM01 = 1 : WGM00 = 0  */
			  TCCR0 &= ~(TC0_TCCR0_WGM00);
			  TCCR0 |= (TC0_TCCR0_WGM01);
	  }
 }
 
 /** @fn			TC0_SetClearTimerOnComparePinMode	
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[5:4] register COM01:COM00.
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8Pin
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple pins,it is there for code clarity.
  *					TC0_PIN_OC0
  * @param			u8CTCPinMode
  * @description	It has following value
  *					TC0_OC0_PIN_DISCONNECTED	
  *					TC0_OC0_PIN_TOGGLE_ON_MATCH
  *					TC0_OC0_PIN_CLEAR_ON_MATCH	
  *					TC0_OC0_PIN_SET_ON_MATCH				
  */
 void	TC0_SetClearTimerOnComparePinMode(uint8_t u8Pin,uint8_t  u8CTCPinMode)
 {
	      if(u8Pin == TC0_PIN_OC0)
		  {
				if(u8CTCPinMode == TC0_OC0_PIN_DISCONNECTED)
			  {	/* COM01 = 0 : COM00 = 0 */
				  TCCR0 &= ~(TC0_TCCR0_COM00);
				  TCCR0 &= ~(TC0_TCCR0_COM01);
			  }
			  if(u8CTCPinMode == TC0_OC0_PIN_TOGGLE_ON_MATCH)
			  {	/* COM01 = 0 : COM00 = 1 */
				  TCCR0 |= (TC0_TCCR0_COM00);
				  TCCR0 &= ~(TC0_TCCR0_COM01);
			  }
			  if(u8CTCPinMode == TC0_OC0_PIN_CLEAR_ON_MATCH)
			  {	/* COM01 = 1 : COM00 = 0 */
				  TCCR0 &= ~(TC0_TCCR0_COM00);
				  TCCR0 |= (TC0_TCCR0_COM01);
			  }
			  if(u8CTCPinMode == TC0_OC0_PIN_SET_ON_MATCH)
			  {	/* COM01 = 1 : COM00 = 1 */
				  TCCR0 |= (TC0_TCCR0_COM00);
				  TCCR0 |= (TC0_TCCR0_COM01);
			  }
		  }/* If (u8PinMode) */
}

  /** @fn			TC0_SetFastPwmMode	
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[6:3] register WGM00:WGM01
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8FastPwmTop
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple Fast Pwm modes,it is there for code clarity.
  *					TC0_TOP_0XFF	
   */
 void	TC0_SetFastPwmMode(uint8_t u8FastPwmTop)
 {
	 if (u8FastPwmTop == TC0_TOP_0XFF)
	 {    /* WGM01 = 1 : WGM00 = 1  */
			 TCCR0 |= (TC0_TCCR0_WGM00);
			 TCCR0 |= (TC0_TCCR0_WGM01);
	 }
 }
 /** @fn			TC0_SetFastPwmPinMode
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[5:4] register COM01:COM00.
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8Pin
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple pwm pins,it is there for code clarity.
  *					TC0_PIN_OC0	
  * @param			u8FastPwmPinMode
  * @description	It has following value
  *					TC0_OC0_PIN_DISCONNECTED
  *					TC0_OC0_PIN_CLEAR_ON_MATCH_SET_ON_TOP
  *					TC0_OC0_PIN_SET_ON_MATCH_CLEAR_ON_TOP
  */ 
void	TC0_SetFastPwmPinMode(uint8_t u8Pin,uint8_t  u8FastPwmPinMode)
{			 
	  if(u8Pin == TC0_PIN_OC0)
		 {	
				if(u8FastPwmPinMode == TC0_OC0_PIN_DISCONNECTED)
				 {	/* COM01 = 0 : COM00 = 0 */
					 TCCR0 &= ~(TC0_TCCR0_COM00);
					 TCCR0 &= ~(TC0_TCCR0_COM01);
				 }
				 if(u8FastPwmPinMode == TC0_OC0_PIN_CLEAR_ON_MATCH_SET_ON_TOP)
				 {	/* COM01 = 1 : COM00 = 0 */
					 TCCR0 &= ~(TC0_TCCR0_COM00);
					 TCCR0 |= (TC0_TCCR0_COM01);
				 }
				 if(u8FastPwmPinMode == TC0_OC0_PIN_SET_ON_MATCH_CLEAR_ON_TOP)
				 {	/* COM01 = 1 : COM00 = 1 */
					 TCCR0 |= (TC0_TCCR0_COM00);
					 TCCR0 |= (TC0_TCCR0_COM01);
				 }
		 }/* If (u8PinMode) */
 }
 /** @fn			TC0_SetPwmPhaseMode
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[6:3] register WGM00:WGM01
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8PwmPhaseTop
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple Phase Pwm modes,it is there for code clarity.
  *					TC0_TOP_0XFF			
  */
 void	TC0_SetPwmPhaseMode(uint8_t u8PwmPhaseTop) 
 {
	 if (u8PwmPhaseTop == TC0_TOP_0XFF)
		 {   /* WGM01 = 0 : WGM00 = 1  */
			 TCCR0 |= (TC0_TCCR0_WGM00);
			 TCCR0 &= ~(TC0_TCCR0_WGM01);
		 }
 }
 
  /** @fn			TC0_SetPwmPhasePinMode
  * @brief			Set the mod of the Timer/Counter1 Module.
  * @McuReg			TCCR0[5:4] register COM01:COM00.
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8Pin
  * @description	It has following value.Even though this parameter is  not required
  *					as there are no multiple pwm pins,it is there for code clarity.
  *					TC0_PIN_OC0			
  * @param			u8PwmPhasePinMode
  * @description	It has following value
  *					TC0_OC0_PIN_DISCONNECTED
  *					TC0_OC0_PIN_CLEAR_UPCOUNTING_SET_DOWNCOUNTING
  *					TC0_OC0_PIN_SET_UPCOUNTING_CLEAR_DOWNCOUNTING
  */
void	TC0_SetPwmPhasePinMode(uint8_t u8Pin,uint8_t  u8PwmPhasePinMode)
{		
			 if(u8Pin == TC0_PIN_OC0)
			 {	
				 if(u8PwmPhasePinMode == TC0_OC0_PIN_DISCONNECTED)
				 {	/* COM01 = 0 : COM00 = 0 */
					 TCCR0 &= ~(TC0_TCCR0_COM00);
					 TCCR0 &= ~(TC0_TCCR0_COM01);
				 }
				 if(u8PwmPhasePinMode == TC0_OC0_PIN_CLEAR_UPCOUNTING_SET_DOWNCOUNTING)
				 {	/* COM01 = 1 : COM00 = 0 */
					 TCCR0 &= ~(TC0_TCCR0_COM00);
					 TCCR0 |= (TC0_TCCR0_COM01);
				 }
				 if(u8PwmPhasePinMode == TC0_OC0_PIN_SET_UPCOUNTING_CLEAR_DOWNCOUNTING)
				 {	/* COM01 = 1 : COM00 = 1 */
					 TCCR0 |= (TC0_TCCR0_COM00);
					 TCCR0 |= (TC0_TCCR0_COM01);
				 }
		   }
 }
  

 /** @fn			TC0_SetTimerMode		
  * @brief			Set TC0 in  TimerMode.
  * @McuReg			TCCR0[6:3] register WGM00:WGM01	 
  * @PreCondition	None
  * @PostCondition  None
  * @param			uint8_t Mode
  * @description    This has Value 
  *					TC0_TOP_0XFF
  * @retval			None
  */
void TC0_SetTimerMode(uint8_t Mode)
{	 
	   if(Mode == TC0_TOP_0XFF)
		  {  /*  WGM01 =0 : WGM00 =0  */
			  TCCR0 &= ~(TC0_TCCR0_WGM00);
			  TCCR0 &= ~(TC0_TCCR0_WGM01);
		  }
}

/** @fn				TC0_SetCounterMode		
  * @brief			Set TC0 in  counter Mode.Counting takes place either on Falling or rising Edge.
  * @McuReg			TCCR0[2:0] register CS02:CS01:CS00		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			Edge
  * @description    This has Value . Pin 1 (T0) is Counter Input.
  *					FALLING_EDGE_ON_T0_PIN
  *					RISING_EDGE_ON_T0_PIN.	
  * @retval			None	
  */
void TC0_SetCounterEdge(uint8_t Edge)
{ 
	if(Edge == TC0_FALLING_EDGE_ON_T0_PIN)
	{  /* CS02 =1 :CS01 =1 :CS00= 0*/
		TCCR0 &= ~(TC0_TCCR0_CS00);
		TCCR0 |= (TC0_TCCR0_CS01);
		TCCR0 |= (TC0_TCCR0_CS02);
	}
	else if(Edge == TC0_RISING_EDGE_ON_T0_PIN)
	{   /* CS02 =1 :CS01 =1 :CS00= 1*/
		TCCR0 |= (TC0_TCCR0_CS00);
		TCCR0 |= (TC0_TCCR0_CS01);
		TCCR0 |= (TC0_TCCR0_CS02);
	}
	else
	{
	}
 
}			
/** @fn				TC0_GetTimerReg		
  * @brief			Read the TCNT0 Register.Which represents No of pulses on T0 pin.
  * @McuReg			TCNT0		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			uint8_t Register Value TCNT0.	
  */
void TC0_SetTimerReg(uint8_t count)
{ 	 /* Write TCNT0 register */
		 TCNT0  = count;
}			
		
/** @fn				TC0_SetCompareReg				
  * @brief			Load OCR0 register with Value. 
  * @McuReg			OCR0		
  * @PreCondition	None
  * @PostCondition  None
  * @param			Value
  * @description    uint8_t value to be loaded in OCR0 Register.	
  * @retval			None	
  */
void TC0_SetCompareReg(uint8_t Value)
{
	OCR0 = Value;
}		
		
/** @fn				TC0_SetPrescalar				
  * @brief			Set Prescalar to Timer/Counter0 Module.
  * @McuReg			TCCR0[2:0] register CS02:CS01:CS00		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			Prescalar
  * @description	It is one of the following.
  *					CLK_DIRECT_NO_PRESCALAR
  *					CLK_IO_BY_X X= 8/64/256/1024/
  * @retval			None	
  */
void TC0_SetClockPrescalar(uint8_t Prescalar)
{  
	if(Prescalar == TC0_CLK_DIRECT_NO_PRESCALAR)
	{	/* CS02 =0 :CS01 =0 :CS00= 1*/
		TCCR0 |= (TC0_TCCR0_CS00);
		TCCR0 &= ~(TC0_TCCR0_CS01);
		TCCR0 &= ~(TC0_TCCR0_CS02);
	}
	else if(Prescalar == TC0_CLK_IO_BY_8)
	{	/* CS02 =0 :CS01 =1 :CS00= 0*/
		TCCR0 &= ~(TC0_TCCR0_CS00);
		TCCR0 |= (TC0_TCCR0_CS01);
		TCCR0 &= ~(TC0_TCCR0_CS02);
	}
	else if(Prescalar == TC0_CLK_IO_BY_64)
	{	/* CS02 =0 :CS01 =1 :CS00= 1*/
		TCCR0 |= (TC0_TCCR0_CS00);
		TCCR0 |= (TC0_TCCR0_CS01);
		TCCR0 &= ~(TC0_TCCR0_CS02);
	}
	else if(Prescalar == TC0_CLK_IO_BY_256)
	{	/* CS02 = 1 :CS01 =0 :CS00= 0*/
		TCCR0 &= ~(TC0_TCCR0_CS00);
		TCCR0 &= ~(TC0_TCCR0_CS01);
		TCCR0 |= (TC0_TCCR0_CS02);
	}
	else if(Prescalar == TC0_CLK_IO_BY_1024)
	{	/* CS02 =1 :CS01 =0 :CS00= 1*/
		TCCR0 |= (TC0_TCCR0_CS00);
		TCCR0 &= ~(TC0_TCCR0_CS01);
		TCCR0 |= (TC0_TCCR0_CS02);
	}
	else 
	{
	}
	 
}
/** @fn				TC0_SetClockResolution_P125USEC		
  * @brief			Set TC0 Timer Resolution to 0.128 usec at 8 Mhz Crystal. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_P125USEC_8MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_DIRECT_NO_PRESCALAR);
	TC0_FunctionNo = 0;
} 
/** @fn				TC0_SetClockResolution_P0625USEC_16MHZ		
  * @brief			Set TC0 Timer Resolution to 0.0625 usec at 16 Mhz Crystal. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_P0625USEC_16MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_DIRECT_NO_PRESCALAR);
	TC0_FunctionNo = 0;
} 

/** @fn				TC0_SetClockResolution_1USEC		
  * @brief			Set TC0 Timer Resolution to 1 usec at 8 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_1USEC_8MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_8);
	TC0_FunctionNo = 1;
} 

/** @fn				TC0_SetClockResolution_P5USEC_16MHZ		
  * @brief			Set TC0 Timer Resolution to 0.5 usec at 16 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_P5USEC_16MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_8);
	TC0_FunctionNo = 1;
} 

/** @fn				TC0_SetClockResolution_8USEC_8MHZ	
  * @brief			Set TC0 Timer Resolution to 8 usec at 8 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_8USEC_8MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_64);
	TC0_FunctionNo = 2;
} 

/** @fn				TC0_SetClockResolution_4USEC_16MHZ		
  * @brief			Set TC0 Timer Resolution to 4 usec at 16 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_4USEC_16MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_64);
	TC0_FunctionNo = 2;
} 


/** @fn				TC0_SetClockResolution_32USEC_8MHZ		
  * @brief			Set TC0 Timer Resolution to 32 usec at 8 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_32USEC_8MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_256);
	TC0_FunctionNo = 3;
} 

/** @fn				TC0_SetClockResolution_16USEC_16MHZ		
  * @brief			Set TC0 Timer Resolution to 16 usec at 16 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_16USEC_16MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_256);
	TC0_FunctionNo = 3;
} 

/** @fn				TC0_SetClockResolution_128USEC_8MHZ		
  * @brief			Set TC0 Timer Resolution to 128 usec at 8 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_128USEC_8MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_1024);
	TC0_FunctionNo = 4;
} 

/** @fn				TC0_SetClockResolution_64USEC_16MHZ		
  * @brief			Set TC0 Timer Resolution to 64 usec at 18 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None	
  */
void TC0_SetClockResolution_64USEC_16MHZ(void)
{
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_1024);
	TC0_FunctionNo = 4;
} 

/** @fn				TC0_StartClock				
  * @brief			Start Timer/Counter0 . 
  * @McuReg		
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_StartTimer(void)
{
	/*	There is no start bit for starting timer. WhenPrescalar value
	    is loaded timer start.Based on FunctionNo we load prescalar
    */
	if(TC0_FunctionNo == 0)
	{
		TC0_SetClockResolution_P125USEC_8MHZ();
	}
	else if(TC0_FunctionNo == 1)
	{
		TC0_SetClockResolution_1USEC_8MHZ();			
	}
		
	else if(TC0_FunctionNo == 2)
	{
		TC0_SetClockResolution_8USEC_8MHZ();
	}
	else if(TC0_FunctionNo == 3)
	{
		TC0_SetClockResolution_32USEC_8MHZ();
	}
	else if(TC0_FunctionNo == 4)
	{
		TC0_SetClockResolution_128USEC_8MHZ();
	}
	else{}
	
}		

/** @fn				TC0_StopClock				
  * @brief			Stop Timer/Counter0 . 
  * @McuReg			TCCR0[2:0] register CS02:CS01:CS00		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_StopTimer(void)
{
	/* CS02 =0 :CS01 =0 :CS00= 0*/
	 TCCR0 &= ~(TC0_TCCR0_CS00);	
	 TCCR0 &= ~(TC0_TCCR0_CS01);	
	 TCCR0 &= ~(TC0_TCCR0_CS02);	
}
		
/** @fn				TC0_EnableTimerInterrupt				
  * @brief			Enable Timer/Counter0 timer Interrupt . 
  * @McuReg			TIMSK[1:0] OCIE0 : TOIE0		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_EnableTimerInterrupt(void)
{
	TIMSK |= TC0_TIMASK_TOIE0 ;
}		

/** @fn				TC0_DisableTimerInterrupt				
  * @brief			Disable Timer/Counter0 timer Interrupt . 
  * @McuReg			TIMSK[1:0] OCIE0 : TOIE0			 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_DisableTimerInterrupt(void)
{
	TIMSK &=  ~(TC0_TIMASK_TOIE0) ;
}		

/** @fn				TC0_EnableCompareInterrupt				
  * @brief			Enable Timer/Counter0 Compare Interrupt . 
  * @McuReg			TIMSK[1:0] OCIE0 : TOIE0			 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_EnableCompareInterrupt(void)
{
	TIMSK |= TC0_TIMASK_OCIE0 ;
}		

/** @fn				TC0_DisableCompareInterrupt				
  * @brief			Disable Timer/Counter0 Compare Interrupt . 
  * @McuReg			TIMSK[1:0] OCIE0 : TOIE0			 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None	
  */
void TC0_DisableCompareInterrupt(void)
{
	TIMSK &=  ~(TC0_TIMASK_OCIE0) ;
}		

/** @fn				TC0_RegisterTimerInterruptService 				
  * @brief			This is interrupt service routine for Timer overflow
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun
  * @description	function pointer to Timer interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None  
  */		
void TC0_RegisterTimerInterruptService(fpointerv_t  fun , uint8_t param)
{
	 u8IntParam[TIMER0_OVF_VECT_NO] = param;
	 ISR_FPTR[TIMER0_OVF_VECT_NO] = fun  ;
} 

/** @fn				TC0_RegisterCompareInterruptService 				
  * @brief			This is interrupt service routine for Compare interrupt
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun
  * @description	function pointer to compare interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None  
  */		

void TC0_RegisterCompareInterruptService(fpointerv_t  fun, uint8_t param)
 {
	u8IntParam[TIMER0_COMP_VECT_NO] = param;
	ISR_FPTR[TIMER0_COMP_VECT_NO] = fun;
}

/**
  * @}
 */
