/**
  ******************************************************************************
  * @file    TC1.h
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
#ifndef  _ATMEGA16_TC1_H
#define  _ATMEGA16_TC1_H

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
  * @#define          
  * @brief      These macros are used for TC1 Module Registers  
  */  
#define TC1_OCR1A_REG								(uint8_t)1
#define TC1_OCR1B_REG								(uint8_t)2
#define TC1_ICR1_REG								(uint8_t)3

/** 
  * @#define          
  * @brief      These macros are used for TC1 Module for  Compare Interrupt   
  */  
#define TC1_OCR1A_INTERRUPT							(uint8_t)1
#define TC1_OCR1B_INTERRUPT							(uint8_t)2
 
/** 
  * @#define          
  * @brief      These macros define all input output hardware pins of MCU  
  */  
#define TC1_PIN_OC1A	PORTD_PD5 /*!< This is OC1A(19) PORTD_PD5  pin Output*/
#define TC1_PIN_OC1B	PORTD_PD4 /*!< This is OC1B(18) PORTD_PD4  pin Output*/
#define TC1_PIN_ICP1	PORTD_PD6 /*!< This is ICP1(20) PORTD_PD6  pin Input */
#define TC1_PIN_T1		PORTB_PB1 /*!< This is T1(2)	PORTD_PB1  pin Input */
/** 
  * @#define          
  * @brief      These macros are used for Counter.  
  */  
//#define TC1_C1							(uint8_t)4 /*!< This is Counter(2) Channel */

/** 
  * @#define          
  * @brief      These macros are used for InputCapture to select input Edge and Noise
  *				Canceler in register  TCCR1B[7:6] ICNC1:ICES1
  */  
#define TC1_TCCR1B_ICES1	 ((uint8_t)0x01 << 6)
#define TC1_TCCR1B_ICNC1	 ((uint8_t)0x01 << 7)

#define TC1_INPUT_CAPTURE_RISING_EDGE			(uint8_t) 1
#define	TC1_INPUT_CAPTURE_FALLING_EDGE			(uint8_t) 0
 /** 
  * @#define          
  * @brief      These macros Configure the Clock bits in TCCR1B[2:0] register CS12:CS11:CS10
  */  
 #define TC1_TCCR1B_CS10		 ((uint8_t)0x01 << 0)
 #define TC1_TCCR1B_CS11		 ((uint8_t)0x01 << 1)
 #define TC1_TCCR1B_CS12		 ((uint8_t)0x01 << 2)
 
#define TC1_STOP							(uint8_t)1  
#define TC1_CLK_DIRECT_NO_PRESCALAR			(uint8_t)2  	  
#define TC1_CLK_IO_BY_8						(uint8_t)3  
#define TC1_CLK_IO_BY_64					(uint8_t)4  
#define TC1_CLK_IO_BY_256					(uint8_t)5  
#define TC1_CLK_IO_BY_1024					(uint8_t)6 
#define TC1_CLK_FALLING_EDGE_ON_T1_PIN		(uint8_t)7 
#define TC1_CLK_RISING_EDGE_ON_T1_PIN		(uint8_t)8 
 /** 
  * @#define          
  * @brief      These macros Configure the Waveform bits in TCCR1A[1:0] register WGM11:WGM10
  *				and in TCCR1B[4:3] register WGM13:WGM12
  *				These are the  five main Modes of the Module.In each mode TCNT1 count up to TOP value.After TOP value is 
  *				reached in mode TCNT1 reset to 0x0000
  *				Following Macro define TOP value. 
  *				 MODES									TOP VALUE
  *				--------------------------------------------------------
  *				[1] Normal(timer)						TC1_TOP_0XFFFF	
  *				[2] CTC ( Clear timer on Compare )		TC1_TOP_OCR1A / TC1_TOP_ICR1	
  *				[3] PWM_FAST							TC1_8BIT_TOP_0X00FF /TC1_9BIT_TOP_0X01FF/TC1_10BIT_TOP_0X03FF/TC1_TOP_OCR1A/TC1_TOP_ICR1					
  *				[4] PWM_PHASE							TC1_8BIT_TOP_0X00FF /TC1_9BIT_TOP_0X01FF/TC1_10BIT_TOP_0X03FF/TC1_TOP_OCR1A/TC1_TOP_ICR1		
  *				[5] PWM_PHASE_FREQUENCY					TC1_TOP_OCR1A / TC1_TOP_ICR1
  */  
 
#define TC1_TCCR1A_WGM10		 ((uint8_t)0x01 << 0)
#define TC1_TCCR1A_WGM11		 ((uint8_t)0x01 << 1) 
#define TC1_TCCR1B_WGM12		 ((uint8_t)0x01 << 3)
#define TC1_TCCR1B_WGM13		 ((uint8_t)0x01 << 4)

/** 
  * @#define          
  * @brief      These macros Configure Compare Match bits in TCCR1A[7:4] register.
  *				COM1A1:COM1A0:COM1B1:COM1B0
  *				This decide the behavior of OC1 pin of the module.
  *				Bits interpretation depends upon in which mode module is configured by 
  *				TCCR1A[1:0] WGM11:WGM10 bits and TCCR1B[4:3] register WGM13:WGM12 bits.
  */  		

#define TC1_TCCR1A_COM1B0		((uint8_t)0x01 << 4)
#define TC1_TCCR1A_COM1B1		((uint8_t)0x01 << 5)
#define TC1_TCCR1A_COM1A0		((uint8_t)0x01 << 6)
#define TC1_TCCR1A_COM1A1		((uint8_t)0x01 << 7)
/** 
  * @#define          
  * @brief       TC1 Interrupt TIMASK[5:2] TICIE1: OCIE1A: OCIE1B: TOIE1	
  */  
#define TC1_TIMASK_TOIE1		 ((uint8_t)0x01 << 2)
#define TC1_TIMASK_OCIE1B		 ((uint8_t)0x01 << 3)
#define TC1_TIMASK_OCIE1A		 ((uint8_t)0x01 << 4)
#define TC1_TIMASK_TICIE1		 ((uint8_t)0x01 << 5)

/* Top Value Macro */
#define TC1_TOP_0XFFFF								(uint8_t)9
#define TC1_TOP_ICR1								(uint8_t)10
#define TC1_TOP_OCR1A								(uint8_t)11
#define TC1_8BIT_TOP_0X00FF							(uint8_t)12
#define TC1_9BIT_TOP_0X01FF							(uint8_t)13
#define TC1_10BIT_TOP_0X03FF						(uint8_t)14
/* Pin Mode Macros */
#define TC1_PIN_DISCONNECTED									(uint8_t)16
#define TC1_PIN_TOGGLE_ON_MATCH									(uint8_t)17
#define TC1_PIN_CLEAR_ON_MATCH									(uint8_t)18
#define TC1_PIN_SET_ON_MATCH									(uint8_t)19
#define TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP						(uint8_t)20
#define TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP						(uint8_t)21
#define TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED			(uint8_t)22
#define TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING			(uint8_t)23
#define TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING			(uint8_t)24

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


/* Function Related to Different Modes*/
void	TC1_ClearTimerOnCompareMode(uint8_t u8CTCTop);
void	TC1_ClearTimerOnComparePinMode(uint8_t u8Pin,uint8_t  u8CTCPinMode);

void	TC1_FastPwmMode(uint8_t u8FastPwmTop);
void	TC1_FastPwmPinMode(uint8_t u8Pin,uint8_t  u8FastPwmPinMode);

void	TC1_PwmPhaseMode(uint8_t u8PwmPhaseTop);
void	TC1_PwmPhasePinMode(uint8_t u8Pin,uint8_t  u8PwmPhasePinMode);

void	TC1_PwmPhaseFrequencyMode(uint8_t u8PwmPhaseFrequencyTop);
void	TC1_PwmPhaseFrequencyPinMode(uint8_t u8Pin,uint8_t  u8PwmPhaseFrequencyPinMode);

void    TC1_TimerMode(uint8_t u8TimerMode);
void    TC1_SetCounterModeEdge(uint8_t u8CounterEdge);

void    TC1_SetInputCapturePin(uint8_t u8CapturePin);
void    TC1_SetInputCaptureEdge(uint8_t u8CaptureEdge); 

/*  Function Related to TIME_REG and COMPARE_REG and CAPTURE_REG */
void		TC1_SetTimerReg(uint16_t u16Count);
uint16_t	TC1_GetTimerReg(void);
void		TC1_SetCompareReg(uint8_t u8CompReg, uint16_t u16Value);
uint16_t	TC1_GetCaptureReg(void);
 
/*  Function Related to TC1 Timer Clock Resolution*/
void	TC1_StopClock(void);
void	TC1_StartClock(void);
void	TC1_SetClockPrescalar(uint8_t u8Prescalar);
void	TC1_SetClockResolution_P125USEC_8MHZ(void);
void	TC1_SetClockResolution_1USEC_8MHZ(void);
void	TC1_SetClockResolution_8USEC_8MHZ(void);
void	TC1_SetClockResolution_32USEC_8MHZ(void);
void	TC1_SetClockResolution_128USEC_8MHZ(void);

void	TC1_SetClockResolution_P0625USEC_16MHZ(void);
void	TC1_SetClockResolution_P5USEC_16MHZ(void);
void	TC1_SetClockResolution_4USEC_16MHZ(void);
void    TC1_SetClockResolution_16USEC_16MHZ(void);
void	TC1_SetClockResolution_64USEC_16MHZ(void);


/* Function Related to TC1 Module Interrupt*/
void	TC1_EnableTimerInterrupt(void);
void	TC1_DisableTimerInterrupt(void);
void	TC1_EnableCompareInterrupt(uint8_t u8Channel);
void	TC1_DisableCompareInterrupt(uint8_t u8Channel);
void	TC1_EnableInputCaptureInterrupt(void);
void	TC1_DisableInputCaptureInterrupt(void);

/* Function for Registering  Interrupt Service Routine*/ 
void	TC1_RegisterTimerInterruptService(fpointerv_t  fun , uint8_t param);
void	TC1_RegisterCompareAInterruptService(fpointerv_t  fun,uint8_t param);	
void	TC1_RegisterCompareBInterruptService(fpointerv_t  fun,uint8_t param);
void	TC1_RegisterInputCaptureInterruptService(fpointerv_t  fun,uint8_t param);

void	TC1_DummyInterrupt(uint8_t dummy);


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