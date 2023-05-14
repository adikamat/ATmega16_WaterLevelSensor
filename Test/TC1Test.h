#ifndef  _TC1TEST_H
#define  _TC1TEST_H



void Test_TC1_SetClearTimerOnCompareMode(void);     /*Pass*/
void Test_TC1_SetClearTimerOnComparePinMode(void);	 /*Pass*/
void Test_TC1_SetFastPwmMode(void);	 /*Pass*/
void Test_TC1_SetFastPwmPinMode(void); /*Pass*/
void Test_TC1_SetPwmPhaseMode(void); /*Pass*/
void Test_TC1_SetPwmPhasePinMode(void); /*Pass*/
void Test_TC1_SetPwmPhaseFrequencyMode(void); /*Pass*/
void Test_TC1_SetPwmPhaseFrequencyPinMode(void); /*Pass*/

void Test_TC1_SetTimerMode(void); /*Pass*/
void Test_TC1_SetCounterModeEdge(void); /*Pass*/

void Test_TC1_SetInputCapturePin(void); /*Pass*/
void Test_TC1_SetInputCaptureEdge(void); /*Pass*/

void Test_TC1_GetTimerReg(void); /*Pass*/
void Test_TC1_SetCompareReg(void); /*Pass*/
void Test_TC1_GetCaptureReg(void); /*Pass*/

void Test_TC1_StopClock(void); /*Pass*/
void Test_TC1_StartClock(void); /*Pass*/
void Test_TC1_SetClockPrescalar(void); /*Pass*/

void Test_TC1_SetClockResolution_P128USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_1USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_8USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_32USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_32USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_32USEC_8MHZ(void); /*Pass*/
void Test_TC1_SetClockResolution_128USEC_8MHZ(void); /*Pass*/

void Test_TC1_EnableTimerInterrupt(void); /*Pass*/
void Test_TC1_DisableTimerInterrupt(void); /*Pass*/

void Test_TC1_EnableCompareInterrupt(void); /*Pass*/
void Test_TC1_DisableCompareInterrupt(void); /*Pass*/

void Test_TC1_EnableInputCaptureInterrupt(void); /*Pass*/
void Test_TC1_DisableInputCaptureInterrupt(void); /*Pass*/




#endif