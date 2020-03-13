/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define VM64I 64    // 256B array length to integer type
#define VM2KI 2048  // 8KB array length to integer type
#define VM32L 32    // 256B array length to long integer type
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
inline void *_vim64_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 02) 32-bit Add (2048 integers)
inline void *_vim2K_iadds(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 03) 32-bit Add Unsigned (64 integers)
inline void *_vim64_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 04) 32-bit Add Unsigned (2048 integers)
inline void *_vim2K_iaddu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 05) 32-bit Subtract (64 integers)
inline void *_vim64_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 06) 32-bit Subtract (2048 integers)
inline void *_vim2K_isubs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 07) 32-bit Subtract Unsigned (64 integers)
inline void *_vim64_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 08) 32-bit Subtract Unsigned (2048 integers)
inline void *_vim2K_isubu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 09) 32-bit Abs (64 integers)
inline void *_vim64_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM64I; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 10) 32-bit Abs (2048 integers)
inline void *_vim2K_iabss(__v32s *a, __v32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM2KI; ++i) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
    return EXIT_SUCCESS;
}

// 11) 32-bit Max (64 integers)
inline void *_vim64_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 12) 32-bit Max (2048 integers)
inline void *_vim2K_imaxs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 13) 32-bit Min (64 integers)
inline void *_vim64_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 14) 32-bit Min (2048 integers)
inline void *_vim2K_imins(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 15) 32-bit Move Data Vector-to-Vector  (32 double)
inline void *_vim64_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

// 16) 32-bit Move Data Vector-to-Vector (1024 double)
inline void *_vim2K_icpys(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

// 17) 32-bit Move Data Vector-to-Vector (32 double)
inline void *_vim64_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

// 18) 32-bit Move Data Vector-to-Vector (1024 double)
inline void *_vim2K_icpyu(__v32u *a, __v32u *b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Logic instructions             */
/****************************************************/

// 19) 32-bit And (64 integers)
inline void *_vim64_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 20) 32-bit And (2048 integers)
inline void *_vim2K_iandu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] & b[i];} return EXIT_SUCCESS;
}

// 21) 32-bit Or (64 integers)
inline void *_vim64_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 22) 32-bit Or (2048 integers)
inline void *_vim2K_iorun(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] | b[i];} return EXIT_SUCCESS;
}

// 23) 32-bit Xor (64 integers)
inline void *_vim64_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 24) 32-bit Xor (2048 integers)
inline void *_vim2K_ixoru(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
    return EXIT_SUCCESS;
}

// 25) 32-bit Not (64 integers)
inline void *_vim64_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM64I; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

// 26) 32-bit Not (2048 integers)
inline void *_vim2K_inots(__v32s *a, __v32s *b) {
    for (int i = 0; i < VM2KI; ++i) {b[i] = ~a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 27) 32-bit Set Less Than (64 integers)
inline void *_vim64_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 28) 32-bit Set Less Than (2048 integers)
inline void *_vim2K_islts(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
inline void *_vim64_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
inline void *_vim2K_isltu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 31) 32-bit Compare if equal (64 integers)
inline void *_vim64_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 32) 32-bit Compare if equal (2048 integers)
inline void *_vim2K_icmqs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
inline void *_vim64_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
inline void *_vim2K_icmqu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*              VIMA Shift instructions             */
/****************************************************/

// 35) 32-bit Shift Left Logical (64 integers)
inline void *_vim64_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 36) 32-bit Shift Left Logical (2048 integers)
inline void *_vim2K_isllu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] << b[i];} return EXIT_SUCCESS;
}

// 37) 32-bit Shift Right Logical (64 integers)
inline void *_vim64_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 38) 32-bit Shift Right Logical (2048 integers)
inline void *_vim2K_isrlu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
inline void *_vim64_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
inline void *_vim2K_isras(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] >> b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 41) 32-bit Divide (64 integers)
inline void *_vim64_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 42) 32-bit Divide (2048 integers)
inline void *_vim2K_idivs(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 43) 32-bit Divide Unsigned (64 integers)
inline void *_vim64_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 44) 32-bit Divide Unsigned (2048 integers)
inline void *_vim2K_idivu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 45) 64-bit Divide (32 integers)
inline void *_vim32_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 46) 64-bit Divide (1024 integers)
inline void *_vim1K_idivs(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 47) 64-bit Divide Unsigned (32 integers)
inline void *_vim32_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 48) 64-bit Divide Unsigned (1024 integers)
inline void *_vim1K_idivu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 49) 32-bit Multiply (64 integers)
inline void *_vim64_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 50) 32-bit Multiply (2048 integers)
inline void *_vim2K_imuls(__v32s *a, __v32s *b, __v32s *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 51) 32-bit Multiply Unsigned (64 integers)
inline void *_vim64_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 52) 32-bit Multiply Unsigned (2048 integers)
inline void *_vim2K_imulu(__v32u *a, __v32u *b, __v32u *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 53) 64-bit Multiply (32 integers)
inline void *_vim32_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 54) 64-bit Multiply (1024 integers)
inline void *_vim1K_imuls(__v64s *a, __v64s *b, __v64s *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 55) 64-bit Multiply Unsigned (32 integers)
inline void *_vim32_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 56) 64-bit Multiply Unsigned (1024 integers)
inline void *_vim1K_imulu(__v64u *a, __v64u *b, __v64u *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 57) 32-bit Multiply-Add (64 floats)
inline void *_vim64_imadu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 58) 32-bit Multiply-Add (2048 integers)
inline void *_vim2K_imadu(__v32u *a, __v32u *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 59) 32-bit Multiply-Add (64 floats)
inline void *_vim64_imads(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 60) 32-bit Multiply-Add (2048 integers)
inline void *_vim2K_imads(__v32s *a, __v32s *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 61) 32-bit Move Immediate Data (64 integers)
inline void *_vim64_imovs(__v32s *a, __v32s b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b;} return EXIT_SUCCESS;
}

// 62) 32-bit Move Immediate Data (2048 integers)
inline void *_vim2K_imovs(__v32s *a, __v32s b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b;} return EXIT_SUCCESS;
}

// 63) 32-bit Move Immediate Data Unsigned (64 integers)
inline void *_vim64_imovu(__v32u *a, __v32u b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b;} return EXIT_SUCCESS;
}

// 64) 32-bit Move Immediate Data (2048 integers)
inline void *_vim2K_imovu(__v32u *a, __v32u b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b;} return EXIT_SUCCESS;
}


/*******************************************************************************************************************
 *                                           FLOATING-POINT INSTRUCTIONS                                           *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 65) 32-bit Add (64 floating-point single precision)
inline void *_vim64_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 66) 32-bit Add (2048 floating-point single precision)
inline void *_vim2K_fadds(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 67) 32-bit Subtract (64 floating-point single precision)
inline void *_vim64_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 68) 32-bit Subtract (2048 floating-point single precision)
inline void *_vim2K_fsubs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 69) 32-bit Abs (64 floating-point single precision)
inline void *_vim64_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 70) 32-bit Abs (2048 floating-point single precision)
inline void *_vim2K_fabss(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 71) 32-bit Max (64 floating-point single precision)
inline void *_vim64_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 72) 32-bit Max (2048 floating-point single precision)
inline void *_vim2K_fmaxs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 73) 32-bit Min (64 floating-point single precision)
inline void *_vim64_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 74) 32-bit Min (2048 floating-point single precision)
inline void *_vim2K_fmins(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 75) 32-bit Move Data Vector-to-Vector (64 floating-point single precision)
inline void *_vim64_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

// 76) 32-bit Move Data Vector-to-Vector (2048 floating-point single precision)
inline void *_vim2K_fcpys(__v32f *a, __v32f *b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 77) 32-bit Set Less Than (64 floating-point single precision)
inline void *_vim64_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 78) 32-bit Set Less Than (2048 floating-point single precision)
inline void *_vim2K_fslts(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 79) 32-bit Compare if equal (64 floating-point single precision)
inline void *_vim64_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 80) 32-bit Compare if equal (2048 floating-point single precision)
inline void *_vim2K_fcmqs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 81) 32-bit Divide (64 floating-point single precision)
inline void *_vim64_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 82) 32-bit Divide (2048 floating-point single precision)
inline void *_vim2K_fdivs(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 83) 32-bit Multiply (64 floating-point single precision)
inline void *_vim64_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM64I; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 84) 32-bit Multiply (2048 floating-point single precision)
inline void *_vim2K_fmuls(__v32f *a, __v32f *b, __v32f *c) {
    for (int i = 0; i < VM2KI; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 85) 32-bit Multiply-Add (64 floating-point single precision)
inline void *_vim64_fmads(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM64I; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 86) 32-bit Multiply-Add (2048 floating-point single precision)
inline void *_vim2K_fmads(__v32f *a, __v32f *b) {
    *b = 0; for (int i = 0; i < VM2KI; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 87) 32-bit Move Immediate Data (64 floating-point single precision)
inline void *_vim64_fmovs(__v32f *a, __v32f b) {
    for (int i = 0; i < VM64I; ++i) {a[i] = b;} return EXIT_SUCCESS;
}

// 88) 32-bit Move Immediate Data (2048 floating-point single precision)
inline void *_vim2K_fmovs(__v32f *a, __v32f b) {
    for (int i = 0; i < VM2KI; ++i) {a[i] = b;} return EXIT_SUCCESS;
}



/*******************************************************************************************************************
 *                                   FLOATING-POINT DOUBLE PRECISION INSTRUCTIONS                                  *
 ******************************************************************************************************************/

/****************************************************/
/*          VIMA Arithmetic instructions            */
/****************************************************/
// 89) 64-bit Add (32 floating-point double precision)
inline void *_vim32_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 90) 64-bit Add (1024 floating-point double precision)
inline void *_vim1K_dadds(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] + b[i];} return EXIT_SUCCESS;
}

// 91) 64-bit Subtract (32 floating-point double precision)
inline void *_vim32_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 92) 64-bit Subtract (1024 floating-point double precision)
inline void *_vim1K_dsubs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] - b[i];} return EXIT_SUCCESS;
}

// 93) 64-bit Abs (32 floating-point double precision)
inline void *_vim32_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 94) 64-bit Abs (1024 floating-point double precision)
inline void *_vim1K_dabss(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < 0.0) {b[i] = a[i] * (-1.0);} else {b[i] = a[i];}}
    return EXIT_SUCCESS;
}

// 95) 64-bit Max (32 floating-point double precision)
inline void *_vim32_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 96) 64-bit Max (1024 floating-point double precision)
inline void *_vim1K_dmaxs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 97) 64-bit Min (32 floating-point double precision)
inline void *_vim32_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 98) 64-bit Min (1024 floating-point double precision)
inline void *_vim1K_dmins(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
    return EXIT_SUCCESS;
}

// 99) 64-bit Move Data Vector-to-Vector (32 floating-point double precision)
inline void *_vim32_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM32L; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

// 100) 64-bit Move Data Vector-to-Vector (1024 floating-point double precision)
inline void *_vim1K_dcpys(__v64d *a, __v64d *b) {
    for (int i = 0; i < VM1KL; ++i) {a[i] = b[i];} return EXIT_SUCCESS;
}

/****************************************************/
/*          VIMA Comparison instructions            */
/****************************************************/

// 101) 64-bit Set Less Than (32 floating-point double precision)
inline void *_vim32_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 102) 64-bit Set Less Than (1024 floating-point double precision)
inline void *_vim1K_dslts(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 103) 64-bit Compare if equal (32 floating-point double precision)
inline void *_vim32_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

// 104) 64-bit Compare if equal (1024 floating-point double precision)
inline void *_vim1K_dcmqs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
    return EXIT_SUCCESS;
}

/****************************************************/
/*    VIMA Multiplication/Division instructions     */
/****************************************************/

// 105) 64-bit Divide (32 floating-point double precision)
inline void *_vim32_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 106) 64-bit Divide (1024 floating-point double precision)
inline void *_vim1K_ddivs(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] / b[i];} return EXIT_SUCCESS;
}

// 107) 64-bit Multiply (32 floating-point double precision)
inline void *_vim32_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM32L; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 108) 64-bit Multiply (1024 floating-point double precision)
inline void *_vim1K_dmuls(__v64d *a, __v64d *b, __v64d *c) {
    for (int i = 0; i < VM1KL; ++i) {c[i] = a[i] * b[i];} return EXIT_SUCCESS;
}

// 109) 64-bit Multiply-Add (32 floating-point double precision)
inline void *_vim32_dmads(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM32L; ++i) {*b += a[i];} return EXIT_SUCCESS;
}

// 110) 64-bit Multiply-Add (1024 floating-point double precision)
inline void *_vim1K_dmads(__v64d *a, __v64d *b) {
    *b = 0; for (int i = 0; i < VM1KL; ++i) {*b += a[i];} return EXIT_SUCCESS;
}
/****************************************************/
/*          VIMA Immediate instructions             */
/****************************************************/

// 111) 64-bit Move Immediate Data (32 floating-point double precision)
inline void *_vim32_dmovs(__v64d *a, __v64d b) {
    for (int i = 0; i < VM32L; ++i) {a[i] = b;} return EXIT_SUCCESS;
}

// 112) 64-bit Move Immediate Data (1024 floating-point double precision)
inline void *_vim1K_dmovs(__v64d *a, __v64d b) {
    for (int i = 0; i < VM1KL; ++i) {a[i] = b;} return EXIT_SUCCESS;
}
