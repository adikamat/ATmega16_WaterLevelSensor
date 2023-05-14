#ifndef  _TC0TEST_H
#define  _TC0TEST_H

void Test_TC0_SetClearTimerOnCompareMode(void);
void Test_TC0_SetClearTimerOnComparePinMode(void);
void Test_TC0_SetFastPwmMode(void);
void Test_TC0_SetFastPwmPinMode(void);
void Test_TC0_SetPwmPhaseMode(void);
void Test_TC0_SetPwmPhasePinMode(void);
void Test_TC0_SetPwmPhaseFrequencyMode(void);
void Test_TC0_SetPwmPhaseFrequencyPinMode(void);

void Test_TC0_SetTimerMode(void);
void Test_TC0_SetCounterEdge(void);


void Test_TC0_GetTimerReg(void);
void Test_TC0_SetCompareReg(void);

void Test_TC0_StopClock(void);
void Test_TC0_StartClock(void);
void Test_TC0_SetClockPrescalar(void);

void Test_TC0_SetClockResolution_P128USEC_8MHZ(void);
void Test_TC0_SetClockResolution_1USEC_8MHZ(void);
void Test_TC0_SetClockResolution_8USEC_8MHZ(void);
void Test_TC0_SetClockResolution_32USEC_8MHZ(void);
void Test_TC0_SetClockResolution_32USEC_8MHZ(void);
void Test_TC0_SetClockResolution_32USEC_8MHZ(void);
void Test_TC0_SetClockResolution_128USEC_8MHZ(void);

void Test_TC0_EnableTimerInterrupt(void);
void Test_TC0_DisableTimerInterrupt(void);

void Test_TC0_EnableCompareInterrupt(void);
void Test_TC0_DisableCompareInterrupt(void);

void Test_TC0_EnableInputCaptureInterrupt(void);
void Test_TC0_DisableInputCaptureInterrupt(void);

#endif