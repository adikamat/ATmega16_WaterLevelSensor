/**
  ******************************************************************************
  * @file    PulseOut.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    11-July-2020
  * @brief   Pulse Module use TC0 timer for pulse generation.
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
  
/** 
  * @brief  system header  
  */


/** 
  * @brief  Application specific header  
  */
#include "PulseOut.h"
#include "Atmega16_Port.h"
#include <util/delay.h> 

/**
  * @}
  */
 
/** @addtogroup Struct/Union definition and Short Name
  * @{
  */ 
  
 
 
/**
  * @}
  */   
  
  
/** @addtogroup static variable 
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
  
/** @addtogroup variable declaration 
  * @{
  */ 
sPulseOut_t		sPulseOut;  
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

/** 			
  * @brief			Initialize Input Capture Structure. 
  * 
  *	@details
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None 
  * @test	Tested OK.
  */
void PO_InitStructure(void)
{
sPulseOut.u8McuPin = DUMMY_MCU_PIN;	 /*!< Pin No on which pulse is generated */
sPulseOut.u8PulseType = RISING_EDGE; /*!< Type of Pulse */
sPulseOut.u8Unit = U;				 /*!< Shows whether duration is in Umicro/ M milli sec. */
sPulseOut.u16Duration = 0;			 /*!< Duration for which pulse is generated */
sPulseOut.u16RepeatCount = 0;		/*!< No of times pulse is repeated on McuPin */
sPulseOut.u16InterPulseDelay = 0;	/*!< Time difference between pulse*/
sPulseOut.u8TimerResolution = _1_USEC;
}

/** 			
  * @brief			Initialize Module. 
  * 
  *	@details
  * @PreCondition	None
  * @PostCondition  None
  * @param			void
  * @description	None
  * @retval			None 
  * @test	Tested OK.
  */

void PO_Init(void)
{   /* Call Default Structure*/
	 PO_InitStructure();
	 /* Set Pulse Parameter*/
	 PO_SetPulseParameter(PORTD_PD4,50,U,RISING_EDGE);
	 /* We have to register PO_PulseInterruptService or  service Routine */
	 PO_RegisterTimerOverflowIntService(&PO_RepeatPulseInterruptService,0); 
}

/** 
  * @brief			Set the pulse parameter i.e  pulse duration and time unit
  * 
  * @details
  * @PreCondition	None
  * @PostCondition  None
  * @param			mcupin
  * @description	PORTx_Pxy  where x is A/B/C/D and y is 0 to 7
  * @param			duration
  * @description	duration for which pin is either high or low.
  * @param			unit
  * @description	Shows whether duration is in micro/milli second.
  *					This has got value U MicroSecond, M MilliSecond
  * @param			pulsetype
  * @description	Pulse type whether rising edge or falling edge.
  * @return			None.
  * @test	Tested OK.
  */
void PO_SetPulseParameter(uint8_t mcupin,uint16_t duration,uint8_t unit, 
						  uint8_t pulsetype)


{
		sPulseOut.u8McuPin = mcupin;
		sPulseOut.u16Duration = duration;
		sPulseOut.u8Unit = unit;
		sPulseOut.u8PulseType = pulsetype;
		/* Set Direction of mcupin as out*/
		Port_SetPinDirection(sPulseOut.u8McuPin,PIN_OUT);
		/* Set Mcu pin Initial State according to Pulse Type */
		if(sPulseOut.u8PulseType == RISING_EDGE)
			Port_WritePin(sPulseOut.u8McuPin,PIN_LOW);
		if(sPulseOut.u8PulseType == FALLING_EDGE	)
			Port_WritePin(sPulseOut.u8McuPin,PIN_HIGH);
		/* Set TC0 in timer mode */
		TC0_SetTimerMode(TC0_TOP_0XFF);
		/* We have to register PO_PulseInterruptService or  service Routine */
		PO_RegisterTimerOverflowIntService(&PO_PulseInterruptService,0);
}

/** 
  * @brief			Set the Repeat pulse parameter like u16RepeatCount and 
  *					u16InterPulseDelay
  * 
  * @details
  * @PreCondition	None
  * @PostCondition  None
  * @param			repeatCount
  * @description	count for which no of times pulse is generated.
  * @param			interpulsedelay
  * @description	time duration between two pulse.
  * @retval			None.
  * @test	Tested OK.
  */
void PO_SetRepeatPulseParameter(uint8_t mcupin,uint16_t duration,uint8_t unit, 
								uint8_t pulsetype,uint16_t repeatCount,
								uint16_t interpulsedelay)
{
		PO_SetPulseParameter(mcupin,duration,unit,pulsetype);
		sPulseOut.u16RepeatCount = repeatCount;
		sPulseOut.u16InterPulseDelay = interpulsedelay;
		
}

/** 
  * @brief			This function get the proper count in timer register and
  *					also set which timer resolution to be used to get that pulse
  *					duration
  *					
  *	@details
  * @PreCondition	None.
  * @PostCondition  None.
  * @param			void
  * @description    None
  * @retval			Count to be loaded in timer register
  * @test	Not Tested.
  */
uint8_t PO_GetCount(void)
{	uint8_t u8count = 0;
		/* Load the count for 8 Mhz crystal */
	#if( MCU_CLOCK == CLOCK_8_MHZ)
			/* Resolution P125 usec*/
		if(sPulseOut.u16Duration >0 && sPulseOut.u16Duration < 32 && sPulseOut.u8Unit == U)			
			{u8count = (uint8_t)255 - (uint8_t)(sPulseOut.u16Duration * 8);
			 sPulseOut.u8TimerResolution = _P125_USEC;	
			}
			/* Resolution 1 usec*/	
		else if (sPulseOut.u16Duration >= 32 && 
				sPulseOut.u16Duration <= 255 && 
				sPulseOut.u8Unit == U)
			{u8count = (uint8_t)255 - (uint8_t)sPulseOut.u16Duration ;
			 sPulseOut.u8TimerResolution = _1_USEC;	
			}
			/* Resolution 8 usec*/
		else if (sPulseOut.u16Duration > 255 &&
				 sPulseOut.u16Duration <= 2000 && 
				 sPulseOut.u8Unit == U)	
			{u8count = (uint8_t)255 - (uint8_t)(sPulseOut.u16Duration >> 3) ;
			 sPulseOut.u8TimerResolution = _8_USEC;	
			}
			/* Resolution 8 usec*/
		else if (sPulseOut.u16Duration >= 1 &&
				 sPulseOut.u16Duration <= 2 && 
				 sPulseOut.u8Unit == M)	
			{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 3);
			 sPulseOut.u8TimerResolution = _8_USEC;	
			}
			/* Resolution 32 usec*/	
		else if (sPulseOut.u16Duration > 2 &&
				 sPulseOut.u16Duration <= 8 &&
				 sPulseOut.u8Unit == M)	
			{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 5);
			 sPulseOut.u8TimerResolution = _32_USEC;	
			}
			/* Resolution 128 usec*/	
		else if (sPulseOut.u16Duration > 8 &&
		         sPulseOut.u16Duration <= 32 &&
				 sPulseOut.u8Unit == M)	
			{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 7);
			sPulseOut.u8TimerResolution = _128_USEC;	
			}
		else {}	
	#endif

	/* Load the count for 16 Mhz crystal  */
	#if( MCU_CLOCK== CLOCK_16_MHZ)
		/* Resolution P0625 usec*/
		if(sPulseOut.u16Duration >0 &&
		   sPulseOut.u16Duration < 15 && 
		   sPulseOut.u8Unit == U)			
		{u8count = (uint8_t)255 - (uint8_t)(sPulseOut.u16Duration * 16);
		sPulseOut.u8TimerResolution = _128_USEC;	
		}
		/* Resolution .5 usec*/	
		else if (sPulseOut.u16Duration >= 15 &&
		         sPulseOut.u16Duration <= 127 && 
				 sPulseOut.u8Unit == U)
		{u8count = (uint8_t)255 - (uint8_t)sPulseOut.u16Duration *2 ;
		sPulseOut.u8TimerResolution = _P5_USEC;	
		}
		/* Resolution 4 usec*/	
		else if (sPulseOut.u16Duration > 127 &&
		         sPulseOut.u16Duration <= 1000 && 
				 sPulseOut.u8Unit == U)	
		{u8count = (uint8_t)255 - (uint8_t)(sPulseOut.u16Duration >> 2) ;
		sPulseOut.u8TimerResolution = _4_USEC;	
		}
		/* Resolution 4 usec*/
		else if (sPulseOut.u16Duration >= 1 &&
		         sPulseOut.u16Duration <= 2 && 
				 sPulseOut.u8Unit == M)	
		{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 2);
		 sPulseOut.u8TimerResolution = _4_USEC;
		}
		/* Resolution 16 usec*/	
		else if (sPulseOut.u16Duration > 2 &&
		         sPulseOut.u16Duration <= 4 && 
				 sPulseOut.u8Unit == M)	
		{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 4);
		sPulseOut.u8TimerResolution = _16_USEC;
		}
		/* Resolution 64 usec*/	
		else if (sPulseOut.u16Duration > 4 && 
		         sPulseOut.u16Duration <= 16 && 
				 sPulseOut.u8Unit == M)	
		{u8count = (uint8_t)255 - (uint8_t)((sPulseOut.u16Duration * 1000) >> 6);
		sPulseOut.u8TimerResolution = _64_USEC;	
		}
		else {}

	#endif
	return (u8count);
}

/** 
  * @brief			When Clock Resolution is set timer clock is started 
  *					There is no separate bit in Atmega16 to start Timer
  *					
  *	@details				
  * @PreCondition	None.
  * @PostCondition  None.
  * @param			void
  * @description    None
  * @retval			None
  * @test	Not Tested.
  */
void PO_StartTimer(uint8_t u8count)
{
	/* Load Count into Timer register */
	TC0_SetTimerReg(u8count);
	 /* Enable T0 Timer interrupt */
	 TC0_EnableTimerInterrupt();
	/* Timer is started  When Resolution is set . There is no separate bit for
	 * it in ATmega16 */
	#if( MCU_CLOCK == CLOCK_8_MHZ)
		 if((sPulseOut.u8TimerResolution == _P125_USEC) &&
		    (sPulseOut.u8Unit == U))
		 {	TC0_SetClockResolution_P125USEC_8MHZ();
		 }
		 else if ((sPulseOut.u8TimerResolution == _1_USEC) &&
		         (sPulseOut.u8Unit == U))
		 {	TC0_SetClockResolution_1USEC_8MHZ();
		 }
		 else if ((sPulseOut.u8TimerResolution == _8_USEC) &&
		           (sPulseOut.u8Unit == U))
		 {	TC0_SetClockResolution_8USEC_8MHZ();
		 }
		 else if ((sPulseOut.u8TimerResolution == _8_USEC) &&
		          (sPulseOut.u8Unit == M))
		 {	TC0_SetClockResolution_8USEC_8MHZ();
		 }
		 else if ((sPulseOut.u8TimerResolution == _32_USEC) &&
		          (sPulseOut.u8Unit == M))
		 {	TC0_SetClockResolution_32USEC_8MHZ();
		 }
		 else if ((sPulseOut.u8TimerResolution == _128_USEC) && 
		          (sPulseOut.u8Unit == M))
		 {	TC0_SetClockResolution_128USEC_8MHZ();
		 }
		 else {}
	  	 
	#endif
		 
	#if( MCU_CLOCK== CLOCK_16_MHZ)
		/* Resolution P0625 usec*/
		if((sPulseOut.u8TimerResolution == _128_USEC) &&
		   (sPulseOut.u8Unit == U))			
			{TC0_SetClockResolution_P0625USEC_16MHZ();
			}
		/* Resolution .5 usec*/
		else if ((sPulseOut.u8TimerResolution == _P5_USEC) &&
		        (sPulseOut.u8Unit == U))
			{TC0_SetClockResolution_P5USEC_16MHZ();
			}
		/* Resolution 4 usec*/	
		else if ((sPulseOut.u8TimerResolution == _4_USEC) &&
		        (sPulseOut.u8Unit == U))	
			{TC0_SetClockResolution_4USEC_16MHZ();
			}
		/* Resolution 4 usec*/	
		else if ((sPulseOut.u8TimerResolution == _4_USEC) &&
		        (sPulseOut.u8Unit == M))	
			{TC0_SetClockResolution_4USEC_16MHZ();
			}
		/* Resolution 16 usec*/	
		else if ((sPulseOut.u8TimerResolution == _16_USEC) &&
		         (sPulseOut.u8Unit == M))	
			{TC0_SetClockResolution_16USEC_16MHZ();
			}
			/* Resolution 64 usec*/
		else if ((sPulseOut.u8TimerResolution == _64_USEC) && 
		         (sPulseOut.u8Unit == M))
			{TC0_SetClockResolution_64USEC_16MHZ();
			}
		else {}
	#endif
}

/** 
  * @brief
  *
  * @details		Create Pulse High or Low on MCU pin for specific duration.
  *					Function write pin value(HIGH or LOW) on mcu pin it configure timer0
  *					according to duration and load count into TCNT0 register. It enables 
  *					Interrupt and start Timer. Delay is created using Interrupt.
  *					Prescalar has to be set according to unit and duration. We have following values @8Mhz 
  *					Prescalar		T from Prescalar		8 Bit overflow( Max Time duration )
  *					1				0.125 usec				32 usec
  *					8				1 usec					256 usec
  *					64				8 usec					2.048 msec
  *					256				32 usec					8.192 msec
  *					1024			128 usec				32.768 msec
  * NOTE:			when Clock Resolution is set timer clock is started so no need
  *					to call TC0_StartTimer which actually call same function.
  *					
  * @PreCondition	Function PO_SetPulseParameter
  *					should be called before calling this function.
  * @PostCondition  
  * @param			None
  * @description	None
  * @retval			None.
  * @test	Tested OK.
  */
void PO_GeneratePulseInt(void)
{ uint8_t u8count = 0;
 /* Get Count to be Loaded*/ 	
u8count = PO_GetCount();
/* Start timer */
PO_StartTimer(u8count);
}

/** 
  * @brief			Generate pulse by using NOP operation.Use for short pulse.
  * 
  * @details
  * @PreCondition	None
  * @PostCondition  None
  * @param			mcuPin
  * @description	mcu pin on which pulse is to generated.
  * @param			pulsetype
  * @description	RISING_EDGE or FALLING_EDGE
  * @param			duration
  * @description	_10USEC /_15USEC/_20USEC
  * @retval			None.
  * @test	
  */
void PO_GeneratePulseSw	(uint8_t mcuPin,uint8_t duration,uint8_t pulsetype)
{ 	
	/* whether rising edge or falling edge PortPin direction should be out*/
  	Port_SetPinDirection(mcuPin,PIN_OUT);
	if(pulsetype == RISING_EDGE)
	{  /* initial value of port pin is HIGH */
		Port_WritePin(mcuPin,PIN_HIGH);
		while (duration >0)
		{	asm ("NOP");
			duration-- ;
		}
		//_delay_us(100);
		/* Final value of port pi is LOW */	
		Port_WritePin(mcuPin,PIN_LOW);
	}
	if (pulsetype == FALLING_EDGE)
	{/* initial value of port pin is LOW */
		Port_WritePin(mcuPin,PIN_LOW);
		while (duration >0)
		{	asm ("NOP");
			duration-- ;
		}
		/* Final value of port pi is HIGH */
		Port_WritePin(mcuPin,PIN_HIGH);
	}	
}

/** 		
  * @brief			This function register Timer0 interrupt service routine.
  * 
  * @details
  * @PreCondition	None
  * @PostCondition  None
  * @param			fun
  * @description	This is function pointer to Timer Interrupt Service
  * @param			param
  * @description	This is uint8_t additional parameter user can use.
  * @retval			None
  * @test	Not Tested.  
  */

void PO_RegisterTimerOverflowIntService(fpointerv_t  fun , uint8_t param)	
{
	TC0_RegisterTimerInterruptService(fun,param);
}

/** 	
  * @brief			This function is related toPO_SetPulseParameter.When 
  *					prescribed duration	specified in function is expired this 
  *					function is called.
  *	@details				
  * @PreCondition	None
  * @PostCondition  None.
  * @param			param
  * @description    It is dummy parameter not used in function.	
  * @retval			None
  * @test	 Not Tested.
  */
void PO_PulseInterruptService(uint8_t param)
{ 
/* Stop Timer */
TC0_StopTimer();
/* change the pin state. If high make it low. If low make it High */
if(sPulseOut.u8PulseType == RISING_EDGE)
	Port_WritePin(sPulseOut.u8McuPin,PIN_LOW);
if(sPulseOut.u8PulseType == FALLING_EDGE)
	Port_WritePin(sPulseOut.u8McuPin,PIN_HIGH);
/* Disable Timer Interrupt */
TC0_DisableTimerInterrupt();
}

/** 
  * @brief	This function is related to PO_SetRepeatPulseParameter.When
  *			prescribed duration specified in function expired this function 
  *			is called.
  *					
  *	@details				
  * @PreCondition	None.
  * @PostCondition  None.
  * @param			param
  * @description    It is dummy parameter not used in function.
  * @retval			None
  * @test	Not Tested.
  */
void PO_RepeatPulseInterruptService(uint8_t param)
{
	/* Decrement Count */
	 sPulseOut.u16RepeatCount--;
	/* Check Whether no of Pulses are over */
if(sPulseOut.u16RepeatCount != 0)
	{/* change the pin state. If high make it low. If low make it High */
		if(sPulseOut.u8PulseType == RISING_EDGE)
		Port_WritePin(sPulseOut.u8McuPin,PIN_LOW);
		if(sPulseOut.u8PulseType == FALLING_EDGE)
		Port_WritePin(sPulseOut.u8McuPin,PIN_HIGH);
		/* Load */
	}
else
	{	/* Stop Timer */
		TC0_StopTimer();
		/* Disable Timer Interrupt */
		TC0_DisableTimerInterrupt();
	}
}

/**
  * @}
  */

