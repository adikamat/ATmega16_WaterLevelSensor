/* Include test file header */
#include "LcdTest.h"

char  msg[] = {'H','e','l','l','o',' ','G','u','r','u',' ','3','.','5','\0'};
char  *pmsg = "Hello Sir"	;
/* Call These function in Main */
/*****************************************************/
/*		Lcd Module functions Test          */
/****************************************************/
//Test_Lcd_WriteCommand();			/*P*/
//Test_Lcd_WriteData();			/*P*/
/* Initialization */
//Test_Lcd_HwInit();				/*P*/
//Test_Lcd_PowerInit();				/*P*/
//Test_Lcd_DisplayClear();			/*p*/
//Test_Lcd_CursorHome();			/*P*/
/*  Function related to Cursor */
//Test_Lcd_SetCursor();				/*P*/
//Test_Lcd_SetCursorPosition();		/*P*/
//Test_Lcd_CursorOn();					/*P*/
//Test_Lcd_CursorOff();				/*P*/
/* Function Related to Printing Ascii Char */
//Test_Lcd_Printf();					/*P*/
/* function Related to Blink */
//Test_Lcd_BlinkOn();					/*P*/
//Test_Lcd_BlinkOff();					/*P*/
/* Function Related to Display */
//Test_Lcd_DisplayOn();				/*p*/
//Test_Lcd_DisplayOff();				/*p*/
/* Function Related to Scrolling */
//Test_Lcd_ScrollDisplayLeft();		/*p*/
//Test_Lcd_ScrollDisplayRight();		/*p*/
//Test_Lcd_AutoScroll();		to be tested
//Test_Lcd_NoAutoScroll();		to be tested
/* Function Related to Text Direction */
//Test_Lcd_TextLeftToRight();			/*p*/
//Test_Lcd_TextRightToLeft();			/*p*/
/* Custom Character Commands */
/* NOTE : Test these two function togather */
//Test_Lcd_CreateCustomChar();			/*p*/
//Test_Lcd_PrintCustomChar();			/*p*/





/* Basic Command */
void Test_Lcd_WriteCommand(void)		
{
   /* Lcd_WriteCommand(uint8_t u8Command);			/*P*/
    /*This function is indirectly tested by calling in other function */
   }

void Test_Lcd_WriteData(void)
{
	/* Lcd_WriteData(uint8_t u8DDRamData);		/*P*/
	/*  This function is indirectly tested by calling in other function */
}

void Test_Lcd_HwInit(void)
{
	Lcd_HwInit();								/*P*/
}
void Test_Lcd_LcdInit(void)
{
	Lcd_LcdInit();							/*P*/
}
/* Initialization */
void Test_Lcd_DisplayClear(void)
{
	Lcd_SetCursor(2,1);
	Lcd_Printf(pmsg);
	_delay_ms(400);
	Lcd_DisplayClear();						/*P*/
}
void Test_Lcd_CursorHome(void)
{
	Lcd_SetCursor(2,4);					/*P*/
	Lcd_CursorHome();					/*P*/
}


/*  Function related to Cursor */
void Test_Lcd_SetCursor(void)
{  /* first Line */
	Lcd_SetCursor(1,1);				/*P*/
	Lcd_SetCursor(1,2);				/*P*/
	Lcd_SetCursor(1,3);				/*P*/
	Lcd_SetCursor(1,4);				/*P*/
	Lcd_SetCursor(1,5);				/*P*/
	Lcd_SetCursor(1,6);				/*P*/
	Lcd_SetCursor(1,7);				/*P*/
	Lcd_SetCursor(1,8);				/*P*/
	Lcd_SetCursor(1,9);				/*P*/
	Lcd_SetCursor(1,10);			/*P*/
	Lcd_SetCursor(1,11);			/*P*/
	Lcd_SetCursor(1,12);			/*P*/
	Lcd_SetCursor(1,13);			/*P*/
	Lcd_SetCursor(1,14);			/*P*/
	Lcd_SetCursor(1,15);			/*P*/
	Lcd_SetCursor(1,16);			/*P*/
	/* Second line */
	Lcd_SetCursor(2,1);				/*P*/
	Lcd_SetCursor(2,2);				/*P*/
	Lcd_SetCursor(2,3);				/*P*/
	Lcd_SetCursor(2,4);				/*P*/
	Lcd_SetCursor(2,5);				/*P*/
	Lcd_SetCursor(2,6);				/*P*/
	Lcd_SetCursor(2,7);				/*P*/
	Lcd_SetCursor(2,8);				/*P*/
	Lcd_SetCursor(2,9);				/*P*/
	Lcd_SetCursor(2,10);			/*P*/
	Lcd_SetCursor(2,11);			/*P*/
	Lcd_SetCursor(2,12);			/*P*/
	Lcd_SetCursor(2,13);			/*P*/
	Lcd_SetCursor(2,14);			/*P*/
	Lcd_SetCursor(2,15);			/*P*/
	Lcd_SetCursor(2,16);			/*P*/
}
void Test_Lcd_SetCursorPosition(void)
{	/* first Line */
	Lcd_SetCursorPosition(_1L1P);	/*P*/
	Lcd_SetCursorPosition(_1L2P);	/*P*/
	Lcd_SetCursorPosition(_1L3P);	/*P*/
	Lcd_SetCursorPosition(_1L4P);	/*P*/
	Lcd_SetCursorPosition(_1L5P);	/*P*/
	Lcd_SetCursorPosition(_1L6P);	/*P*/
	Lcd_SetCursorPosition(_1L7P);	/*P*/
	Lcd_SetCursorPosition(_1L8P);	/*P*/
	Lcd_SetCursorPosition(_1L9P);	/*P*/
	Lcd_SetCursorPosition(_1L10P);	/*P*/
	Lcd_SetCursorPosition(_1L11P);	/*P*/
	Lcd_SetCursorPosition(_1L12P);	/*P*/
	Lcd_SetCursorPosition(_1L13P);	/*P*/
	Lcd_SetCursorPosition(_1L14P);	/*P*/
	Lcd_SetCursorPosition(_1L15P);	/*P*/
	Lcd_SetCursorPosition(_1L16P);	/*P*/
	/* Second line */
	Lcd_SetCursorPosition(_2L1P);	/*P*/
	Lcd_SetCursorPosition(_2L2P);	/*P*/
	Lcd_SetCursorPosition(_2L3P);	/*P*/
	Lcd_SetCursorPosition(_2L4P);	/*P*/
	Lcd_SetCursorPosition(_2L5P);	/*P*/
	Lcd_SetCursorPosition(_2L6P);	/*P*/
	Lcd_SetCursorPosition(_2L7P);	/*P*/
	Lcd_SetCursorPosition(_2L8P);	/*P*/
	Lcd_SetCursorPosition(_2L9P);	/*P*/
	Lcd_SetCursorPosition(_2L9P);	/*P*/
	Lcd_SetCursorPosition(_2L10P);	/*P*/
	Lcd_SetCursorPosition(_2L11P);	/*P*/
	Lcd_SetCursorPosition(_2L12P);	/*P*/
	Lcd_SetCursorPosition(_2L13P);	/*P*/
	Lcd_SetCursorPosition(_2L14P);	/*P*/
	Lcd_SetCursorPosition(_2L15P);	/*P*/
	Lcd_SetCursorPosition(_2L16P);	/*P*/
}
void Test_Lcd_CursorOn(void)
{ /* Lcd_HwInit(void) already uses this function for 
	 initialization*/
	Lcd_CursorOn();					/*P*/
}
void Test_Lcd_CursorOff(void)
{
	Lcd_SetCursorPosition(_2L16P);
	_delay_ms(300);
	Lcd_CursorOff();			/*P*/
}

/* Function Related to Printing Ascii Char */
void Test_Lcd_Printf(void)
{
	Lcd_SetCursorPosition(_1L1P);
	Lcd_Printf(msg);			/*P*/		
	Lcd_SetCursor(2,1);
	Lcd_Printf(pmsg);			/*P*/
}

/* function Related to Blink */
void Test_Lcd_BlinkOn(void)
{
	Lcd_SetCursorPosition(_1L1P);
	Lcd_Printf(msg);
	Lcd_BlinkOn();			/*p*/
}
void Test_Lcd_BlinkOff(void)
{
	Lcd_SetCursor(2,1);
	Lcd_Printf(pmsg);
	Lcd_BlinkOn();
	_delay_ms(400);
	Lcd_BlinkOff();			/*p*/
}

/* Function Related to Display */
void Test_Lcd_DisplayOn(void)
{
	Lcd_SetCursor(1,1);
	Lcd_Printf(msg);
	_delay_ms(200);
	Lcd_DisplayOff();
	_delay_ms(300);
	Lcd_DisplayOn();			/*p*/
}
void Test_Lcd_DisplayOff(void)
{ 
	Lcd_SetCursor(2,1);
	Lcd_Printf(pmsg);
	_delay_ms(300);
	Lcd_DisplayOff();			/*p*/
}

/* Function Related to Scrolling */
void Test_Lcd_ScrollDisplayLeft(void)
{
	Lcd_SetCursor(2,1);
	Lcd_Printf(msg);
	Lcd_ScrollDisplayLeft();		/*p*/
	_delay_ms(100);
	Lcd_ScrollDisplayLeft();
	_delay_ms(100);
	Lcd_ScrollDisplayLeft();
	_delay_ms(100);
	Lcd_ScrollDisplayLeft();
	_delay_ms(100);
	Lcd_ScrollDisplayLeft();
	_delay_ms(100);
	
}

void Test_Lcd_ScrollDisplayRight(void)
{
	Lcd_SetCursor(1,1);
	Lcd_Printf(msg);
	_delay_ms(100);
	Lcd_ScrollDisplayRight();	/*p*/
	_delay_ms(100);
	Lcd_ScrollDisplayRight();
	_delay_ms(100);
	Lcd_ScrollDisplayRight();
	_delay_ms(100);
	Lcd_ScrollDisplayRight();
	_delay_ms(100);
	Lcd_ScrollDisplayRight();
	_delay_ms(100);
}
void Test_Lcd_AutoScroll(void)
{
	Lcd_SetCursor(2,1);
	Lcd_Printf(msg);
	Lcd_AutoScroll(msg); 
}
void Test_Lcd_NoAutoScroll(void)
{
	Lcd_NoAutoScroll();
}

/* Function Related to Text Direction */
void Test_Lcd_TextLeftToRight(void)
{ /* This is default setting */
	Lcd_TextLeftToRight();			/*p*/
}
void Test_Lcd_TextRightToLeft(void)
{
	Lcd_TextRightToLeft();
	Lcd_SetCursor(2,16);
	Lcd_Printf(msg);				/*p*/
}

/* Custom Character Commands */
void Test_Lcd_CreateCustomChar(void)
{
	Lcd_CreateCustomChar(CHAR0_CGRAM_ADDRESS, ArrowUpData);		/*p*/
	Lcd_CreateCustomChar(CHAR1_CGRAM_ADDRESS, ArrowDownData);	/*p*/
}
void Test_Lcd_PrintCustomChar(void)
{
	Lcd_SetCursorPosition(_1L14P);
	Lcd_PrintCustomChar(ARROW_UP);			/*p*/
	Lcd_SetCursorPosition(_2L1P);
	Lcd_PrintCustomChar(ARROW_DOWN);		/*p*/
}
