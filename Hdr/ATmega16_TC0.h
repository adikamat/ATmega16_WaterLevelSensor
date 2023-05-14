 /**
  ******************************************************************************
  * @file    TC0.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020
  * @brief   Driver for Timer/Counter0
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
#ifndef  _TC0_H
#define  _TC0_H

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
  * @brief      These macros are used as OuputCompare Channel 
  */  
#define TC0_PIN_OC0					(uint8_t)1		/*!< This is Output Compare (4) pin */

/** 
  * @#define          
  * @brief      These macros are used for TC0 Module Registers  
  */  
#define TC1_OCR0_REG								(uint8_t)1

 
 
 /** 
  * @#define          
  * @brief      These macros Configure the Clock bits in TCCR0[2:0] register CS02:CS01:CS00
  */  
 #define TC0_TCCR0_CS00		 ((uint8_t)0x01 << 0)
 #define TC0_TCCR0_CS01		 ((uint8_t)0x01 << 1)
 #define TC0_TCCR0_CS02		 ((uint8_t)0x01 << 2)
 
#define TC0_STOP							(uint8_t)1 
#define TC0_CLK_DIRECT_NO_PRESCALAR			(uint8_t)2  	  
#define TC0_CLK_IO_BY_8						(uint8_t)3	
#define TC0_CLK_IO_BY_64					(uint8_t)4	
#define TC0_CLK_IO_BY_256					(uint8_t)5	
#define TC0_CLK_IO_BY_1024					(uint8_t)6	
#define TC0_FALLING_EDGE_ON_T0_PIN			(uint8_t)7    
#define TC0_RISING_EDGE_ON_T0_PIN			(uint8_t)8    
/** 
  * @#define          
  * @brief      These macros Configure the Waveform bits in TCCR0[6:3] register WGM00:WGM01
  *				These are the main Modes of the Module. 1] Normal(timer) [2] PWM_PHASE
  *				[3] CTC ( Clear timer on Compare ) [4] PWM_FAST
  *				In TOP_x x shows Maximum Value of count sequence of TCNT0 counter.After that
  *				TCNT0 reset to 0x00(BOTTOM).  
  */  
#define TC0_TCCR0_WGM00						((uint8_t)0x01 << 6)		    
#define TC0_TCCR0_WGM01						((uint8_t)0x01 << 3)	

#define TC0_TOP_0XFF			(uint8_t)1
#define TC0_TOP_OCR0			(uint8_t)2

/** 
  * @#define          
  * @brief      These macros Configure Compare Match bits in TCCR0[5:4] register COM01:COM00.
  *				This decide the behavior of OC0 pin of the module.
  *				Bits interpretation depends upon in which mode module is configured by TCCR0[6:3] bits.
  *				Use following macro When Module is configure in NON_PWM means either in Normal(timer)
  *				or CTC ( Clear Timer on Compare) mode 
  */  

#define TC0_TCCR0_COM00		 ((uint8_t)0x01 << 4)
#define TC0_TCCR0_COM01		 ((uint8_t)0x01 << 5)


#define TC0_OC0_PIN_DISCONNECTED						(uint8_t)5 
#define TC0_OC0_PIN_TOGGLE_ON_MATCH						(uint8_t)6
#define TC0_OC0_PIN_CLEAR_ON_MATCH						(uint8_t)7
#define TC0_OC0_PIN_SET_ON_MATCH						(uint8_t)8
#define TC0_OC0_PIN_CLEAR_ON_MATCH_SET_ON_TOP			(uint8_t)10
#define TC0_OC0_PIN_SET_ON_MATCH_CLEAR_ON_TOP			(uint8_t)11
#define TC0_OC0_PIN_CLEAR_UPCOUNTING_SET_DOWNCOUNTING	(uint8_t)13
#define TC0_OC0_PIN_SET_UPCOUNTING_CLEAR_DOWNCOUNTING	(uint8_t)14


/** 
  * @#define          
  * @brief       TC0 Interrupt TIMASK[1:0] OCIE0 : TOIE0	
  */  
#define TC0_TIMASK_TOIE0		 ((uint8_t)0x01 << 0)
#define TC0_TIMASK_OCIE0		 ((uint8_t)0x01 << 1)

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
  
/** @defgroup  typedef Module specific  
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
void    TC0_SetClearTimerOnCompareMode(uint8_t u8CTCTop);
void	TC0_SetClearTimerOnComparePinMode(uint8_t u8Pin,uint8_t  u8CTCPinMode);

void	TC0_SetFastPwmMode(uint8_t u8FastPwmTop);
void	TC0_SetFastPwmPinMode(uint8_t u8Pin,uint8_t  u8FastPwmPinMode);

void	TC0_SetPwmPhaseMode(uint8_t u8PwmPhaseTop);
void	TC0_SetPwmPhasePinMode(uint8_t u8Pin,uint8_t  u8PwmPhasePinMode);

void    TC0_SetTimerMode(uint8_t Mode);
void	TC0_SetCounterEdge(uint8_t Edge);

/*  Function Related to TIME_REG and COMPARE_REG */
void	TC0_SetTimerReg(uint8_t count);
void	TC0_SetCompareReg(uint8_t Value);

/*  Function Related to TC0 Timer Clock*/
void TC0_StartTimer(void);
void TC0_StopTimer(void);

/*  Function Related to TC0 Timer Clock Resolution 8 Mhz Crystal*/
void TC0_SetClockResolution_P125USEC_8MHZ(void);
void TC0_SetClockResolution_1USEC_8MHZ(void);
void TC0_SetClockResolution_8USEC_8MHZ(void);
void TC0_SetClockResolution_32USEC_8MHZ(void);
void TC0_SetClockResolution_128USEC_8MHZ(void);
/*  Function Related to TC0 Timer Clock Resolution 16 Mhz Crystal*/
void TC0_SetClockResolution_P0625USEC_16MHZ(void);
void TC0_SetClockResolution_P5USEC_16MHZ(void);
void TC0_SetClockResolution_4USEC_16MHZ(void);
void TC0_SetClockResolution_16USEC_16MHZ(void);
void TC0_SetClockResolution_64USEC_16MHZ(void);




/* Function Related to TC0 Module Interrupt*/
void TC0_EnableTimerInterrupt(void);
void TC0_DisableTimerInterrupt(void);

void TC0_EnableCompareInterrupt(void);
void TC0_DisableCompareInterrupt(void);

/* Interrupt SericeRoutine */
void TC0_RegisterTimerInterruptService(fpointerv_t  fun , uint8_t param);
void TC0_RegisterCompareInterruptService(fpointerv_t  fun, uint8_t param);

/**
  * @}
  */


/** @addtogroup External variables 
  * @{
  */ 
  
/**
  * @}
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