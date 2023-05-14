/*
 * WaterLevelController.c
 *
 * Created: 31-07-2021 11:11:15
 * Author : Guruprasad R. T
 */ 
/****** ATmel Files ************/
//#include <avr/io.h>
//#include <util/delay.h> 
//#include <avr/interrupt.h>
//#include <stdlib.h>
/********System Files *************/
#include "ATmega16_Init.h"
#include "Usart.h"
/********* Application files ********/
#include "CharLcd.h"
#include "Ultrasonic.h"
#include "PulseOut.h" 
#include "InputCapture.h"
/***********************************/
extern sInputCapture_t sInputCapture;

int main(void)
{ 	
	/* Call One time System Initialization */
	Init_System();
	   
   while(1) 
    {
		/* Transmit the pulse */
		PO_GeneratePulseSw(PORTD_PD4, _20USEC, RISING_EDGE);
		/* Wait for Data to be capture */
		while (sInputCapture.u8DataStatus == IC_DATA_NOT_CAPTURED);
         /* Calculate and Display Range */		
		 Ultra_GetObjectRange();
	   /* Transmit Range data on Usart */ 
		 
	}
}
