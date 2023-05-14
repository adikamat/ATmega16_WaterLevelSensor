/**
  ******************************************************************************
  * @file    ATmega16_TC1.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020
  * @brief   Driver for Timer/Counter1
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
#include "System.h"

/** 
  * @brief  Application specific header  
  */
#include "ATmega16_TC1.h"
#include "ATmega16_Port.h"
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
  *@Var		FunctionNo
  *@brief   Variable hold the no for, which ClockResolution function was called.
  *			No and called function  relation is as follows.
  *			FunctionNo		 Fucntion Called
  *				0			TC1_SetClockResolution_P128USEC_8MHZ()
  *				1			TC1_SetClockResolution_1USEC_8MHZ()
  *				2			TC1_SetClockResolution_8USEC_8MHZ()
  *				3			TC1_SetClockResolution_32USEC_8MHZ()
  *				4			TC1_SetClockResolution_128USEC_8MHZ()
 */
			
 static uint8_t  TC1_FunctionNo = 0 ; /* This is default value*/
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
 
extern uint8_t  u8IntParam[] ;
 
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

/** @brief			TC1_ClearTimerOnCompareMode
  * @brief			when TC1 is set in this mode content of TCNT1 register is incremented every
  *					clock cycle.You can compare this register content against one of the 
  *					two registers OCR1A or ICR1. when TCNT1 count matches to on of them,TCNT1 is 
  *					clear that is set to 0.You can select which register to us with this function.  
  * @McuReg			TCCR1A[1:0] register WGM11:WGM10
  *					TCCR1B[4:3] register WGM13:WGM12
  * @PreCondition	None
  * @PostCondition	None
  * @param			u8CTCTop
  * @description	It has following value.
  *					TC1_TOP_OCR1A 
  *					TC1_TOP_ICR1
  * @test	Tested OK.	
  */
void    TC1_ClearTimerOnCompareMode(uint8_t u8CTCTop)
{
			if(u8CTCTop == TC1_TOP_OCR1A )
				{/* set WGM13 = 0 : WGM12= 1 :WGM11=0 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A &= ~(TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
					/* Set value into OCR1A Reg */
				}
			else if(u8CTCTop == TC1_TOP_ICR1 )
				{/* set WGM13 = 1 : WGM12= 1 :WGM11=0 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A &= ~(TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B |= (TC1_TCCR1B_WGM13);
				 
				}
		    else { 
				/* Error in Mode*/
				}		
}

/** @brief			TC1_ClearTimerOnComparePinMode
  * @brief			When TC1 is in	CTC(Clear timer on Compare) mode and TCNT1( timer reg) is matched
  *					with one of the OCR1A or ICR1 register set by TC1_ClearTimerOnCompareMode function.
  *					you can choose what event should happen to one of hardware pin OC1A or OC2B. 
  *					The events are
  *					TC1_PIN_DISCONNECTED
  *					TC1_PIN_TOGGLE_ON_MATCH
  *					TC1_PIN_CLEAR_ON_MATCH
  *					TC1_PIN_SET_ON_MATCHTC1
  *					Function allow you select pin as well as event on that pin. 
  * @McuReg			TCCR1A[5:4] register COM1B1: COM1B0
  *					TCCR1A[7:6] register COM1A1: COM1A0
  * @PreCondition	Function TC1_ClearTimerOnCompareMode should be called before calling this function.
  * @PostCondition	None
  * @param			u8Pin
  * @description	It has following value.
  *					TC1_PIN_OC1A
  *					TC1_PIN_OC2B
  * @param			u8CTCPinMode
  * @description	It has following value.
  *					TC1_PIN_DISCONNECTED	
  *					TC1_PIN_TOGGLE_ON_MATCH
  *					TC1_PIN_CLEAR_ON_MATCH
  *					TC1_PIN_SET_ON_MATCH
  * @test	Tested OK.		
  */
void TC1_ClearTimerOnComparePinMode(uint8_t u8Pin, uint8_t  u8CTCPinMode)
{
	 			if(u8Pin == TC1_PIN_OC1A)
				{		
							if(u8CTCPinMode == TC1_PIN_DISCONNECTED	)
							{/*Set COM1A1 = 0 : COM1A0 = 0 */
									TCCR1A &= ~(TC1_TCCR1A_COM1A0);
									TCCR1A &= ~(TC1_TCCR1A_COM1A1);
							}
						   if(u8CTCPinMode == TC1_PIN_TOGGLE_ON_MATCH)
							{/*Set COM1A1 = 0 : COM1A0 = 1 */
									TCCR1A |= (TC1_TCCR1A_COM1A0);
									TCCR1A &= ~(TC1_TCCR1A_COM1A1);
							}
							if(u8CTCPinMode == TC1_PIN_CLEAR_ON_MATCH)
							{/*Set COM1A1 = 1 : COM1A0 = 0 */
									TCCR1A &= ~(TC1_TCCR1A_COM1A0);
									TCCR1A |= (TC1_TCCR1A_COM1A1);
							}
							if(u8CTCPinMode == TC1_PIN_SET_ON_MATCH)
							{/*Set COM1A1 = 1 : COM1A0 = 1 */
									TCCR1A |= (TC1_TCCR1A_COM1A0);
									TCCR1A |= (TC1_TCCR1A_COM1A1);
							}
		       }/* End of  if (u8PinChannel== TC1_OC1A)*/
			   
			if(u8Pin == TC1_PIN_OC1B)
			  {
				    	if(u8CTCPinMode == TC1_PIN_DISCONNECTED)
						{ /*Set COM1B1 = 0 : COM1B0 = 0 */
								TCCR1A &= ~(TC1_TCCR1A_COM1B0);
								TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						}
						if(u8CTCPinMode == TC1_PIN_TOGGLE_ON_MATCH)
						{/*Set COM1B1 = 0 : COM1B0 = 1 */
								TCCR1A |= (TC1_TCCR1A_COM1B0);
								TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						}
						if(u8CTCPinMode == TC1_PIN_CLEAR_ON_MATCH)
						{/*Set COM1B1 = 1 : COM1B0 = 0 */
								TCCR1A &= ~(TC1_TCCR1A_COM1B0);
								TCCR1A |= (TC1_TCCR1A_COM1B1);
						}
						if(u8CTCPinMode == TC1_PIN_SET_ON_MATCH)
						{/*Set COM1B1 = 1 : COM1B0 = 1 */
								TCCR1A |= (TC1_TCCR1A_COM1B0);
								TCCR1A |= (TC1_TCCR1A_COM1B1);
						}
     	    }/* End of  if(u8PinChannel == TC1_OC2B)*/
			 
}

/** @brief			TC1_FastPwmMode		
  * @brief			When TC1 is set in this mode to generate PWM, TCNT1 should be compared with
  *					either some Register or with Fixed value.So when the match occurs pin can be set
  *					or reset.Function allows to choose three fixed values 8BIT_TOP_0X00F/9BIT_TOP_0X01FF/
  *					10BIT_TOP_0X03FFF or two registers ICR1 or OCR1a. These are called TOP values in data sheets.
  *					This function set one      of the modes as mention in data sheet.    
  * @McuReg			TCCR1A[1:0] register WGM11:WGM10
  *					TCCR1B[4:3] register WGM13:WGM12
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8FastPwmTopReg
  * @description	It has following value
  *					TC1_8BIT_TOP_0X00FF
  *					TC1_9BIT_TOP_0X01FF
  *					TC1_10BIT_TOP_0X03FF
  *					TC1_TOP_ICR1
  *					TC1_TOP_OCR1A
  * @test	Tested OK.		
  */  
void	TC1_FastPwmMode(uint8_t u8FastPwmTopReg)
{
			if(u8FastPwmTopReg == TC1_8BIT_TOP_0X00FF)
			{/* set WGM13 = 0 : WGM12= 1 :WGM11=0 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A &= ~(TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
			}
			if(u8FastPwmTopReg == TC1_9BIT_TOP_0X01FF)
			{/* set WGM13 = 0 : WGM12= 1 :WGM11=1 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
			}
			if(u8FastPwmTopReg == TC1_10BIT_TOP_0X03FF)
			{/* set WGM13 = 0 : WGM12= 1 :WGM11=1 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
			}
			if(u8FastPwmTopReg == TC1_TOP_ICR1)
			{/* set WGM13 = 1 : WGM12= 1 :WGM11=1 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12);
					TCCR1B |= (TC1_TCCR1B_WGM13);
			}
			if(u8FastPwmTopReg == TC1_TOP_OCR1A)
			{/* set WGM13 = 1 : WGM12= 1 :WGM11=1 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B |= (TC1_TCCR1B_WGM12) ;
			}
 }

/** @brief			TC1_FastPwmPinMode	
  * @brief			When TC1 is in FastPwmMode mode and TCNT1( timer reg) is matched with one of the TOP
  *					values set by TC1_FastPwmMode function you can choose what events should happen on OC1A
  *					and OC2B hardware pins.The events are
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP
  *					TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP
  *					Function allows Which pin to select and what event should happen on that pin.	 
  * @McuReg			TCCR1A[5:4] register COM1B1: COM1B0
  *					TCCR1A[7:6] register COM1A1: COM1A0 
  * @PreCondition	Function TC1_FastPwmMode should be called before this function. 	
  * @PostCondition  None
   * @param			u8Pin
  * @description	It has following value.
  *					TC1_PIN_OC1A
  *					TC1_PIN_OC2B
  * @param			u8FastPwmPinMode
  * @description	It has following value
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP
  *					TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP
  * @test	Tested OK.		
  */  	
void	TC1_FastPwmPinMode(uint8_t u8Pin,uint8_t  u8FastPwmPinMode)
{
		 		if(u8Pin == TC1_PIN_OC1A)
					{
						if(u8FastPwmPinMode == TC1_PIN_DISCONNECTED)
							{/*Set COM1A1 = 0 : COM1A0 = 0 */
								TCCR1A &= ~(TC1_TCCR1A_COM1A0);
								TCCR1A &= ~(TC1_TCCR1A_COM1A1);
							}
						if(u8FastPwmPinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
							{/*Set COM1A1 = 0 : COM1A0 = 1 */
								TCCR1A |= (TC1_TCCR1A_COM1A0);
								TCCR1A &= ~(TC1_TCCR1A_COM1A1);
							}
						if(u8FastPwmPinMode == TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP)
							{/*Set COM1A1 = 1 : COM1A0 = 0 */
								TCCR1A &= ~(TC1_TCCR1A_COM1A0);
								TCCR1A |= (TC1_TCCR1A_COM1A1);
							}
						if(u8FastPwmPinMode == TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP)
							{/*Set COM1A1 = 1 : COM1A0 = 1 */
								TCCR1A |= (TC1_TCCR1A_COM1A0);
								TCCR1A |= (TC1_TCCR1A_COM1A1);
							}
					
				 }/* End of  if if(u8Pin == TC1_OC1A)*/
					
			 if(u8Pin == TC1_PIN_OC1B)
				{
						 if(u8FastPwmPinMode == TC1_PIN_DISCONNECTED)
						 {/*Set COM1B1 = 0 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						 }
						 if(u8FastPwmPinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
						 {/*Set COM1B1 = 0 : COM1B0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1B0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						 }
						 if(u8FastPwmPinMode == TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP)
						 {/*Set COM1B1 = 1 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
						 if(u8FastPwmPinMode == TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP)
						 {/*Set COM1B1 = 1 : COM1B0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
				   }/* End of  if(u8Channel == TC1_OC2B)*/
				  
}

/** @brief			TC1_PwmPhaseMode	
  * @brief			When TC1 is set in this mode to generate PWM, TCNT1 should be compared with
  *					either some Register or with Fixed value.So when the match occurs pin can be set
  *					or reset.Function allows to choose three fixed values 8BIT_TOP_0X00F/9BIT_TOP_0X01FF/
  *					10BIT_TOP_0X03FFF or two registers ICR1 or OCR1a. These are called TOP values in data sheets.
  *					This function set one of the modes as mention in data sheet.
  * @McuReg			TCCR1A[1:0] register WGM11:WGM10
  *					TCCR1B[4:3] register WGM13:WGM12
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8PwmPhaseTop
  * @description	It has following value
  *					TC1_8BIT_TOP_0X00FF
  *					TC1_9BIT_TOP_0X01FF
  *					TC1_10BIT_TOP_0X03FF
  *					TC1_TOP_ICR1
  *					TC1_TOP_OCR1A	
  * @test	Tested OK.		
  */  
void	TC1_PwmPhaseMode(uint8_t u8PwmPhaseTop)
{
			if(u8PwmPhaseTop == TC1_8BIT_TOP_0X00FF)
				{/* set WGM13 = 0 : WGM12= 0 :WGM11=0 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A &= ~(TC1_TCCR1A_WGM11);
					TCCR1B &= ~(TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
				}
				if(u8PwmPhaseTop == TC1_9BIT_TOP_0X01FF)
				{/* set WGM13 = 0 : WGM12= 0 :WGM11=1 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B &= ~(TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
				}
				if(u8PwmPhaseTop == TC1_10BIT_TOP_0X03FF)
				{/* set WGM13 = 0 : WGM12= 0 :WGM11=1 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B &= ~(TC1_TCCR1B_WGM12);
					TCCR1B &= ~(TC1_TCCR1B_WGM13);
				}
				if(u8PwmPhaseTop == TC1_TOP_ICR1)
				{/* set WGM13 = 1 : WGM12= 0 :WGM11=1 : WGM10=0 */
					TCCR1A &= ~(TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B &= ~(TC1_TCCR1B_WGM12);
					TCCR1B |= (TC1_TCCR1B_WGM13);
				}
				if(u8PwmPhaseTop == TC1_TOP_OCR1A)
				{/* set WGM13 = 1 : WGM12= 0 :WGM11=1 : WGM10=1 */
					TCCR1A |= (TC1_TCCR1A_WGM10);
					TCCR1A |= (TC1_TCCR1A_WGM11);
					TCCR1B &= ~(TC1_TCCR1B_WGM12);
					TCCR1B |= (TC1_TCCR1B_WGM13);
				}
				
}
/** @brief			TC1_PwmPhasePinMode		
  * @brief			When TC1 is in PwmPhaseMode mode and TCNT1( timer reg) is matched with one of the TOP
  *					values set by TC1_PwmPhaseMode function you can choose what events should happen on OC1A
  *					and OC2B hardware pins.The events are
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING
  *					TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING
  *					Function allows Which pin to select and what event should happen on that pin.
  * @McuReg			TCCR1A[5:4] register COM1B1: COM1B0
  *					TCCR1A[7:6] register COM1A1: COM1A0 
  * @PreCondition	Function TC1_PwmPhaseMode should be called before this function.	
  * @PostCondition  None
   * @param			u8Pin
  * @description	It has following value.
  *					TC1_PIN_OC1A
  *					TC1_PIN_OC2B
  * @param			u8PwmPhasePinMode
  * @description	It has following value
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING
  *					TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING
  * @test	Tested OK.		
  */  		
void	TC1_PwmPhasePinMode(uint8_t u8Pin,uint8_t  u8PwmPhasePinMode)
{
				if(u8Pin == TC1_PIN_OC1A)
					{
						 if(u8PwmPhasePinMode == TC1_PIN_DISCONNECTED)
						 {/*Set COM1A1 = 0 : COM1A0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1A0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1A1);
						 }
						 if(u8PwmPhasePinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
						 {/*Set COM1A1 = 0 : COM1A0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1A0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1A1);
						 }
						 if(u8PwmPhasePinMode == TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING)
						 {/*Set COM1A1 = 1 : COM1A0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1A0);
							 TCCR1A |= (TC1_TCCR1A_COM1A1);
						 }
						 if(u8PwmPhasePinMode == TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING)
						 {/*Set COM1A1 = 1 : COM1A0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1A0);
							 TCCR1A |= (TC1_TCCR1A_COM1A1);
						 }
					}
					
					if(u8Pin == TC1_PIN_OC1B)
					{
						 if(u8PwmPhasePinMode == TC1_PIN_DISCONNECTED)
						 {/*Set COM1B1 = 0 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						  }
						  if(u8PwmPhasePinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
						  {/*Set COM1B1 = 0 : COM1B0 = 1 */
							  TCCR1A |= (TC1_TCCR1A_COM1B0);
							  TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						  } 
						 if(u8PwmPhasePinMode == TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING)
						 {/*Set COM1B1 = 1 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
						 if(u8PwmPhasePinMode == TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING)
						 {/*Set COM1B1 = 1 : COM1B0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
				  }
}

  /** @brief		TC1_PwmPhaseFrequencyMode
  * @brief			When TC1 is set in this mode to generate PWM, TCNT1 should be compared with
  *					either some Register.So when the match occurs pin can be set or reset.Function allows
  *					two registers ICR1 or OCR1a. These are called TOP values in data sheets.
  *					This function set one of       the modes as mention in data sheet.
  * @McuReg			TCCR1A[1:0] register WGM11:WGM10
  *					TCCR1B[4:3] register WGM13:WGM12
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8PwmPhaseFrequencyTop
  * @description	It has following value
  *					TC1_TOP_ICR1 
  *					TC1_TOP_OCR1A
  * @test	Tested OK.		
  */  
void	TC1_PwmPhaseFrequencyMode(uint8_t u8PwmPhaseFrequencyTop)
{
	    			if(u8PwmPhaseFrequencyTop == TC1_TOP_ICR1)
					{/* set WGM13 = 1 : WGM12= 0 :WGM11=0 : WGM10=0 */
						TCCR1A &= ~(TC1_TCCR1A_WGM10);
						TCCR1A &= ~(TC1_TCCR1A_WGM11);
						TCCR1B &= ~(TC1_TCCR1B_WGM12);
						TCCR1B |= (TC1_TCCR1B_WGM13);
					}
					if(u8PwmPhaseFrequencyTop == TC1_TOP_OCR1A)
					{/* set WGM13 = 1 : WGM12= 0 :WGM11=0 : WGM10=1 */
						TCCR1A |= (TC1_TCCR1A_WGM10);
						TCCR1A &= ~(TC1_TCCR1A_WGM11);
						TCCR1B &= ~(TC1_TCCR1B_WGM12);
						TCCR1B |= (TC1_TCCR1B_WGM13);
					}
}
/** @brief			TC1_PwmPhaseFrequencyPinMode
  * @brief			When TC1 is in PwmPhaseFrequencyMode mode and TCNT1( timer reg) is matched with one of the TOP
  *					values set by TC1_PwmPhaseFrequencyMode function you can choose what events should happen 
  *					on OC1A	and OC2B hardware pins.The events are
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING
  *					TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING
  *					Function allows Which pin to select and what event should happen on that pin.
  * @McuReg			TCCR1A[5:4] register COM1B1: COM1B0
  *					TCCR1A[7:6] register COM1A1: COM1A0 
  * @PreCondition	Function TC1_PwmPhaseFrequencyMode should be called before this function.
  * @PostCondition  None
  * @param			u8Pin
  * @description	It has following value.
  *					TC1_PIN_OC1A
  *					TC1_PIN_OC2B
  * @param			u8PwmPhaseFrequencyPinMode
  * @description	It has following value
  *					TC1_PIN_DISCONNECTED
  *					TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED
  *					TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING
  *					TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING
  * @test	Tested OK.		
  */  		
void	TC1_PwmPhaseFrequencyPinMode(uint8_t u8Pin,uint8_t  u8PwmPhaseFrequencyPinMode)
{
			if(u8Pin == TC1_PIN_OC1A)
				{
						if(u8PwmPhaseFrequencyPinMode == TC1_PIN_DISCONNECTED)
						{/*Set COM1A1 = 0 : COM1A0 = 0 */
							TCCR1A &= ~(TC1_TCCR1A_COM1A0);
							TCCR1A &= ~(TC1_TCCR1A_COM1A1);
						}
						if(u8PwmPhaseFrequencyPinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
						{/*Set COM1A1 = 0 : COM1A0 = 1 */
							TCCR1A |= (TC1_TCCR1A_COM1A0);
							TCCR1A &= ~(TC1_TCCR1A_COM1A1);
						}
						if(u8PwmPhaseFrequencyPinMode == TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING)
						{/*Set COM1A1 = 1 : COM1A0 = 0 */
							TCCR1A &= ~(TC1_TCCR1A_COM1A0);
							TCCR1A |= (TC1_TCCR1A_COM1A1);
						}
						if(u8PwmPhaseFrequencyPinMode == TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING)
						{/*Set COM1A1 = 1 : COM1A0 = 1 */
							TCCR1A |= (TC1_TCCR1A_COM1A0);
							TCCR1A |= (TC1_TCCR1A_COM1A1);
						}
					
				}
					
			if(u8Pin == TC1_PIN_OC1B)
			{
						 if(u8PwmPhaseFrequencyPinMode == TC1_PIN_DISCONNECTED)
						 {/*Set COM1B1 = 0 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						 }
						 if(u8PwmPhaseFrequencyPinMode == TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED)
						 {/*Set COM1B1 = 0 : COM1B0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1B0);
							 TCCR1A &= ~(TC1_TCCR1A_COM1B1);
						 }
						 if(u8PwmPhaseFrequencyPinMode == TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING)
						 {/*Set COM1B1 = 1 : COM1B0 = 0 */
							 TCCR1A &= ~(TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
						 if(u8PwmPhaseFrequencyPinMode == TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING)
						 {/*Set COM1B1 = 1 : COM1B0 = 1 */
							 TCCR1A |= (TC1_TCCR1A_COM1B0);
							 TCCR1A |= (TC1_TCCR1A_COM1B1);
						 }
			}
}

/** @brief			TC1_TimerMode		
  * @brief			Set TC1 in TimerMode. 
  * @McuReg			TCCR1B[2:0]  CS12:CS11:CS10 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8Mode
  * @description    This has Value 
  *					TC1_TOP_0XFFFF
  * @retval			None
  * @test	Tested OK.		
  */
void TC1_TimerMode(uint8_t u8Mode)
{
	if(u8Mode  == TC1_TOP_0XFFFF)
	{/* set WGM13 = 0 : WGM12= 0 :WGM11=0 : WGM10=0 */
		TCCR1A &= ~(TC1_TCCR1A_WGM10);
		TCCR1A &= ~(TC1_TCCR1A_WGM11);
		TCCR1B &= ~(TC1_TCCR1B_WGM12);
		TCCR1B &= ~(TC1_TCCR1B_WGM13);
	}
}	

/** @brief			TC1_SetCounterModeEdge	
  * @brief			Set TC1 in  counter Mode.Counting takes place either on Falling or rising Edge. 
  * @McuReg			TCCR1B[2:0]  CS12:CS11:CS10 . Mcu pin 2 (T1)
  * @PreCondition	None
  * @PostCondition  None
  * @param			Edge
  * @description    This has Value 
  *					TC1_CLK_FALLING_EDGE_ON_T1_PIN
  *					TC1_CLK_RISING_EDGE_ON_T1_PIN	
  * @retval			None
    * @test	Tested OK.		
  */
void	TC1_SetCounterModeEdge(uint8_t u8Edge)
{
	if(u8Edge == TC1_CLK_FALLING_EDGE_ON_T1_PIN)
	{  /* CS12 =1 :CS11 =1 :CS10= 0*/
		TCCR1B &= ~(TC1_TCCR1B_CS10);
		TCCR1B |= (TC1_TCCR1B_CS11);
		TCCR1B |= (TC1_TCCR1B_CS12);
	}
	else if(u8Edge == TC1_CLK_RISING_EDGE_ON_T1_PIN)
	{   /* CS12 =1 :CS11 =1 :CS10= 1*/
		TCCR1B |= (TC1_TCCR1B_CS10);
		TCCR1B |= (TC1_TCCR1B_CS11);
		TCCR1B |= (TC1_TCCR1B_CS12);
	}
	else
	{
		
	}
}
		
/** @brief			TC1_SetInputCapturePin	
  * @brief			Set Input Capture Source Mcu pin 20 ICP1 
  * @McuReg			ACSR[3] ACIC 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8InputCapturePin
  * @description	PORTx_Pxy  where x is A/B/C/D and y is 0 to 7 
  *	
  * @retval			None	
  */
void TC1_SetInputCapturePin(uint8_t u8InputCapturePin)	 
 {
	//if(u8InputCapturePin == TC1_PIN_ICP1)
	{
		/*Set Pin Direction as Input*/
		Port_SetPinDirection(u8InputCapturePin,PORT_IN);  
	}
}

/** @brief			TC1_SetInputCaptureEdge		
  * @brief			Set Input Capture Source  edge Mcu pin 20 ICP1 
  * @McuReg			TCCR1B[7:6] ICNC1 : ICES1 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8CaptureEdge 
  * @description    This has Value 
  *					TC1_INPUT_CAPTURE_RISING_EDGE
  *					TC1_INPUT_CAPTURE_FALLING_EDGE
  * @retval			None	
  * @test	Tested OK.		
  */
void TC1_SetInputCaptureEdge(uint8_t u8CaptureEdge)	 
{
	if(u8CaptureEdge == TC1_INPUT_CAPTURE_FALLING_EDGE)
	{	/* ICES1 = 0*/
		TCCR1B &= ~(TC1_TCCR1B_ICES1);
	}
	if(u8CaptureEdge == TC1_INPUT_CAPTURE_RISING_EDGE)
	{		/* ICES1 = 1*/
		TCCR1B |= (TC1_TCCR1B_ICES1);
	}
}
/** @brief			TC1_SetTimerReg		
  * @brief			Write the TCNT1 Register.
  * @McuReg			TCNT1		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u16Count
  * @description    Count to be loaded into timer register.	
  * @retval			None
  * @test		
  */

void TC1_SetTimerReg(uint16_t u16Count)
{ 
uint8_t  u8TCNT1L,u8TCNT1H;	
	 /* To Write TCNT1 16 bit register, Write TCNT1H first 
	    and TCNT1L next as per manual page 90
	  */
		 u8TCNT1L  = (uint8_t)u16Count ;
		 u8TCNT1H = u16Count >>8 ;
		 TCNT1H = u8TCNT1H;
		 TCNT1L= u8TCNT1L;
}			

/** @brief			TC1_GetTimerReg		
  * @brief			Read the TCNT1 Register.
  * @McuReg			TCNT1		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			uint16_t Register Value TCNT1.	
  * @test	Tested OK.		
  */

uint16_t TC1_GetTimerReg(void)
{ 
uint16_t u16TCNT1;
uint8_t  u8TCNT1L,u8TCNT1H;	
	 /* To Read TCNT1 16 bit register, Read TCNT1L first 
	    and TCNT1H next as per manual page 90
	  */
		u8TCNT1L = TCNT1L;
		u8TCNT1H = TCNT1H;
	/* Combine two bytes into one*/
		u16TCNT1  = u8TCNT1H ;
		u16TCNT1 = u8TCNT1H <<8 ;
	    u16TCNT1 |= u8TCNT1L ;
 		return ( u16TCNT1);
}			

/** @brief			TC1_SetCompareReg				
  * @brief			Load OCR1A or OCR1B register with Value.
  * @McuReg		    OCR1AH : OCR1AL
  *					OCR1BH : OCR1BL 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8CompReg
  * @description    It has following values 
  *					TC1_OCR1A_REG......means OCR1A Reg is Loaded.	
  *					TC1_OCR1B_REG......means OCR1B Reg is Loaded
  *					TC1_ICR1_REG.......means ICR1 Reg is Loaded
  * @param			u16Value
  * @description    It is 16 bit value which is loaded into register
  * @retval			None
   * @test	Tested OK.					
  */
void TC1_SetCompareReg(uint8_t u8CompReg, uint16_t u16Value)
{
	uint8_t u8ValueL,u8ValueH;
	/* To Write OCR1x 16 bit register, Write OCR1xH first 
	    and OCR1xL next as per manual page 90
	  */
	/* Split Value into Low and High Byte */
	     u8ValueL = (uint8_t)u16Value;
		 u8ValueH = (uint8_t)(u16Value >> 8); 
	if(u8CompReg == TC1_OCR1A_REG)
	{ 
		OCR1AH = u8ValueH;
		OCR1AL = u8ValueL;
	}
	else if(u8CompReg == TC1_OCR1B_REG)
	{
		OCR1BH = u8ValueH;
		OCR1BL = u8ValueL;
	}
	else if(u8CompReg == TC1_ICR1_REG)
	{
		ICR1H = u8ValueH;
		ICR1L = u8ValueL;
	}
	else
	{
		
	}
}		

/** @brief			TC1_GetCaptureReg				
  * @brief			Get the ICR1 register Value. 
  * @McuReg			ICR1H: ICR1L
  * @PreCondition	None
  * @PostCondition  None
  * @param			Void
  * @description    None	
  * @retval
  * @test	Tested OK.					
  */
uint16_t TC1_GetCaptureReg(void)
{
 uint16_t u16CaptureValue;
  uint8_t  u8CaptureValueH,u8CaptureValueL;	
	 ///* To Read ICR1 16 bit register, Read ICR1L first 
	    //and ICR1H next as per manual page 90
	  //*/
		u8CaptureValueL = ICR1L;
		u8CaptureValueH = ICR1H;
	/* Combine two bytes into one*/
		u16CaptureValue = u8CaptureValueH ;
		u16CaptureValue = u16CaptureValue << 8;
		u16CaptureValue |= u8CaptureValueL ;
		return u16CaptureValue ;
}	


/** @brief			TC1_StopClock				
  * @brief			Set Prescalar to 0. 
  * @McuReg			TCCR1B[2:0]  CS12:CS11:CS10 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	Stop Clock to Prescalar.
  * @retval			None
  * @test	Tested OK.			
  */
void TC1_StopClock(void)
{	
	/* CS12 =0 :CS11 =0 :CS10= 0*/
	TCCR1B &= ~(TC1_TCCR1B_CS10);
	TCCR1B &= ~(TC1_TCCR1B_CS11);
	TCCR1B &= ~(TC1_TCCR1B_CS12); 
}

/** @brief			TC1_StartClock				
  * @brief			Set Prescalar to 0. 
  * @McuReg			TCCR1B[2:0]  CS12:CS11:CS10 
  * @PreCondition	None
  * @PostCondition  None
  * @param			None
  * @description	Start Clock by Loading  Prescalar Value.
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_StartClock(void)
{   
	/*	There is no start bit for starting timer. WhenPrescalar value
	    is loaded timer start.Based on FunctionNo we load prescalar
    */
	if(TC1_FunctionNo == 0)
	{
		TC1_SetClockResolution_P125USEC_8MHZ();
	}
	else if(TC1_FunctionNo == 1)
	{
		TC1_SetClockResolution_1USEC_8MHZ();			
	}
	else if(TC1_FunctionNo == 2)
	{
		TC1_SetClockResolution_8USEC_8MHZ();
	}
	else if(TC1_FunctionNo == 3)
	{
		TC1_SetClockResolution_32USEC_8MHZ();
	}
	else if(TC1_FunctionNo == 4)
	{
		TC1_SetClockResolution_128USEC_8MHZ();
	}
	else{}
}

			
/** @brief			TC1_SetClockPrescalar		
  * @brief			Set Prescalar to Timer/Counter1 Module. 
  * @McuReg			TCCR1B[2:0]  CS12:CS11:CS10 
  * @PreCondition	None
  * @PostCondition  None
  * @param			u8Prescalar
  * @description	It is one of the following.
  *					TC1_CLK_DIRECT_NO_PRESCALAR
  *					TC1_CLK_IO_BY_X X= 8/64/256/1024/
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockPrescalar(uint8_t u8Prescalar)
{
	if(u8Prescalar == TC1_CLK_DIRECT_NO_PRESCALAR)
	{	/* CS12 =0 :CS11 =0 :CS10= 1*/
		TCCR1B |= (TC1_TCCR1B_CS10);
		TCCR1B &= ~(TC1_TCCR1B_CS11);
		TCCR1B &= ~(TC1_TCCR1B_CS12);
	}
	else if(u8Prescalar == TC1_CLK_IO_BY_8)
	{	/* CS12 =0 :CS11 =1 :CS10= 0*/
		TCCR1B &= ~(TC1_TCCR1B_CS10);
		TCCR1B |= (TC1_TCCR1B_CS11);
		TCCR1B &= ~(TC1_TCCR1B_CS12);
	}
	else if(u8Prescalar == TC1_CLK_IO_BY_64)
	{	/* CS12 =0 :CS11 =1 :CS10= 1*/
		TCCR1B |= (TC1_TCCR1B_CS10);
		TCCR1B |= (TC1_TCCR1B_CS11);
		TCCR1B &= ~(TC1_TCCR1B_CS12);
	}
	else if(u8Prescalar == TC1_CLK_IO_BY_256)
	{	/* CS12 = 1 :CS11 =0 :CS10= 0*/
		TCCR1B &= ~(TC1_TCCR1B_CS10);
		TCCR1B &= ~(TC1_TCCR1B_CS11);
		TCCR1B |= (TC1_TCCR1B_CS12);
	}
	else if(u8Prescalar == TC1_CLK_IO_BY_1024)
	{	/* CS12 =1 :CS11 =0 :CS10= 1*/
		TCCR1B |= (TC1_TCCR1B_CS10);
		TCCR1B &= ~(TC1_TCCR1B_CS11);
		TCCR1B |= (TC1_TCCR1B_CS12);
	}
	else
	{
	}
}

/** @brief			TC1_SetClockResolution_P128USEC		
  * @brief			Set TC1 Timer Resolution to 0.128 usec at 8 Mhz Crystal. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_P125USEC_8MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_DIRECT_NO_PRESCALAR);
	TC1_FunctionNo = 0;
} 
/** @brief			TC1_SetClockResolution_P0625USEC_16MHZ		
  * @brief			Set TC1 Timer Resolution to 0.0625usec at 16 Mhz Crystal. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_P0625USEC_16MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_DIRECT_NO_PRESCALAR);
	TC1_FunctionNo = 0;
}

/** @brief			TC1_SetClockResolution_1USEC		
  * @brief			Set TC1 Timer Resolution to 1 usec at 8 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_1USEC_8MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_8);
	TC1_FunctionNo = 1;
} 
/** @brief			TC1_SetClockResolution_P5USEC_16MHZ	
  * @brief			Set TC1 Timer Resolution to 0.5 usec at 16 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_P5USEC_16MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_8);
	TC1_FunctionNo = 1;
}

/** @brief			TC1_SetClockResolution_8USEC		
  * @brief			Set TC1 Timer Resolution to 8 usec at 8 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_8USEC_8MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_64);
	TC1_FunctionNo = 2;
} 
/** @brief			TC1_SetClockResolution_4USEC_16MHZ		
  * @brief			Set TC1 Timer Resolution to 4 usec at 16 Mhz Crystal.. 
  * @McuReg			Noe
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_4USEC_16MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_64);
	TC1_FunctionNo = 2;
}


/** @brief			TC1_SetClockResolution_32USEC		
  * @brief			Set TC1 Timer Resolution to 32 usec at 8 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_32USEC_8MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_256);
	TC1_FunctionNo = 3;
} 
/** @brief			TC1_SetClockResolution_16USEC_16MHZ		
  * @brief			Set TC1 Timer Resolution to 16 usec at 16 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_16USEC_16MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_256);
	TC1_FunctionNo = 3;
}

/** @brief			TC1_SetClockResolution_128USEC		
  * @brief			Set TC1 Timer Resolution to 128 usec at 8 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_128USEC_8MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_1024);
	TC1_FunctionNo = 4;
} 
/** @brief			TC1_SetClockResolution_64USEC_16MHZ		
  * @brief			Set TC1 Timer Resolution to 64 usec at 16 Mhz Crystal.. 
  * @McuReg			None
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_SetClockResolution_64USEC_16MHZ(void)
{
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_1024);
	TC1_FunctionNo = 4;
}
	
/** @brief			TC1_EnableTimerInterrupt				
  * @brief			Enable Timer/Counter1 Timer1 Interrupt.
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_EnableTimerInterrupt(void)
{
	TIMSK |= TC1_TIMASK_TOIE1 ;	
}

/** @brief			TC1_DisableTimerInterrupt				
  * @brief			Disable Timer/Counter1 Timer1 Interrupt.
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1		 
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description    	
  * @retval			None
  * @test	Tested OK.		 	
  */
void TC1_DisableTimerInterrupt(void)
{
	TIMSK &= ~(TC1_TIMASK_TOIE1) ;
}


/** @brief			TC1_EnableCompareInterrupt				
  * @brief			Enable Timer/Counter1 Compare Interrupt. 
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1
  * @PreCondition	None
  * @PostCondition  None
  * @param			Channel
  * @description     It has following values
  *					TC1_OCR1A_INTERRUPT	 ...means match interrupt for Output Compare A Enable.
  *					TC1_OCR1B_INTERRUPT...means match interrupt for Output Compare B Enable.
  * @retval			None
  * @test	Tested OK.		 
  */
void TC1_EnableCompareInterrupt(uint8_t u8Channel)
{
	if(u8Channel == TC1_OCR1A_INTERRUPT	)
	{
		TIMSK |= TC1_TIMASK_OCIE1A ;	
	}
	else if(u8Channel == TC1_OCR1B_INTERRUPT)
	{
		TIMSK |= TC1_TIMASK_OCIE1B ;
	}
	else
	{
	}
}		

/** @brief			TC1_DiableCompareInterrupt				
  * @brief			Enable Timer/Counter1 Compare Interrupt . 
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1
  * @PreCondition	None
  * @PostCondition  None
  * @param			Channel
  * @description    It has following values
  *					TC1_OCR1A_INTERRUPT ...means match interrupt for Output Compare A Disable.
  *					TC1_OCR1B_INTERRUPT....means match interrupt for Output Compare B Disable.
  * @retval			None
  * @test	Tested OK.		 
  */
void TC1_DisableCompareInterrupt(uint8_t u8Channel)
{
	if(u8Channel ==  TC1_OCR1A_INTERRUPT)
	{
		TIMSK &= ~(TC1_TIMASK_OCIE1A) ;
	}
	else if(u8Channel == TC1_OCR1B_INTERRUPT)
	{
		TIMSK &= ~(TC1_TIMASK_OCIE1B) ;
	}
	else
	{
	}
}

/** @brief			TC1_EnableInputCaptureInterrupt				
  * @brief			Enable Timer/Counter1 Compare Interrupt. 
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1
  * @PreCondition	None
  * @PostCondition   None
  * @param			Void
  * @description     
  * @retval			None
  * @test	Tested OK.		
 */
void TC1_EnableInputCaptureInterrupt(void)
{
	TIMSK |= TC1_TIMASK_TICIE1 ;	
}				

/** @brief			TC1_DisableInputCaptureInterrupt				
  * @brief			Enable Timer/Counter1 Compare Interrupt. 
  * @McuReg			TIMSK[5:2]   TCIE1:OCIE1A:OCIE1B:TOIE1
  * @PreCondition	None
  * @PostCondition   None
  * @param			Void
  * @description     
  * @retval			None
  * @test	Tested OK.		 
  */
void TC1_DisableInputCaptureInterrupt(void)
{
	TIMSK &= ~(TC1_TIMASK_TICIE1) ;	
}		

 
/** @brief			TC1_RegisterTimerInterruptService			
  * @brief			This register service routine for Timer1 Overflow.
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun		
  * @description	function pointer to Timer interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None
  * @test	Tested OK.		   
  */		
void TC1_RegisterTimerInterruptService(fpointerv_t  fun , uint8_t param)
{
	 u8IntParam[TIMER1_OVF_VECT_NO] = param;
	 ISR_FPTR[TIMER1_OVF_VECT_NO] = fun  ;
} 

/** @brief			TC1_RegisterCompareAInterruptService			
  * @brief			This register interrupt service routine for Compare channelA .
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun
  * @description	function pointer to Timer interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None  
  */		
void TC1_RegisterCompareAInterruptService(fpointerv_t  fun, uint8_t param)
{
	 u8IntParam[TIMER1_COMPA_VECT_NO] = param;
	 ISR_FPTR[TIMER1_COMPA_VECT_NO] = fun;
} 
/** @brief			TC1_RegisterCompareBInterruptService			
  * @brief			This register interrupt service routine for Compare channel B
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun
  * @description	function pointer to Timer interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None  
  */		
void TC1_RegisterCompareBInterruptService(fpointerv_t  fun, uint8_t param)
{
	  u8IntParam[TIMER1_COMPB_VECT_NO] = param;
	  ISR_FPTR[TIMER1_COMPB_VECT_NO] = fun;
} 
/** @brief			TC1_RegisterInputCaptureInterruptService				
  * @brief			This register interrupt service routine for Input Capture.
  * @PreCondition	None
  * @PostCondition  None
  * @param	        fun
  * @description	function pointer to Timer interrupt service routine.
  * @param	        param
  * @description	Additional Parameter if required.
  * @retval			None  
  */		
void TC1_RegisterInputCaptureInterruptService(fpointerv_t  fun, uint8_t param)
{
	  u8IntParam[TIMER1_CAPT_VECT_NO] = param;
	  ISR_FPTR[TIMER1_CAPT_VECT_NO] = fun;
} 

/** @brief			TC1_DummyInterrupt				
  * @brief			This dummy interrupt used to initialize Interrupt function pointer.
  * @PreCondition	None
  * @PostCondition  None
  * @param	        None		
  * @description	None
  * @retval			None  
  */		

void TC1_DummyInterrupt(uint8_t dummy) 
{
	
}

/**
  * @}
 */
