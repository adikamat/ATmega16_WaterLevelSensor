#include "ATmega16_TC1.h"
#include "System.h"

/*  Test for TC1 timer Interrupt  Call these in main*/

#define COUNTER_VAL (0xFFA3) // Use 0xFFEB for count 20 (10 us)
void Toggle1(uint8_t Mcupin);
void Toggle2(uint8_t Mcupin);

/*********************************************************	 
             Configure TC1 for timer mode              
********************************************************/
void Test_TC1TimerInterrupt(void)
{ 				
			 /* Configure Mcupin 5 as output */
			 //Port_SetPinDirection(Mcupin,PIN_OUT);
			 /* Set TC1 in timer Mode */
			 //TC1_TimerMode(TC1_TOP_0XFFFF);
			/* Associate ISR with TC1 Module */
			//TC1_RegisterTimerInterruptService(&Toggle1,Mcupin);
			/*Enable Timer Interrupt*/
			//TC1_EnableTimerInterrupt();
			/* Load Timer with Count for delay  */
			//TC1_SetTimerReg(COUNTER_VAL);
			/* Set Resolution of TC1 Start clock*/
			//TC1_SetClockResolution_1USEC_8MHZ();
			//TC1_SetClockResolution_P5USEC_16MHZ();
			//TC1_SetClockResolution_P0625USEC_16MHZ();
}

/************ Timer Interrupt function**************/

//void Toggle1(uint8_t Mcupin)
//{
//if((PINB  & (0x01 << 0x04))  == 0)
//PORTB |= (uint8_t)0x01 << 4;
//else
//PORTB &= ~((uint8_t)0x01) << 4;
///* Load Timer with Count again  */
////TC1_SetTimerReg(0xFFF5);
//TCNT1H = (COUNTER_VAL & (0xFF00)) >> 8;
//TCNT1L = (COUNTER_VAL & (0x00FF));
//}

//void Toggle2(uint8_t Mcupin)
//{uint8_t  temp = 0;
//temp = Port_ReadPin(Mcupin);
//if(temp  == 1)
//Port_WritePin(Mcupin,PIN_LOW);
//else
//Port_WritePin(Mcupin,PIN_HIGH);
///* Load Timer with Count again  */
//TC1_SetTimerReg(COUNTER_VAL);
//}




/* Function Related to Different Modes*/
void  Test_TC1_ClearTimerOnCompareMode(void)
{      
	 TCCR1A =0x00;
	 TCCR1B =0x00;	
	 TC1_ClearTimerOnCompareMode(TC1_TOP_OCR1A);	 /* Pass*/
	 TCCR1A =0x00;
	 TCCR1B =0x00;
	 TC1_ClearTimerOnCompareMode(TC1_TOP_ICR1);	 /* Pass*/
}

void Test_TC1_ClearTimerOnComparePinMode(void)
{
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC1A,TC1_PIN_DISCONNECTED);		/* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC1A,TC1_PIN_TOGGLE_ON_MATCH);	/* Pass*/	
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC1A,TC1_PIN_CLEAR_ON_MATCH);	   /* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC1A,TC1_PIN_SET_ON_MATCH);		/* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC2B,TC1_PIN_DISCONNECTED);		/* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC2B,TC1_PIN_TOGGLE_ON_MATCH);	/* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC2B,TC1_PIN_CLEAR_ON_MATCH);	/* Pass*/
	TCCR1A =0x00;
	TC1_ClearTimerOnComparePinMode(TC1_PIN_OC2B,TC1_PIN_SET_ON_MATCH);	/* Pass*/
	TCCR1A =0x00;
}

void Test_TC1_FastPwmMode(void)
{
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_FastPwmMode(TC1_8BIT_TOP_0X00FF);	 /* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_FastPwmMode(TC1_9BIT_TOP_0X01FF);	 /* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_FastPwmMode(TC1_10BIT_TOP_0X03FF);	 /* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_FastPwmMode(TC1_TOP_ICR1);			 /* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_FastPwmMode(TC1_TOP_OCR1A);			 /* Pass*/
}

void Test_TC1_FastPwmPinMode(void)
{
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC1A,TC1_PIN_DISCONNECTED);	/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC1A,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);	/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC1A,TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP);/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC1A,TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP);/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC2B,TC1_PIN_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC2B,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC2B,TC1_PIN_CLEAR_ON_MATCH_SET_ON_TOP);/* Pass*/
	TCCR1A =0x00;
	TC1_FastPwmPinMode(TC1_PIN_OC2B,TC1_PIN_SET_ON_MATCH_CLEAR_ON_TOP);/* Pass*/
	TCCR1A =0x00;
}

void Test_TC1_PwmPhaseMode(void)
{
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseMode(TC1_8BIT_TOP_0X00FF);/* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseMode(TC1_9BIT_TOP_0X01FF);/* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseMode(TC1_10BIT_TOP_0X03FF);/* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseMode(TC1_TOP_ICR1);/* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseMode(TC1_TOP_OCR1A);/* Pass*/
	
}

void Test_TC1_PwmPhasePinMode(void)
{
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC1A,TC1_PIN_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC1A,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC1A,TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC1A,TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC2B,TC1_PIN_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC2B,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC2B,TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhasePinMode(TC1_PIN_OC2B,TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING);/* Pass*/
	
}

void Test_TC1_PwmPhaseFrequencyMode(void)
{
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseFrequencyMode(TC1_TOP_ICR1);/* Pass*/
	TCCR1A =0x00;
	TCCR1B =0x00;
	TC1_PwmPhaseFrequencyMode(TC1_TOP_OCR1A);/* Pass*/
}

void Test_TC1_PwmPhaseFrequencyPinMode(void)
{
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC1A,TC1_PIN_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC1A,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC1A,TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC1A,TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC2B,TC1_PIN_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC2B,TC1_OC1A_PIN_TOGGLE_ON_MATCH_OC1B_DISCONNECTED);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC2B,TC1_PIN_CLEAR_ON_UPCOUNTING_SET_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	TC1_PwmPhaseFrequencyPinMode(TC1_PIN_OC2B,TC1_PIN_SET_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNING);/* Pass*/
	TCCR1A =0x00;
	
}

void Test_TC1_TimerMode(void)
{
	TCCR1A =0x00;
	TCCR1B =0x00;
	 TC1_TimerMode(TC1_TOP_0XFFFF);/* Pass*/
}

void Test_TC1_SetCounterModeEdge(void)
{
	TCCR1B =0x00;
	TC1_SetCounterModeEdge(TC1_CLK_FALLING_EDGE_ON_T1_PIN);/* Pass*/
	TCCR1B =0x00;
	TC1_SetCounterModeEdge(TC1_CLK_RISING_EDGE_ON_T1_PIN);/* Pass*/
}

void Test_TC1_SetInputCapturePin(void)
{
   TC1_SetInputCapturePin(TC1_IC1);	
   TC1_SetInputCapturePin(TC1_IC2);	
   
}

void Test_TC1_SetInputCaptureEdge(void)
{
	TCCR1B =0x00;
	TC1_SetInputCaptureEdge(TC1_INPUT_CAPTURE_RISING_EDGE);/* Pass*/
	TCCR1B =0x00;
	TC1_SetInputCaptureEdge(TC1_INPUT_CAPTURE_FALLING_EDGE);/* Pass*/
}


/* Mcu Register  related Function */

void  Test_TC1_GetTimerReg(void)
{   uint16_t TReg = 0x0000 ;
	TCNT1 =0x23ea ;
	 TReg =TC1_GetTimerReg(); /* Pass*/
	 
}

void  Test_TC1_SetCompareReg(void)
{
	TC1_SetCompareReg(TC1_OCR1A_REG, 0x56de);/* Pass*/
	TC1_SetCompareReg(TC1_OCR1B_REG, 0xf2e5);/* Pass*/
	TC1_SetCompareReg(TC1_ICR1_REG, 0x34fd);/* Pass*/
}

void  Test_TC1_GetCaptureReg(void)
{
	uint16_t  RegVal =0x0000;
	ICR1 = 0x34FD;
	RegVal  =  TC1_GetCaptureReg(); /* Pass*/
}


/* Clock Related  Function */

void Test_TC1_StopClock(void)
{
		TC1_StopClock(); /*Pass*/
}

void Test_TC1_StartClock(void)
{
		TC1_StartClock(); /*Pass*/
}

void  Test_TC1_SetClockPrescalar(void)
{
	TCCR1B =0x00;
	TC1_SetClockPrescalar(TC1_CLK_DIRECT_NO_PRESCALAR);/* Pass*/
	TCCR1B =0x00;
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_8);/* Pass*/
	TCCR1B =0x00;
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_64);/* Pass*/
	TCCR1B =0x00;
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_256);/* Pass*/
	TCCR1B =0x00;
	TC1_SetClockPrescalar(TC1_CLK_IO_BY_1024);/* Pass*/ 
	TCCR1B =0x00;
}


/*Clcok Resolution relate  */ 
void Test_TC1_SetClockResolution_P128USEC_8MHZ(void)
{
		TC1_SetClockResolution_P128USEC_8MHZ();	/* Pass*/ 
}

void Test_TC1_SetClockResolution_1USEC_8MHZ(void)
{
		TC1_SetClockResolution_1USEC_8MHZ();/* Pass*/ 
}

void Test_TC1_SetClockResolution_8USEC_8MHZ(void)
{
		TC1_SetClockResolution_8USEC_8MHZ();/* Pass*/ 
}

void Test_TC1_SetClockResolution_32USEC_8MHZ(void)
{
		TC1_SetClockResolution_32USEC_8MHZ();	/* Pass*/ 
}

void Test_TC1_SetClockResolution_128USEC_8MHZ(void)
{
		TC1_SetClockResolution_128USEC_8MHZ();/* Pass*/ 
}


/* Interrupt related Function */

void Test_TC1_EnableTimerInterrupt(void)
{
	TIMSK =0x00;
	 TC1_EnableTimerInterrupt();/* Pass*/ 
}

void Test_TC1_DisableTimerInterrupt(void)
{
	TC1_DisableTimerInterrupt();/* Pass*/ 
}

void Test_TC1_EnableCompareInterrupt(void)
{
	TIMSK =0x00;
	TC1_EnableCompareInterrupt(TC1_OCR1A_INTERRUPT);/* Pass*/ 
	TC1_EnableCompareInterrupt(TC1_OCR1B_INTERRUPT);/* Pass*/ 
}

void Test_TC1_DisableCompareInterrupt(void)
{
	TC1_DisableCompareInterrupt(TC1_OCR1A_INTERRUPT);/* Pass*/ 
	TC1_DisableCompareInterrupt(TC1_OCR1B_INTERRUPT);/* Pass*/ 
}

void Test_TC1_EnableInputCaptureInterrupt(void)
{
	TIMSK =0x00;
	TC1_EnableInputCaptureInterrupt();/* Pass*/ 
}

void Test_TC1_DisableInputCaptureInterrupt(void)
{
	TC1_DisableInputCaptureInterrupt();/* Pass*/ 
}


