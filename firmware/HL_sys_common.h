#ifndef __SYS_COMMON_H__
#define __SYS_COMMON_H__

#include "HL_hal_stdtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* USER CODE BEGIN (0) */
/* USER CODE END */

/************************************************************/
/* Type Definitions                                         */
/************************************************************/

#ifndef _TBOOLEAN_DECLARED
typedef boolean tBoolean;
#define _TBOOLEAN_DECLARED
#endif

/** @enum loopBackType
*   @brief Loopback type definition
*/
/** @typedef loopBackType_t
*   @brief Loopback type Type Definition
*
*   This type is used to select the module Loopback type Digital or Analog loopback.
*/
typedef enum loopBackType 
{
    Digital_Lbk = 0U, 
    Analog_Lbk = 1U
}loopBackType_t;

/** @enum config_value_type
*   @brief config type definition
*/
/** @typedef config_value_type_t
*   @brief config type Type Definition
*
*   This type is used to specify the Initial and Current value.
*/
typedef enum config_value_type
{
	InitialValue,
	CurrentValue
}config_value_type_t;


#ifndef __little_endian__
#define __little_endian__  0
#endif
#ifndef __LITTLE_ENDIAN__
#define __LITTLE_ENDIAN__  0
#endif

/* USER CODE BEGIN (1) */
/* USER CODE END */

/********************************************************************************/
/* The ASSERT macro, which does the actual assertion checking.  Typically, this */
/* will be for procedure arguments.                                             */
/********************************************************************************/
#ifdef DEBUG
#define ASSERT(expr) {                                      \
                         if(!(expr))                        \
                         {                                  \
                             __error__(__FILE__, __LINE__); \
                         }                                  \
                     }
#else
#define ASSERT(expr)
#endif

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* USER CODE BEGIN (3) */
/* USER CODE END */

/**@}*/
#ifdef __cplusplus
}
#endif


#endif

