#ifndef  _TC2TEST_H
#define  _TC2TEST_H

void Test_TC2_SetClearTimerOnCompareMode(void);
void Test_TC2_SetClearTimerOnComparePinMode(void);
void Test_TC2_SetFastPwmMode(void);
void Test_TC2_SetFastPwmPinMode(void);
void Test_TC2_SetPwmPhaseMode(void);
void Test_TC2_SetPwmPhasePinMode(void);
void Test_TC2_SetPwmPhaseFrequencyMode(void);
void Test_TC2_SetPwmPhaseFrequencyPinMode(void);

void Test_TC2_SetTimerMode(void);
void Test_TC2_SetCounterEdge(void);


void Test_TC2_GetTimerReg(void);
void Test_TC2_SetCompareReg(void);

void Test_TC2_StopClock(void);
void Test_TC2_StartClock(void);
void Test_TC2_SetClockPrescalar(void);

void Test_TC2_SetClockResolution_P128USEC_8MHZ(void);
void Test_TC2_SetClockResolution_1USEC_8MHZ(void);
void Test_TC2_SetClockResolution_8USEC_8MHZ(void);
void Test_TC2_SetClockResolution_32USEC_8MHZ(void);
void Test_TC2_SetClockResolution_32USEC_8MHZ(void);
void Test_TC2_SetClockResolution_32USEC_8MHZ(void);
void Test_TC2_SetClockResolution_128USEC_8MHZ(void);

void Test_TC2_EnableTimerInterrupt(void);
void Test_TC2_DisableTimerInterrupt(void);

void Test_TC2_EnableCompareInterrupt(void);
void Test_TC2_DisableCompareInterrupt(void);

void Test_TC2_EnableInputCaptureInterrupt(void);
void Test_TC2_DisableInputCaptureInterrupt(void);

#endif