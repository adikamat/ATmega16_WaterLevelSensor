/**
  ******************************************************************************
  * @file    ATmega16_Int.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    02-Nov-2020
  * @brief   Header file for ATmega16 Interrupt .
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
#ifndef  ATMEGA16_INT_H
#define  ATMEGA16_INT_H

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
  
/** @addtogroup Struct/Union 
  * @{
  */ 
  
  /**
  * @}
  */  
  
/** @defgroup  #define Macros 
  * @{
  */
#define RESET_VECT_NO			1			
/* External Interrupts */ 
#define INT0_VECT_NO			2			
#define INT1_VECT_NO			3			
#define INT2_VECT_NO			4			
/* Timer0 Interrupts */ 
#define TIMER0_OVF_VECT_NO		5	
#define TIMER0_COMP_VECT_NO		6
/*  Timer1 Interrupts */ 
#define TIMER1_OVF_VECT_NO		7		
#define TIMER1_COMPB_VECT_NO	8		
#define TIMER1_COMPA_VECT_NO	9			
#define TIMER1_CAPT_VECT_NO		10	
 /*Timer2 Interrupts */
#define TIMER2_COMP_VECT_NO		11
#define TIMER2_OVF_VECT_NO		12
/* SPI Interrupts */
#define SPI_STC_VECT_NO			13	
/* USART Interrupts */
#define USART_RX_VECT_NO		14
#define USART_TX_VECT_NO		15
#define USART_UDRE_VECT_NO		16
/*ADC Interrupts */
#define ADC_VECT_NO				17
/* EEPROM Interrupts */
#define EE_RDY_VECT_NO			18
/* Analog Compare Interrupts */
#define ANALOG_COMP_VECT_NO		19
/*   I2C  Interrupts */
#define TWI_VECT_NO				20

#define NO_OF_INT_VECT         20

extern  fpointerv_t ISR_FPTR[NO_OF_INT_VECT];

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