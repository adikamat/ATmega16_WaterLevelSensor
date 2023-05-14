/* Prototype for Usart Test*/

#ifndef _USART_TEST_H
#define _USART_TEST_H
/* Module Enable / disable*/
void   Test_Usart_Tx_Module_Enable(void); /*P*/
void  Test_Usart_Rx_Module_Enable(void); /*P*/
void  Test_Usart_Tx_Module_Disable(void); /*P*/
void  Test_Usart_Rx_Module_Disbale(void); /*P*/
/* Interrupts*/	
void  Test_Usart_Tx_Interrupt_Enable(void); /*P*/
void  Test_Usart_Rx_Interrupt_Enable(void); /*P*/
void  Test_Usart_DataRegEmpty_Interrupt_Enable(void); /*CC*/

void Test_Usart_Tx_Interrupt_Disable(void); /*P*/
void Test_Usart_Rx_Interrupt_Disable(void); /*P*/
void Test_Usart_DataRegEmpty_Interrupt_Disable(void); /*CC*/
/* Flags  Checking*/
uint8_t  Test_Usart_IsReceiveComplete(void); /*CC*/
uint8_t  Test_Usart_IsTransmitComplete(void); /*P*/
uint8_t  Test_Usart_IsDataRegEmpty(void); /*CC*/
uint8_t  Test_Usart_IsFrameError(void); /*CC*/
uint8_t  Test_Usart_IsParityError(void); /*CC*/
uint8_t  Test_Usart_IsDataOverRunError(void); /*CC*/
/* Usart Initialization function*/
void Test_Usart_InitStructure(void);
void Test_Usart_Init(void);
void Test_Usart_InitSfr(void);
/*Usart Tx Rx function */
void Test_Usart_Transmit(void);
int8_t Test_Usart_Receive(void);
/* Set/Get Methods for  Structure*/
void Test_Usart_SetMode(void);
void Test_Usart_SetStopBits(void);
void Test_Usart_SetParity(void);
void Test_Usart_SetBaudRate(void);
void Test_Usart_SetClockPolarity(void);
uint8_t Test_Usart_GetMode(void);
uint8_t Test_Usart_GetDataBits(void);
uint8_t Test_Usart_GetStopBits(void);
uint8_t Test_Usart_GetParity(void);
uint8_t Test_Usart_GetBaudRate(void);
uint8_t Test_Usart_GetClockPolarity(void);

#endif

