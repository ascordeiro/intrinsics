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
typedef int32_t  __vm32s; // signed integer operand
typedef uint32_t __vm32u; // unsigned integer operand
typedef int64_t  __vm64s; // long integer operand
typedef uint64_t __vm64u; // long unsigned integer operand
typedef float  __vm32f; // signed float operand

/*********************************/
/* VIMA Arithmetic instructions */
/*********************************/

// 01) 32-bit Add (64 integers)
inline void *_vim64_iadds(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] + b[i];}
}

// 02) 32-bit Add (2048 integers)
inline void *_vim2K_iadds(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] + b[i];}
}

// 03) 32-bit Add Unsigned (64 integers)
inline void *_vim64_iaddu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] + b[i];}
}

// 04) 32-bit Add Unsigned (2048 integers)
inline void *_vim2K_iaddu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] + b[i];}
}

// 05) 32-bit Subtract (64 integers)
inline void *_vim64_isubs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] - b[i];}
}

// 06) 32-bit Subtract (2048 integers)
inline void *_vim2K_isubs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] - b[i];}
}

// 07) 32-bit Subtract Unsigned (64 integers)
inline void *_vim64_isubu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] - b[i];}
}

// 08) 32-bit Subtract Unsigned (2048 integers)
inline void *_vim2K_isubu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] - b[i];}
}

// 09) 32-bit Abs (64 integers)
inline void *_vim64_iabss(__vm32s *a, __vm32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM64I; i++) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
}

// 10) 32-bit Abs (2048 integers)
inline void *_vim2K_iabss(__vm32s *a, __vm32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < VM2KI; i++) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
}

// 11) 32-bit Max (64 integers)
inline void *_vim64_imaxs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 12) 32-bit Max (2048 integers)
inline void *_vim2K_imaxs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 13) 32-bit Min (64 integers)
inline void *_vim64_imins(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 14) 32-bit Min (2048 integers)
inline void *_vim2K_imins(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

/****************************/
/* VIMA Logic instructions */
/****************************/

// 15) 32-bit And (64 integers)
inline void *_vim64_iandu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] & b[i];}
}


// 16) 32-bit And (2048 integers)
inline void *_vim2K_iandu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] & b[i];}
}

// 17) 32-bit Or (64 integers)
inline void *_vim64_iorun(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] | b[i];}
}

// 18) 32-bit Or (2048 integers)
inline void *_vim2K_iorun(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] | b[i];}
}

// 19) 32-bit Xor (64 integers)
inline void *_vim64_ixoru(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
}

// 20) 32-bit Xor (2048 integers)
inline void *_vim2K_ixoru(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
}

// 21) 32-bit Not (64 integers)
inline void *_vim64_inots(__vm32s *a, __vm32s *b) {
    for (int i = 0; i < VM64I; i++) {b[i] = ~a[i];}
}

// 22) 32-bit Not (2048 integers)
inline void *_vim2K_inots(__vm32s *a, __vm32s *b) {
    for (int i = 0; i < VM2KI; i++) {b[i] = ~a[i];}
}

// 23) 32-bit Mask (64 integers)
inline void *_vim64_imsks(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 24) 32-bit Mask (2048 integers)
inline void *_vim2K_imsks(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 25) 32-bit Masku (64 integers)
inline void *_vim64_imsku(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 26) 32-bit Masku (2048 integers)
inline void *_vim2K_imsku(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

/*********************************/
/* VIMA Comparison instructions */
/*********************************/

// 27) 32-bit Set Less Than (64 integers)
inline void *_vim64_islts(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 28) 32-bit Set Less Than (2048 integers)
inline void *_vim2K_islts(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
inline void *_vim64_isltu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
inline void *_vim2K_isltu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 31) 32-bit Compare if equal (64 integers)
inline void *_vim64_icmqs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 32) 32-bit Compare if equal (2048 integers)
inline void *_vim2K_icmqs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
inline void *_vim64_icmqu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
inline void *_vim2K_icmqu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

/****************************/
/* VIMA Shift instructions */
/****************************/

// 35) 32-bit Shift Left Logical (64 integers)
inline void *_vim64_isllu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] << b[i];}
}

// 36) 32-bit Shift Left Logical (2048 integers)
inline void *_vim2K_isllu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] << b[i];}
}

// 37) 32-bit Shift Right Logical (64 integers)
inline void *_vim64_isrlu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] >> b[i];}
}

// 38) 32-bit Shift Right Logical (2048 integers)
inline void *_vim2K_isrlu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] >> b[i];}
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
inline void *_vim64_isras(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] >> b[i];}
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
inline void *_vim2K_isras(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] >> b[i];}
}

/**********************************************/
/* VIMA Multiplication/Division instructions */
/**********************************************/

// 41) 32-bit Divide Only (64 integers)
inline void *_vim64_idivs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] / b[i];}
}

// 42) 32-bit Divide Only (2048 integers)
inline void *_vim2K_idivs(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] / b[i];}
}

// 43) 32-bit Divide Only Unsigned (64 integers)
inline void *_vim64_idivu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] / b[i];}
}

// 44) 32-bit Divide Only Unsigned (2048 integers)
inline void *_vim2K_idivu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] / b[i];}
}

// 45) 32-bit Module Only (64 integers)
inline void *_vim64_imods(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] % b[i];}
}

// 46) 32-bit Module Only (2048 integers)
inline void *_vim2K_imods(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] % b[i];}
}

// 47) 32-bit Module Only Unsigned (64 integers)
inline void *_vim64_imodu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] % b[i];}
}

// 48) 32-bit Module Only Unsigned (2048 integers)
inline void *_vim2K_imodu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] % b[i];}
}

// 49) 32-bit Multiply (64 integers)
inline void *_vim64_imuls(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] * b[i];}
}

// 50) 32-bit Multiply (2048 integers)
inline void *_vim2K_imuls(__vm32s *a, __vm32s *b, __vm32s *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] * b[i];}
}

// 51) 32-bit Multiply Unsigned (64 integers)
inline void *_vim64_imulu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] * b[i];}
}

// 52) 32-bit Multiply Unsigned (2048 integers)
inline void *_vim2K_imulu(__vm32u *a, __vm32u *b, __vm32u *c) {
    for (int i = 0; i < VM2KI; i++) {c[i] = a[i] * b[i];}
}

// 53) 64-bit Multiply (32 integers)
inline void *_vim32_imuls(__vm64s *a, __vm64s *b, __vm64s *c) {
    for (int i = 0; i < VM32L; i++) {c[i] = a[i] * b[i];}
}

// 54) 64-bit Multiply (1024 integers)
inline void *_vim1K_imuls(__vm64s *a, __vm64s *b, __vm64s *c) {
    for (int i = 0; i < VM1KL; i++) {c[i] = a[i] * b[i];}
}

// 55) 64-bit Multiply Unsigned (32 integers)
inline void *_vim32_imulu(__vm64u *a, __vm64u *b, __vm64u *c) {
    for (int i = 0; i < VM32L; i++) {c[i] = a[i] * b[i];}
}

// 56) 64-bit Multiply Unsigned (1024 integers)
inline void *_vim1K_imulu(__vm64u *a, __vm64u *b, __vm64u *c) {
    for (int i = 0; i < VM1KL; i++) {c[i] = a[i] * b[i];}
}

/********************************/
/* VIMA Immediate instructions */
/********************************/

// 57) 32-bit Move Immediate Data (64 integers)
inline void *_vim64_imovs(__vm32s *a, __vm32s b) {
    for (int i = 0; i < VM64I; i++) {a[i] = b;}
}

// 58) 32-bit Move Immediate Data (2048 integers)
inline void *_vim2K_imovs(__vm32s *a, __vm32s b) {
    for (int i = 0; i < VM2KI; i++) {a[i] = b;}
}

// 59) 32-bit Move Immediate Data Unsigned (64 integers)
inline void *_vim64_imovu(__vm32u *a, __vm32u b) {
    for (int i = 0; i < VM64I; i++) {a[i] = b;}
}

// 60) 32-bit Move Immediate Data (2048 integers)
inline void *_vim2K_imovu(__vm32u *a, __vm32u b) {
    for (int i = 0; i < VM2KI; i++) {a[i] = b;}
}

/**************************/
/* VIMA kNN instructions */
/**************************/

// 61) 32-bit Move Immediate Data (64 floats)
inline void *_vim64_fmovs(__vm32f *a, __vm32f b) {
    for (int i = 0; i < VM64I; i++) {a[i] = b;}
}

// 62) 32-bit Subtract (64 floats)
inline void *_vim64_fsubs(__vm32f *a, __vm32f *b, __vm32f *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] - b[i];}
}

// 63) 32-bit Multiply (64 floats)
inline void *_vim64_fmuls(__vm32f *a, __vm32f *b, __vm32f *c) {
    for (int i = 0; i < VM64I; i++) {c[i] = a[i] * b[i];}
}

// 64) 32-bit Cumulative Sum (64 floats)
inline void *_vim64_fcsum(__vm32f *a, __vm32f *b) {
    *b = 0;
    for (int i = 0; i < VM64I; i++) {*b += a[i];}
}
