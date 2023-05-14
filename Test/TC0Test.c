#include "ATmega16_TC0.h"

/* Function Related to Different Modes*/
void  Test_TC0_SetClearTimerOnCompareMode(void)
{
	TC0_SetClearTimerOnCompareMode(TC0_TOP_OCR0);
	
}

void Test_TC0_SetClearTimerOnComparePinMode(void)
{
	TC0_SetClearTimerOnComparePinMode(TC0_PIN_OC0,TC0_OC0_PIN_DISCONNECTED);
	TC0_SetClearTimerOnComparePinMode(TC0_PIN_OC0,TC0_OC0_PIN_TOGGLE_ON_MATCH);
	TC0_SetClearTimerOnComparePinMode(TC0_PIN_OC0,TC0_OC0_PIN_CLEAR_ON_MATCH);
	TC0_SetClearTimerOnComparePinMode(TC0_PIN_OC0,TC0_OC0_PIN_SET_ON_MATCH);
	
}

void Test_TC0_SetFastPwmMode(void)
{
	TC0_SetFastPwmMode(TC0_TOP_0XFF);
}

void Test_TC0_SetFastPwmPinMode(void)
{
	TC0_SetFastPwmPinMode(TC0_PIN_OC0,TC0_OC0_PIN_DISCONNECTED);
	TC0_SetFastPwmPinMode(TC0_PIN_OC0,TC0_OC0_PIN_CLEAR_ON_MATCH_SET_ON_TOP);
	TC0_SetFastPwmPinMode(TC0_PIN_OC0,TC0_OC0_PIN_SET_ON_MATCH_CLEAR_ON_TOP);
}

void Test_TC0_SetPwmPhaseMode(void)
{
	TC0_SetPwmPhaseMode(TC0_TOP_0XFF);
}

void Test_TC0_SetPwmPhasePinMode(void)
{
	TC0_SetPwmPhasePinMode(TC0_PIN_OC0,TC0_OC0_PIN_DISCONNECTED);
	TC0_SetPwmPhasePinMode(TC0_PIN_OC0,TC0_OC0_PIN_CLEAR_UPCOUNTING_SET_DOWNCOUNTING);
	TC0_SetPwmPhasePinMode(TC0_PIN_OC0,TC0_OC0_PIN_SET_UPCOUNTING_CLEAR_DOWNCOUNTING);
}


void Test_TC0_SetTimerMode(void)
{
	TC0_SetTimerMode(TC0_TOP_0XFF);
}

void Test_TC0_SetCounterEdge(void)
{
	TC0_SetCounterEdge(TC0_FALLING_EDGE_ON_T0_PIN);
	TC0_SetCounterEdge(TC0_RISING_EDGE_ON_T0_PIN);
}


/* Mcu Register  related Function */

void  Test_TC0_GetTimerReg(void)
{
	TC0_GetTimerReg(void);
}

void  Test_TC0_SetCompareReg(void)
{
	TC0_SetCompareReg(0x0000);
	
}


/* Clock Related  Function */

void Test_TC0_StopClock(void)
{
	TC0_StopClock();
}

void Test_TC0_StartClock(void)
{
	TC0_StartClock();
}

void  Test_TC0_SetClockPrescalar(void)
{
	TC0_SetClockPrescalar(TC0_CLK_DIRECT_NO_PRESCALAR);
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_8);
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_64);
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_256);
	TC0_SetClockPrescalar(TC0_CLK_IO_BY_1024);
}


/*Clcok Resolution relate  */


void Test_TC0_SetClockResolution_P128USEC_8MHZ(void)
{
	TC0_SetClockResolution_P128USEC_8MHZ();
}

void Test_TC0_SetClockResolution_1USEC_8MHZ(void)
{
	TC0_SetClockResolution_1USEC_8MHZ();
}

void Test_TC0_SetClockResolution_8USEC_8MHZ(void)
{
	TC0_SetClockResolution_8USEC_8MHZ();
}

void Test_TC0_SetClockResolution_32USEC_8MHZ(void)
{
	TC0_SetClockResolution_32USEC_8MHZ();
}

void Test_TC0_SetClockResolution_128USEC_8MHZ(void)
{
	TC0_SetClockResolution_128USEC_8MHZ();
}


/* Interrupt related Function */

void Test_TC0_EnableTimerInterrupt(void)
{
	TC0_EnableTimerInterrupt();
}

void Test_TC0_DisableTimerInterrupt(void)
{
	TC0_DisableTimerInterrupt();
}

void Test_TC0_EnableCompareInterrupt(void)
{
	TC0_EnableCompareInterrupt();
	TC0_EnableCompareInterrupt();
}

void Test_TC0_DisableCompareInterrupt(void)
{
	TC0_DisableCompareInterrupt();
	TC0_DisableCompareInterrupt();

}
