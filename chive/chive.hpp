/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define CH64I 64    // 256B array length to integer type
#define CH2KI 2048  // 8KB array length to integer type
#define CH32L 32    // 256B array length to long integer type
#define CH1KL 1024  // 8KB array length to long integer type

/* CHVE types */
typedef int32_t  __ch32s; // signed integer operand
typedef uint32_t __ch32u; // unsigned integer operand
typedef int64_t  __ch64s; // long integer operand
typedef uint64_t __ch64u; // long unsigned integer operand
typedef float_t  __ch32f; // signed float operand

/*********************************/
/* CHIVE Arithmetic instructions */
/*********************************/

// 01) 32-bit Add (64 integers)
inline void *_chive64_iadds(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] + b[i];}
}

// 02) 32-bit Add (2048 integers)
inline void *_chive2K_iadds(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] + b[i];}
}

// 03) 32-bit Add Unsigned (64 integers)
inline void *_chive64_iaddu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] + b[i];}
}

// 04) 32-bit Add Unsigned (2048 integers)
inline void *_chive2K_iaddu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] + b[i];}
}

// 05) 32-bit Subtract (64 integers)
inline void *_chive64_isubs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] - b[i];}
}

// 06) 32-bit Subtract (2048 integers)
inline void *_chive2K_isubs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] - b[i];}
}

// 07) 32-bit Subtract Unsigned (64 integers)
inline void *_chive64_isubu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] - b[i];}
}

// 08) 32-bit Subtract Unsigned (2048 integers)
inline void *_chive2K_isubu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] - b[i];}
}

// 09) 32-bit Abs (64 integers)
inline void *_chive64_iabss(__ch32s *a, __ch32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < CH64I; i++) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
}

// 10) 32-bit Abs (2048 integers)
inline void *_chive2K_iabss(__ch32s *a, __ch32s *b) {
    int mask, shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < CH2KI; i++) {mask = a[i] >> shift; b[i] = ((a[i] + mask) ^ mask);}
}

// 11) 32-bit Max (64 integers)
inline void *_chive64_imaxs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 12) 32-bit Max (2048 integers)
inline void *_chive2K_imaxs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] > b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 13) 32-bit Min (64 integers)
inline void *_chive64_imins(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

// 14) 32-bit Min (2048 integers)
inline void *_chive2K_imins(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] < b[i]) {c[i] = a[i];} else {c[i] = b[i];}}
}

/****************************/
/* CHIVE Logic instructions */
/****************************/

// 15) 32-bit And (64 integers)
inline void *_chive64_iandu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] & b[i];}
}


// 16) 32-bit And (2048 integers)
inline void *_chive2K_iandu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] & b[i];}
}

// 17) 32-bit Or (64 integers)
inline void *_chive64_iorun(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] | b[i];}
}

// 18) 32-bit Or (2048 integers)
inline void *_chive2K_iorun(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] | b[i];}
}

// 19) 32-bit Xor (64 integers)
inline void *_chive64_ixoru(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
}

// 20) 32-bit Xor (2048 integers)
inline void *_chive2K_ixoru(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);}
}

// 21) 32-bit Not (64 integers)
inline void *_chive64_inots(__ch32s *a, __ch32s *b) {
    for (int i = 0; i < CH64I; i++) {b[i] = ~a[i];}
}

// 22) 32-bit Not (2048 integers)
inline void *_chive2K_inots(__ch32s *a, __ch32s *b) {
    for (int i = 0; i < CH2KI; i++) {b[i] = ~a[i];}
}

// 23) 32-bit Mask (64 integers)
inline void *_chive64_imsks(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 24) 32-bit Mask (2048 integers)
inline void *_chive2K_imsks(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 25) 32-bit Masku (64 integers)
inline void *_chive64_imsku(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

// 26) 32-bit Masku (2048 integers)
inline void *_chive2K_imsku(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {if (b[i] == 0) {c[i] = a[i];}}
}

/*********************************/
/* CHIVE Comparison instructions */
/*********************************/

// 27) 32-bit Set Less Than (64 integers)
inline void *_chive64_islts(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 28) 32-bit Set Less Than (2048 integers)
inline void *_chive2K_islts(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
inline void *_chive64_isltu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
inline void *_chive2K_isltu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] < b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 31) 32-bit Compare if equal (64 integers)
inline void *_chive64_icmqs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 32) 32-bit Compare if equal (2048 integers)
inline void *_chive2K_icmqs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
inline void *_chive64_icmqu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
inline void *_chive2K_icmqu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {if (a[i] == b[i]) {c[i] = 1;} else {c[i] = 0;}}
}

/****************************/
/* CHIVE Shift instructions */
/****************************/

// 35) 32-bit Shift Left Logical (64 integers)
inline void *_chive64_isllu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] << b[i];}
}

// 36) 32-bit Shift Left Logical (2048 integers)
inline void *_chive2K_isllu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] << b[i];}
}

// 37) 32-bit Shift Right Logical (64 integers)
inline void *_chive64_isrlu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] >> b[i];}
}

// 38) 32-bit Shift Right Logical (2048 integers)
inline void *_chive2K_isrlu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] >> b[i];}
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
inline void *_chive64_isras(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] >> b[i];}
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
inline void *_chive2K_isras(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] >> b[i];}
}

/**********************************************/
/* CHIVE Multiplication/Division instructions */
/**********************************************/

// 41) 32-bit Divide Only (64 integers)
inline void *_chive64_idivs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] / b[i];}
}

// 42) 32-bit Divide Only (2048 integers)
inline void *_chive2K_idivs(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] / b[i];}
}

// 43) 32-bit Divide Only Unsigned (64 integers)
inline void *_chive64_idivu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] / b[i];}
}

// 44) 32-bit Divide Only Unsigned (2048 integers)
inline void *_chive2K_idivu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] / b[i];}
}

// 45) 32-bit Module Only (64 integers)
inline void *_chive64_imods(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] % b[i];}
}

// 46) 32-bit Module Only (2048 integers)
inline void *_chive2K_imods(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] % b[i];}
}

// 47) 32-bit Module Only Unsigned (64 integers)
inline void *_chive64_imodu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] % b[i];}
}

// 48) 32-bit Module Only Unsigned (2048 integers)
inline void *_chive2K_imodu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] % b[i];}
}

// 49) 32-bit Multiply (64 integers)
inline void *_chive64_imuls(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] * b[i];}
}

// 50) 32-bit Multiply (2048 integers)
inline void *_chive2K_imuls(__ch32s *a, __ch32s *b, __ch32s *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] * b[i];}
}

// 51) 32-bit Multiply Unsigned (64 integers)
inline void *_chive64_imulu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] * b[i];}
}

// 52) 32-bit Multiply Unsigned (2048 integers)
inline void *_chive2K_imulu(__ch32u *a, __ch32u *b, __ch32u *c) {
    for (int i = 0; i < CH2KI; i++) {c[i] = a[i] * b[i];}
}

// 53) 64-bit Multiply (32 integers)
inline void *_chive32_imuls(__ch64s *a, __ch64s *b, __ch64s *c) {
    for (int i = 0; i < CH32L; i++) {c[i] = a[i] * b[i];}
}

// 54) 64-bit Multiply (1024 integers)
inline void *_chive1K_imuls(__ch64s *a, __ch64s *b, __ch64s *c) {
    for (int i = 0; i < CH1KL; i++) {c[i] = a[i] * b[i];}
}

// 55) 64-bit Multiply Unsigned (32 integers)
inline void *_chive32_imulu(__ch64u *a, __ch64u *b, __ch64u *c) {
    for (int i = 0; i < CH32L; i++) {c[i] = a[i] * b[i];}
}

// 56) 64-bit Multiply Unsigned (1024 integers)
inline void *_chive1K_imulu(__ch64u *a, __ch64u *b, __ch64u *c) {
    for (int i = 0; i < CH1KL; i++) {c[i] = a[i] * b[i];}
}

/********************************/
/* CHIVE Immediate instructions */
/********************************/

// 57) 32-bit Move Immediate Data (64 integers)
inline void *_chive64_imovs(__ch32s *a, __ch32s b) {
    for (int i = 0; i < CH64I; i++) {a[i] = b;}
}

// 58) 32-bit Move Immediate Data (2048 integers)
inline void *_chive2K_imovs(__ch32s *a, __ch32s b) {
    for (int i = 0; i < CH2KI; i++) {a[i] = b;}
}

// 59) 32-bit Move Immediate Data Unsigned (64 integers)
inline void *_chive64_imovu(__ch32u *a, __ch32u b) {
    for (int i = 0; i < CH64I; i++) {a[i] = b;}
}

// 60) 32-bit Move Immediate Data (2048 integers)
inline void *_chive2K_imovu(__ch32u *a, __ch32u b) {
    for (int i = 0; i < CH2KI; i++) {a[i] = b;}
}

/**************************/
/* CHIVE kNN instructions */
/**************************/

// 61) 32-bit Move Immediate Data (64 floats)
inline void *_chive64_fmovs(__ch32f *a, __ch32f b) {
    for (int i = 0; i < CH64I; i++) {a[i] = b;}
}

// 62) 32-bit Subtract (64 floats)
inline void *_chive64_fsubs(__ch32f *a, __ch32f *b, __ch32f *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] - b[i];}
}

// 63) 32-bit Multiply (64 floats)
inline void *_chive64_fmuls(__ch32f *a, __ch32f *b, __ch32f *c) {
    for (int i = 0; i < CH64I; i++) {c[i] = a[i] * b[i];}
}

// 64) 32-bit Cumulative Sum (64 floats)
inline void *_chive64_fcsum(__ch32f *a, __ch32f *b) {
    *b = 0;
    for (int i = 0; i < CH64I; i++) {*b += a[i];}
}
