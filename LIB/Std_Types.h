/**
 * @file Std_Types.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the definition of the standard types used in the project.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char uint8_t;   /**< Unsigned 8-bit integer */
typedef signed char   sint8_t;     /**< Signed 8-bit integer */

typedef unsigned int  uint16_t;   /**< Unsigned 16-bit integer */
typedef signed int    sint16_t;     /**< Signed 16-bit integer */

typedef unsigned long uint32_t;  /**< Unsigned 32-bit integer */
typedef signed long   sint32_t;    /**< Signed 32-bit integer */

typedef unsigned long long uint64_t;  /**< Unsigned 64-bit integer */
typedef signed long long sint64_t;    /**< Signed 64-bit integer */


typedef uint8_t  u8;  /**< Unsigned 8-bit integer */
typedef sint8_t  s8;  /**< Signed 8-bit integer */
typedef uint16_t u16; /**< Unsigned 16-bit integer */
typedef sint16_t s16; /**< Signed 16-bit integer */
typedef uint32_t u32; /**< Unsigned 32-bit integer */
typedef sint32_t s32; /**< Signed 32-bit integer */
typedef uint64_t u64; /**< Unsigned 64-bit integer */
typedef sint64_t s64; /**< Signed 64-bit integer */


typedef void* Ptr_Void_t; /**< Pointer to void type */


/* =========== NULL pointer ============= */
#define NULL_PTR ((void*)0) /**< NULL pointer definition */

/* =========== NULL character ============= */
#define NULL_CHAR '\0' /**< NULL character definition */

/* =========== Function pointer ============= */

typedef void (*Ptr_VoidFuncVoid_t)(void); /**< Function pointer to function returning void and taking no arguments */
typedef void (*Ptr_VoidFuncU8_t)(u8); /**< Function pointer to function returning void and taking an unsigned 8-bit integer argument */
typedef void (*Ptr_VoidFuncU16_t)(u16); /**< Function pointer to function returning void and taking an unsigned 16-bit integer argument */
typedef void (*Ptr_VoidFuncU32_t)(u32); /**< Function pointer to function returning void and taking an unsigned 32-bit integer argument */
typedef void (*Ptr_VoidFuncS8_t)(s8); /**< Function pointer to function returning void and taking a signed 8-bit integer argument */
typedef void (*Ptr_VoidFuncS16_t)(s16); /**< Function pointer to function returning void and taking a signed 16-bit integer argument */
typedef void (*Ptr_VoidFuncS32_t)(s32); /**< Function pointer to function returning void and taking a signed 32-bit integer argument */

/* =========== Function pointer to function returning pointer to void ============= */
/**
 * @brief 
 * This kind of construct is not very common, but it can be useful in certain scenarios.
 * For example:
 *   			[1] it can be used in state machines, where each state is represented by a function,
 *                  and transitions between states are represented by functions returning pointers to other functions (states).
 *       		[2] It can also be used in event-driven systems,
 *  			    where different events trigger different functions,
 *  				and the sequence of events can be controlled by functions returning pointers to other functions.
 * @par Example:
 *   @code
 *    // Define a function that matches the signature
 *    void someFunction(void) {
 *    // Function body
 *    }
 * 
 *   // Define a function that returns a pointer to the above function
 *   Ptr_VoidFuncVoid_t functionReturningFunction(void) {
 *   return &someFunction;
 *   }
 * 
 *   // Use the defined type to declare a variable
 *   Ptr_Ptr_VoidFuncVoid_t ptrToFunctionReturningFunction = &functionReturningFunction;
 *   @endcode
 * @warning
 */
typedef Ptr_VoidFuncVoid_t (*Ptr_Ptr_VoidFuncVoid_t)(void); /**< Function pointer to function returning pointer to function returning void and taking no arguments */
typedef Ptr_VoidFuncU8_t  (*Ptr_Ptr_VoidFuncU8_t)(u8); /**< Function pointer to function returning pointer to function returning void and taking an unsigned 8-bit integer argument */
typedef Ptr_VoidFuncU16_t (*Ptr_Ptr_VoidFuncU16_t)(u16); /**< Function pointer to function returning pointer to function returning void and taking an unsigned 16-bit integer argument */
typedef Ptr_VoidFuncU32_t (*Ptr_Ptr_VoidFuncU32_t)(u32); /**< Function pointer to function returning pointer to function returning void and taking an unsigned 32-bit integer argument */
typedef Ptr_VoidFuncS8_t  (*Ptr_Ptr_VoidFuncS8_t)(s8); /**< Function pointer to function returning pointer to function returning void and taking a signed 8-bit integer argument */
typedef Ptr_VoidFuncS16_t (*Ptr_Ptr_VoidFuncS16_t)(s16); /**< Function pointer to function returning pointer to function returning void and taking a signed 16-bit integer argument */
typedef Ptr_VoidFuncS32_t (*Ptr_Ptr_VoidFuncS32_t)(s32); /**< Function pointer to function returning pointer to function returning void and taking a signed 32-bit integer argument */

/* =========== Error type ============= */
/**
 * @file Std_Types.h
 * @brief This file contains the definition of the Std_Error_t enumeration.
 *
 * The Std_Error_t enumeration defines a set of standard error codes that can be used in software development.
 * These error codes can be used to indicate the status or outcome of a particular operation or function.
 * Each error code represents a specific error condition and can be used to provide meaningful error messages or handle error cases.
 *
 */
typedef enum{
	STD_OK, /**< Operation completed successfully */
	STD_NOK, /**< Operation failed */
	STD_BUSY, /**< Resource is currently busy */
	STD_NULL_POINTER, /**< Null pointer encountered */
	STD_BUFFER_FULL, /**< Buffer is full */
	STD_BUFFER_EMPTY, /**< Buffer is empty */
	STD_BUFFER_OVERFLOW, /**< Buffer overflow occurred */
	STD_BUFFER_UNDERFLOW, /**< Buffer underflow occurred */
	STD_NOT_INITIALIZED, /**< Module or component not initialized */
	STD_ALREADY_INITIALIZED, /**< Module or component already initialized */
	STD_INVALID_ARG, /**< Invalid argument passed */
	STD_TIMEOUT, /**< Operation timed out */
	STD_OUT_OF_RANGE, /**< Value is out of range */
	STD_OUT_OF_MEMORY, /**< Out of memory */
	STD_NOT_EXIST, /**< Entity does not exist */
	STD_NOT_SUPPORTED, /**< Operation or feature not supported */
	STD_NO_DEVICE, /**< No device available */
	STD_NOT_READY, /**< Entity is not ready */
	STD_NOT_ACCESSIBLE, /**< Entity is not accessible */
	STD_NOT_CONFIGURED, /**< Entity is not configured */
	STD_NOT_STARTED, /**< Entity is not started */
	STD_NOT_STOPPED, /**< Entity is not stopped */
	STD_NOT_ENABLED, /**< Entity is not enabled */
	STD_NOT_DISABLED, /**< Entity is not disabled */
	STD_NOT_CONNECTED, /**< Entity is not connected */
	STD_NOT_DISCONNECTED, /**< Entity is not disconnected */
	STD_NOT_OPENED, /**< Entity is not opened */
	STD_NOT_CLOSED, /**< Entity is not closed */
	STD_NOT_LOCKED, /**< Entity is not locked */
	STD_NOT_UNLOCKED, /**< Entity is not unlocked */
	STD_NOT_VALID, /**< Entity is not valid */
	STD_NOT_INVALID /**< Entity is not invalid */
}Std_Error_t;

/**
 * @brief Status type enumeration.
 */
typedef enum{
	STD_ACTIVE, /**< Active status */
	STD_IDLE, /**< Idle status */
	STD_DONE, /**< Done status */
	STD_PENDING,
	STD_ERROR /**< Error status */
}Std_Status_t;

/**
 * @brief Boolean type enumeration.
 */
typedef enum{
	STD_FALSE, /**< False value */
	STD_TRUE /**< True value */
}Std_Bool_t;

/**
 * @brief Enable/Disable type enumeration.
 */
typedef enum {
	STD_DISABLED, /**< Disabled state */
	STD_ENABLED /**< Enabled state */
} Std_EnableDisable_t;

/**
 * @brief On/Off type enumeration.
 */
typedef enum {
	STD_OFF, /**< Off state */
	STD_ON /**< On state */
} Std_OnOff_t;

/**
 * @brief High/Low type enumeration.
 */
typedef enum {
	STD_LOW, /**< Low state */
	STD_HIGH /**< High state */
} Std_HighLow_t;

/**
 * @brief Input/Output type enumeration.
 */
typedef enum {
	STD_IN, /**< Input state */
	STD_OUT /**< Output state */
} Std_InOut_t;

/**
 * @brief Increment/Decrement type enumeration.
 */
typedef enum {
	STD_INCREMENT, /**< Increment state */
	STD_DECREMENT /**< Decrement state */
} Std_IncrementDecrement_t;

/**
 * @brief Clockwise/Anticlockwise type enumeration.
 */
typedef enum {
	STD_CLOCKWISE, /**< Clockwise direction */
	STD_ANTICLOCKWISE /**< Anticlockwise direction */
} Std_ClockwiseAnticlockwise_t;

/**
 * @brief Forward/Backward type enumeration.
 */
typedef enum {
	STD_FORWARD, /**< Forward direction */
	STD_BACKWARD /**< Backward direction */
} Std_ForwardBackward_t;

/**
 * @brief Start/Stop type enumeration.
 */
typedef enum {
	STD_STOP, /**< Stop state */
	STD_START /**< Start state */
} Std_StartStop_t;

/**
 * @brief Down/Up type enumeration.
 */
typedef enum {
	STD_DOWN, /**< Down direction */
	STD_UP /**< Up direction */
} Std_DownUp_t;

/**
 * @brief Left/Right type enumeration.
 */
typedef enum {
	STD_LEFT, /**< Left direction */
	STD_RIGHT /**< Right direction */
} Std_LeftRight_t;

/**
 * @brief Open/Close type enumeration.
 */
typedef enum {
	STD_CLOSE, /**< Close state */
	STD_OPEN /**< Open state */
} Std_OpenClose_t;

/**
 * @brief Lock/Unlock type enumeration.
 */
typedef enum {
	STD_LOCK, /**< Lock state */
	STD_UNLOCK /**< Unlock state */
} Std_LockUnlock_t;

/**
 * @brief Connect/Disconnect type enumeration.
 */
typedef enum {
	STD_CONNECT, /**< Connect state */
	STD_DISCONNECT /**< Disconnect state */
} Std_ConnectDisconnect_t;

/**
 * @brief Valid/Invalid type enumeration.
 */
typedef enum {
	STD_VALID, /**< Valid state */
	STD_INVALID /**< Invalid state */
} Std_ValidInvalid_t;

/**
 * @brief Equal/Not Equal type enumeration.
 */
typedef enum {
	STD_EQUAL, /**< Equal state */
	STD_NOT_EQUAL /**< Not equal state */
} Std_EqualNotEqual_t;

/**
 * @brief Maximum and minimum values for various data types.
 */
#define MAX_U8   (u8(255)) /**< Maximum value for unsigned 8-bit integer */
#define MIN_U8   (u8(0)) /**< Minimum value for unsigned 8-bit integer */

#define MAX_S8   (s8(127)) /**< Maximum value for signed 8-bit integer */
#define MIN_S8   (s8(-128)) /**< Minimum value for signed 8-bit integer */

#define MAX_U16  (u16(65535)) /**< Maximum value for unsigned 16-bit integer */
#define MIN_U16  (u16(0)) /**< Minimum value for unsigned 16-bit integer */

#define MAX_S16  (s16(32767)) /**< Maximum value for signed 16-bit integer */
#define MIN_S16  (s16(-32768)) /**< Minimum value for signed 16-bit integer */

#define MAX_U32  (u32(4294967295)) /**< Maximum value for unsigned 32-bit integer */
#define MIN_U32  (u32(0)) /**< Minimum value for unsigned 32-bit integer */

#define MAX_S32  (s32(2147483647)) /**< Maximum value for signed 32-bit integer */
#define MIN_S32  (s32(-2147483648)) /**< Minimum value for signed 32-bit integer */

#define MAX_U64  (u64(18446744073709551615)) /**< Maximum value for unsigned 64-bit integer */
#define MIN_U64  (u64(0)) /**< Minimum value for unsigned 64-bit integer */

#define MAX_S64  (s64(9223372036854775807)) /**< Maximum value for signed 64-bit integer */
#define MIN_S64  (s64(-9223372036854775808)) /**< Minimum value for signed 64-bit integer */

#endif /* STD_TYPES_H_ */