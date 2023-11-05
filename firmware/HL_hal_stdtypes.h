#ifndef __HAL_STDTYPES_H__
#define __HAL_STDTYPES_H__

/* USER CODE BEGIN (0) */
/* USER CODE END */

#include <stdint.h>
#include <stdbool.h>

/* USER CODE BEGIN (1) */
/* USER CODE END */
/************************************************************/
/* Type Definitions                                         */
/************************************************************/
#ifndef _UINT64_DECLARED
typedef uint64_t uint64;
#define	_UINT64_DECLARED
#endif

#ifndef _UINT32_DECLARED
typedef uint32_t uint32;
#define	_UINT32_DECLARED
#endif

#ifndef _UINT16_DECLARED
typedef uint16_t uint16;
#define	_UINT16_DECLARED
#endif

#ifndef _UINT8_DECLARED
typedef uint8_t uint8;
#define	_UINT8_DECLARED
#endif

#ifndef _BOOLEAN_DECLARED
#ifdef __cplusplus
typedef bool boolean;
#else
typedef _Bool boolean;
#endif
#define	_BOOLEAN_DECLARED
#endif

#ifndef _SINT64_DECLARED
typedef int64_t sint64;
#define	_SINT64_DECLARED
#endif

#ifndef _SINT32_DECLARED
typedef int32_t sint32;
#define	_SINT32_DECLARED
#endif

#ifndef _SINT16_DECLARED
typedef int16_t sint16;
#define	_SINT16_DECLARED
#endif

#ifndef _SINT8_DECLARED
typedef int8_t sint8;
#define	_SINT8_DECLARED
#endif

#ifndef _FLOAT32_DECLARED
typedef float float32;
#define	_FLOAT32_DECLARED
#endif

#ifndef _FLOAT64_DECLARED
typedef double float64;
#define	_FLOAT64_DECLARED
#endif


typedef uint8 Std_ReturnType;

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8  instanceID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;

/*****************************************************************************/
/* SYMBOL DEFINITIONS                                                        */
/*****************************************************************************/
#ifndef STATUSTYPEDEFINED
  #define STATUSTYPEDEFINED
  #define E_OK     0x00U

  typedef unsigned char StatusType;
#endif

#ifndef E_NOT_OK
#define E_NOT_OK   0x01U
#endif

#ifndef STD_ON
#define STD_ON     0x01U
#endif

#ifndef STD_OFF
#define STD_OFF    0x00U
#endif



/************************************************************/
/* Global Definitions                                       */
/************************************************************/
/** @def NULL
*   @brief NULL definition
*/
#ifndef NULL
    #define NULL ((void *) 0U)
#endif

/** @def TRUE
*   @brief definition for TRUE
*/
#ifndef TRUE
    #define TRUE true
#endif

/** @def FALSE
*   @brief BOOLEAN definition for FALSE
*/
#ifndef FALSE
    #define FALSE false
#endif

/*****************************************************************************/
/* Define:       NULL_PTR                                                    */
/* Description:  Void pointer to 0                                           */
/*****************************************************************************/
#ifndef NULL_PTR
#define NULL_PTR ((void *)0x0U)
#endif
/* USER CODE BEGIN (2) */
/* USER CODE END */

#endif /* __HAL_STDTYPES_H__ */
