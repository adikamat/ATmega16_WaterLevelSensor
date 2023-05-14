/**
  ******************************************************************************
  * @file    Usart.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    23-Aug-2020
  * @brief   Header file for USART Module.
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
#ifndef  _ATMEGA16_USART_H
#define  _ATMEGA16_USART_H

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
#include "Usart_Config.h"
/**
  * @}
  */
  
/** @addtogroup Struct/Union 
  * @{
  */ 
  
typedef struct{
uint8_t Mode;
uint8_t DataBits;
uint8_t StopBits;
uint8_t Parity;
uint8_t	BaudRate;
uint8_t ClockPolarity;  
 } sUsart_t;
  /**
  * @}
  */  
  
/** @defgroup  #define Macros 
  * @{
  */

  /** 
  * @#define          
  * @brief      These macros are used for UCSRA register.
  *			   BITS:	RXC | TXC| UDRE| FE| DOR| PE| U2X| MPCM
  *				
  */  
 #define USART_UCSRA_MPCM		(((uint8_t)0x01 << 0)) 
 #define USART_UCSRA_MPCM_BIT    0
 #define USART_UCSRA_U2X 		(((uint8_t)0x01 << 1))
 #define USART_UCSRA_U2X_BIT 	 1 
 #define USART_UCSRA_PE			(((uint8_t)0x01 << 2)) 
 #define USART_UCSRA_PE_BIT      2
 #define USART_UCSRA_DOR		(((uint8_t)0x01 << 3)) 
 #define USART_UCSRA_DOR_BIT     3
 #define USART_UCSRA_FE			(((uint8_t)0x01 << 4)) 
 #define USART_UCSRA_FE_BIT      4	
 #define USART_UCSRA_UDRE		(((uint8_t)0x01 << 5)) 
 #define USART_UCSRA_UDRE_BIT    5
 #define USART_UCSRA_TXC		(((uint8_t)0x01 << 6)) 
 #define USART_UCSRA_TXC_BIT     6
 #define USART_UCSRA_RXC		(((uint8_t)0x01 << 7)) 
 #define USART_UCSRA_RXC_BIT     7
 
  /** 
  * @#define          
  * @brief      These macros are used for UCSRB register.
  *			   BITS:	RXCIE|TXCIE|UDRIE|RXEN|TXEN|UCSZ2|RXB8| TXB8
  *				
  */  
  #define USART_UCSRB_TXB8		(((uint8_t)0x01 << 0))
  #define USART_UCSRB_RXB8 		(((uint8_t)0x01 << 1))
  #define USART_UCSRB_UCSZ2		(((uint8_t)0x01 << 2))
  #define USART_UCSRB_TXEN		(((uint8_t)0x01 << 3))
  #define USART_UCSRB_RXEN		(((uint8_t)0x01 << 4))
  #define USART_UCSRB_UDREIE	(((uint8_t)0x01 << 5))
  #define USART_UCSRB_TXCIE		(((uint8_t)0x01 << 6))
  #define USART_UCSRB_RXCIE		(((uint8_t)0x01 << 7))
  
  
  /** 
  * @#define          
  * @brief      These macros are used for UCSRC register.
  *			   BITS:	URSEL| UMSEL| UPM1| UPM0| USBS| UCSZ1| UCSZ0| UCPOL
  *				
  */  
  
  #define USART_UCSRC_UCPOL		(((uint8_t)0x01 << 0))
  #define USART_UCSRC_UCSZ0 	(((uint8_t)0x01 << 1))
  #define USART_UCSRC_UCSZ1		(((uint8_t)0x01 << 2))
  #define USART_UCSRC_USBS		(((uint8_t)0x01 << 3))
  #define USART_UCSRC_UPM0		(((uint8_t)0x01 << 4))
  #define USART_UCSRC_UPM1		(((uint8_t)0x01 << 5))
  #define USART_UCSRC_UMSEL		(((uint8_t)0x01 << 6))
  #define USART_UCSRC_URSEL		((0x01 << 7))
  
 /* Macro for  Usart modes  */
 
 #define  ASYNCHRONOUS_NORMAL	(uint8_t)0x01 
 #define  ASYNCHRONOUS_DOUBLE   (uint8_t)0x02 
 #define  SYNCHRONOUS    (uint8_t)0x03
 
 
/* Macro for  Parity  */

#define  NO_PARITY				(uint8_t)0x01
#define  EVEN_PARITY			(uint8_t)0x02 
#define  ODD_PARITY				(uint8_t)0x03


/* Macro for  Data bits  */
  
 #define  _5_DATA_BIT			(uint8_t)0x01 
 #define  _6_DATA_BIT			(uint8_t)0x02
 #define  _7_DATA_BIT			(uint8_t)0x03
 #define  _8_DATA_BIT			(uint8_t)0x04
 #define  _9_DATA_BIT			(uint8_t)0x05
 
 /* Macros for Stop Bits */
 #define  ONE_STOP_BIT			(uint8_t)0x01
 #define  TWO_STOP_BIT			(uint8_t)0x02
 
 /* Macro for baud  Rate P stand for point*/
 #define   _2400_BAUD			(uint8_t)1
 #define   _4800_BAUD			(uint8_t)2
 #define   _9600_BAUD			(uint8_t)3
 #define   _14_P_4K_BAUD		(uint8_t)4
 #define   _19_P_2K_BAUD		(uint8_t)5
 #define   _28_P_8K_BAUD		(uint8_t)6
 #define   _57_P_6K_BAUD		(uint8_t)7
 #define   _76_P_8K_BAUD		(uint8_t)8
 #define   _115_P_2K_BAUD		(uint8_t)9
 #define   _230_P_4K_BAUD		(uint8_t)10	
 #define   _250K_BAUD			(uint8_t)11	
 
 /* Macros for synchronous mode polarity use when mode is synchronous */
 #define  TX_DATACHANGED_RISING_RX_SAMPLE_FALLING	 (uint8_t)0x01
 #define  RX_DATACHANGED_FALLING_RX_SAMPLE_RISING   (uint8_t)0x02
 
 /* Error Codes */
 #define NO_ERROR					(int8_t)1
 #define DATA_RECEIVED              (int8_t)2
 #define NO_DATA_RECEIVED           (int8_t)3 
 #define FRAME_ERROR				(int8_t)-1
 #define PARITY_ERROR				(int8_t)-2
 #define DATA_OVERRUN_ERROR			(int8_t)-3
  
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
extern sUsart_t  Usart;

/* Short Name for Usart Structure*/

#define u8Mode			Usart.Mode
#define u8DataBits		Usart.DataBits
#define u8StopBits		Usart.StopBits
#define u8Parity		Usart.Parity
#define u8BaudRate		Usart.BaudRate
#define u8ClockPolarity	Usart.ClockPolarity


/**
  * @}
  */   

/* Inline function */ 
void   Usart_Tx_Module_Enable(void);
void  Usart_Rx_Module_Enable(void);
void  Usart_Tx_Module_Disable(void);
void  Usart_Rx_Module_Disbale(void) ;
void  Usart_Tx_Interrupt_Enable(void) ;
void  Usart_Rx_Interrupt_Enable(void);
void  Usart_DataRegEmpty_Interrupt_Enable(void);
void Usart_Tx_Interrupt_Disable(void) ;
void  Usart_Rx_Interrupt_Disable(void);
void  Usart_DataRegEmpty_Interrupt_Disable(void) ;
uint8_t Usart_IsReceiveComplete(void);
uint8_t  Usart_IsTransmitComplete(void) ;
uint8_t  Usart_IsDataRegEmpty(void);
uint8_t  Usart_IsFrameError(void) ;
uint8_t Usart_IsParityError(void) ;
uint8_t  Usart_IsDataOverRunError(void);
void  Usart_DoubleTxSpeedEnable(void);
void  Usart_DoubleTxSpeedDisbale(void);
void  Usart_MultiprocessorComEnable(void);
void  Usart_MultiprocessorComDisbale(void);
 /* Usart Initialization function*/
void Usart_InitStructure(void );
void Usart_Init(void);
void  Usart_InitSfr(void);
void  Usart_InitTxBuffer(void);
void  Usart_InitRxBuffer(void);
/*Usart Tx Rx function */
void Usart_Transmit(char  TX_Buffer[]);
int8_t Usart_Receive(char Rx_Buffer[]);
/* Set/Get Methods for  Structure*/
void Usart_SetMode(uint8_t mode);
void Usart_SetDataBits(uint8_t noOfDataBits);
void Usart_SetStopBits(uint8_t noOfStopBits);
void Usart_SetParity(uint8_t parity);
void Usart_SetBaudRate(uint8_t baudRate);
void Usart_SetClockPolarity(uint8_t polarity);
uint8_t Usart_GetMode(void);
uint8_t Usart_GetDataBits(void);
uint8_t Usart_GetStopBits(void);
uint8_t Usart_GetParity(void);
uint8_t Usart_GetBaudRate(void);
uint8_t Usart_GetClockPolarity(void);
/* Register Interrupt Functions */
void Usart_RegisterTxInterruptService(fpointerv_t  fun , uint8_t param);
void Usart_RegisterRxInterruptService(fpointerv_t  fun , uint8_t param);
void Usart_RegisterDataRegEmptyInterruptService(fpointerv_t  fun , uint8_t param);
/* Usart Interrupt Service routines */
void Usart_Tx_InterruptService(void);
void Usart_Rx_InterruptService(void);
void Usart_DataRegEmptyInterruptService(void);

#endif