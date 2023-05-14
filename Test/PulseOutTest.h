/**
  ******************************************************************************
  * @file    header.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    15-July-2020
  * @brief   This file provides templete for header.
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
#ifndef  _PULSEOUTTEST_H
#define  _PULSEOUTTEST_H

void Test_PO_InitStructure(void);
void Test_PO_SetMcuPin(void);
void Test_PO_SetPulseParameter(void);
void Test_PO_SetRepeatPulseParameter(void);
void Test_PO_Init(void);
void Test_PO_GeneratePulse(void);
void Test_PO_RepeatPulse(void);



#endif