/**
  ******************************************************************************
  * @file    CharLcd.c
  * @author  GRT/AMK
  * @version V1.0
  * @date    03-Nov-2020
  * @brief   Character Lcd module.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, I SHALL NOT BE HELD LIABLE FOR ANY
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
#include "CharLcd.h"
#include "ATmega16_Port.h"
#include <util/delay.h>  
/**
  * @}
  */
  
 /**
  * @}
  */
 
/** @addtogroup Struct/Union definition and Short Name
  * @{
  */ 
  
 /**
   * @Var	sCLcd
   * @brief	DataStructure for Virtual Lcd Hardware Pins
   */
sCLcd_t     sCLcd;
 
/**
  * @}
  */   
  
  
/** @addtogroup static variable 
  * @{
  */ 

/**
   * @Var	u8DisplayClearHomeCmd
   * @brief	This is command for Clearing display and Returning Home .It can have following different values
   *		CLEAR_LCD_DISPLAY | RETURN_HOME 
   *
   *         RETURN_HOME
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	0	0	0	0	1	 *			 * Don't Care take as 0
   *		:--------------------------------------/
   *			
   *		CLEAR_LCD_DISPLAY
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	0	0	0	0	0	1
   *		:--------------------------------------/
   */
  static uint8_t u8DisplayClearHomeCmd =0x00	;  /*!< Default value */

/**
   * @Var	u8DisplayCmd
   * @brief	This is command for display /Cursor/Blink.It can have following different values
   *		DISPLAY_ON | DISPLAY_OFF| CURS_ON | CURS_OFF| BLINK_ON| BLINK_OFF
   *		D	DISPLAY_ON | DISPLAY_OFF
   *		C	CURS_ON | CURS_OFF
   *		B	BLINK_ON| BLINK_OFF
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	0	0	1	D	C	 B
   *		:--------------------------------------/
   */
  static uint8_t u8DisplayCmd = 0x08	;  /*!< Default value D C B taken as 0 */
 
/**
   * @Var	u8EntryModeCmd
   * @brief	This is command for Entry Mode . It can have following different values
   *		INCREMENT_ADDRESS|DECREMENT_ADDRESS|TEXT_LEFT_TO_RIGHT|TEXT_RIGHT_TO_LEFT  
   *		I/D		INCREMENT_ADDRESS|DECREMENT_ADDRESS
   *		S		TEXT_LEFT_TO_RIGHT|TEXT_RIGHT_TO_LEFT
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	0	0	0	1	I/D	 S
   *		:--------------------------------------/
   */
  static uint8_t u8EntryModeCmd = 0x04	;  /*!< Default value I/D s taken as 0 */  
  
/**
   * @Var	u8CursorTextShiftCmd
   * @brief	This is command for Cursor or Display shift. It can have following different values
   *		CURS_SHIFT|TEXT_SHIFT| SHIFT_RIGHT|SHIFT_LEFT 
   *		S/C		CURS_SHIFT|TEXT_SHIFT
   *		R/L		SHIFT_RIGHT|SHIFT_LEFT
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	0	1	S/C	R/L *	*
   *		:--------------------------------------/
   */
  static uint8_t u8CursorTextShiftCmd = 0x10	;  /*!< Default value S/C R/L and * taken as 0 */   

/**
   * @Var	u8FunctionSetCmd
   * @brief	This is command for 4 Bit or * Bit Interface. It can have following different values
   *		_4BIT_INTERFACE|_8BIT_INTERFACE| _1LINE	|_2LINE	|_5_BY_7|_5_BY_10
   *		DL		_4BIT_INTERFACE|_8BIT_INTERFACE
   *		N		_1LINE	|_2LINE	
   *		F		_5_BY_7|_5_BY_10			
   *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0
   *		:--------------------------------------
   *		:0	0	0	0	1	DL	N	F	*	*
   *		:--------------------------------------/
   */
  static uint8_t u8FunctionSetCmd = 0x20	;  /*!< Default value  DL N F and * taken as 0 */   

  
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
  
  
/**
  * @}
  */      
/** @addtogroup  Static Function DefinItion 
  * @{
  */ 
  
  /**
  * @}
  */     
  
/** @addtogroup  Module Interface Function DefinItion 
  * @{
  */
  
/**
  * @brief			Function write command to Lcd.It generate all hardware
  *					signal necessary to write command.
  * @PreCondition	All ports to which Lcd is connected should be configure
  *					as OUT 
  * @PostCondition  Command is send to Lcd 
  * @param			u8Command
  * @description	Different command Like
  *					Clear Display / Return Home/Entry Mode/ DisplayOn/ 	
  *					Display off / Cursor display shift
  * @retval			None
  * @Test			Tested OK  used Proteus 
  */
void Lcd_WriteCommand(uint8_t u8Command)
{	
	/* NOTE : !!!!!!!!!!Do not alter the sequence  */
			/* Clear Control Signals */
            u8LcdControl = CLEAR_CONTROL ;
		    /* Output Data on Data Port */
			 u8LcdData = u8Command ;
			 SW_TO_HW_LCD_DATA;
			/*RS Command Register RS =0*/
			bRs = 0;
		    SW_TO_HW_LCD_RS ;	
			/*RW  Write  RW=0 */
			bRw = 0;
			SW_TO_HW_LCD_RW ;
			/* High on Enable pin*/
			bEn = 1;
			SW_TO_HW_LCD_EN ;
		  /*Delay  */
		  _delay_ms(15);
           /*PullDown E Generated High to Low Pulse */
			bEn = 0;
			SW_TO_HW_LCD_EN ;	
			/*Delay  */
			_delay_ms(15);
}

/** 
  * @brief			Function write Data to the Previously set Address Counter of Lcd
  *					by the function Lcd_SetDDRamAddress. This function should be used only
  *					after using Lcd_SetDDRamAddress function. 
  * @PreCondition	None
  * @PostCondition  Data is written to Currently to address set by Lcd_SetDDRamAddress function
  * @param			u8DDRamData
  * @description	RamData
  * @retval			None
  * @Test			Tested OK  used Proteus 
  */

void Lcd_WriteData(uint8_t u8DDRamData)
{ 
	/* NOTE : !!!!!!!!!!Do not alter the sequence  */
		/* Clear Control Signals */
			u8LcdControl = CLEAR_CONTROL ;
		/* Write Lcd Data to Virtual Pins and then Copy to MCU pins */
			u8LcdData = u8DDRamData;
			SW_TO_HW_LCD_DATA;	  
      	/*RS Data Register RS = 1*/
			bRs = 1;	
			SW_TO_HW_LCD_RS;
		/*RW  Write  RW=0 */	
   	        bRw = 0;
		   	SW_TO_HW_LCD_RW;
		/*Generate (Falling Edge) H-to-L pulse on Enable pin*/	   
            bEn = 1;
		 	SW_TO_HW_LCD_EN;
		 /*Delay  */
		 _delay_ms(10);	 
        /*Make enable pin = 0 for H-to-L pulse*/
            bEn = 0;	
			SW_TO_HW_LCD_EN;	
			/*Delay  */
			_delay_ms(15);
}
/** 
  * @brief			Function Initialize Ports of Lcd 
  * @PreCondition	None
  * @PostCondition  All ports connected to Lcd are configured properly. 
  * @param			void
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_HwInit(void)
{
	/* Set Lcd Data port Direction as OUT */
		//Port_SetPortDirection(PORTA_,PORT_OUT );
		
		Port_SetPinDirection(PORTA_PA0,PIN_OUT);
		Port_SetPinDirection(PORTA_PA1,PIN_OUT);
		Port_SetPinDirection(PORTA_PA2,PIN_OUT);
		Port_SetPinDirection(PORTA_PA3,PIN_OUT);
		Port_SetPinDirection(PORTA_PA4,PIN_OUT);
		Port_SetPinDirection(PORTA_PA5,PIN_OUT);
		Port_SetPinDirection(PORTA_PA6,PIN_OUT);
		Port_SetPinDirection(PORTA_PA7,PIN_OUT);
	
	/* Set Lcd Control Port Direction as OUT */	
		/*  Signal RS  PORTC_PC7*/
		Port_SetPinDirection(PORTC_PC5,PIN_OUT);  
		/*  Signal RW  PORTC_PC6*/
		Port_SetPinDirection(PORTC_PC6,PIN_OUT);
		/*  Signal EN PORTC_PC5*/
		Port_SetPinDirection(PORTC_PC7,PIN_OUT);
}

/**
  * @brief			.
  * @PreCondition	All ports to which Lcd is connected should be configure
  *					as OUT 
  * @PostCondition  Lcd is initialize to receive command. 
  * @param			void
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_LcdInit(void)
{
	/* This Sequence is mentioned in Data sheet of Lcd Controller*/
	
	/* wait for 15 msec after Power Up as per data sheet but
	   we will wait little more 20 msec */    
//		_delay_ms(20);
	/* Send Follwing Command 
		RS	R/W	D7	D6	D5	D4	D3	D2	D1	D0 
		0	0	0	0	1	1	x	x	x	x   we take x =0
		So command is 0x30 
	 */
		Lcd_WriteCommand(0x30);
	/* wait for 4.1 msec as per data sheet but we will wait little more 20 msec */    		
		_delay_ms(20);		
	/* Send the above bit pattern again  */
		Lcd_WriteCommand(0x30);
	/* wait for  more then 100 usec  as per data sheet but we will wait little more 20 msec */    
		_delay_ms(20);		
	/*Send FunctionSet Command */
		u8FunctionSetCmd  |=	_8BIT_INTERFACE;
		u8FunctionSetCmd  |=	_2LINE; 
		u8FunctionSetCmd  &=	_5_BY_7;
		Lcd_WriteCommand(u8FunctionSetCmd);
	/* Set Entry Mode as Required  */
		u8EntryModeCmd  |= INCREMENT_ADDRESS;
		Lcd_WriteCommand(u8EntryModeCmd);	
 	/* Send Display Clear  */
	u8DisplayClearHomeCmd |= CLEAR_LCD_DISPLAY ;
	u8DisplayClearHomeCmd |= RETURN_HOME;
	Lcd_WriteCommand(u8DisplayClearHomeCmd);	
	/* Send Display ON/OFF Control as required  */
	u8DisplayCmd |= DISPLAY_ON	;
	//u8DisplayCmd |= CURS_ON	;
	Lcd_WriteCommand(u8DisplayCmd);
	/* Set Curson ON */
		Lcd_CursorOn();	
		
}

/** 
  * @brief			Function Set The Address Counter of Lcd to u8DDRamAddress
  *					So that when Data is written it is written to this address.
  * @PreCondition   None	
  * @PostCondition  Lcd Address counter is set to the value of u8DddRamAddress.
  * @param			u8DDRamAddress
  * @description	DDRamAddress value.
  * @retval			None
  * @Test			Tested OK used Proteus 
  */

void Lcd_SetCursorPosition(uint8_t  u8PositionAddress)
{
	/* Single Line LCD Type */
	#if(LCD_TYPE == _8_BY_1 || LCD_TYPE == _16_BY_1 || LCD_TYPE == _20_BY_1 || LCD_TYPE == _40_BY_1)
		 if((u8PositionAddress >= FIRST_LINE_START_ADDRESS) )
		 {	 /* Lcd type 8x1 */
			#if(LCD_TYPE == _8_BY_1 )
				if(u8PositionAddress <= _8_BY_1_FIRST_LINE_END_ADDRESS)
				{Lcd_WriteCommand( u8PositionAddress);
				}
			#endif	
			/* Lcd type 16x1 */
			#if(LCD_TYPE == _16_BY_1 )
				if(u8PositionAddress <= _16_BY_1_FIRST_LINE_END_ADDRESS)
				{Lcd_WriteCommand( u8PositionAddress);
				}
			#endif
			/* Lcd type 20x1 */
			#if(LCD_TYPE == _20_BY_1 )
				if(u8PositionAddress <= _20_BY_1_FIRST_LINE_END_ADDRESS	)
				{Lcd_WriteCommand( u8PositionAddress);
				}
			#endif
			/* Lcd type 40x1 */
			#if(LCD_TYPE == _40_BY_1 )
				if(u8PositionAddress <= _40_BY_1_FIRST_LINE_END_ADDRESS		)
				{Lcd_WriteCommand( u8PositionAddress);
				}
			#endif
				  
		 }
		 else 
		  {
			  /* First Line Error Code */
		  }
	#endif
	
	/* Dual Line Lcd Type */
	#if(LCD_TYPE == _8_BY_2 || LCD_TYPE == _16_BY_2 || LCD_TYPE == _20_BY_2 || LCD_TYPE == _40_BY_2) 
			 /* Lcd type 8x2 */
			#if(LCD_TYPE == _8_BY_2 )
				if(((u8PositionAddress >= FIRST_LINE_START_ADDRESS) && (u8PositionAddress <= _8_BY_1_FIRST_LINE_END_ADDRESS)) ||
					((u8PositionAddress >= SECOND_LINE_START_ADDRESS) && (u8PositionAddress <= _8_BY_1_SECOND_LINE_END_ADDRESS))
					{Lcd_WriteCommand( u8PositionAddress);
					}
			#endif
			/* Lcd type 16x2*/
			#if(LCD_TYPE == _16_BY_2 )
				if(((u8PositionAddress >= FIRST_LINE_START_ADDRESS) && (u8PositionAddress <= _16_BY_1_FIRST_LINE_END_ADDRESS)) ||
					((u8PositionAddress >= SECOND_LINE_START_ADDRESS) && (u8PositionAddress <= _16_BY_1_SECOND_LINE_END_ADDRESS)))
					{Lcd_WriteCommand( u8PositionAddress);
					}
			#endif
			/* Lcd type 20x2 */
			#if(LCD_TYPE == _20_BY_2 )
				if(((u8PositionAddress >= FIRST_LINE_START_ADDRESS) && (u8PositionAddress <= _20_BY_1_FIRST_LINE_END_ADDRESS)) ||
					((u8PositionAddress >= SECOND_LINE_START_ADDRESS) && (u8PositionAddress <= _20_BY_1_SECOND_LINE_END_ADDRESS)))
					{Lcd_WriteCommand( u8PositionAddress);
					}
			#endif
			/* Lcd type 40x2 */
			#if(LCD_TYPE == _40_BY_2 )
				if(((u8PositionAddress >= FIRST_LINE_START_ADDRESS) && (u8PositionAddress <= _40_BY_1_FIRST_LINE_END_ADDRESS)) ||
					((u8PositionAddress >= SECOND_LINE_START_ADDRESS) && (u8PositionAddress <= _40_BY_1_SECOND_LINE_END_ADDRESS)))
					{Lcd_WriteCommand( u8PositionAddress);
					}
			#endif
			
	#endif
}

/** 
  * @brief			Clear all the characters of the display
  * @PreCondition	None
  * @PostCondition  Display is Blank. No Character is displayed.
  * @param			void
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_DisplayClear(void)
{  
	/* Send command  CLEAR_LCD_DISPLAY to Lcd */
	u8DisplayClearHomeCmd |= CLEAR_LCD_DISPLAY ;
	Lcd_WriteCommand(u8DisplayClearHomeCmd);
}

/** @brief				Lcd_Home
  * @brief			Return the cursor to the home position.
  * @PreCondition	None
  * @PostCondition  Cursor is bring to first line  first position.
  * @param			void
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_CursorHome(void)
{
	/* Send command  RETURN_HOME to Lcd */
	u8DisplayClearHomeCmd |= RETURN_HOME ;
	Lcd_WriteCommand(u8DisplayClearHomeCmd);
}

/** 
  * @brief			Position the LCD cursor; that is, set the location at 
  *					which subsequent text written to the LCD will be displayed.
  * @PreCondition	None
  * @PostCondition  Cursor is shifted to position .
  * @param			u8Line
  * @description	Line no
  * @param			u8Column
  * @description	Column no
  * @retval			None
  * @Test
  */
void Lcd_SetCursor(uint8_t u8Line, uint8_t u8Column)
{ 
	uint8_t	u8DDRamAddr =_1L1P ;
	/* Check Line Parameter */
	 if((u8Line >=1) && (u8Line <=2))
	 {	/* Check Column Parameter */ 
			if ((u8Column >= 1) &&  (u8Column <= COLUMN))
				{		if(u8Line == 1)
						   { /*Generate DDRAM address from u8Column*/
							  u8DDRamAddr = FIRST_LINE_START_ADDRESS + (u8Column - 1) ;
						   }
					   #if(LCD_TYPE == _8_BY_2 || LCD_TYPE == _16_BY_2 || LCD_TYPE == _20_BY_2 || LCD_TYPE == _40_BY_2) 
							if(u8Line == 2)  
							{	/*Generate DDRAM address from u8Column*/
								u8DDRamAddr = SECOND_LINE_START_ADDRESS  + (u8Column - 1) ;
							}
					   #endif	
						Lcd_WriteCommand(u8DDRamAddr);   	
				}
	 }
}

/** 
  * @brief			Print text to Lcd at the current cursor Position 
  * @PreCondition	None
  * @PostCondition  Text is printed.
  * @param			*ptrChar
  * @description	Pointer to character Array.
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_Printf(const char *ptrString )
{  
	/* loop till end of the String */
	while (*ptrString != '\0')
	 {	/* Write Data to DDRam */
		 Lcd_WriteData(*ptrString);
		 /* Go to Next Character */
		 ptrString++;
	 }
}

/** 
  * @brief			Display the LCD cursor: an underscore (line) 
  *					at the position to which the next character will be written.
  * @PreCondition	None
  * @PostCondition  Cursor is Displayed
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_CursorOn(void)
{	
	 /* send command for Cursor ON */
	u8DisplayCmd |= CURS_ON; 	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/** 
  * @brief			Hides the LCD cursor.
  * @PreCondition	None
  * @PostCondition  Cursor is not Displayed
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_CursorOff(void)
{	
	/* send command for Cursor OFF */
	u8DisplayCmd &= CURS_OFF ;	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/** 
  * @brief			Display the blinking LCD Character. If used in combination with 
  *					the cursor() function the result will depend on the particular display.
  * @PreCondition	None
  * @PostCondition  Character is Blink
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_BlinkOn(void)
{	
	/* send command for Blink ON */
	u8DisplayCmd |= BLINK_ON; 	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/** 
  * @brief			Turns off the blinking LCD cursor.
  * @PreCondition	None
  * @PostCondition  No blinking of Character.
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_BlinkOff(void)
{	
	/* send command for Blink OFF */
	u8DisplayCmd &= BLINK_OFF; 	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/** 
  * @brief			Turns on the LCD display, after it's been turned off with noDisplay().
  *					This will restore the text (and cursor) that was on the display.
  * @PreCondition	None
  * @PostCondition  Turn On Display.
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_DisplayOn(void)
{	
	/* send command for Display ON */
	u8DisplayCmd |=DISPLAY_ON	; 	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/**
  * @brief			Turns off the LCD display, without losing the text currently shown on it.
  * @PreCondition	None
  * @PostCondition  Turn Off Display.
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_DisplayOff(void)
{	
	/* send command for Display ON */
	u8DisplayCmd &= DISPLAY_OFF	; 	/*!< Other bits in u8DisplayCmd are unaffected */
	Lcd_WriteCommand(u8DisplayCmd);
}

/** 
  * @brief			Scrolls the contents of the display (text and cursor) one space to the left.
  * @PreCondition	None
  * @PostCondition  Display is Shifted to one space Left
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_ScrollDisplayLeft(void)
{  
	/* Form the u8CursorDisplayShiftCmd command*/
	u8CursorTextShiftCmd |= TEXT_SHIFT;
	u8CursorTextShiftCmd &= SHIFT_LEFT ;
	Lcd_WriteCommand(u8CursorTextShiftCmd);	
}

/** 
  * @brief			Scrolls the contents of the display (text and cursor) one space to the right.
  * @PreCondition	None
  * @PostCondition  Display is Shifted to one space Right
  * @param			None
  * @description	None
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_ScrollDisplayRight(void)
{	
	/* Form the u8CursorDisplayShiftCmd command*/
	u8CursorTextShiftCmd |= TEXT_SHIFT;
	u8CursorTextShiftCmd |= SHIFT_RIGHT;
	Lcd_WriteCommand(u8CursorTextShiftCmd);
}

/** 
  * @brief			Turns on automatic scrolling of the LCD. This causes each character 
  *					output to the display to push previous characters over by one space.
  *					If the current text direction is left-to-right (the default), the display scrolls to the left;
  *					if the current direction is right-to-left, the display scrolls to the right.
  *					This has the effect of outputting each new character to the same location on the LCD.
  * @PreCondition	None
  * @PostCondition  Display is Scroll
  * @param			None
  * @description	None
  * @retval			None
  * @Test
  */
void Lcd_AutoScroll(char *pchar)
{
	while (*pchar |= '\0')
	{
		Lcd_ScrollDisplayLeft();
		_delay_ms(10);
		
	}
}

/** 
  * @brief			Turns off automatic scrolling of the LCD.
  * @PreCondition	None
  * @PostCondition  Stop scrolling display.
  * @param			None
  * @description	None
  * @retval			None
  * @Test
  */
void Lcd_NoAutoScroll(void)
{
	

}

/** 
  * @brief			Set the direction for text written to the LCD to left-to-right, the default.
  *					This means that subsequent characters written to the display will go from left to right,
  *					but does not affect previously output text.
  * @PreCondition	None
  * @PostCondition  Characters are written left to right.
  * @param			None
  * @description	None
  * @retval			None
  * @Test
  */
void Lcd_TextLeftToRight(void)
{	
	/* Form the u8EntryModeCmd command*/
	u8EntryModeCmd |= TEXT_LEFT_TO_RIGHT;
	Lcd_WriteCommand(u8EntryModeCmd);
}

/** 
  * @brief			Set the direction for text written to the LCD to right-to-left (the default is left-to-right).
  *					This means that subsequent characters written to the display will go from right to left,
  *					but does not affect previously-output text.
  * @PreCondition	None
  * @PostCondition  Characters are written right to left.
  * @param			None
  * @description	None
  * @retval			None
  * @Test
  */
void Lcd_TextRightToLeft(void)
{
	/* Form the u8EntryModeCmd command*/
	u8EntryModeCmd &= TEXT_RIGHT_TO_LEFT;
	u8EntryModeCmd &= DECREMENT_ADDRESS;
	Lcd_WriteCommand(u8EntryModeCmd);
}

/** 
  * @brief			Create a custom character (glyph) for use on the LCD. Up to eight characters of 5x8 pixels 
  *					are supported (numbered 0 to 7). The appearance of each custom character is specified by 
  *					an array of eight bytes, one for each row. The five least significant bits of each byte determine the pixels
  *					in that row. To display a custom character on the screen, write() its number.
  *					NB : When referencing custom character "0", if it is not in a variable, you need to cast it as a byte,
  *					otherwise the compiler throws an error. 
  * @PreCondition	None
  * @PostCondition  Characters are written right to left.
  * @param			num
  * @description	Which Character to Create (0-7)
  * @param			Data
  * @description	The character's pixel data array
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_CreateCustomChar(uint8_t CGRamAddress, const char CharData[])
{
	 uint8_t dataIndex,Data;
		Lcd_WriteCommand(CGRamAddress);
		/* Write Custom Char data */
		for (dataIndex = 0; dataIndex<8 ;dataIndex++)
		{
			Data =CharData[dataIndex];
			Lcd_WriteData(Data);	
		}
}

/** 
  * @brief			Display Custom character on Lcd
  * @PreCondition	None
  * @PostCondition  Custom Character is Displayed.
  * @param			num
  * @description	Which Character to display (0-7)
  * @retval			None
  * @Test			Tested OK used Proteus 
  */
void Lcd_PrintCustomChar(uint8_t num)
{
	/* Valid ommand number for printing Custom Char */
	if(num >= 0 || num <=7)
    {  
		Lcd_WriteData(num);
	}
}

/**
  * @}
 */
