/**
  ******************************************************************************
  * @file    CharLcd.h
  * @author  GRT/AMK
  * @version V1.0
  * @date    15-July-2020
  * @brief   Contains macro and data structure for LCD.Vartual LCD port is defined and all
             the function defined in this module acts on this virtual Lcd  port.
			 CLcd = Character LCD
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
#ifndef  _CHAR_LCD_H
#define  _CHAR_LCD_H

/** @addtogroup  Header
  * @{
  */
  
/** 
  * @brief  system header  
  */
#include "System.h"
/** 
  * @brief  Application specific header  
  */
#include "CharLcd_Config.h"
/**
  * @}
  */
  
  
/** @addtogroup Struct/Union 
  * @{
  */ 

  /** 
  * @struct  sCLcdData_t
  * @brief   Hardware Data pins of CharLcd          
  */ 
typedef struct{
uint8_t  bD0		:1 ; /* Data0 bit of Lcd */
uint8_t  bD1		:1 ; /* Data1 bit of Lcd */
uint8_t  bD2		:1 ; /* Data2 bit of Lcd */
uint8_t  bD3		:1 ; /* Data3 bit of Lcd */
uint8_t  bD4		:1 ; /* Data4 bit of Lcd */
uint8_t  bD5		:1 ; /* Data5 bit of Lcd */
uint8_t  bD6		:1 ; /* Data6 bit of Lcd */
uint8_t  bD7		:1 ; /* Data7 bit of Lcd */
}sCLcdData_t;
  
 /** 
  * @union  uCLcdData_t
  * @brief Hardware Data pins of CharLcd          
  */ 
typedef union{
sCLcdData_t		sCLcdData;
uint8_t			u8CLcdData;
}uCLcdData_t;

/** 
  * @struct  sLcdControl_t
  * @brief   Hardware Control pins of CharLcd          
  */ 
typedef struct{
uint8_t  bRs		 	:1; /* Register Select */
uint8_t  bRw			:1; /* Read Write      */
uint8_t  bEn			:1; /* Enable          */
uint8_t  Reserved       :5; /* Reserved  	   */
}sCLcdControl_t;

/** 
  * @struct  uLcdControl_t
  * @brief   Hardware Control pins of CharLcd          
  */ 
typedef union{
sCLcdControl_t       sCLcdControl;
uint8_t  		     u8CLcdControl;
}uCLcdControl_t;

/** 
  * @struct  uLcdControl_t
  * @brief   Hardware Control pins of CharLcd          
  */ 
typedef struct{
uCLcdData_t		uCLcdData;
uCLcdControl_t	uCLcdControl;
}sCLcd_t;
  
/**
  * @}
  */
  
 /** @addtogroup External variables 
  * @{
  */ 
 extern sCLcd_t			sCLcd;
 extern  const char	  ArrowUpData[]	;
 extern  const char	  ArrowDownData[];
/**
  * @}
  */    
  
  
/** @defgroup  #define Macros 
  * @{
  */

 /** 
  * @#define	 
  * @brief		 Short Names for Virtual Lcd Data Port 
  */			
#define bD0    sCLcd.uCLcdData.sCLcdData.bD0
#define bD1    sCLcd.uCLcdData.sCLcdData.bD1
#define bD2    sCLcd.uCLcdData.sCLcdData.bD2
#define bD3    sCLcd.uCLcdData.sCLcdData.bD3
#define bD4    sCLcd.uCLcdData.sCLcdData.bD4
#define bD5    sCLcd.uCLcdData.sCLcdData.bD5
#define bD6    sCLcd.uCLcdData.sCLcdData.bD6
#define bD7    sCLcd.uCLcdData.sCLcdData.bD7

#define u8LcdData		sCLcd.uCLcdData.u8CLcdData
#define CLEAR_DATA		((uint8_t)0x00) 

/** 
  * @#define	 
  * @brief		 Short Names for Lcd Control Signals
  */		

#define bRs	     	sCLcd.uCLcdControl.sCLcdControl.bRs
#define bRw	     	sCLcd.uCLcdControl.sCLcdControl.bRw
#define bEn	     	sCLcd.uCLcdControl.sCLcdControl.bEn

#define u8LcdControl	sCLcd.uCLcdControl.u8CLcdControl
#define CLEAR_CONTROL	((uint8_t)0x00)


/*  CGRAM  Address  Switch */
/** 
  * @#define	ASCII_OFFSET_FOR_NUMBER
  * @brief		To display number add this offset 
  *				NOTE :
  *				DDRAM Address are mapped to LCD display position as follows.Since there are 
  *				8total 80 Ram location starting from address 00 to 4F,in all total 80 characters can
  *				be displayed on different LCD type.
  *
  *				MAP FOR  1 LINE DISPLAY ADDRESS & LCD POSITION 
  *    
  *				LCD				1	2	3	4	5	...	.			.....	79	80
  *				POSITION  ---------------------------------------------------------
  * 
  *				DD				00	01	02	03	04							4E	4F		
  *				RAM ADDRESS	
  *				-------------------------------------------------------------------
  *				So 8x1,16x1,40x1 Lcd follw this address assignment.
  * 
  *				MAP FOR  2 LINE DISPLAY ADDRESS & LCD POSITION
  *
  *				LCD			1	2	3	4	5							39	40	
  *				POSITION  ---------------------------------------------------------
  *
  *				DD			00	01	02	03	04							26	27		
  *				RAM       -------------------------------------------------------
  *				ADDRESS     40	41	42	43	44							66	67
  *
  *				For 2 Line display note that after 40th position address does
  * 			not start at 28 but at 40. All 8x2 ,16x2,40x2 Lcd follow
  *				this address assignment.
  *
  *				Instruction for DDRAM Address is shown below.
  *				INSTRUCTION: Set the DDRAM Address 
  *					:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *                  :--------------------------------------
  *					:0	0	1	A6	A5	A4	A3	A2	A1	A0
  *					:--------------------------------------
  *				A0toA6 are the address of the DDRAM location DB7 is 1 so all
  *				the address for 1 Line start from  10000000b = 0x80 onwards (A0-A6 =0x00)
  *				For 2 line display second line address start from 11000000 = 0xC0 (A0-A6 =0x40)
  */
/******************************************************************/
/*  Display data ram address (DDRAM) for 8x1,16X1,20x1,40x1  LCD */
/******************************************************************/
#if((LCD_TYPE == _8_BY_1) || (LCD_TYPE == _16_BY_1) || (LCD_TYPE == _20_BY_1) ||(LCD_TYPE == _40_BY_1))

#define	FIRST_LINE_START_ADDRESS   ((uint8_t)0x80) 

        #define _1L1P			((uint8_t)0x80)
        #define _1L2P			((uint8_t)0x81)
        #define _1L3P			((uint8_t)0x82)
        #define _1L4P			((uint8_t)0x83)
        #define _1L5P			((uint8_t)0x84)
        #define _1L6P			((uint8_t)0x85)
        #define _1L7P			((uint8_t)0x86) 
        #define _1L8P			((uint8_t)0x87)
#define _8_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0x87)
#endif
#if((LCD_TYPE == _16_BY_1) || (LCD_TYPE == _20_BY_1) || (LCD_TYPE == _40_BY_1))
        #define _1L9P			((uint8_t)0x88)
		#define _1L10P			((uint8_t)0x89) 
		#define _1L11P			((uint8_t)0x8A)
		#define _1L12P			((uint8_t)0x8B)
		#define _1L13P			((uint8_t)0x8C)
		#define _1L14P			((uint8_t)0x8D)
		#define _1L15P			((uint8_t)0x8E)
        #define _1L16P			((uint8_t)0x8F)
#define _16_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0x8F)		
#endif
#if((LCD_TYPE == _20_BY_1) ||(LCD_TYPE == _40_BY_1))
		#define  _1L17P			((uint8_t)0x90)
		#define  _1L18P			((uint8_t)0x91)
		#define  _1L19P			((uint8_t)0x92)
		#define  _1L20P			((uint8_t)0x93)
#define _20_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0x93)			
#endif
#if(LCD_TYPE ==  _40_BY_1)
		#define _1L21P			((uint8_t)0x94) 
		#define _1L22P			((uint8_t)0x95)
		#define _1L23P			((uint8_t)0x96)
		#define _1L24P			((uint8_t)0x97)
		#define _1L25P			((uint8_t)0x98)
		#define _1L26P			((uint8_t)0x99)
        #define _1L27P			((uint8_t)0x9A)
		#define _1L28P			((uint8_t)0x9B)
		#define _1L29P			((uint8_t)0x9C)
		#define _1L30P			((uint8_t)0x9D)

   		#define _1L31P			((uint8_t)0x9E)
		#define _1L32P			((uint8_t)0x9F)
		#define _1L33P			((uint8_t)0xA0)
		#define _1L34P			((uint8_t)0xA1)
		#define _1L35P			((uint8_t)0xA2)
        #define _1L36P			((uint8_t)0xA3)
		#define _1L37P			((uint8_t)0xA4)
		#define _1L38P			((uint8_t)0xA5)
		#define _1L39P			((uint8_t)0xA6)
		#define _1L40P			((uint8_t)0xA7)
#define _40_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0xA7)
#endif

/******************************************************************/
/*  Display data ram address (DDRAM) for 8x2,16X2,20x2,40x2  LCD */
/******************************************************************/
#if(LCD_TYPE == _8_BY_2 || _16_BY_2 || _20_BY_2 || _40_BY_2)
     /*  First Line  */
#define	FIRST_LINE_START_ADDRESS   ((uint8_t)0x80) 	 
		#define _1L1P			((uint8_t)0x80)
        #define _1L2P			((uint8_t)0x81)
        #define _1L3P			((uint8_t)0x82)
        #define _1L4P			((uint8_t)0x83)
        #define _1L5P			((uint8_t)0x84)
        #define _1L6P			((uint8_t)0x85)
        #define _1L7P			((uint8_t)0x86) 
        #define _1L8P			((uint8_t)0x87)
#define _8_BY_1_FIRST_LINE_END_ADDRESS		(uint8_t)0x87		
#endif
#if((LCD_TYPE == _16_BY_2) ||(LCD_TYPE == _20_BY_2) || (LCD_TYPE ==_40_BY_2))
        #define _1L9P			(uint8_t)0x88
		#define _1L10P			(uint8_t)0x89 
		#define _1L11P			(uint8_t)0x8A
		#define _1L12P			(uint8_t)0x8B
		#define _1L13P			(uint8_t)0x8C
		#define _1L14P			(uint8_t)0x8D
		#define _1L15P			(uint8_t)0x8E
        #define _1L16P			(uint8_t)0x8F
#define _16_BY_1_FIRST_LINE_END_ADDRESS		(uint8_t)0x8F		
#endif
#if(LCD_TYPE == _20_BY_2 || _40_BY_2)
		#define  _1L17P			(uint8_t)0x90
		#define  _1L18P			(uint8_t)0x91
		#define  _1L19P			(uint8_t)0x92
		#define  _1L20P			(uint8_t)0x93
#define _20_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0x93)		
#endif
#if(LCD_TYPE == _40_BY_2)
		#define _1L21P			(uint8_t)0x94 
		#define _1L22P			(uint8_t)0x95
		#define _1L23P			(uint8_t)0x96
		#define _1L24P			(uint8_t)0x97
		#define _1L25P			(uint8_t)0x98
		#define _1L26P			(uint8_t)0x99
        #define _1L27P			(uint8_t)0x9A
		#define _1L28P			(uint8_t)0x9B
		#define _1L29P			(uint8_t)0x9C
		#define _1L30P			(uint8_t)0x9D

   		#define _1L31P			(uint8_t)0x9E
		#define _1L32P			(uint8_t)0x9F
		#define _1L33P			(uint8_t)0xA0
		#define _1L34P			(uint8_t)0xA1
		#define _1L35P			(uint8_t)0xA2
        #define _1L36P			(uint8_t)0xA3
		#define _1L37P			(uint8_t)0xA4
		#define _1L38P			(uint8_t)0xA5
		#define _1L39P			(uint8_t)0xA6
		#define _1L40P			(uint8_t)0xA7
#define _40_BY_1_FIRST_LINE_END_ADDRESS		((uint8_t)0xA7)		
#endif
        /**************************************************/              
        /*			Second Line							*/
		/************************************************/

#if((LCD_TYPE == _8_BY_2) || (LCD_TYPE ==_16_BY_2) || (LCD_TYPE ==_20_BY_2) || (LCD_TYPE ==_40_BY_2))
#define	SECOND_LINE_START_ADDRESS   ((uint8_t)0xC0) 	 
        #define _2L1P			(uint8_t)0xC0
        #define _2L2P			(uint8_t)0xC1
        #define _2L3P			(uint8_t)0xC2
        #define _2L4P			(uint8_t)0xC3
        #define _2L5P			(uint8_t)0xC4
        #define _2L6P			(uint8_t)0xC5
        #define _2L7P			(uint8_t)0xC6 
        #define _2L8P			(uint8_t)0xC7
#define _8_BY_1_SECOND_LINE_END_ADDRESS		((uint8_t)0xC7)
#endif
#if((LCD_TYPE ==  _16_BY_2 )|| (LCD_TYPE == _20_BY_2) ||(LCD_TYPE ==  _40_BY_2))
     	#define _2L9P			(uint8_t)0xC8
		#define _2L10P			(uint8_t)0xC9 
		#define _2L11P			(uint8_t)0xCA
		#define _2L12P			(uint8_t)0xCB
		#define _2L13P			(uint8_t)0xCC
		#define _2L14P			(uint8_t)0xCD
		#define _2L15P			(uint8_t)0xCE
        #define _2L16P			(uint8_t)0xCF
#define _16_BY_1_SECOND_LINE_END_ADDRESS		((uint8_t)0xCF)			
#endif

#if((LCD_TYPE ==  _20_BY_2) || (LCD_TYPE == _40_BY_2))
		#define _2L17P			(uint8_t)0xD0
		#define _2L18P			(uint8_t)0xD1
		#define _2L19P			(uint8_t)0xD2
		#define _2L20P			(uint8_t)0xD3
#define _20_BY_1_SECOND_LINE_END_ADDRESS		((uint8_t)0xD3)		
#endif

#if(LCD_TYPE ==   _40_BY_2)
		#define _2L21P			(uint8_t)0xD4
		#define _2L22P			(uint8_t)0xD5
		#define _2L23P			(uint8_t)0xD6
		#define _2L24P			(uint8_t)0xD7
		#define _2L25P			(uint8_t)0xD8
		#define _2L26P			(uint8_t)0xD9
		#define _2L27P			(uint8_t)0xDA
		#define _2L28P			(uint8_t)0xDB
		#define _2L29P			(uint8_t)0xDC
		#define _2L30P			(uint8_t)0xDD

		#define _2L31P			(uint8_t)0xDE
		#define _2L32P			(uint8_t)0xDF
		#define _2L33P			(uint8_t)0xE0
		#define _2L34P			(uint8_t)0xE1
		#define _2L35P			(uint8_t)0xE2
		#define _2L36P			(uint8_t)0xE3
		#define _2L37P			(uint8_t)0xE4
		#define _2L38P			(uint8_t)0xE5
		#define _2L39P			(uint8_t)0xE6
		#define _2L40P			(uint8_t)0xE7
#define _40_BY_1_SECOND_LINE_END_ADDRESS		((uint8_t)0xE7)

#endif

#if((LCD_TYPE == _8_BY_1) || (LCD_TYPE == _8_BY_2 ))
#define COLUMN		8
#endif

#if((LCD_TYPE == _16_BY_1) || (LCD_TYPE ==_16_BY_2 ))
#define COLUMN		16
#endif

#if((LCD_TYPE == _20_BY_1) ||(LCD_TYPE == _20_BY_2 ))
#define COLUMN		20
#endif
#if((LCD_TYPE == _40_BY_1) || (LCD_TYPE == _40_BY_2 ))
#define COLUMN		40
#endif
/** 
  * @#define   ASCII_OFFSET_FOR_NUMBER
  * @brief     To display number add this offset 
  */          
#define  ASCII_OFFSET_FOR_NUMBER    48  /*0x30*/

/** 
  * @#define   
  * @brief  Following are CGRAM Address.
  *			CG-RAM size is 64 Bytes. You can create 8 characters at a time and load them in cg-ram.
  *			Each character occupies 8-bytes. Eight characters each of eight byte (8-characters * 8-Bytes)
  *			is equal to 8×8=64 Bytes. CG-RAM address in lcd memory starts from 0x40(Hexadecimal) or 64 in decimal. 
  *			You can place your first character in address ranging from 0x40 to 0x47. 
  *			The address moves on by 8 bytes for each character for 2nd character address starts from 0x48 and goes to 0x4F.
  *			Last eight’t character address starts from 0x78 and goes to 0x7F. 
  */       
#define	 CHAR0_CGRAM_ADDRESS		(uint8_t)0x40
#define  CHAR1_CGRAM_ADDRESS		(uint8_t)0x48
#define  CHAR2_CGRAM_ADDRESS		(uint8_t)0x50
#define  CHAR3_CGRAM_ADDRESS		(uint8_t)0x58
#define  CHAR4_CGRAM_ADDRESS		(uint8_t)0x60
#define  CHAR5_CGRAM_ADDRESS		(uint8_t)0x68
#define  CHAR6_CGRAM_ADDRESS		(uint8_t)0x70
#define  CHAR7_CGRAM_ADDRESS		(uint8_t)0x78


/** 
  * @#define   
  * @brief      Macros for character codes which are not define in ASCII    
  *				but are in Character ROM Give suitable Names.
  *				Also Check Datasheet of Corresponding Lcd driver to know
  *				which Graphic Characters they support. 
 */       
#define 	RIGHT_ARROW 			0x7E
#define 	LEFT_ARROW 				0x7F

#define  	ALPHA				0xE0
#define  	SYM1	 			0xE1
#define  	BETA				0xE2
#define  	EPISON				0xE3
#define 	MU					0xE4
#define  	SYM5   				0XE5
#define  	RHO					0xE6
#define  	SYM7	 			0xE7
#define 	SQROOT				0xE8
#define  	SYM9	 			0xE9
#define  	SYM10				0xEA
#define 	SYM11				0xEB
#define 	SYM12				0xEC
#define 	SYM13	 			0xED
#define 	SYM14				0xEE
#define 	SYM15	 			0xEF
#define  	SYM16				0xF0
#define  	SYM17	 			0xF1
#define  	SYM18				0xF2
#define  	SYM19				0xF3
#define 	SYM20				0xF4
#define  	SYM21  				0XF5
#define  	SYM22				0xF6
#define  	SYM23	 			0xF7
#define 	SYM24				0xF8
#define  	SYM25	 			0xF9
#define  	SYM26				0xFA
#define 	SYM27				0xFB
#define 	SYM28				0xFC
#define 	SYM29	 			0xFD
#define 	SYM30				0xFE
#define 	SYM31	 			0xFF

#define  BLANK                  0x20
/** 
  * @#define	DDRAM ADDRESS			
  * @brief		DDRAM  Address Instruction has following format.
  *				 
  *		RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	1	ADD	ADD	ADD ADD ADD	ADD	ADD	
  *		:--------------------------------------/
  *		since address start from (DB6-DB0 000000) to (DB6-DB0 111111)
  *		the actual address start with 0x80 to 0xFF 
  *		
  */     


/** 
  * @#define	CGRAM ADDRESS			
  * @brief		CGRAM  Address Instruction has following format.
  *				 
  *		RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	1	ACG	ACG ACG ACG	ACG	ACG	
  *		:--------------------------------------/
  *		since address start from (DB5-DB0 000000) to (DB5-DB0 111111)
  *		the actual address including DB6(1) & DB7(0) is 0x40 to 0x7F
  *		There are totally 64 Bytes in CGRAM.

*/     
#define CGRAM_START_ADDRESS          ((uint8_t)0x40)
#define CGRAM_END_ADDRESS            ((uint8_t)0x7F)

#define CGRAM_SIZE_FOR_5_BY_8		 ((uint8_t)0x40) /* 64 Bytes */
#define CGRAM_SIZE_FOR_5_BY_10       ((uint8_t)0x28)

/** 
  * @#define	 CLEAR_LCD_DISPLAY 	
  * @brief		 Clear Display command 
  *			Variable Used: u8DisplayClearHomeCmd		 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	0	0	0	0	0	1
  *		:--------------------------------------/
  *		Clear display writes space code 20H (character pattern for character code 20H must be a blank pattern) into
  *		all DDRAM addresses. It then sets DDRAM address 0 into the address counter, and returns the display to
  *		its original status if it was shifted. In other words, the display disappears and the cursor or blinking goes to
  *		the left edge of the display (in the first line if 2 lines are displayed). It also sets I/D to 1 (increment mode)
  *		in entry mode. S of entry mode does not change.
  */     
#define  CLEAR_LCD_DISPLAY 					((uint8_t)0x01 << 0)
/** 
  * @#define	 RETURN_HOME
  * @brief		 Return Home  command 
  *			Variable Used: u8DisplayClearHomeCmd	 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	0	0	0	0	1	 *			 * Don't Care take as 0
  *		:--------------------------------------/
  *		Return home sets DDRAM address 0 into the address counter, and returns the display to its original status
  *		if it was shifted. The DDRAM contents do not change.
  *		The cursor or blinking go to the left edge of the display (in the first line if 2 lines are displayed).
  */     
#define  RETURN_HOME                   ((uint8_t) 0x01 <<1)

/** 
  * @#define	 ENTRY_MODE_XXXX .
  * @brief		 Entry Mode Set  command 
  *		Variable used :u8EntryModeCmd= 0x04		 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	0	0	0	1	I/D	 S		
  *		:--------------------------------------/
  *		I/D: Increments (I/D = 1) or decrements (I/D = 0) the DDRAM address by 1 when a character code is
  *		written into or read from DDRAM.
  *		The cursor or blinking moves to the right when incremented by 1 and to the left when decremented by 1.
  *		The same applies to writing and reading of CGRAM.
  *		S: Shifts the entire display either to the right (I/D = 0) or to the left (I/D = 1) when S is 1. The display does
  *		not shift if S is 0.
  *		If S is 1, it will seem as if the cursor does not move but the display does. The display does not shift when
  *		reading from DDRAM. Also, writing into or reading out from CGRAM does not shift the display.
  */  
#define  INCREMENT_ADDRESS				    ((uint8_t)0x01<<1)
#define  DECREMENT_ADDRESS                  ~((uint8_t)0x01<<1)   
#define  TEXT_LEFT_TO_RIGHT					((uint8_t)0x01<<0)
#define  TEXT_RIGHT_TO_LEFT					~((uint8_t)0x01<<0)


/** 
  * @#define	 Display ON/OFF Control. .
  * @brief		 Display ON/OFF Control.  command 
  *			Variable used :u8DisplayCmd	= 0x08 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	0	0	1	D	C	 B	
  *		:--------------------------------------/
  *		: Set Entire display ON/OFF  -- D
  *		: Set Cursor  ON/OFF  -------- C
  *		: Blink of Cursor ON/OFF ------B.
  *     : Following Combinations are possible
  *			1		D		C		B
  *			1		0		x		x		Display OFF |x is taken as 0 Because when display is OFf  C and B does not matter 					
  *			1		1		0		0		Display ON|Cursor OFF|Blink OFF
  *			1		1		1		0		Display ON|Cursor ON|Blink OFF
  *			1		1		0		1		Display ON|Cursor OFF|Blink ON
  *         1		1		1		1		Display ON|Cursor ON|Blink ON       
  */     

#define  DISPLAY_ON					((uint8_t)0x01 <<2)
#define  DISPLAY_OFF				~((uint8_t)0x01 <<2)
#define  CURS_ON					((uint8_t)0x01 <<1)
#define  CURS_OFF					~((uint8_t)0x01 <<1)
#define  BLINK_ON					((uint8_t)0x01 <<0)
#define  BLINK_OFF					~((uint8_t)0x01 <<0)


/** 
  * @#define	 Cursor or Display Shift
  * @brief		Cursor or Display Shift.  command 
  *			Variable used: u8CursorTextShiftCmd = 0x10	 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	0	1	S/C	R/L *	*
  *		:--------------------------------------/
  *		 following combination is possible
  *			
  *			1		S/C		R/L		DB1		DB0
  *			1		0		0		0		0		Shift Cursor position to Left
  *			1		0		1		0		0		Shift Cursor position to Right
  *			1		1		0		0		0		Shift Entire display to Left  Cursor follow the display shift.
  *			1		1		1		0		0		Shift Entire display to Right Cursor follow the display shift.
  */     
#define   CURS_SHIFT                    ~((uint8_t)0x01 <<3)
#define   TEXT_SHIFT                    ((uint8_t)0x01 <<3)
#define   SHIFT_RIGHT					((uint8_t)0x01 <<2)
#define   SHIFT_LEFT					~((uint8_t)0x01 <<2)



/** 
  * @#define	Function Set
  * @brief		Function Set.  command 
  *		 variable used :u8FunctionSetCmd = 0x20		 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	0	0	0	1	DL	N	F	*	*
  *		:--------------------------------------/
  *		:Set interface data length to		DL =0 =>4 Bit / DL =1 =>8 Bit
  *		:Set No of Line						N =0 =>1 Line / N = 1 =>2 Line
  *		:Set Font type						F= 0  5x7 Dot / F =1 5x10 dots.
  *		 following combination is possible
  *			
  *		1	DL		N		F		DB1		DB2
  *		1	0		0		0		0		0		Interface 4 Bit| 1Line |Font 5x7
  *		1	0		0		1		0		0		Interface 4 Bit| 1Line |Font 5x10
  *		1	0		1		0		0		0		Interface 4 Bit| 2Line |Font 5x7
  *		1	0		1		1		0		0		Interface 4 Bit| 2Line |Font 5x10
  *
  *		1	1		0		0		0		0		Interface 8 Bit| 1Line |Font 5x7
  *		1	1		0		1		0		0		Interface 8 Bit| 1Line |Font 5x10
  *		1	1		1		0		0		0		Interface 8 Bit| 2Line |Font 5x7
  *		1	1		1		1		0		0		Interface 8 Bit| 2Line |Font 5x10
  */     

#define  _4BIT_INTERFACE			~((uint8_t)0x01 << 4)
#define  _8BIT_INTERFACE			((uint8_t)0x01 << 4)

#define  _1LINE						~((uint8_t)0x01 << 3)
#define  _2LINE						((uint8_t)0x01  << 3)

#define  _5_BY_7					~((uint8_t)0x01 << 2)
#define  _5_BY_10					((uint8_t)0x01  << 2)


//#define  _4BIT_1LINE_5BY7DOT  			(uint8_t)0x20  <<0
//#define  _4BIT_1LINE_5BY10DOT  			(uint8_t)0x22  <<0
//#define  _4BIT_2LINE_5BY7DOT  			(uint8_t)0x28  <<0
//#define  _4BIT_2LINE_5BY10DOT  			(uint8_t)0x2C  <<0
//
//#define  _8BIT_1LINE_5BY7DOT  			(uint8_t)0x30  <<0
//#define  _8BIT_1LINE_5BY10DOT  			(uint8_t)0x32  <<0
//#define  _8BIT_2LINE_5BY7DOT  			(uint8_t)0x38  <<0
//#define  _8BIT_2LINE_5BY10DOT  			(uint8_t)0x3C  <<0

/** 
  * @#define	Read Busy Flag & Address Counter 
  * @brief		Read Busy Flag & Address Counter. command 
  *				 
  *		:RS	R/W	DB7	DB6	DB5	DB4	DB3	DB2	DB1	DB0	
  *		:--------------------------------------
  *		:0	1	BF	AC6	AC5	AC4	AC3	AC2	AC1	AC0
  *		:--------------------------------------/
  *		:Read Busy flag(BF) indication of internal operation
  *		: is being performed & reads the address counter
  *		:content.
  */     

#define  BUSY_MASK					((uint8_t)0x80)
#define  ADDRESS_COUNTER_MASK       ((uint8_t)0x7F)

/**
  * @}
  */


  /** @defgroup  Function Macros 
  * @{
  */
 
/**
  * @}
  */
  
/** @defgroup  Inline Function  
  * @{
  */
 
/**
  * @}
  */ 
  
 
/** @addtogroup Enum 
  * @{
  */
typedef enum {
FONT_5_BY_8,
FONT_5_BY_10
}eFont_t;


/**
  * @}
  */
  
/** @addtogroup Function Prototype
  * @{
  */ 
/* Basic Command */   
void Lcd_WriteCommand(uint8_t u8Command);
void Lcd_WriteData(uint8_t u8DDRamData);
/* Initialization */
void Lcd_DisplayClear(void);
void Lcd_CursorHome(void);
void Lcd_HwInit(void);
void Lcd_LcdInit(void);
/*  Function related to Cursor */
void Lcd_SetCursor(uint8_t u8Line, uint8_t u8Column);
void Lcd_SetCursorPosition(uint8_t  u8PositionAddress);
void Lcd_CursorOn(void);
void Lcd_CursorOff(void);
/* Function Related to Printing Ascii Char */
void Lcd_Printf(const char *ptrString );
/* function Related to Blink */
void Lcd_BlinkOn(void);
void Lcd_BlinkOff(void);
/* Function Related to Display */
void Lcd_DisplayOn(void);
void Lcd_DisplayOff(void);
/* Function Related to Scrolling */
void Lcd_ScrollDisplayLeft(void);
void Lcd_ScrollDisplayRight(void); 
void Lcd_AutoScroll(char *pchar);
void Lcd_NoAutoScroll(void);
/* Function Related to Text Direction */
void Lcd_TextLeftToRight(void);
void Lcd_TextRightToLeft(void);
/* Custom Character Commands */
void Lcd_CreateCustomChar(uint8_t CGRamAddress, const char CharData[]);
void Lcd_PrintCustomChar(uint8_t num);

/**
  * @}
  */

  



#endif