/**
******************************************************************************
* @file    Ultrasonic.c
* @author  GRT/AMK
* @version V1.0
* @date    18-Feb-2021
* @brief   Ultrasonic Module
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
#include "Ultrasonic.h"
#include "PulseOut.h"
#include "InputCapture.h"
#include "CharLcd.h"

/**
* @}
*/

/** @addtogroup Struct/Union definition and Short Name
* @{
*/
sUltrasonicSensor_t			sUltrasonicSensor;
sObjectStatus_t				sObjectStatus;
/**
* @}
*/


/** @addtogroup static variable
* @{
*/

/**
* @}
*/
/** @addtogroup static fucntion
* @{
*/

/**
* @}
*/

/** @addtogroup variable declaration
* @{
*/
const char WelcomMsg[]={'W','E','L','C','O','M','E','\0'} ;
const char *pcMaxDistanceMsg	= "MAX 400";
const char *pcMinDistanceMsg	= "MIN 2";
const char *pcObjectDistMsg		= "RANGE";

const char *pcUnit				= "cm";
const char *pcOutOfRangeMsg		= "Out Of Range";
const char *pcCollisionMsg		= "On Collision";
const char *pcInRangeMsg		= "In Range";
/* ObjectRange ascii contains XXX.YY'/0' format*/
char	ObjectRangeAscii[7];
char	RangeMinAscii[7];
char	RangeMaxAscii[7];



/**
* @}
*/
/** @addtogroup  Function Definition
* @{
*/

/**
* @}
*/

/** @addtogroup  Module Interface Function Definition
* @{
*/
/**
* @brief	        Initialize object RangeAscii to null.
*
* @details		Initialize Port pin to output to which sensor is connected.
*					Enable Timer1 input Capture Interrupt for detecting rising edge.
*					Register InputCapture Interrupt function.
* @PreCondition	None
* @PostCondition  Port,CaptureEdge,TimerResolution is configured properly.
* @param			None
* @description	None
* @retval			None
* @Test
*/

void Ultra_ClrearObjectRangeAscii(void)
{uint8_t i ;
	for(i=0; i<7; i++)
	{
		ObjectRangeAscii[i] = '\0';
	}
}



/**
* @brief	        Initialize Pulse out and input capture modules.
*
* @details		Initialize Port pin to output to which sensor is connected.
*					Enable Timer1 input Capture Interrupt for detecting rising edge.
*					Register InputCapture Interrupt function.
* @PreCondition	None
* @PostCondition  Port,CaptureEdge,TimerResolution is configured properly.
* @param			None
* @description	None
* @retval			None
* @Test
*/
void  Ultra_Init(void)
{
	/*Initialize trigger pin*/
	//PO_Init();
	/* Initialize InputCapture  */
	//IC_Init();
}

/**
* @brief			Send 10 usec Pulse Out
*
* @details		Send 10usec pulse on Trigger Pin
* @PreCondition	Trigger Pin Should be configured as OutPut.
*					And u16ObjectRange of previous measurement is calculated.
* @PostCondition  10usec Pulse is send on Trigger Pin.
* @param			None
* @description	None
* @retval			None
* @Test
*/
void  Ultra_SendPulse(void)
{
	/* Send pulse on trigger Pin */
	PO_GeneratePulseInt();
}

/** @brief		   Calculate target distance if present
*
* @details		Calculate object Range.
*					Distance Calculation for Ultrasonic Sensor HC-SR04.
*					Sound Velocity (Vs) taken  at 20 Celsius 343.0 m/sec = 34300 cm/sec.
*					Distance travel by sound wave in time T sec is  D = Vs * T  ........ 1
*					Since it travels two times between sensor to object and from object to sensor after
*					bouncing back, the distance to object is given by Do = (Vs * T  )/2 . ........2
*					Time T is provided by the sensor Echo pulse, which is rising pulse.We need following
*					information	to calculate time
*					1]	No of counts between rising edge and falling edge say C.
*					2]	Time resolution of count ,i.e time duration of incrementing one count say Tr
*					3]	So  the pulse duration is  Tp = C * Tr = T .......3
*					Count is given by input capture module  C = [TH:TL]......4
*					Time resolution Tr = 1/Fr where Fr is frequency correspond to Tr.
*					we have  following clock chain in Atmega16
*					------Fclk----->| Prescalar 1,2,8,16 |-Ftclk------>| TC1 timer Module|
*					where  Fclk is Mcu Crystal Frequency. FTclk is frequency input to timer TC1 module
*					which in our case is Fr i.e Fr = Ftclk  and P is prescalar factor.
*					Now Fr is given by Fr = Fclk /p .........5
*					Tr is    Tr = 1/ Fr =  P/Fclk ........ 6
*					putting  4 and 6 into 3 we get
*					Tp = T= [TH:TL] * P /Fclk  ....... 7
*					Putting  7 into 2 we get
*					D0 = (Vs *[TH:TL] * P) /2 * Fclk ......8
*					we have following Parameters
*					Fclk = 8000000 Hz /
*		  		    P = 8 / Ftclk = 1000000
*					Vs =34300 cm /sec so putting into 8 we get
*					Do	= 34300[TH:TL] *8 / 2* 8000000
*						= 17150 [TH:TL]/1000000
*						= 0.01715 * C
*						= C / 58.28   as 1/58.28 = 0.01715
*						in Q0.16 we have round( 0.01715 * 2^16)=  DEC 1124 = Hex 0x0464
*						If we reverse calculate we get  1124/2^16 = 0.017150
*					Variables				Format				Description
*					--------------------------------------------------------
*					u16Difference			Q16.0				Difference in Timestamp
*					Constant				Q0.16				0.01715 =DEC 1124= HEX 0x0464
*					u16ObjectRange			Q10.6				Object distance
*					temp					Q16.16				Intermediate variable.
* @PreCondition	Rising and Falling time stamp should be available.
* @PostCondition  Object range is available and bits are set accordingly.
* @param			None
* @description	None
* @retval			None
* @Test
*/
uint8_t   Ultra_CalculateObjectRange(void)
{ 
	uint8_t status = FALSE;
	uint16_t u16Q1600Count;					/*in Q16.00*/
	uint16_t u16Q0016Constant = 0x0464;		/*in Q00.16*/
	uint32_t u32Q1616temp = 0;				/*in Q16.16*/
	uint8_t  u8DataStatus;
	
	u8DataStatus = IC_GetDataStatus();
	if(u8DataStatus == IC_DATA_CAPTURED )
	{
		/* Get Pulse count */
		u16Q1600Count = IC_GetPulseCount();
		/* Calculate  object distance and store it in u16ObjectRange  */
		u32Q1616temp = (uint32_t)u16Q0016Constant * u16Q1600Count;
		u32Q1616temp = u32Q1616temp >> 10 ;
		u16ObjectRange = (uint16_t)u32Q1616temp;
		/* if object range is between than Max range and Min set bInRange bit*/
		if(u16ObjectRange >= u16DetectionRangeMin &&
		u16ObjectRange <= u16DetectionRangeMax)
		{
			SET_BIT(ObjectRangeStatus,IN_RANGE_BIT);
			CLR_BIT(ObjectRangeStatus,ABOVE_MAX_RANGE_BIT);
			CLR_BIT(ObjectRangeStatus,COLLISION_BIT);
		}
		/* if object range is greater than Max range set bAboveMaxRange bit*/
		if(u16ObjectRange >= u16DetectionRangeMax)
		{
			SET_BIT(ObjectRangeStatus,ABOVE_MAX_RANGE_BIT);
			CLR_BIT(ObjectRangeStatus,IN_RANGE_BIT);
			CLR_BIT(ObjectRangeStatus,COLLISION_BIT);
		}
		/* if object range is less than Max range set bCollision bit*/
		if(u16ObjectRange <= u16DetectionRangeMin)
		{
			SET_BIT(ObjectRangeStatus,COLLISION_BIT );
			CLR_BIT(ObjectRangeStatus,ABOVE_MAX_RANGE_BIT);
			CLR_BIT(ObjectRangeStatus,IN_RANGE_BIT);
		}
		
		/* Convert it into ASCII*/
		Ultra_ConvertDistanceToAscii(u16ObjectRange, ObjectRangeAscii);
		/* We have completed one cycle of capture -calculate-
		change status to IC_DATA_NOT_CAPTURED to start next cycle*/
		Ultra_DisplayObjectRange();
		
		status = TRUE;
	}
	return status;
}

/** @brief			Return Object range.
*
* @details		Get the distance of object in cm
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			Object distance in Q10.6 format.
* @Test			OK
*/
uint8_t  Ultra_GetObjectRange(void)
{  uint8_t ret;
	/* Calculate object range */
	ret = Ultra_CalculateObjectRange();
	/*Start Input Capture Process */
	IC_StartInputCapture();
	/* We have Calculated distance and display Change data status to
	IC_DATA_NOT_CAPTURED*/
	IC_SetDataStatus(IC_DATA_NOT_CAPTURED);
	return ret;
}

/**
* @brief			Ultra_SetMaxRange
*
* @details		Maximum detection range set by user.If object is beyond this
*					range sensor does not detect it.This value is stored in
*					u16DetectionRangeMax in  Q10.6 format.
* @PreCondition	None
* @PostCondition  None
* @param			Range
* @description	Maximum range which user set it.
* @retval			None
* @Test			OK
*/
void   Ultra_SetMaxRange(uint16_t Range)
{ 	/* First get the range in Q10.6 format*/
	Range = Range << 6 ;
	/* Check whether it is in sensor max(400cm) range*/
	if(Range <= ULTASONIC_SENSOR_MAX_RANGE &&  Range > ULTASONIC_SENSOR_MIN_RANGE)
	{  /* value is in range  store value */
		u16DetectionRangeMax = Range ;
	}
	else
	{  /* Set  user Max range equal to Sensor max range */
		u16DetectionRangeMax = ULTASONIC_SENSOR_MAX_RANGE ;
	}
}

/**
* @brief			Ultra_GetMaxRange
*
* @details		Get user setting of Max range.
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			Object distance in Q10.6 format.
* @Test			 OK
*/
uint16_t	Ultra_GetMaxDetectionRange(void)
{
	return(u16DetectionRangeMax);
}

/**
* @brief			 Ultra_SetMinRange
*
* @details		If object comes below this range  Collision flag is set.
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			Object distance in Q16.16 format.
* @Test			 OK
*/
void   Ultra_SetMinRange(uint16_t Range)
{
	/* First get the range in Q10.6 format*/
	Range = Range << 6 ;
	/* Check whether it is in sensor max(400cm) range*/
	if(Range <= ULTASONIC_SENSOR_MAX_RANGE)
	{  /* check whether this value is less than MaxRange value  */
		if(Range < u16DetectionRangeMax && Range >= ULTASONIC_SENSOR_MIN_RANGE )
		u16DetectionRangeMin = Range ;
		else /* Range is less than senor min range */
		{  /* Set user Min range equal to Sensor min range */
			u16DetectionRangeMin = ULTASONIC_SENSOR_MIN_RANGE ;
		}
	}
}
/**
* @brief			Ultra_GetMinRange
*
* @details		Get user setting of Min range.
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			Object distance in Q10.6 format.
* @Test			 OK
*/
uint16_t	Ultra_GetMinDetectionRange(void)
{
	return(u16DetectionRangeMin);
}


/**
* @brief		    Detect if object is in collision course .
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			TRUE if it is in collision course else FALSE .
* @Test
*/
uint8_t Ultra_IsCollision(void)
{
	uint8_t  Status = FALSE;

	if(ISBITSET(ObjectRangeStatus,COLLISION_BIT))
	{
		Status = TRUE;
	}
	return Status;
}

/**
* @brief			Detect if object is in Detection range.
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			TRUE if object is detected else FALSE.
* @Test
*/
uint8_t Ultra_IsObjectInRange(void)
{
	uint8_t  Status = FALSE;
	if(ISBITSET(ObjectRangeStatus,IN_RANGE_BIT))
	{
		Status = TRUE;
	}
	return Status;
}

/**
* @brief			Ultra_IsObjectBeyondRange
*
* @details		Detect if object is beyond Max range.
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			TRUE if object is beyond Max range else FALSE.
* @Test
*/
uint8_t Ultra_IsObjectAboveRange(void)
{
	uint8_t  Status = FALSE;
	if(ISBITSET(ObjectRangeStatus,ABOVE_MAX_RANGE_BIT))
	{
		Status = TRUE;
	}
	return Status;
}


/**
* @brief			Clear string Array
*
* @details		Display Set min range on Lcd
* @PreCondition	None
* @PostCondition  None
* @param			Array[]
* @description	Character array which is to be clear.
* @retval			None
* @Test			 OK
*/
void	Ultra_ClearArray(char Array[])
{ uint8_t  i =0;
	while (i <= 6)
	{    Array[i] = '0';
		if(i==6)
		{
			/*Put String Termination Character */
			Array[i] ='\0';
		}
		i++;
	}
}

/**
* @brief			ReverseString
*
* @details		Reverse the string in Array
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test			 OK
*/
void Ultra_ReverseString(char Array[])
{
	uint8_t i = 0, j = 0, Strlen = 0, temp;
	/* Get String Length*/
	while (Array[i] != '\0')
	{
		Strlen++;
		i++;
	}
	/* Reset Counters*/
	i = 0;
	j = Strlen - 1;
	while (i < j)
	{
		temp = Array[i];
		Array[i] = Array[j];
		Array[j] = temp;
		i++;
		j--;
	}
}

/**
* @brief			Ultra_ConverteDistanceToAscii
*
* @details		Convert Distance which is in Q10.6 format into Ascii
* @PreCondition	None
* @PostCondition  None
* @param			Distance
* @description	Distance in Q10.6 format to be converted into Ascii
* @param			Array[]
* @description	array which hold Distance in Ascii
* @retval			None
* @Test			 OK
*/
void Ultra_ConvertDistanceToAscii(uint16_t  Distance, char Array[])
{
	uint8_t  u8NoOfDigits = 0;
	uint16_t  IntegerMask = 0xFFC0, FractionMask = 0x003F;
	uint16_t IDistance, FDistance, FIDistance;
	/* Get Integer part of Distance*/
	IDistance = Distance & IntegerMask;
	IDistance = IDistance >> 6;
	/* Get fractional part of Distance At this point we have
	FIDistance  fraction equivalent of Integer part
	but in Binary. We need to convert into Ascii */
	FDistance = Distance & FractionMask;
	FIDistance = (FDistance * 1000) / ((uint16_t)1 << 6);

	Ultra_ClearArray(Array);

	/* Convert IDistance into Ascii Character digits */
	uint8_t enteredHundreds = FALSE;
	if (IDistance >= 100)
	{
		Array[u8NoOfDigits++] = IDistance / 100 + '0';
		IDistance = (IDistance % 100);
		enteredHundreds = TRUE;
	}
	if (IDistance >= 10)
	{
		Array[u8NoOfDigits++] = IDistance / 10 + '0';
		IDistance = (IDistance % 10);
	}
	else if (enteredHundreds)
	{
		Array[u8NoOfDigits++] = '0';
	}
	Array[u8NoOfDigits++] = IDistance + '0';

	Array[u8NoOfDigits++] = '.';

	/* Convert FIDistance into Ascii Character digits
	We convert up to two decimal places
	*/
	if (FIDistance >= 1000)
	{
		Array[u8NoOfDigits++] = (FIDistance / 1000) + '0';
		FIDistance = (FIDistance % 1000);
	}
	if (FIDistance >= 100)
	{
		Array[u8NoOfDigits++] = FIDistance / 100 + '0';
		FIDistance = (FIDistance % 100);
	}
	else
	{
		Array[u8NoOfDigits++] = '0';
	}
	if (u8NoOfDigits > 5) return;

	if (FIDistance >= 10)
	{
		Array[u8NoOfDigits++] = FIDistance / 10 + '0';
		FIDistance = (FIDistance % 10);
	}
	else
	{
		Array[u8NoOfDigits++] = '0';
	}
	if (u8NoOfDigits > 5) return;

	Array[u8NoOfDigits++] = FIDistance + '0';
}

/**
* @brief			Set Display RANGE text on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test
*/
void Ultra_DisplayRangeText(void)
{
	Lcd_CursorOff();
	Lcd_SetCursor(1,1);
	Lcd_Printf(pcObjectDistMsg);
}
/**
* @brief			Set Display MAX text on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test
*/
void Ultra_DisplayMaxText(void)
{	/* Set the cursor position */
	Lcd_CursorOff();
	Lcd_SetCursor(2,1);
	Lcd_Printf(pcMaxDistanceMsg);
}
/**
* @brief			Set Display MIN text on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test
*/
void Ultra_DisplayMinText(void)
{	/* Set the cursor position */
	Lcd_CursorOff();
	Lcd_SetCursor(2,12);
	Lcd_Printf(pcMinDistanceMsg);
	
}
/**
* @brief			Set Display Cm text on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test
*/
void Ultra_DisplayCmText(void)
{	/* Set the cursor position */
	Lcd_CursorOff();
	Lcd_SetCursor(1,15);
	Lcd_Printf(pcUnit);
}

/**
* @brief			Display object range on Lcd.
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test
*/

void Ultra_DisplayObjectRange(void)
{
	Lcd_CursorOff();
	Lcd_SetCursor(1,7);
	Lcd_Printf(ObjectRangeAscii);
	
}

/**
* @brief			Display Set max range on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test			OK
*/

void	Ultra_DisplayMaxRange(void)
{
	Lcd_CursorOff();
	Lcd_SetCursor(2,1);
	Lcd_Printf(RangeMaxAscii);
}

/**
* @brief			Display Set min range on Lcd
*
* @details
* @PreCondition	None
* @PostCondition  None
* @param			None
* @description	None
* @retval			None
* @Test			 OK
*/

void Ultra_DisplayMinRange(void)
{
	Lcd_CursorOff();
	Lcd_SetCursor(2,5);
	Lcd_Printf(RangeMinAscii);
}



/**
* @}
*/
