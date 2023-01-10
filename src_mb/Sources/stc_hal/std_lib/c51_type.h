#ifndef C51_TYPE_H
#define C51_TYPE_H

// #include <LIMITS.H>
// #include <FLOAT.H>

// #define uint8_t unsigned char
// #define uint16_t unsigned int
// #define uint32_t unsigned long
#define uint64_t unsigned long int

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef unsigned char bool;

//typedef uint32_t size_t;

#define int8_t signed char
#define int16_t signed int
#define int32_t signed long

#define float32_t float
#define float64_t double

#define u8 volatile unsigned char
#define u16 volatile unsigned int
#define u32 volatile unsigned long

#define TRUE ((uint8_t)(1))
#define FALSE ((uint8_t)(0))

#define UINT8_MAX ((uint8_t)(0xFF))
#define UINT16_MAX ((uint16_t)(0xFFFF))
#define UINT32_MAX ((uint32_t)(0xFFFFFFFF))

#define UINT8_MIN ((uint8_t)(0))
#define UINT16_MIN ((uint16_t)(0))
#define UINT32_MIN ((uint32_t)(0))

#define INT8_MAX ((int8_t)(0x7F))
#define INT16_MAX ((int16_t)(0x7FFF))
#define INT32_MAX ((int32_t)(0x7FFFFFFF))

#define INT8_MIN ((int8_t)(0x80))
#define INT16_MIN ((int16_t)(0x8000))
#define INT32_MIN ((int16_t)(0x80000000))

// #define UINT8_MIN (0)
// #define UINT8_MAX USHRT_MAX
// #define INT8_MIN SHRT_MIN
// #define INT8_MAX SHRT_MAX

// #define UINT16_MIN (0)
// #define UINT16_MAX UINT_MAX
// #define INT16_MIN INT_MIN
// #define INT16_MAX INT_MAX

// #define UINT32_MIN (0)
// #define UINT32_MAX ULONG_MAX
// #define INT32_MIN LONG_MIN
// #define INT32_MAX LONG_MAX

#endif /* End of C51_TYPE_H */
