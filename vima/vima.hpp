/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#ifdef NOINLINE
    #define INLINE __attribute__ ((noinline))
#endif
#ifndef NOINLINE
    #define INLINE inline
#endif

#define VM64I 64    // 256B array length to integer type
#define VM128I 128    // 512B array length to integer type DONE
#define VM256I 256    // 1KB array length to integer type
#define VM512I 512    // 2KB array length to integer type
#define VM1KI 1024    // 4KB array length to integer type DONE
#define VM2KI 2048  // 8KB array length to integer type

#define VM32L 32    // 256B array length to long integer type
#define VM64L 64    // 512B array length to long integer type DONE
#define VM128L 128    // 1KB array length to long integer type
#define VM256L 256    // 2KB array length to long integer type
#define VM512L 512    // 4KB array length to long integer type DONE
#define VM1KL 1024  // 8KB array length to long integer type

/* VIMA types */
typedef int32_t  __v32s; // signed integer operand
typedef uint32_t __v32u; // unsigned integer operand
typedef float  __v32f; // signed float operand

typedef int64_t  __v64s; // long integer operand
typedef uint64_t __v64u; // long unsigned integer operand
typedef double __v64d; // signed double operand

/*******************************************************************************************************************
 *                                              INTEGER INSTRUCTIONS                                               *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/

// 01) 32-bit Add (64 integers)
void INLINE *_vim64_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 02) 32-bit Add (2048 integers)
void INLINE *_vim2K_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 03) 32-bit Add Unsigned (64 integers)
void INLINE *_vim64_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 04) 32-bit Add Unsigned (2048 integers)
void INLINE *_vim2K_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 05) 32-bit Subtract (64 integers)
void INLINE *_vim64_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 06) 32-bit Subtract (2048 integers)
void INLINE *_vim2K_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 07) 32-bit Subtract Unsigned (64 integers)
void INLINE *_vim64_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 08) 32-bit Subtract Unsigned (2048 integers)
void INLINE *_vim2K_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 09) 32-bit Abs (64 integers)
void INLINE *_vim64_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM64I; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 10) 32-bit Abs (2048 integers)
void INLINE *_vim2K_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM2KI; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 11) 32-bit Max (64 integers)
void INLINE *_vim64_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 12) 32-bit Max (2048 integers)
void INLINE *_vim2K_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 13) 32-bit Min (64 integers)
void INLINE *_vim64_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 14) 32-bit Min (2048 integers)
void INLINE *_vim2K_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 15) 32-bit Move Data Vector-to-Vector  (32 double)
void INLINE *_vim64_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 16) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim2K_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 17) 32-bit Move Data Vector-to-Vector (32 double)
void INLINE *_vim64_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 18) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim2K_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Logic instructions             */
/****************************************************/

// 19) 32-bit And (64 integers)
void INLINE *_vim64_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 20) 32-bit And (2048 integers)
void INLINE *_vim2K_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 21) 32-bit Or (64 integers)
void INLINE *_vim64_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 22) 32-bit Or (2048 integers)
void INLINE *_vim2K_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 23) 32-bit Xor (64 integers)
void INLINE *_vim64_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 24) 32-bit Xor (2048 integers)
void INLINE *_vim2K_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 25) 32-bit Not (64 integers)
void INLINE *_vim64_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

// 26) 32-bit Not (2048 integers)
void INLINE *_vim2K_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 27) 32-bit Set Less Than (64 integers)
void INLINE *_vim64_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 28) 32-bit Set Less Than (2048 integers)
void INLINE *_vim2K_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
void INLINE *_vim64_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
void INLINE *_vim2K_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 31) 32-bit Compare if equal (64 integers)
void INLINE *_vim64_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 32) 32-bit Compare if equal (2048 integers)
void INLINE *_vim2K_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
void INLINE *_vim64_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
void INLINE *_vim2K_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Shift instructions             */
/****************************************************/

// 35) 32-bit Shift Left Logical (64 integers)
void INLINE *_vim64_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 36) 32-bit Shift Left Logical (2048 integers)
void INLINE *_vim2K_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 37) 32-bit Shift Right Logical (64 integers)
void INLINE *_vim64_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 38) 32-bit Shift Right Logical (2048 integers)
void INLINE *_vim2K_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
void INLINE *_vim64_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
void INLINE *_vim2K_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 41) 32-bit Divide (64 integers)
void INLINE *_vim64_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 42) 32-bit Divide (2048 integers)
void INLINE *_vim2K_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 43) 32-bit Divide Unsigned (64 integers)
void INLINE *_vim64_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 44) 32-bit Divide Unsigned (2048 integers)
void INLINE *_vim2K_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 45) 64-bit Divide (32 integers)
void INLINE *_vim32_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 46) 64-bit Divide (1024 integers)
void INLINE *_vim1K_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 47) 64-bit Divide Unsigned (32 integers)
void INLINE *_vim32_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 48) 64-bit Divide Unsigned (1024 integers)
void INLINE *_vim1K_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 49) 32-bit Multiply (64 integers)
void INLINE *_vim64_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 50) 32-bit Multiply (2048 integers)
void INLINE *_vim2K_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 51) 32-bit Multiply Unsigned (64 integers)
void INLINE *_vim64_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 52) 32-bit Multiply Unsigned (2048 integers)
void INLINE *_vim2K_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 53) 64-bit Multiply (32 integers)
void INLINE *_vim32_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 54) 64-bit Multiply (1024 integers)
void INLINE *_vim1K_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 55) 64-bit Multiply Unsigned (32 integers)
void INLINE *_vim32_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 56) 64-bit Multiply Unsigned (1024 integers)
void INLINE *_vim1K_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 57) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim64_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 58) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim2K_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 59) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim64_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 60) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim2K_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 61) 32-bit Move Immediate Data (64 integers)
void INLINE *_vim64_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 62) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim2K_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 63) 32-bit Move Immediate Data Unsigned (64 integers)
void INLINE *_vim64_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 64) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim2K_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/*******************************************************************************************************************
 *                                           FLOATING-POINT INSTRUCTIONS                                           *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 65) 32-bit Add (64 floating-point single precision)
void INLINE *_vim64_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 66) 32-bit Add (2048 floating-point single precision)
void INLINE *_vim2K_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 67) 32-bit Subtract (64 floating-point single precision)
void INLINE *_vim64_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 68) 32-bit Subtract (2048 floating-point single precision)
void INLINE *_vim2K_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 69) 32-bit Abs (64 floating-point single precision)
void INLINE *_vim64_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 70) 32-bit Abs (2048 floating-point single precision)
void INLINE *_vim2K_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 71) 32-bit Max (64 floating-point single precision)
void INLINE *_vim64_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 72) 32-bit Max (2048 floating-point single precision)
void INLINE *_vim2K_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 73) 32-bit Min (64 floating-point single precision)
void INLINE *_vim64_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 74) 32-bit Min (2048 floating-point single precision)
void INLINE *_vim2K_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 75) 32-bit Move Data Vector-to-Vector (64 floating-point single precision)
void INLINE *_vim64_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 76) 32-bit Move Data Vector-to-Vector (2048 floating-point single precision)
void INLINE *_vim2K_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 77) 32-bit Set Less Than (64 floating-point single precision)
void INLINE *_vim64_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 78) 32-bit Set Less Than (2048 floating-point single precision)
void INLINE *_vim2K_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 79) 32-bit Compare if equal (64 floating-point single precision)
void INLINE *_vim64_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 80) 32-bit Compare if equal (2048 floating-point single precision)
void INLINE *_vim2K_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 81) 32-bit Divide (64 floating-point single precision)
void INLINE *_vim64_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 82) 32-bit Divide (2048 floating-point single precision)
void INLINE *_vim2K_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 83) 32-bit Multiply (64 floating-point single precision)
void INLINE *_vim64_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 84) 32-bit Multiply (2048 floating-point single precision)
void INLINE *_vim2K_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 85) 32-bit Cumulative Sum (64 floating-point single precision)
void INLINE *_vim64_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 86) 32-bit Cumulative Sum (2048 floating-point single precision)
void INLINE *_vim2K_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 87) 32-bit Move Immediate Data (64 floating-point single precision)
void INLINE *_vim64_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 88) 32-bit Move Immediate Data (2048 floating-point single precision)
void INLINE *_vim2K_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}



/*******************************************************************************************************************
 *                                   FLOATING-POINT DOUBLE PRECISION INSTRUCTIONS                                  *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 89) 64-bit Add (32 floating-point double precision)
void INLINE *_vim32_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 90) 64-bit Add (1024 floating-point double precision)
void INLINE *_vim1K_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 91) 64-bit Subtract (32 floating-point double precision)
void INLINE *_vim32_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 92) 64-bit Subtract (1024 floating-point double precision)
void INLINE *_vim1K_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 93) 64-bit Abs (32 floating-point double precision)
void INLINE *_vim32_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 94) 64-bit Abs (1024 floating-point double precision)
void INLINE *_vim1K_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 95) 64-bit Max (32 floating-point double precision)
void INLINE *_vim32_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 96) 64-bit Max (1024 floating-point double precision)
void INLINE *_vim1K_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 97) 64-bit Min (32 floating-point double precision)
void INLINE *_vim32_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 98) 64-bit Min (1024 floating-point double precision)
void INLINE *_vim1K_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 99) 64-bit Move Data Vector-to-Vector (32 floating-point double precision)
void INLINE *_vim32_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM32L; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 100) 64-bit Move Data Vector-to-Vector (1024 floating-point double precision)
void INLINE *_vim1K_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM1KL; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 101) 64-bit Set Less Than (32 floating-point double precision)
void INLINE *_vim32_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 102) 64-bit Set Less Than (1024 floating-point double precision)
void INLINE *_vim1K_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 103) 64-bit Compare if equal (32 floating-point double precision)
void INLINE *_vim32_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 104) 64-bit Compare if equal (1024 floating-point double precision)
void INLINE *_vim1K_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 105) 64-bit Divide (32 floating-point double precision)
void INLINE *_vim32_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 106) 64-bit Divide (1024 floating-point double precision)
void INLINE *_vim1K_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 107) 64-bit Multiply (32 floating-point double precision)
void INLINE *_vim32_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {
        c[i] = a[i] * b[i];
        // printf("%lf = %lf * %lf ", c[i], a[i], b[i]);
    }
    // printf("\n\n");
    return EXIT_SUCCESS;
}

// 108) 64-bit Multiply (1024 floating-point double precision)
void INLINE *_vim1K_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 109) 64-bit Cumulative Sum (32 floating-point double precision)
void INLINE *_vim32_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM32L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 110) 64-bit Cumulative Sum (1024 floating-point double precision)
void INLINE *_vim1K_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM1KL; ++i) {*b += a[i];} return EXIT_SUCCESS;
}
/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 111) 64-bit Move Immediate Data (32 floating-point double precision)
void INLINE *_vim32_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM32L; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 112) 64-bit Move Immediate Data (1024 floating-point double precision)
void INLINE *_vim1K_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM1KL; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/****************************************************/
/*          VIMA Additional instructions             */
/****************************************************/

// 113) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim64_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim2K_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Load (64 32-bit signed integers)
void INLINE *_vim64_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Load (64 32-bit signed integers)
void INLINE *_vim2K_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Load (64 floating-point single precision)
void INLINE *_vim64_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Load (2048 floating-point single precision)
void INLINE *_vim2K_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Load (32 floating-point double precision)
void INLINE *_vim64_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM32L; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Load (1024 floating-point double precision)
void INLINE *_vim2K_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM1KL; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 113) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim64_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim2K_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Store (64 32-bit signed integers)
void INLINE *_vim64_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Store (64 32-bit signed integers)
void INLINE *_vim2K_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Store (64 floating-point single precision)
void INLINE *_vim64_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Store (2048 floating-point single precision)
void INLINE *_vim2K_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Store (32 floating-point double precision)
void INLINE *_vim64_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM32L; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Store (1024 floating-point double precision)
void INLINE *_vim2K_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM1KL; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 121) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim64_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 122) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim2K_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 123) Mask Reset (64 32-bit signed integers)
void INLINE *_vim64_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 124) Mask Reset (64 32-bit signed integers)
void INLINE *_vim2K_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 125) Mask Reset (64 floating-point single precision)
void INLINE *_vim64_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM64I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 126) Mask Reset (2048 floating-point single precision)
void INLINE *_vim2K_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM2KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 127) Mask Reset (32 floating-point double precision)
void INLINE *_vim64_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM32L; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 128) Mask Reset (1024 floating-point double precision)
void INLINE *_vim2K_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM1KL; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 129) Permute (64 32-bit unsigned integers)
void INLINE *_vim64_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 130) Permute (64 32-bit unsigned integers)
void INLINE *_vim2K_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 131) Permute (64 32-bit signed integers)
void INLINE *_vim64_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 132) Permute (64 32-bit signed integers)
void INLINE *_vim2K_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 133) Permute (64 floating-point single precision)
void INLINE *_vim64_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 134) Permute (2048 floating-point single precision)
void INLINE *_vim2K_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 135) Permute (32 floating-point double precision)
void INLINE *_vim64_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM32L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 136) Permute (1024 floating-point double precision)
void INLINE *_vim2K_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM1KL; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 137) Mod (64 32-bit unsigned integers)
void INLINE *_vim64_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 138) Mod (64 32-bit unsigned integers)
void INLINE *_vim2K_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 139) Mod (64 32-bit signed integers)
void INLINE *_vim64_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 140) Mod (64 32-bit signed integers)
void INLINE *_vim2K_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 141) Gather (64 32-bit unsigned integers)
void INLINE *_vim64_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 142) Gather (64 32-bit unsigned integers)
void INLINE *_vim2K_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 143) Gather (64 32-bit signed integers)
void INLINE *_vim64_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 144) Gather (64 32-bit signed integers)
void INLINE *_vim2K_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 145) Gather (64 floating-point single precision)
void INLINE *_vim64_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM64I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 146) Gather (2048 floating-point single precision)
void INLINE *_vim2K_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM2KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 147) Gather (32 floating-point double precision)
void INLINE *_vim64_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM32L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 148) Gather (1024 floating-point double precision)
void INLINE *_vim2K_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM1KL; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 149) Scatter (64 32-bit unsigned integers)
void INLINE *_vim64_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM64I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 150) Scatter (64 32-bit unsigned integers)
void INLINE *_vim2K_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM2KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 151) Scatter (64 32-bit signed integers)
void INLINE *_vim64_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM64I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 152) Scatter (64 32-bit signed integers)
void INLINE *_vim2K_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM2KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 153) Scatter (64 floating-point single precision)
void INLINE *_vim64_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM64I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 154) Scatter (2048 floating-point single precision)
void INLINE *_vim2K_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM2KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 155) Scatter (32 floating-point double precision)
void INLINE *_vim64_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM32L; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 156) Scatter (1024 floating-point double precision)
void INLINE *_vim2K_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM1KL; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 157) Dot Product (64 unsigned integers)
void INLINE *_vim64_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM64I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 158) Dot Product (2048 unsigned integers)
void INLINE *_vim2K_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM2KI; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 159) Dot Product (64 signed integers)
void INLINE *_vim64_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM64I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 160) Dot Product (2048 signed integers)
void INLINE *_vim2K_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM2KI; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 161) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim64_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM64I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 162) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim2K_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM2KI; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 163) Scatter OR (64 32-bit signed integers)
void INLINE *_vim64_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM64I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 164) Scatter OR (64 32-bit signed integers)
void INLINE *_vim2K_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM2KI; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

/*******************************************************************************************************************
 *                                              INTEGER INSTRUCTIONS                                               *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/

// 01) 32-bit Add (64 integers)
void INLINE *_vim128_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 02) 32-bit Add (2048 integers)
void INLINE *_vim1K_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 03) 32-bit Add Unsigned (64 integers)
void INLINE *_vim128_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 04) 32-bit Add Unsigned (2048 integers)
void INLINE *_vim1K_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 05) 32-bit Subtract (64 integers)
void INLINE *_vim128_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 06) 32-bit Subtract (2048 integers)
void INLINE *_vim1K_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 07) 32-bit Subtract Unsigned (64 integers)
void INLINE *_vim128_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 08) 32-bit Subtract Unsigned (2048 integers)
void INLINE *_vim1K_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 09) 32-bit Abs (64 integers)
void INLINE *_vim128_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM128I; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 10) 32-bit Abs (2048 integers)
void INLINE *_vim1K_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM1KI; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 11) 32-bit Max (64 integers)
void INLINE *_vim128_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 12) 32-bit Max (2048 integers)
void INLINE *_vim1K_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 13) 32-bit Min (64 integers)
void INLINE *_vim128_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 14) 32-bit Min (2048 integers)
void INLINE *_vim1K_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 15) 32-bit Move Data Vector-to-Vector  (32 double)
void INLINE *_vim128_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 16) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim1K_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 17) 32-bit Move Data Vector-to-Vector (32 double)
void INLINE *_vim128_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 18) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim1K_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Logic instructions             */
/****************************************************/

// 19) 32-bit And (64 integers)
void INLINE *_vim128_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 20) 32-bit And (2048 integers)
void INLINE *_vim1K_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 21) 32-bit Or (64 integers)
void INLINE *_vim128_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 22) 32-bit Or (2048 integers)
void INLINE *_vim1K_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 23) 32-bit Xor (64 integers)
void INLINE *_vim128_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 24) 32-bit Xor (2048 integers)
void INLINE *_vim1K_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 25) 32-bit Not (64 integers)
void INLINE *_vim128_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

// 26) 32-bit Not (2048 integers)
void INLINE *_vim1K_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 27) 32-bit Set Less Than (64 integers)
void INLINE *_vim128_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 28) 32-bit Set Less Than (2048 integers)
void INLINE *_vim1K_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
void INLINE *_vim128_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
void INLINE *_vim1K_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 31) 32-bit Compare if equal (64 integers)
void INLINE *_vim128_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 32) 32-bit Compare if equal (2048 integers)
void INLINE *_vim1K_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
void INLINE *_vim128_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
void INLINE *_vim1K_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Shift instructions             */
/****************************************************/

// 35) 32-bit Shift Left Logical (64 integers)
void INLINE *_vim128_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 36) 32-bit Shift Left Logical (2048 integers)
void INLINE *_vim1K_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 37) 32-bit Shift Right Logical (64 integers)
void INLINE *_vim128_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 38) 32-bit Shift Right Logical (2048 integers)
void INLINE *_vim1K_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
void INLINE *_vim128_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
void INLINE *_vim1K_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 41) 32-bit Divide (64 integers)
void INLINE *_vim128_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 42) 32-bit Divide (2048 integers)
void INLINE *_vim1K_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 43) 32-bit Divide Unsigned (64 integers)
void INLINE *_vim128_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 44) 32-bit Divide Unsigned (2048 integers)
void INLINE *_vim1K_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 45) 64-bit Divide (32 integers)
void INLINE *_vim64_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 46) 64-bit Divide (1024 integers)
void INLINE *_vim512_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 47) 64-bit Divide Unsigned (32 integers)
void INLINE *_vim64_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 48) 64-bit Divide Unsigned (1024 integers)
void INLINE *_vim512_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 49) 32-bit Multiply (64 integers)
void INLINE *_vim128_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 50) 32-bit Multiply (2048 integers)
void INLINE *_vim1K_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 51) 32-bit Multiply Unsigned (64 integers)
void INLINE *_vim128_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 52) 32-bit Multiply Unsigned (2048 integers)
void INLINE *_vim1K_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 53) 64-bit Multiply (32 integers)
void INLINE *_vim64_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 54) 64-bit Multiply (1024 integers)
void INLINE *_vim512_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 55) 64-bit Multiply Unsigned (32 integers)
void INLINE *_vim64_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 56) 64-bit Multiply Unsigned (1024 integers)
void INLINE *_vim512_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 57) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim128_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM128I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 58) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim1K_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM1KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 59) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim128_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM128I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 60) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim1K_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM1KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 61) 32-bit Move Immediate Data (64 integers)
void INLINE *_vim128_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 62) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim1K_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 63) 32-bit Move Immediate Data Unsigned (64 integers)
void INLINE *_vim128_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 64) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim1K_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/*******************************************************************************************************************
 *                                           FLOATING-POINT INSTRUCTIONS                                           *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 65) 32-bit Add (64 floating-point single precision)
void INLINE *_vim128_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 66) 32-bit Add (2048 floating-point single precision)
void INLINE *_vim1K_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 67) 32-bit Subtract (64 floating-point single precision)
void INLINE *_vim128_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 68) 32-bit Subtract (2048 floating-point single precision)
void INLINE *_vim1K_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 69) 32-bit Abs (64 floating-point single precision)
void INLINE *_vim128_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 70) 32-bit Abs (2048 floating-point single precision)
void INLINE *_vim1K_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 71) 32-bit Max (64 floating-point single precision)
void INLINE *_vim128_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 72) 32-bit Max (2048 floating-point single precision)
void INLINE *_vim1K_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 73) 32-bit Min (64 floating-point single precision)
void INLINE *_vim128_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 74) 32-bit Min (2048 floating-point single precision)
void INLINE *_vim1K_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 75) 32-bit Move Data Vector-to-Vector (64 floating-point single precision)
void INLINE *_vim128_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 76) 32-bit Move Data Vector-to-Vector (2048 floating-point single precision)
void INLINE *_vim1K_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 77) 32-bit Set Less Than (64 floating-point single precision)
void INLINE *_vim128_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 78) 32-bit Set Less Than (2048 floating-point single precision)
void INLINE *_vim1K_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 79) 32-bit Compare if equal (64 floating-point single precision)
void INLINE *_vim128_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 80) 32-bit Compare if equal (2048 floating-point single precision)
void INLINE *_vim1K_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 81) 32-bit Divide (64 floating-point single precision)
void INLINE *_vim128_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 82) 32-bit Divide (2048 floating-point single precision)
void INLINE *_vim1K_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 83) 32-bit Multiply (64 floating-point single precision)
void INLINE *_vim128_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM128I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 84) 32-bit Multiply (2048 floating-point single precision)
void INLINE *_vim1K_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM1KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 85) 32-bit Cumulative Sum (64 floating-point single precision)
void INLINE *_vim128_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM128I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 86) 32-bit Cumulative Sum (2048 floating-point single precision)
void INLINE *_vim1K_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM1KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 87) 32-bit Move Immediate Data (64 floating-point single precision)
void INLINE *_vim128_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM128I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 88) 32-bit Move Immediate Data (2048 floating-point single precision)
void INLINE *_vim1K_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM1KI; ++i) {b[i] = a;} return EXIT_SUCCESS;
}



/*******************************************************************************************************************
 *                                   FLOATING-POINT DOUBLE PRECISION INSTRUCTIONS                                  *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 89) 64-bit Add (32 floating-point double precision)
void INLINE *_vim64_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 90) 64-bit Add (1024 floating-point double precision)
void INLINE *_vim512_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 91) 64-bit Subtract (32 floating-point double precision)
void INLINE *_vim64_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 92) 64-bit Subtract (1024 floating-point double precision)
void INLINE *_vim512_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 93) 64-bit Abs (32 floating-point double precision)
void INLINE *_vim64_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM64L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 94) 64-bit Abs (1024 floating-point double precision)
void INLINE *_vim512_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM512L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 95) 64-bit Max (32 floating-point double precision)
void INLINE *_vim64_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 96) 64-bit Max (1024 floating-point double precision)
void INLINE *_vim512_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 97) 64-bit Min (32 floating-point double precision)
void INLINE *_vim64_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 98) 64-bit Min (1024 floating-point double precision)
void INLINE *_vim512_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 99) 64-bit Move Data Vector-to-Vector (32 floating-point double precision)
void INLINE *_vim64_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM64L; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 100) 64-bit Move Data Vector-to-Vector (1024 floating-point double precision)
void INLINE *_vim512_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM512L; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 101) 64-bit Set Less Than (32 floating-point double precision)
void INLINE *_vim64_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 102) 64-bit Set Less Than (1024 floating-point double precision)
void INLINE *_vim512_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 103) 64-bit Compare if equal (32 floating-point double precision)
void INLINE *_vim64_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 104) 64-bit Compare if equal (1024 floating-point double precision)
void INLINE *_vim512_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 105) 64-bit Divide (32 floating-point double precision)
void INLINE *_vim64_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 106) 64-bit Divide (1024 floating-point double precision)
void INLINE *_vim512_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 107) 64-bit Multiply (32 floating-point double precision)
void INLINE *_vim64_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM64L; ++i) {
        c[i] = a[i] * b[i];
        // printf("%lf = %lf * %lf ", c[i], a[i], b[i]);
    }
    // printf("\n\n");
    return EXIT_SUCCESS;
}

// 108) 64-bit Multiply (1024 floating-point double precision)
void INLINE *_vim512_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM512L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 109) 64-bit Cumulative Sum (32 floating-point double precision)
void INLINE *_vim64_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM64L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 110) 64-bit Cumulative Sum (1024 floating-point double precision)
void INLINE *_vim512_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM512L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}
/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 111) 64-bit Move Immediate Data (32 floating-point double precision)
void INLINE *_vim64_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM64L; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 112) 64-bit Move Immediate Data (1024 floating-point double precision)
void INLINE *_vim512_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM512L; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/****************************************************/
/*          VIMA Additional instructions             */
/****************************************************/

// 113) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim128_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim1K_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Load (64 32-bit signed integers)
void INLINE *_vim128_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Load (64 32-bit signed integers)
void INLINE *_vim1K_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Load (64 floating-point single precision)
void INLINE *_vim128_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Load (2048 floating-point single precision)
void INLINE *_vim1K_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Load (32 floating-point double precision)
void INLINE *_vim128_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM64L; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Load (1024 floating-point double precision)
void INLINE *_vim1K_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM512L; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 113) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim128_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim1K_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Store (64 32-bit signed integers)
void INLINE *_vim128_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Store (64 32-bit signed integers)
void INLINE *_vim1K_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Store (64 floating-point single precision)
void INLINE *_vim128_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Store (2048 floating-point single precision)
void INLINE *_vim1K_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Store (32 floating-point double precision)
void INLINE *_vim128_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM64L; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Store (1024 floating-point double precision)
void INLINE *_vim1K_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM512L; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 121) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim128_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 122) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim1K_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 123) Mask Reset (64 32-bit signed integers)
void INLINE *_vim128_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 124) Mask Reset (64 32-bit signed integers)
void INLINE *_vim1K_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 125) Mask Reset (64 floating-point single precision)
void INLINE *_vim128_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM128I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 126) Mask Reset (2048 floating-point single precision)
void INLINE *_vim1K_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM1KI; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 127) Mask Reset (32 floating-point double precision)
void INLINE *_vim128_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM64L; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 128) Mask Reset (1024 floating-point double precision)
void INLINE *_vim1K_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM512L; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 129) Permute (64 32-bit unsigned integers)
void INLINE *_vim128_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 130) Permute (64 32-bit unsigned integers)
void INLINE *_vim1K_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 131) Permute (64 32-bit signed integers)
void INLINE *_vim128_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 132) Permute (64 32-bit signed integers)
void INLINE *_vim1K_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 133) Permute (64 floating-point single precision)
void INLINE *_vim128_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 134) Permute (2048 floating-point single precision)
void INLINE *_vim1K_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 135) Permute (32 floating-point double precision)
void INLINE *_vim128_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM64L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 136) Permute (1024 floating-point double precision)
void INLINE *_vim1K_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM512L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 137) Mod (64 32-bit unsigned integers)
void INLINE *_vim128_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 138) Mod (64 32-bit unsigned integers)
void INLINE *_vim1K_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 139) Mod (64 32-bit signed integers)
void INLINE *_vim128_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 140) Mod (64 32-bit signed integers)
void INLINE *_vim1K_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 141) Gather (64 32-bit unsigned integers)
void INLINE *_vim128_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 142) Gather (64 32-bit unsigned integers)
void INLINE *_vim1K_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 143) Gather (64 32-bit signed integers)
void INLINE *_vim128_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 144) Gather (64 32-bit signed integers)
void INLINE *_vim1K_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 145) Gather (64 floating-point single precision)
void INLINE *_vim128_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM128I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 146) Gather (2048 floating-point single precision)
void INLINE *_vim1K_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM1KI; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 147) Gather (32 floating-point double precision)
void INLINE *_vim128_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM64L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 148) Gather (1024 floating-point double precision)
void INLINE *_vim1K_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM512L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 149) Scatter (64 32-bit unsigned integers)
void INLINE *_vim128_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM128I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 150) Scatter (64 32-bit unsigned integers)
void INLINE *_vim1K_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM1KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 151) Scatter (64 32-bit signed integers)
void INLINE *_vim128_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM128I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 152) Scatter (64 32-bit signed integers)
void INLINE *_vim1K_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM1KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 153) Scatter (64 floating-point single precision)
void INLINE *_vim128_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM128I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 154) Scatter (2048 floating-point single precision)
void INLINE *_vim1K_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM1KI; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 155) Scatter (32 floating-point double precision)
void INLINE *_vim128_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM64L; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 156) Scatter (1024 floating-point double precision)
void INLINE *_vim1K_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM512L; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 157) Dot Product (64 unsigned integers)
void INLINE *_vim128_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM128I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 158) Dot Product (2048 unsigned integers)
void INLINE *_vim1K_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM1KI; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 159) Dot Product (64 signed integers)
void INLINE *_vim128_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM128I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 160) Dot Product (2048 signed integers)
void INLINE *_vim1K_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM1KI; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 161) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim128_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM128I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 162) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim1K_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM1KI; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 163) Scatter OR (64 32-bit signed integers)
void INLINE *_vim128_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM128I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 164) Scatter OR (64 32-bit signed integers)
void INLINE *_vim1K_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM1KI; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

/*******************************************************************************************************************
 *                                              INTEGER INSTRUCTIONS                                               *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/

// 01) 32-bit Add (64 integers)
void INLINE *_vim256_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 02) 32-bit Add (2048 integers)
void INLINE *_vim512_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 03) 32-bit Add Unsigned (64 integers)
void INLINE *_vim256_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 04) 32-bit Add Unsigned (2048 integers)
void INLINE *_vim512_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 05) 32-bit Subtract (64 integers)
void INLINE *_vim256_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 06) 32-bit Subtract (2048 integers)
void INLINE *_vim512_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 07) 32-bit Subtract Unsigned (64 integers)
void INLINE *_vim256_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 08) 32-bit Subtract Unsigned (2048 integers)
void INLINE *_vim512_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 09) 32-bit Abs (64 integers)
void INLINE *_vim256_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM256I; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 10) 32-bit Abs (2048 integers)
void INLINE *_vim512_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM512I; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 11) 32-bit Max (64 integers)
void INLINE *_vim256_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 12) 32-bit Max (2048 integers)
void INLINE *_vim512_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 13) 32-bit Min (64 integers)
void INLINE *_vim256_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 14) 32-bit Min (2048 integers)
void INLINE *_vim512_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 15) 32-bit Move Data Vector-to-Vector  (32 double)
void INLINE *_vim256_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 16) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim512_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 17) 32-bit Move Data Vector-to-Vector (32 double)
void INLINE *_vim256_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 18) 32-bit Move Data Vector-to-Vector (1024 double)
void INLINE *_vim512_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Logic instructions             */
/****************************************************/

// 19) 32-bit And (64 integers)
void INLINE *_vim256_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 20) 32-bit And (2048 integers)
void INLINE *_vim512_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 21) 32-bit Or (64 integers)
void INLINE *_vim256_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 22) 32-bit Or (2048 integers)
void INLINE *_vim512_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 23) 32-bit Xor (64 integers)
void INLINE *_vim256_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 24) 32-bit Xor (2048 integers)
void INLINE *_vim512_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 25) 32-bit Not (64 integers)
void INLINE *_vim256_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

// 26) 32-bit Not (2048 integers)
void INLINE *_vim512_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 27) 32-bit Set Less Than (64 integers)
void INLINE *_vim256_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 28) 32-bit Set Less Than (2048 integers)
void INLINE *_vim512_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
void INLINE *_vim256_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
void INLINE *_vim512_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 31) 32-bit Compare if equal (64 integers)
void INLINE *_vim256_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 32) 32-bit Compare if equal (2048 integers)
void INLINE *_vim512_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
void INLINE *_vim256_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
void INLINE *_vim512_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Shift instructions             */
/****************************************************/

// 35) 32-bit Shift Left Logical (64 integers)
void INLINE *_vim256_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 36) 32-bit Shift Left Logical (2048 integers)
void INLINE *_vim512_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 37) 32-bit Shift Right Logical (64 integers)
void INLINE *_vim256_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 38) 32-bit Shift Right Logical (2048 integers)
void INLINE *_vim512_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
void INLINE *_vim256_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
void INLINE *_vim512_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 41) 32-bit Divide (64 integers)
void INLINE *_vim256_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 42) 32-bit Divide (2048 integers)
void INLINE *_vim512_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 43) 32-bit Divide Unsigned (64 integers)
void INLINE *_vim256_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 44) 32-bit Divide Unsigned (2048 integers)
void INLINE *_vim512_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 45) 64-bit Divide (32 integers)
void INLINE *_vim128_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 46) 64-bit Divide (1024 integers)
void INLINE *_vim256_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 47) 64-bit Divide Unsigned (32 integers)
void INLINE *_vim128_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 48) 64-bit Divide Unsigned (1024 integers)
void INLINE *_vim256_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 49) 32-bit Multiply (64 integers)
void INLINE *_vim256_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 50) 32-bit Multiply (2048 integers)
void INLINE *_vim512_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 51) 32-bit Multiply Unsigned (64 integers)
void INLINE *_vim256_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 52) 32-bit Multiply Unsigned (2048 integers)
void INLINE *_vim512_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 53) 64-bit Multiply (32 integers)
void INLINE *_vim128_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 54) 64-bit Multiply (1024 integers)
void INLINE *_vim256_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 55) 64-bit Multiply Unsigned (32 integers)
void INLINE *_vim128_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 56) 64-bit Multiply Unsigned (1024 integers)
void INLINE *_vim256_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 57) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim256_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM256I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 58) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim512_icumu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM512I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 59) 32-bit Cumulative Sum (64 floats)
void INLINE *_vim256_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM256I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 60) 32-bit Cumulative Sum (2048 integers)
void INLINE *_vim512_icums(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM512I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 61) 32-bit Move Immediate Data (64 integers)
void INLINE *_vim256_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 62) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim512_imovs(__v32s a, __v32s *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 63) 32-bit Move Immediate Data Unsigned (64 integers)
void INLINE *_vim256_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 64) 32-bit Move Immediate Data (2048 integers)
void INLINE *_vim512_imovu(__v32u a, __v32u *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/*******************************************************************************************************************
 *                                           FLOATING-POINT INSTRUCTIONS                                           *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 65) 32-bit Add (64 floating-point single precision)
void INLINE *_vim256_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 66) 32-bit Add (2048 floating-point single precision)
void INLINE *_vim512_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 67) 32-bit Subtract (64 floating-point single precision)
void INLINE *_vim256_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 68) 32-bit Subtract (2048 floating-point single precision)
void INLINE *_vim512_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 69) 32-bit Abs (64 floating-point single precision)
void INLINE *_vim256_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 70) 32-bit Abs (2048 floating-point single precision)
void INLINE *_vim512_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 71) 32-bit Max (64 floating-point single precision)
void INLINE *_vim256_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 72) 32-bit Max (2048 floating-point single precision)
void INLINE *_vim512_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 73) 32-bit Min (64 floating-point single precision)
void INLINE *_vim256_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 74) 32-bit Min (2048 floating-point single precision)
void INLINE *_vim512_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 75) 32-bit Move Data Vector-to-Vector (64 floating-point single precision)
void INLINE *_vim256_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 76) 32-bit Move Data Vector-to-Vector (2048 floating-point single precision)
void INLINE *_vim512_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 77) 32-bit Set Less Than (64 floating-point single precision)
void INLINE *_vim256_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 78) 32-bit Set Less Than (2048 floating-point single precision)
void INLINE *_vim512_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 79) 32-bit Compare if equal (64 floating-point single precision)
void INLINE *_vim256_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 80) 32-bit Compare if equal (2048 floating-point single precision)
void INLINE *_vim512_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 81) 32-bit Divide (64 floating-point single precision)
void INLINE *_vim256_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 82) 32-bit Divide (2048 floating-point single precision)
void INLINE *_vim512_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 83) 32-bit Multiply (64 floating-point single precision)
void INLINE *_vim256_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM256I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 84) 32-bit Multiply (2048 floating-point single precision)
void INLINE *_vim512_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM512I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 85) 32-bit Cumulative Sum (64 floating-point single precision)
void INLINE *_vim256_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM256I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 86) 32-bit Cumulative Sum (2048 floating-point single precision)
void INLINE *_vim512_fcums(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM512I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 87) 32-bit Move Immediate Data (64 floating-point single precision)
void INLINE *_vim256_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM256I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 88) 32-bit Move Immediate Data (2048 floating-point single precision)
void INLINE *_vim512_fmovs(__v32f a, __v32f *b) {
    for (int i = 0; i < VM512I; ++i) {b[i] = a;} return EXIT_SUCCESS;
}



/*******************************************************************************************************************
 *                                   FLOATING-POINT DOUBLE PRECISION INSTRUCTIONS                                  *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 89) 64-bit Add (32 floating-point double precision)
void INLINE *_vim128_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 90) 64-bit Add (1024 floating-point double precision)
void INLINE *_vim256_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 91) 64-bit Subtract (32 floating-point double precision)
void INLINE *_vim128_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 92) 64-bit Subtract (1024 floating-point double precision)
void INLINE *_vim256_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 93) 64-bit Abs (32 floating-point double precision)
void INLINE *_vim128_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM128L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 94) 64-bit Abs (1024 floating-point double precision)
void INLINE *_vim256_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM256L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 95) 64-bit Max (32 floating-point double precision)
void INLINE *_vim128_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 96) 64-bit Max (1024 floating-point double precision)
void INLINE *_vim256_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 97) 64-bit Min (32 floating-point double precision)
void INLINE *_vim128_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 98) 64-bit Min (1024 floating-point double precision)
void INLINE *_vim256_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 99) 64-bit Move Data Vector-to-Vector (32 floating-point double precision)
void INLINE *_vim128_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM128L; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

// 100) 64-bit Move Data Vector-to-Vector (1024 floating-point double precision)
void INLINE *_vim256_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM256L; ++i) {b[i] = a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 101) 64-bit Set Less Than (32 floating-point double precision)
void INLINE *_vim128_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 102) 64-bit Set Less Than (1024 floating-point double precision)
void INLINE *_vim256_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 103) 64-bit Compare if equal (32 floating-point double precision)
void INLINE *_vim128_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 104) 64-bit Compare if equal (1024 floating-point double precision)
void INLINE *_vim256_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 105) 64-bit Divide (32 floating-point double precision)
void INLINE *_vim128_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 106) 64-bit Divide (1024 floating-point double precision)
void INLINE *_vim256_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 107) 64-bit Multiply (32 floating-point double precision)
void INLINE *_vim128_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM128L; ++i) {
        c[i] = a[i] * b[i];
        // printf("%lf = %lf * %lf ", c[i], a[i], b[i]);
    }
    // printf("\n\n");
    return EXIT_SUCCESS;
}

// 108) 64-bit Multiply (1024 floating-point double precision)
void INLINE *_vim256_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM256L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 109) 64-bit Cumulative Sum (32 floating-point double precision)
void INLINE *_vim128_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM128L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 110) 64-bit Cumulative Sum (1024 floating-point double precision)
void INLINE *_vim256_dcums(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM256L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}
/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 111) 64-bit Move Immediate Data (32 floating-point double precision)
void INLINE *_vim128_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM128L; ++i) {b[i] = a;} return EXIT_SUCCESS;
}

// 112) 64-bit Move Immediate Data (1024 floating-point double precision)
void INLINE *_vim256_dmovs(__v64d a, __v64d *b) {
    for (int i = 0; i < VM256L; ++i) {b[i] = a;} return EXIT_SUCCESS;
}


/****************************************************/
/*          VIMA Additional instructions             */
/****************************************************/

// 113) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim256_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Load (64 32-bit unsigned integers)
void INLINE *_vim512_ilmku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Load (64 32-bit signed integers)
void INLINE *_vim256_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Load (64 32-bit signed integers)
void INLINE *_vim512_ilmks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Load (64 floating-point single precision)
void INLINE *_vim256_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Load (2048 floating-point single precision)
void INLINE *_vim512_flmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Load (32 floating-point double precision)
void INLINE *_vim256_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM128L; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Load (1024 floating-point double precision)
void INLINE *_vim512_dlmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM256L; i++){
        if (mask[i] == 1) dst[i] = vec[count++];
    }
    return EXIT_SUCCESS;
}

// 113) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim256_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 114) Mask Store (64 32-bit unsigned integers)
void INLINE *_vim512_ismku (__v32u* vec, __v32u* mask, __v32u* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 115) Mask Store (64 32-bit signed integers)
void INLINE *_vim256_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 116) Mask Store (64 32-bit signed integers)
void INLINE *_vim512_ismks (__v32s* vec, __v32u* mask, __v32s* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 117) Mask Store (64 floating-point single precision)
void INLINE *_vim256_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 118) Mask Store (2048 floating-point single precision)
void INLINE *_vim512_fsmks (__v32f* vec, __v32u* mask, __v32f* dst){
    int count = 0;
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 119) Mask Store (32 floating-point double precision)
void INLINE *_vim256_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM128L; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 120) Mask Store (1024 floating-point double precision)
void INLINE *_vim512_dsmks (__v64d* vec, __v32u* mask, __v64d* dst){
    int count = 0;
    for (int i = 0; i < VM256L; i++){
        if (mask[i] == 1) dst[count++] = vec[i];
    }
    return EXIT_SUCCESS;
}

// 121) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim256_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 122) Mask Reset (64 32-bit unsigned integers)
void INLINE *_vim512_irmku (__v32u* vec, __v32u* mask){
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 123) Mask Reset (64 32-bit signed integers)
void INLINE *_vim256_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 124) Mask Reset (64 32-bit signed integers)
void INLINE *_vim512_irmks (__v32s* vec, __v32u* mask){
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 125) Mask Reset (64 floating-point single precision)
void INLINE *_vim256_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM256I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 126) Mask Reset (2048 floating-point single precision)
void INLINE *_vim512_frmks (__v32f* vec, __v32u* mask){
    for (int i = 0; i < VM512I; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 127) Mask Reset (32 floating-point double precision)
void INLINE *_vim256_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM128L; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 128) Mask Reset (1024 floating-point double precision)
void INLINE *_vim512_drmks (__v64d* vec, __v32u* mask){
    for (int i = 0; i < VM256L; i++){
        if (mask[i] == 1) vec[i] = 0;
    }
    return EXIT_SUCCESS;
}

// 129) Permute (64 32-bit unsigned integers)
void INLINE *_vim256_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 130) Permute (64 32-bit unsigned integers)
void INLINE *_vim512_ipmtu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 131) Permute (64 32-bit signed integers)
void INLINE *_vim256_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 132) Permute (64 32-bit signed integers)
void INLINE *_vim512_ipmts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 133) Permute (64 floating-point single precision)
void INLINE *_vim256_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 134) Permute (2048 floating-point single precision)
void INLINE *_vim512_fpmts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 135) Permute (32 floating-point double precision)
void INLINE *_vim256_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM128L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 136) Permute (1024 floating-point double precision)
void INLINE *_vim512_dpmts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM256L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 137) Mod (64 32-bit unsigned integers)
void INLINE *_vim256_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 138) Mod (64 32-bit unsigned integers)
void INLINE *_vim512_imodu (__v32u* vec, __v32u imm, __v32u* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 139) Mod (64 32-bit signed integers)
void INLINE *_vim256_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 140) Mod (64 32-bit signed integers)
void INLINE *_vim512_imods (__v32s* vec, __v32u imm, __v32s* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[i] % imm;
    return EXIT_SUCCESS;
}

// 141) Gather (64 32-bit unsigned integers)
void INLINE *_vim256_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 142) Gather (64 32-bit unsigned integers)
void INLINE *_vim512_igtru (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 143) Gather (64 32-bit signed integers)
void INLINE *_vim256_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 144) Gather (64 32-bit signed integers)
void INLINE *_vim512_igtrs (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 145) Gather (64 floating-point single precision)
void INLINE *_vim256_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM256I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 146) Gather (2048 floating-point single precision)
void INLINE *_vim512_fgtrs (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM512I; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 147) Gather (32 floating-point double precision)
void INLINE *_vim256_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM128L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 148) Gather (1024 floating-point double precision)
void INLINE *_vim512_dgtrs (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM256L; i++) dst[i] = vec[idx[i]];
    return EXIT_SUCCESS;
}

// 149) Scatter (64 32-bit unsigned integers)
void INLINE *_vim256_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM256I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 150) Scatter (64 32-bit unsigned integers)
void INLINE *_vim512_isctu (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM512I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 151) Scatter (64 32-bit signed integers)
void INLINE *_vim256_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM256I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 152) Scatter (64 32-bit signed integers)
void INLINE *_vim512_iscts (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM512I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 153) Scatter (64 floating-point single precision)
void INLINE *_vim256_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM256I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 154) Scatter (2048 floating-point single precision)
void INLINE *_vim512_fscts (__v32f* vec, __v32u* idx, __v32f* dst){
    for (int i = 0; i < VM512I; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 155) Scatter (32 floating-point double precision)
void INLINE *_vim256_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM128L; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 156) Scatter (1024 floating-point double precision)
void INLINE *_vim512_dscts (__v64d* vec, __v32u* idx, __v64d* dst){
    for (int i = 0; i < VM256L; i++) dst[idx[i]] = vec[i];
    return EXIT_SUCCESS;
}

// 157) Dot Product (64 unsigned integers)
void INLINE *_vim256_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM256I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 158) Dot Product (2048 unsigned integers)
void INLINE *_vim512_idptu (__v32u* vec, __v32u* imm){
    *imm = 0;
    for (int i = 0; i < VM512I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 159) Dot Product (64 signed integers)
void INLINE *_vim256_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM256I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 160) Dot Product (2048 signed integers)
void INLINE *_vim512_idpts (__v32s* vec, __v32s* imm){
    *imm = 0;
    for (int i = 0; i < VM512I; i++) *imm += vec[i];
    return EXIT_SUCCESS;
}

// 161) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim256_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM256I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 162) Scatter OR (64 32-bit unsigned integers)
void INLINE *_vim512_iscou (__v32u* vec, __v32u* idx, __v32u* dst){
    for (int i = 0; i < VM512I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 163) Scatter OR (64 32-bit signed integers)
void INLINE *_vim256_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM256I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}

// 164) Scatter OR (64 32-bit signed integers)
void INLINE *_vim512_iscos (__v32s* vec, __v32u* idx, __v32s* dst){
    for (int i = 0; i < VM512I; i++) dst[idx[i]] = dst[idx[i]] | vec[i];
    return EXIT_SUCCESS;
}