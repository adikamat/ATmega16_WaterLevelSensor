/**
  ******************************************************************************
  * @file    Source file name.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    23-Dec-2020
  * @brief   All interrupt Service routine Defined Here.
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
#include <avr/io.h>

#include "System.h" 
#include "ATmega16_TC1.h"
#include "ATmega16_Int.h"
#include "PulseOut.h"
/** 
  * @brief  Application specific header  
  */

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
  * @}
  */   
  
/** @addtogroup variable declaration 
  * @{
  */ 
/* Function Pointer to Interrupt Service routine */
fpointerv_t ISR_FPTR[NO_OF_INT_VECT];
/*Function Pointer Parameter array*/
uint8_t  u8IntParam [NO_OF_INT_VECT];    /* Int parameter */

    
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
  
/**	
  * @brief				Interrupt Service routine for External INT0		
  * @PreCondition		None
  * @PostCondition		None  
  * @param				INT0_vect
  * @description		None
  * @retval				None
  */
void INT0_vect(void)__attribute__((interrupt));
void INT0_vect(void)
{ 
   /* Call Interrupt Handler */
   ISR_FPTR[INT0_VECT_NO](u8IntParam[INT0_VECT_NO]);
}

/** 		
  * @brief				Interrupt Service routine for External INT1		
  * @PreCondition		None
  * @PostCondition		None  
  * @param				INT1_vect
  * @description		None
  * @retval				None
  */
void INT1_vect(void)__attribute__((interrupt));
void INT1_vect(void)
{
	/* Call Interrupt Handler */
	ISR_FPTR[INT1_VECT_NO](u8IntParam[INT1_VECT_NO]);
}

/** 	 		
  * @brief				Interrupt Service routine for External INT2		
  * @PreCondition		None
  * @PostCondition		None  
  * @param				INT2_vect
  * @description		None
  * @retval				None
  */
void INT2_vect(void) __attribute__((interrupt));
void INT2_vect(void)
{	
  /* Call Interrupt Handler */
  ISR_FPTR[INT2_VECT_NO](u8IntParam[INT2_VECT_NO]);
}

/** 	
  * @brief				Interrupt Service routine for Timer0 Overflow 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER0_OVF_vect
  * @description		None
  * @retval				None
  */
void TIMER0_OVF_vect(void) __attribute__((interrupt));
void TIMER0_OVF_vect(void)
{
	 /* Call Interrupt Handler */
   ISR_FPTR[TIMER0_OVF_VECT_NO](u8IntParam[TIMER0_OVF_VECT_NO]);
}

/** 	 		
  * @brief				Interrupt Service routine for Timer0 Compare 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER0_COMP_vect
  * @description		None
  * @retval				None
  */

void TIMER0_COMP_vect(void) __attribute__((interrupt));
void TIMER0_COMP_vect(void)
{
   /* Call Interrupt Handler */
   ISR_FPTR[TIMER0_COMP_VECT_NO](u8IntParam[TIMER0_COMP_VECT_NO]);
}

/** 		
  * @brief				Interrupt Service routine for Timer1 Overflow 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER1_OVF_vect
  * @description		None
  * @retval				None
  */
void TIMER1_OVF_vect(void) __attribute__((interrupt));
void TIMER1_OVF_vect(void)
{   
	 	/* Call Interrupt Handler */
		ISR_FPTR[TIMER1_OVF_VECT_NO](u8IntParam[TIMER1_OVF_VECT_NO]);
}

/** 	
  * @brief				Interrupt Service routine for Timer1 Compare B  	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER1_COMPB_vect
  * @description		None
  * @retval				None
  */
void TIMER1_COMPB_vect(void) __attribute__((interrupt));
void TIMER1_COMPB_vect(void)
{
	  /* Call Interrupt Handler */
  	  ISR_FPTR[TIMER1_COMPB_VECT_NO](u8IntParam[TIMER1_COMPB_VECT_NO]);
}

/**	
  * @brief				Interrupt Service routine for Timer1 Compare A  	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER1_COMPA_vect
  * @description		None
  * @retval				None
  */
void TIMER1_COMPA_vect(void) __attribute__((interrupt));
void TIMER1_COMPA_vect(void)
{
	  /* Call Interrupt Handler */
  ISR_FPTR[TIMER1_COMPA_VECT_NO](u8IntParam[TIMER1_COMPA_VECT_NO]);
}

/** 		
  * @brief				Interrupt Service routine for Timer1 Capture  	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER1_CAPT_vect
  * @description		None
  * @retval				None
  */

void TIMER1_CAPT_vect(void) __attribute__((interrupt));
void TIMER1_CAPT_vect(void)
{
	 /* Call Interrupt Handler */
	 ISR_FPTR[TIMER1_CAPT_VECT_NO](u8IntParam[TIMER1_CAPT_VECT_NO]);
}

/**  		
  * @brief				Interrupt Service routine for Timer2 Compare 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER2_COMP_vect
  * @description		None
  * @retval				None
  */

void TIMER2_COMP_vect(void) __attribute__((interrupt));
void TIMER2_COMP_vect(void)
{
  /* Call Interrupt Handler */
  ISR_FPTR[TIMER2_COMP_VECT_NO](u8IntParam[TIMER2_COMP_VECT_NO]);
}

/** 		
  * @brief				Interrupt Service routine for Timer2 OverFlow 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TIMER2_OVF_vect
  * @description		None
  * @retval				None
  */
void TIMER2_OVF_vect(void) __attribute__((interrupt));
void TIMER2_OVF_vect(void)
{
	   /* Call Interrupt Handler */
   ISR_FPTR[TIMER2_OVF_VECT_NO](u8IntParam[TIMER2_OVF_VECT_NO]);
}

/** 	
  * @brief				Interrupt Service routine for SPI STC 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				SPI_STC_vect
  * @description		None
  * @retval				None
  */
void SPI_STC_vect(void) __attribute__((interrupt));
void SPI_STC_vect(void)
{
	  /* Call Interrupt Handler */
    ISR_FPTR[SPI_STC_VECT_NO](u8IntParam[SPI_STC_VECT_NO]);
}

/** 	
  * @brief				Interrupt Service routine for USART Rx 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				USART0_RX_vect
  * @description		None
  * @retval				None
  */
void USART_RXC_vect(void) __attribute__((interrupt));
void USART_RXC_vect(void)
{
    /* Call Interrupt Handler */
    ISR_FPTR[USART_RX_VECT_NO](u8IntParam[USART_RX_VECT_NO]);
}

/** 
  * @brief				Interrupt Service routine for USART Tx 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				USART0_TX_vect
  * @description		None
  * @retval				None
  */
void USART_TXC_vect(void) __attribute__((interrupt));
void USART_TXC_vect(void)
{
  /* Call Interrupt Handler */
  ISR_FPTR[USART_TX_VECT_NO](u8IntParam[USART_TX_VECT_NO]);
}

/** 	
  * @brief				Interrupt Service routine for USART UDRE 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				USART0_UDRE_vect
  * @description		None
  * @retval				None
  */
void USART_UDRE_vect(void) __attribute__((interrupt));
void USART_UDRE_vect(void)
{
  /* Call Interrupt Handler */
  ISR_FPTR[USART_UDRE_VECT_NO](u8IntParam[USART_UDRE_VECT_NO]);	
}


/**  		
  * @brief				Interrupt Service routine for ADC 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				ADC_vect
  * @description		None
  * @retval				None
  */
void ADC_vect(void) __attribute__((interrupt));
void ADC_vect(void)
{
	/* Call Interrupt Handler */
    ISR_FPTR[ADC_VECT_NO](u8IntParam[ADC_VECT_NO]);
}

/**  		
  * @brief				Interrupt Service routine for EEPROM 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				EE_RDY_vect
  * @description		None
  * @retval				None
  */
void EE_RDY_vect(void) __attribute__((interrupt));
void EE_RDY_vect(void) 
{
	/* Call Interrupt Handler */
  ISR_FPTR[EE_RDY_VECT_NO](u8IntParam[EE_RDY_VECT_NO]);
}


/** 	
  * @brief				Interrupt Service routine for Analog Comparator 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				ANALOG_COMP_vect
  * @description		None
  * @retval				None
  */
void ANA_COMP_vect(void) __attribute__((interrupt));
void ANA_COMP_vect(void)
{
	 /* Call Interrupt Handler */
   ISR_FPTR[ANALOG_COMP_VECT_NO](u8IntParam[ANALOG_COMP_VECT_NO]);
}

/**	
  * @brief				Interrupt Service routine for I2C TWI 	
  * @PreCondition		None
  * @PostCondition		None  
  * @param				TWI_vect
  * @description		None
  * @retval				None
  */
void TWI_vect(void) __attribute__((interrupt));
void TWI_vect(void)
{
	    /* Call Interrupt Handler */
    ISR_FPTR[TWI_VECT_NO](u8IntParam[TWI_VECT_NO]);
}



/**
  * @}
 */

