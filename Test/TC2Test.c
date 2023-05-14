#include "ATmega16_TC2.h"

/* Function Related to Different Modes*/
void  Test_TC2_SetClearTimerOnCompareMode(void)
{
	TC2_SetClearTimerOnCompareMode(TC2_TOP_OCR2);
	
}

void Test_TC2_SetClearTimerOnComparePinMode(void)
{
	TC2_SetClearTimerOnComparePinMode(TC2_PIN_OC2,TC2_OC2_PIN_DISCONNECTED);
	TC2_SetClearTimerOnComparePinMode(TC2_PIN_OC2,TC2_OC2_PIN_TOGGLE_ON_MATCH);
	TC2_SetClearTimerOnComparePinMode(TC2_PIN_OC2,TC2_OC2_PIN_CLEAR_ON_MATCH);
	TC2_SetClearTimerOnComparePinMode(TC2_PIN_OC2,TC2_OC2_PIN_SET_ON_MATCH);
	
}

void Test_TC2_SetFastPwmMode(void)
{
	TC2_SetFastPwmMode(TC2_TOP_0XFF);
}

void Test_TC2_SetFastPwmPinMode(void)
{
	TC2_SetFastPwmPinMode(TC2_PIN_OC2,TC2_OC2_PIN_DISCONNECTED);
	TC2_SetFastPwmPinMode(TC2_PIN_OC2,TC2_OC2_PIN_CLEAR_ON_MATCH_SET_ON_TOP);
	TC2_SetFastPwmPinMode(TC2_PIN_OC2,TC2_OC2_PIN_SET_ON_MATCH_CLEAR_ON_TOP);
}

void Test_TC2_SetPwmPhaseMode(void)
{
	TC2_SetPwmPhaseMode(TC2_TOP_0XFF);
}

void Test_TC2_SetPwmPhasePinMode(void)
{
	TC2_SetPwmPhasePinMode(TC2_PIN_OC2,TC2_OC2_PIN_DISCONNECTED);
	TC2_SetPwmPhasePinMode(TC2_PIN_OC2,TC2_OC2_PIN_CLEAR_UPCOUNTING_SET_DOWNCOUNTING);
	TC2_SetPwmPhasePinMode(TC2_PIN_OC2,TC2_OC2_PIN_SET_UPCOUNTING_CLEAR_DOWNCOUNTING);
}


void Test_TC2_SetTimerMode(void)
{
	TC2_SetTimerMode(TC2_TOP_0XFF);
}

 
/* Mcu Register  related Function */

void  Test_TC2_GetTimerReg(void)
{
	TC2_GetTimerReg(void);
}

void  Test_TC2_SetCompareReg(void)
{
	TC2_SetCompareReg(0x0000);
	
}


/* Clock Related  Function */

void Test_TC2_StopClock(void)
{
	TC2_StopClock();
}

void Test_TC2_StartClock(void)
{
	TC2_StartClock();
}

void  Test_TC2_SetClockPrescalar(void)
{
	TC2_SetClockPrescalar(TC2_CLK_DIRECT_NO_PRESCALAR);
	TC2_SetClockPrescalar(TC2_CLK_IO_BY_8);
	TC2_SetClockPrescalar(TC2_CLK_IO_BY_64);
	TC2_SetClockPrescalar(TC2_CLK_IO_BY_256);
	TC2_SetClockPrescalar(TC2_CLK_IO_BY_1024);
}


/*Clcok Resolution relate  */


void Test_TC2_SetClockResolution_P128USEC_8MHZ(void)
{
	TC2_SetClockResolution_P128USEC_8MHZ();
}

void Test_TC2_SetClockResolution_1USEC_8MHZ(void)
{
	TC2_SetClockResolution_1USEC_8MHZ();
}

void Test_TC2_SetClockResolution_8USEC_8MHZ(void)
{
	TC2_SetClockResolution_8USEC_8MHZ();
}

void Test_TC2_SetClockResolution_32USEC_8MHZ(void)
{
	TC2_SetClockResolution_32USEC_8MHZ();
}

void Test_TC2_SetClockResolution_128USEC_8MHZ(void)
{
	TC2_SetClockResolution_128USEC_8MHZ();
}


/* Interrupt related Function */

void Test_TC2_EnableTimerInterrupt(void)
{
	TC2_EnableTimerInterrupt();
}

void Test_TC2_DisableTimerInterrupt(void)
{
	TC2_DisableTimerInterrupt();
}

void Test_TC2_EnableCompareInterrupt(void)
{
	TC2_EnableCompareInterrupt();
	TC2_EnableCompareInterrupt();
}

void Test_TC2_DisableCompareInterrupt(void)
{
	TC2_DisableCompareInterrupt();
	TC2_DisableCompareInterrupt();

}
