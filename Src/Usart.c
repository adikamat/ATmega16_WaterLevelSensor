/**
  ******************************************************************************
  * @file    Usart.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    23-Aug-2022
  * @brief   This file provides all the USART firmware functions.
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
  #include "Usart.h"
/** 
  * @brief  system header  
  */


/** 
  * @brief  Application specific header  
  */

/**
  * @}
  */
 
/** @addtogroup Struct/Union definition 
  * @{
  */ 
  
 sUsart_t  Usart;
 
/**
  * @}
  */   

  /** @addtogroup variable declaration 
  * @{
  */ 
  char  Tx_Buffer[TX_BUFFER_SIZE];
  char  Rx_Buffer[RX_BUFFER_SIZE];
/**
  * @}
  */    

/** @addtogroup static variable 
  * @{
  */ 
  
/**
  * @}
  */   

  
/** @defgroup  #define Macros
  * @{
  */
/**
  * @}
  */
  
/** @defgroup  Function Macros 
  * @{
  */
// FTEST: All inline  function   PENDING

 /* Tx Rx Module Enable Disable function Macro*/

inline __attribute__((always_inline)) void   Usart_Tx_Module_Enable(void) 
 {
	 UCSRB |=  USART_UCSRB_TXEN	;
 }
inline __attribute__((always_inline)) void  Usart_Rx_Module_Enable(void) 
 {
	 UCSRB |= USART_UCSRB_RXEN ;
 }
inline __attribute__((always_inline)) void  Usart_Tx_Module_Disable(void) 
 {
	 UCSRB &= ~( USART_UCSRB_TXEN)	;
 }
inline __attribute__((always_inline)) void  Usart_Rx_Module_Disbale(void) 
 {
	 UCSRB &= ~(USART_UCSRB_RXEN );
 }
 /* Tx Rx Interrupt Enable Disable function Macro*/
inline __attribute__((always_inline)) void  Usart_Tx_Interrupt_Enable(void) 
 {
	 UCSRB |= USART_UCSRB_TXCIE ;
 }
inline __attribute__((always_inline)) void  Usart_Rx_Interrupt_Enable(void) 
 {
	 UCSRB |= USART_UCSRB_RXCIE ;
 }
inline __attribute__((always_inline)) void  Usart_DataRegEmpty_Interrupt_Enable(void)
{
	UCSRB |= USART_UCSRB_UDREIE ;
}
 inline __attribute__((always_inline)) void Usart_Tx_Interrupt_Disable(void) 
 {
	UCSRB &= ~(USART_UCSRB_TXCIE) ;
 }
inline __attribute__((always_inline)) void  Usart_Rx_Interrupt_Disable(void) 
 {
	 UCSRB &= ~(USART_UCSRB_RXCIE) ;
 }
inline __attribute__((always_inline)) void  Usart_DataRegEmpty_Interrupt_Disable(void) 
 {
	 UCSRB &= ~(USART_UCSRB_UDREIE) ;
 }


 /* Receive Transmit  Detection flag function Macro*/
 inline __attribute__((always_inline)) uint8_t Usart_IsReceiveComplete(void) 
 { uint8_t status = FALSE;
	 
	if(ISBITSET(UCSRA ,USART_UCSRA_RXC_BIT))
	 status = TRUE;
	 
	 return(status);
 }
inline __attribute__((always_inline)) uint8_t  Usart_IsTransmitComplete(void) 
 {uint8_t status = FALSE;
	 
	 if(ISBITSET(UCSRA ,USART_UCSRA_TXC_BIT))
	 status = TRUE;
	 
	 return(status);
 }
inline __attribute__((always_inline)) uint8_t  Usart_IsDataRegEmpty(void) 
 {uint8_t status = FALSE;
	 
	 if(ISBITSET(UCSRA ,USART_UCSRA_UDRE_BIT))
	 status = TRUE;
	 
	 return(status);
 }
 /* Error Detection  function Macro*/
inline __attribute__((always_inline)) uint8_t  Usart_IsFrameError(void) 
 {uint8_t status = FALSE;
	 
	 if(ISBITSET(UCSRA ,USART_UCSRA_FE_BIT))
	 status = TRUE;
	 
	 return(status);
 }
inline __attribute__((always_inline)) uint8_t Usart_IsParityError(void) 
 {uint8_t status = FALSE;
	 
	 if(ISBITSET(UCSRA ,USART_UCSRA_PE_BIT ))
	 status = TRUE;
	 
	 return(status);
 }
inline __attribute__((always_inline)) uint8_t  Usart_IsDataOverRunError(void) 
 {uint8_t status = FALSE;
	 
	 if(ISBITSET(UCSRA ,USART_UCSRA_DOR_BIT ))
	 status = TRUE;
	 
	 return(status);
 }

inline __attribute__((always_inline)) void  Usart_DoubleTxSpeedEnable(void)
{
	UCSRA |= (USART_UCSRA_U2X_BIT) ;
}

inline __attribute__((always_inline)) void  Usart_DoubleTxSpeedDisbale(void)
{
	UCSRA &= ~( USART_UCSRA_U2X_BIT );
}

inline __attribute__((always_inline)) void  Usart_MultiprocessorComEnable(void)
{	
	UCSRA |= (USART_UCSRA_MPCM_BIT) ;
}

inline __attribute__((always_inline)) void  Usart_MultiprocessorComDisbale(void)
{
	
	UCSRA &= ~(USART_UCSRA_MPCM_BIT) ;
}
/**
  * @}
  */
  
/** @addtogroup Enum 
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
  

/** @addtogroup  Static Function Definition 
  * @{
  */ 
  
  /**
  * @}
  */     
  
/** @addtogroup  Module Interface Function Definition 
  * @{
  */
  
 /** @brief			Usart_InitStructure
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
 //FTEST: Usart_InitStructure(void )	PENDING
void Usart_InitStructure(void )
{   /* These are default Values of Structure */
	 u8Mode			= ASYNCHRONOUS_NORMAL;			
	 u8DataBits		=	_8_DATA_BIT;	
	 u8StopBits		=	ONE_STOP_BIT;	
	 u8Parity		=	NO_PARITY;
	 u8BaudRate		=	_9600_BAUD;	
	 u8ClockPolarity =	TX_DATACHANGED_RISING_RX_SAMPLE_FALLING	;
} 
  
/** @brief			Usart_Init
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
//FTEST: Usart_Init(void ) PENDING
void Usart_Init(void)
{ /* Init Structure */
	Usart_InitStructure();
  /* Init SFR based on Init_structure. */
	Usart_InitSfr();
  
 /* Register Interrupts*/
 #if(TX_RX_METHODS == INTERRUPT)
Usart_RegisterTxInterruptService(&Usart_Tx_InterruptService , 0);
Usart_RegisterRxInterruptService(&Usart_Rx_InterruptService , 0);
Usart_RegisterDataRegEmptyInterruptService(&Usart_DataRegEmptyInterruptService,0);

/* Enable Interrupts*/
Usart_Tx_Interrupt_Enable();
Usart_Rx_Interrupt_Enable();
Usart_DataRegEmpty_Interrupt_Enable();
#endif

/* Enable Tx RX Module*/
Usart_Tx_Module_Enable();
Usart_Rx_Module_Enable();

/* Initialize  Tx / RX  Buffers*/
 Usart_InitTxBuffer();
 Usart_InitRxBuffer();

}

/** @brief			Usart_InitTxBuffer
  * @brief			Initialize Tx  buffer 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
void  Usart_InitTxBuffer(void)
{ uint8_t index =0;
	
	for (index=0;index <= TX_BUFFER_SIZE;index++ )
	{
		Tx_Buffer[index] =  '\0';
	}
	
}

/** @brief			Usart_InitRxBuffer
  * @brief			Initialize Rx  buffer 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
void  Usart_InitRxBuffer(void)
{ uint8_t index =0;
	
	for (index=0;index <= RX_BUFFER_SIZE;index++ )
	{
		Rx_Buffer[index] =  '\0';
	}
	
}

/** @brief			Usart_InitSfr
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
//FTEST: Usart_InitSfr(void) PENDING
void  Usart_InitSfr(void)
{/* Initialize SFR according to Usart_inti structure */
/* For  Mode, DatBits,Stop Bit, Parity,ClockPolarity we need to set URSEL =1 to
   have write access to UCSRC Register   */
	 
	 UCSRC |=  USART_UCSRC_URSEL;
	 
	/* Init Mode */
	if(u8Mode ==  ASYNCHRONOUS_NORMAL)
	{
		UCSRC &= ~(USART_UCSRC_UMSEL);
	}
	else if(u8Mode ==  ASYNCHRONOUS_DOUBLE)
	{
		UCSRC &= ~(USART_UCSRC_UMSEL);
		UCSRA |=  (USART_UCSRA_U2X );	
	}
	else if(u8Mode ==  SYNCHRONOUS)
	{
		UCSRC |= (USART_UCSRC_UMSEL); 		
	}
	
	else{}
	
 
	/* Init Data Bit */
	 switch(u8DataBits)
	 {    
		 case _5_DATA_BIT:
		   /* UCSZ2	= 0	UCSZ1 = 0	UCSZ0= 0	*/
				UCSRC  &=	~(USART_UCSRC_UCSZ0);
				UCSRC  &=	~(USART_UCSRC_UCSZ1);		
				UCSRB  &=	~(USART_UCSRB_UCSZ2);		
							break;
		 case _6_DATA_BIT:
		 /* UCSZ2	= 0	UCSZ1 = 0	UCSZ0= 1	*/
			 UCSRC  |=	(USART_UCSRC_UCSZ0);
			 UCSRC  &=	~(USART_UCSRC_UCSZ1);
			 UCSRB  &=	~(USART_UCSRB_UCSZ2);
							break;
		 case _7_DATA_BIT:
		  /* UCSZ2	= 0	UCSZ1 = 1	UCSZ0= 0	*/
			  UCSRC  &=	~(USART_UCSRC_UCSZ0);
			  UCSRC  |=	(USART_UCSRC_UCSZ1);
			  UCSRB  &=	~(USART_UCSRB_UCSZ2);
							break;
		 case _8_DATA_BIT:
		  /* UCSZ2	= 0	UCSZ1 = 1	UCSZ0= 1	*/
			  UCSRC  |=	(USART_UCSRC_UCSZ0);
			  UCSRC  |=	(USART_UCSRC_UCSZ1);
			  UCSRB  &=	~(USART_UCSRB_UCSZ2);
							break;
		 case _9_DATA_BIT:
		  /* UCSZ2	= 1	UCSZ1 = 1	UCSZ0 = 1	*/
			  UCSRC  |=	(USART_UCSRC_UCSZ0);
			  UCSRC  |=	(USART_UCSRC_UCSZ1);
			  UCSRB  |=	(USART_UCSRB_UCSZ2);
							break;
		default:
							break;					
	          
	 }
	
	/* Init Stop Bit */
	if(u8StopBits ==  ONE_STOP_BIT)
	{
		UCSRC &= ~(USART_UCSRC_USBS);
	}
	else if(u8StopBits ==  TWO_STOP_BIT)
	{
		UCSRC |= (USART_UCSRC_USBS);
	}
	else{  }
		
	/* Init Parity */
	if(u8Parity ==  NO_PARITY)
	{  /*	UPM1 = 0		UPM0 = 0 */
		UCSRC  &=  ~(USART_UCSRC_UPM0);
		UCSRC  &=  ~(USART_UCSRC_UPM1);
	}
	else if(u8Parity ==  EVEN_PARITY)
	{ /*	UPM1 = 1		UPM0 = 0 */
		UCSRC  &=  ~(USART_UCSRC_UPM0);
		UCSRC  |=  (USART_UCSRC_UPM1);
		
	}
	else if(u8Parity ==  ODD_PARITY	)
	{ /*	UPM1 = 1		UPM0 = 1 */
		UCSRC  |=  (USART_UCSRC_UPM0);
		UCSRC  |=  (USART_UCSRC_UPM1);
		
	}
	else{  }	
		
   /* Init Polarity */
   if(u8ClockPolarity ==  TX_DATACHANGED_RISING_RX_SAMPLE_FALLING)
   {
	   UCSRC &=  ~(USART_UCSRC_UCPOL);
   }
   else if(u8ClockPolarity ==  RX_DATACHANGED_FALLING_RX_SAMPLE_RISING)
   {
	  UCSRC |= (USART_UCSRC_UCPOL);
   }
   else{  }		
		
 /* Init Baud Rate setting is different in Asynchronous and Synchronous mode 
    It is also different for each crystal  frequency. Following values are for
	8 Mhz Crystal. Baud rate has two register UBRRL and UBRRH. If baud rate
	value is with in range(0-255) of UBRRL, then we need not worry URSEL bit.
	If baud rate value uses both registers than  in order to have write access
	to UBRRH register we should reset this  bit, as this bit is set to 1 above
	to have access to UCSRC register.
	For	following values we need not reset this bit because for all the values of 
	baud mention below we don't need UBRRH register.But for higher baud we may
	need UBRRH, in that case uncomment following code.   
    */
 
	/*UCSRC &= ~( USART_UCSRC_URSEL); */
	
 if(u8BaudRate	 ==  _2400_BAUD)
 {  /* This value is taken from DataSheets*/
	 UBRRL = 207;
 }
 else if(u8BaudRate	 ==  _4800_BAUD)
 {/* This value is taken from DataSheets*/
	 UBRRL = 103;
 }
 else if(u8BaudRate	 ==  _9600_BAUD)
 {/* This value is taken from DataSheets*/
	 UBRRL = 51;
 }
 else if(u8BaudRate	 ==  _14_P_4K_BAUD)
 {/* This value is taken from DataSheets*/
	 UBRRL = 34;
 }
 else{  }		
	
}

/** @brief			Usart_Transmit
  * @brief			Data is transmitted in Polling mode.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			*pbuf
  * @description	Pointer to Transmit Buffer.
  * @test	
  */

#if ((TX_RX_METHODS) == (POLLING))
//FTEST: Usart_Transmit(uint8_t  *pbuf) in polling mode PENDING

void Usart_Transmit(char  Tx_Buffer[])
{uint8_t index =0,temp =0;
	  
		
	/* loop over for no Bytes in Tx Buffer*/
	  for(index= 0 ; index < TX_BUFFER_SIZE; index++)
	  {  /* Check whether previous transmission is over or not by checking
	      UDRE flag is set */
	   
	  	if((ISBITSET(UCSRA,USART_UCSRA_UDRE_BIT)))
	   {   /* Transmit first Byte */
	      UDR = Tx_Buffer[index];
		  temp = 0;
	   }
	     /* Wait here till flag is 0 means transmission is going on */
		  while(temp == 0)
		  { temp = UCSRA & (1<< USART_UCSRA_UDRE_BIT) ;
		  };
	  } 
} 

/** @brief			Usart_Receive
  * @brief			Data is receive in Polling mode.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			*pbuf
  * @description	Pointer to Transmit Buffer.
  * @test	
  */
//FTEST: Usart_Receive(uint8_t *pbuf) in polling mopde PENDING
int8_t Usart_Receive(char  Rx_Buffer[])
{uint8_t index ;
 int8_t	 status = NO_ERROR;
		/* loop over for no Bytes in Rx Buffer*/
	  for(index= 0 ; index < RX_BUFFER_SIZE; index++)
	  {/* Wait for RXC bit to be set */
			while(!(ISBITSET(UCSRA,USART_UCSRA_RXC_BIT )))
		   {
			  /* wait for bit to set */ 
		   }
		   /* Check for  PE Error*/
		   if(ISBITSET(UCSRA,USART_UCSRA_PE_BIT))
		   {
				status = PARITY_ERROR ;
				 break; 
		   }
		   /* Check for FE  Error*/
			if(ISBITSET(UCSRA,USART_UCSRA_FE_BIT))
			{
				status = FRAME_ERROR ;
				 break; 
			}
		   /* Check for DOR Error*/
		   if(ISBITSET(UCSRA,USART_UCSRA_DOR_BIT))
		   {
				status = DATA_OVERRUN_ERROR;
				 break; 
		   }
			if(status ==  NO_ERROR)
			{	/* copy UDR to buffer*/
				Rx_Buffer[index] = UDR ;
			}
			else
			{ /* we encounter  error break loop and return error code*/
				
			} 
	 }/* end of for loop*/
	  if((status != PARITY_ERROR) || (status != FRAME_ERROR) ||
	   (status != DATA_OVERRUN_ERROR) )
	   {
		   status = DATA_RECEIVED ; 
	   }
	 return(status);
}
#endif

/** @brief			Usart_Transmit
  * @brief			Data is transmitted in Interrupt Method.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			*pbuf
  * @description	Pointer to Transmit Buffer.
  * @test	
  */

#if (TX_RX_METHODS == INTERRUPT)
// TODO: Implement Usart_Transmit(uint8_t  *pbuf) for interrupt mode PENDING
//FTEST: Usart_Transmit(uint8_t  *pbuf) in Interrupt mode  PENDING
void Usart_Transmit(uint8_t  *pbuf)
{
	
}

/** @brief			Usart_Transmit
  * @brief			Data is transmitted in Interrupt Method.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			*pbuf
  * @description	Pointer to Transmit Buffer.
  * @test	
  */
// TODO: Implement Usart_Receive(uint8_t *pbuf) for interrupt mode PENDING
//FTEST: Usart_Receive(uint8_t *pbuf) in Interrupt mode PENDING
int8_t Usart_Receive(uint8_t *pbuf)
{
	
}

#endif


/** @brief			Usart_SetMode
  * @brief			Set mode for transmission and receiving
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	It has following value
  *					ASYNCHRONOUS_NORMAL
  *					ASYNCHRONOUS_DOUBLE
  *					SYNCHRONOUS_MASTER 
  *					SYNCHRONOUS_SLAVE
  * @test	
  */
//FTEST: Usart_SetMode(uint8_t mode)  PENDING
void Usart_SetMode(uint8_t mode)
{
	 u8Mode = mode;
	 
}
/** @brief			Usart_SetDataBits
  * @brief			Set no of data bits in Frame.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	It has following value
  *					_1_DATA_BIT to _X_DATA_BIT where X is 1 to 9 leaving 3 and 4
  * @test	
  */
//FTEST: Usart_SetDataBits(uint8_t noOfDataBits) PENDING
void Usart_SetDataBits(uint8_t noOfDataBits)
{
	u8DataBits =noOfDataBits;
}
/** @brief			Usart_SetStopBits
  * @brief			Set no of stop bits when transmission end. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			noOfStopBits
  * @description	It has following value
  *					ONE_STOP_BIT
  *					TWO_STOP_BIT
  * @test	
  */
//FTEST: Usart_SetStopBits(uint8_t noOfStopBits) PENDING
void Usart_SetStopBits(uint8_t noOfStopBits)
{
	u8StopBits = noOfStopBits;
}
/** @brief			Usart_SetParity
  * @brief			Parity of the frame is set. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			parity
  * @description	It has following value
  *					NO_PARITY
  *					EVEN_PARITY
  *					ODD_PARITY		
  * @test	
  */
//FTEST: Usart_SetParity(uint8_t parity) PENDING
void Usart_SetParity(uint8_t parity)
{
	u8Parity = parity;
}

/** @brief			Usart_SetBaudRate
  * @brief			Set the baud rate of transmission
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			polarity 
  * @description    It has following value
  *					_2400_BAUD /  _4800_BAUD / _9600_BAUD / _14_P_4K_BAUD
  *                  Mcu support following values but is not implemented
  *					 by Module		
  *					_19_P_2K_BAUD / _28_P_8K_BAUD	
  *					_57_P_6K_BAUD / _76_P_8K_BAUD /_115_P_2K_BAUD	
  *					_230_P_4K_BAUD / _250K_BAUD
  * @test	
  */
//FTEST: Usart_SetBaudRate(uint8_t baudRate)  PENDING
void Usart_SetBaudRate(uint8_t baudRate)
{
	u8BaudRate = baudRate;
}

/** @brief			Usart_SetClockPolarity
  * @brief			When in Asynchronous mode you can set clock polarity
  *					when data should change while transmitting mode and when 
  *					sampling is done while receiving. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			polarity 
  * @description    It has following value
  *					TX_DATACHANGED_RISING_RX_SAMPLE_FALLING
  *					RX_DATACHANGED_FALLING_RX_SAMPLE_RISING	
  * @test	
  */
//FTEST: Usart_SetClockPolarity(uint8_t polarity)  PENDING
void Usart_SetClockPolarity(uint8_t polarity)
{
	u8ClockPolarity = polarity ;
}

/** @brief			Usart_GetMode
  * @brief			Get mode for transmission and receiving
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	It has following value
  *					ASYNCHRONOUS_NORMAL
  *					ASYNCHRONOUS_DOUBLE
  *					SYNCHRONOUS_MASTER 
  *					SYNCHRONOUS_SLAVE
  * @test	
  */
//FTEST: Usart_GetMode(uint8_t mode)  PENDING
uint8_t Usart_GetMode(void)
{
	 return(u8Mode);
}
/** @brief			Usart_GetDataBits
  * @brief			Get no of data bits in Frame.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	It has following value
  *					_1_DATA_BIT to _X_DATA_BIT where X is 1 to 9 leaving 3 and 4
  * @test	
  */
//FTEST: Usart_GetDataBits(void)  PENDING
uint8_t Usart_GetDataBits(void)
{
	return(u8DataBits);
}
/** @brief			Usart_GetStopBits
  * @brief			Get no of stop bits when transmission end. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			noOfStopBits
  * @description	It has following value
  *					ONE_STOP_BIT
  *					TWO_STOP_BIT
  * @test	
  */
//FTEST: Usart_GetStopBits(uint8_t noOfStopBits)  PENDING
uint8_t Usart_GetStopBits(void)
{
	return(u8StopBits);
}
/** @brief			Usart_GetParity
  * @brief			Parity of the frame is set. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			parity
  * @description	It has following value
  *					NO_PARITY
  *					EVEN_PARITY
  *					ODD_PARITY		
  * @test	
  */
//FTEST: Usart_GetParity(void)  PENDING
uint8_t Usart_GetParity(void)
{
	return(u8Parity);
}

/** @brief			Usart_GetBaudRate
  * @brief			Get the baud rate of transmission
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			polarity 
  * @description    It has following value
  *					_2400_BAUD /  _4800_BAUD / _9600_BAUD / _14_P_4K_BAUD
  *					Following values are supported by MCU but not implemented.		
  *					_19_P_2K_BAUD /_14_P_4K_BAUD / _28_P_8K_BAUD	
  *					_57_P_6K_BAUD / _76_P_8K_BAUD /_115_P_2K_BAUD	
  *					_230_P_4K_BAUD / _250K_BAUD
  * @test	
  */
//FTEST: Usart_GetBaudRate(uint8_t baudRate) PENDING
uint8_t Usart_GetBaudRate(void)
{
	return(u8BaudRate);
}

/** @brief			Usart_GetClockPolarity
  * @brief			When in Asynchronous mode you can set clock polarity
  *					when data should change while transmitting mode and when 
  *					sampling is done while receiving. 
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			polarity 
  * @description    It has following value
  *					TX_DATACHANGED_RISING_RX_SAMPLE_FALLING
  *					RX_DATACHANGED_FALLING_RX_SAMPLE_RISING	
  * @test	
  */
//FTEST: Usart_GetClockPolarity(void) PENDING
uint8_t Usart_GetClockPolarity(void)
{
	return(u8ClockPolarity );
}

/** @brief			Usart_RegisterTxInterrupt
  * @brief			Register Tx interrupt service routine.
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			fun
  * @description	Fun is called when Tx interrupt is occurred
  * @param			param
  * @description	Parameter to Tx interrupt service routine.
  * @test	
  */
#if(TX_RX_METHODS == INTERRUPT)

void Usart_RegisterTxInterruptService(fpointerv_t  fun , uint8_t param)
{
	u8IntParam[USART_TX_VECT_NO] = param;
	ISR_FPTR[USART_TX_VECT_NO] = fun  ;
}


/** @brief			Usart_RegisterRxInterrupt
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			fun
  * @description	Fun is called when Rx interrupt is occurred
  * @param			param
  * @description	Parameter to Rx interrupt service routine.
  * @test	
  */
void Usart_RegisterRxInterruptService(fpointerv_t  fun , uint8_t param)
{
	u8IntParam[USART_RX_VECT_NO] = param;
	ISR_FPTR[USART_RX_VECT_NO] = fun  ;
}

/** @brief			Usart_RegisterDataRegEmptyInterrupt
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			fun
  * @description	Fun is called when DataRegEmpty interrupt is occurred
  * @param			param
  * @description	Parameter to DataRegEmpty interrupt service routine.
  * @test	
  */
void Usart_RegisterDataRegEmptyInterruptService(fpointerv_t  fun , uint8_t param)
{
	u8IntParam[USART_UDRE_VECT_NO] = param;
	ISR_FPTR[USART_UDRE_VECT_NO] = fun  ;
}


/** @brief			Usart_TxInterruptService
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
//TODO: Usart_Tx_InterruptService(void) Implement PENDING
void Usart_Tx_InterruptService(void)
{
	
}

/** @brief			Usart_RxInterruptService
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
//TODO: Usart_Rx_InterruptService(void) Implement PENDING
void Usart_Rx_InterruptService(void)
{
	
}

/** @brief			Usart_DataRegEmptyInterruptService
  * @brief			
  * @McuReg			
  * @PreCondition	None
  * @PostCondition	None
  * @param			
  * @description	
  * @test	
  */
//TODO: Usart_DataRegEmptyInterruptService(void)Implement  PENDING
void Usart_DataRegEmptyInterruptService(void)
{
	
}

#endif

/**
  * @}
 */
