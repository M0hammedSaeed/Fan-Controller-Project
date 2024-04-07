/*******************************************************************************
 *
 *  [Module]	 : Common - Platform Types Abstraction
 *
 *  [File Name]	 : std_types.h
 *
 *  [Description]: All common types That need it to use .
 *
 *  [Author]	 : Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_UTILS_STD_TYPES_H_
#define SRC_UTILS_STD_TYPES_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

#define NULL_PTR		((void *)0)

#ifndef TRUE
#define	TRUE			(1u)
#endif
#ifndef FALSE
#define FALSE			(0u)
#endif

#define DISABLE			(0u)
#define ENABLE			(1u)

#define LOGIC_LOW		(0u)
#define LOGIC_HIGH		(1u)

/*------------------------------------------------------------------------------
 *                                    TYPES
 *------------------------------------------------------------------------------*/

/*Boolean Data Type */
typedef unsigned char		boolean;

/* unsigned Data types */
/* unsigned Data types */
typedef unsigned char 		uint8;       /*                   0..255                     */
typedef unsigned short 		uint16;      /*                  0..65535                    */
typedef unsigned long 		uint32;      /*                0..4294967295                 */
typedef unsigned long long 	uint64;  	 /*           0..1844674407370955                */

/* Signed Data types */
typedef signed char 		sint8;       /*                 -128 .. +127                 */
typedef signed short 		sint16;      /*               -32768 .. +3276                */
typedef signed long 		sint32;      /*          -2147483648 .. +2147483647          */
typedef signed long long 	sint64;      /* -9223372036854775808 .. +9223372036854775807 */

/* float types*/
typedef float 				float32;
typedef double 				float64;

typedef enum
{
	logic_low,
	logic_high
}STD_LevelType;

/*------------------------------------------------------------------------------
 *                                REGISTER 8_BITS
 *------------------------------------------------------------------------------*/

/* Define register 8 bit */
typedef unsigned char	byte;
typedef union
{
	byte Data;
	struct
	{
		byte BIT0:1;	/* 1 bit size */
		byte BIT1:1;
		byte BIT2:1;
		byte BIT3:1;
		byte BIT4:1;
		byte BIT5:1;
		byte BIT6:1;
		byte BIT7:1;
	}BITS;
}STD_Reg_8bits;

#endif /* SRC_UTILS_STD_TYPES_H_ */
