/**
******************************************************************************
* @file    Std_Types.h
* @author  GRT/AMK
* @version V1.0
* @date    07-July-2020
* @brief   This file includes Platform and compiler specific header.
*          AUTOSAR DOCUMENT NO:
*          AUTOSAR VERSIOn NO:
*
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

#ifndef  _STD_TYPES_H
#define  _STD_TYPES_H

/** @addtogroup  Header
* @{
*/

/**
* @brief  Platform Specific header
*/

/**
* @brief  Compiler specific header
*/

/**
* @}
*/

/** @addtogroup Enum
* @{
*/


/**
* @}
*/

/** @defgroup  typedef Module specific
* @{
*/

/** @typedef
* @brief Basic typedef
*
*/
typedef	signed char				int8_t	;
typedef	unsigned char	       	uint8_t	;
typedef	signed int	       		int16_t	;
typedef	unsigned int	       	uint16_t;
typedef	signed long	       		int32_t	;
typedef	unsigned long	       	uint32_t;

/** @typedef
*
* @brief function callback  
*/

typedef void (*Callback_t) (void);
/**
* Function Pointer declaration
*/

typedef void (*fpointerv_t)(uint8_t) ;


/**
* @}
*/

/** @addtogroup Struct/Union
* @{
*/

/**
* @}
*/

/** @defgroup  #define Macros
* @{
*/
/**
* @#define
* @brief  These macros are comon across All Software Modules.
*         0x02-0x3F Available to user specific errors
*/

#define  E_OK           0x00
#define  E_NOT_OK       0x01
#define  STD_HIGH       0x01      /*!< Physical state 5V or 3.3V */
#define  STD_LOW        0x00      /*!< Physical state 0V */
#define  STD_ACTIVE     0x01      /*!< Logical state active */
#define  STD_IDLE       0x00      /*!< Logical state idle */
#define  STD_ON         0x01
#define  STD_OFF        0x00


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


/** @addtogroup External variables
* @{
*/

/**
* @}
*/

/** @addtogroup Function Prototype
* @{
*/

/**
* @}
*/
#endif  /* STD_TYPES_H */
