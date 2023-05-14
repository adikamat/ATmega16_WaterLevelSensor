/**
  ******************************************************************************
  * @file    UsartTest.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    29-Aug-2022
  * @brief   Test file for Usart Module.
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
  
#include "Usart.h"

extern uint8_t  Tx_Buffer[TX_BUFFER_SIZE];
extern uint8_t  Rx_Buffer[RX_BUFFER_SIZE];

/* Module Enable / disable*/
void   Test_Usart_Tx_Module_Enable(void)/*P*/
{
	Usart_Tx_Module_Enable();
}
void  Test_Usart_Rx_Module_Enable(void)/*P*/
{
	Usart_Rx_Module_Enable();
}
void  Test_Usart_Tx_Module_Disable(void)/*P*/
{
	Usart_Tx_Module_Disable();
}
void  Test_Usart_Rx_Module_Disbale(void)/*P*/
{
	Usart_Rx_Module_Disbale();
	
/* Interrupts*/	
} 
void  Test_Usart_Tx_Interrupt_Enable(void)/*P*/
{
	Usart_Tx_Interrupt_Enable();
}
void  Test_Usart_Rx_Interrupt_Enable(void)/*P*/
{
	Usart_Rx_Interrupt_Enable();
}
void  Test_Usart_DataRegEmpty_Interrupt_Enable(void)/*CC Can't Check*/
{
	UDR = 0x98;
	Usart_DataRegEmpty_Interrupt_Enable();
	
}
void Test_Usart_Tx_Interrupt_Disable(void)/*P*/
{
	Usart_Tx_Interrupt_Disable();
}

void  Test_Usart_Rx_Interrupt_Disable(void)/*P*/
{
	Usart_Rx_Interrupt_Disable();
}

void Test_Usart_DataRegEmpty_Interrupt_Disable(void) /*CC*/ 
{
	Usart_DataRegEmpty_Interrupt_Disable();
}
/* Flag Checking*/

uint8_t Test_Usart_IsReceiveComplete(void)/*CC*/
{uint8_t status= FALSE;
	status = Usart_IsReceiveComplete();
	return(status);
}

uint8_t  Test_Usart_IsTransmitComplete(void)/*P*/
{ uint8_t status;
	status = Usart_IsTransmitComplete();
	return(status);
}

uint8_t  Test_Usart_IsDataRegEmpty(void)/*CC*/
{uint8_t status;
	status = Usart_IsDataRegEmpty();
	return(status);
}

uint8_t  Test_Usart_IsFrameError(void) /*CC*/
{uint8_t status;
	status = Usart_IsFrameError(); 
	return(status);
}
uint8_t Test_Usart_IsParityError(void) /*CC*/
{uint8_t status;
	status = Usart_IsParityError(); 
	return(status);
}
uint8_t  Test_Usart_IsDataOverRunError(void)/*CC*/
{uint8_t status;
	status = Usart_IsDataOverRunError();
	return(status);
}


/* Usart Initialization function*/
void Test_Usart_InitStructure(void )/*P*/
{
	Usart_InitStructure();
}
void Test_Usart_Init(void)/*P*/
{
	Usart_Init();	
}
void  Test_Usart_InitSfr(void)/*P*/
{
	Usart_InitSfr();
}
/*Usart Tx Rx function */
void Test_Usart_Transmit(void)
{
	Usart_Transmit(&Tx_Buffer);
}
void Test_Usart_Receive(void)
{
	Usart_Receive(&Rx_Buffer);
}
/* Set/Get Methods for  Structure*/
void Test_Usart_SetMode(void)/*P*/
{
	Usart_SetMode(ASYNCHRONOUS_NORMAL);
	Usart_SetMode(ASYNCHRONOUS_DOUBLE);
	Usart_SetMode(SYNCHRONOUS);
}
void Test_Usart_SetDataBits(void)/*P*/
{
	Usart_SetDataBits(_5_DATA_BIT);
	Usart_SetDataBits(_6_DATA_BIT);
	Usart_SetDataBits(_7_DATA_BIT);
	Usart_SetDataBits(_8_DATA_BIT);
	Usart_SetDataBits(_9_DATA_BIT);
}
void Test_Usart_SetStopBits(void)/*P*/
{
	Usart_SetStopBits(ONE_STOP_BIT	);
	Usart_SetStopBits(TWO_STOP_BIT);
	
}
void Test_Usart_SetParity(void)/*P*/
{
	Usart_SetParity(NO_PARITY);
	Usart_SetParity(EVEN_PARITY);
	Usart_SetParity(ODD_PARITY);
	
}
void Test_Usart_SetBaudRate(void)/*P*/
{
	Usart_SetBaudRate(_2400_BAUD);
	Usart_SetBaudRate(_4800_BAUD);
	Usart_SetBaudRate(_9600_BAUD);
	Usart_SetBaudRate(_14_P_4K_BAUD);
}
void Test_Usart_SetClockPolarity(void)/*P*/
{
	Usart_SetClockPolarity(TX_DATACHANGED_RISING_RX_SAMPLE_FALLING);
	Usart_SetClockPolarity(RX_DATACHANGED_FALLING_RX_SAMPLE_RISING);
	
}
uint8_t Test_Usart_GetMode(void)/*P*/
{uint8_t  Mode;
	Mode = Usart_GetMode();
	 return(Mode);
}
uint8_t Test_Usart_GetDataBits(void)/*P*/
{uint8_t  DataBits;
	DataBits = Usart_GetDataBits();
	 return(DataBits);
}
uint8_t Test_Usart_GetStopBits(void)/*P*/
{uint8_t  StopBits;
	StopBits = Usart_GetStopBits();
	 return(StopBits);
}
uint8_t Test_Usart_GetParity(void)/*P*/
{uint8_t  Parity;
	Parity = Usart_GetParity();
	 return(Parity);
}
uint8_t Test_Usart_GetBaudRate(void)/*P*/
{uint8_t  BaudRate;
	BaudRate = Usart_GetBaudRate();
	 return(BaudRate);
}
uint8_t Test_Usart_GetClockPolarity(void)/*P*/
{ uint8_t  pol;
	pol = Usart_GetClockPolarity();
	 return(pol);
}

extern  char  Rx_Buffer[RX_BUFFER_SIZE];
/* Following function receive something in 
   Receive buffer and transmit the same*/ 
void Test_Usart_Receive(void)
{ uint8_t status;
	status = Usart_Receive(Rx_Buffer);
	if(status == DATA_RECEIVED)
	Usart_Transmit(Rx_Buffer);
	/* Clear Both Buffers for next Rx and TX */
	Usart_InitTxBuffer();
	Usart_InitRxBuffer();
}


