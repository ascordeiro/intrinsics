/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>

#define HI64I 64    // 256B array length to integer type
#define HI2kI 2048  // 8KB array length to integer type
#define HI32L 32    // 256B array length to long integer type
#define HI1kL 1024  // 8KB array length to long integer type

/* HIVE types */
typedef int32_t  __hi32s; // signed integer operand
typedef uint32_t __hi32u; // unsigned integer operand
typedef int64_t  __hi64s; // long integer operand
typedef uint64_t __hi64u; // long unsigned integer operand

/********************************/
/* HIVE Arithmetic instructions */
/********************************/

// 01) 32-bit Add
inline __hi32s *_hi64_add(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

// 02) 32-bit Add Unsigned
inline __hi32u *_hi64_addu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

// 03) 32-bit Subtract
inline __hi32s *_hi64_sub(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

// 04) 32-bit Subtract Unsigned
inline __hi32u *_hi64_subu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

// 05) 32-bit Abs
inline __hi32s *_hi64_abs(__hi32s *a) {
    int const mask;
    int shift = (sizeof(int) * 8 - 1);
    __hi32s *b = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        mask = a[i] >> shift;
        b[i] = ((a[i] + mask) ^ mask);
    }
    return b;
}

// 06) 32-bit Max
inline __hi32s *_hi64_max(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] > b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
    }
    return c;
}

// 07) 32-bit Min
inline __hi32s *_hi64_min(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
    }
    return c;
}

/***************************/
/* HIVE Logic instructions */
/***************************/

// 08) 32-bit And
inline __hi32u *_hi64_and(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] & b[i];
    }
    return c;
}

// 09) 32-bit Or
inline __hi32u *_hi64_or(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] | b[i];
    }
    return c;
}

// 10) 32-bit Xor
inline __hi32u *_hi64_xor(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);
    }
    return c;
}

// 11) 32-bit Not
inline __hi32s *_hi64_not(__hi32s *a) {
    __hi32s *b = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        b[i] = ~a[i];
    }
    return b;
}

// 12) 32-bit Mask
inline __hi32s *_hi64_mask(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
    return c;
}

// 13) 32-bit Masku
inline __hi32u *_hi64_masku(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
    return c;
}

/********************************/
/* HIVE Comparison instructions */
/********************************/

// 14) 32-bit Set Less Than
inline __hi32s *_hi64_slt(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
    return c;
}

// 15) 32-bit Set Less Than Unsigned
inline __hi32u *_hi64_sltu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
    return c;
}

// 16) 32-bit Compare if equal
inline __hi32s *_hi64_ceq(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
    return c;
}

// 17) 32-bit Compare if equal Unsigned
inline __hi32u *_hi64_cequ(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
    return c;
}

/***************************/
/* HIVE Shift instructions */
/***************************/

// 18) 32-bit Shift Left Logical
inline __hi32u *_hi64_sll(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] << b[i];
    }
    return c;
}

// 19) 32-bit Shift Right Logical
inline __hi32u *_hi64_srl(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] >> b[i];
    }
    return c;
}

// 20) 32-bit Shift Right Arithmetic
inline __hi32s *_hi64_sra(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] >> b[i];
    }
    return c;
}

/*********************************************/
/* HIVE Multiplication/Division instructions */
/*********************************************/

// 21) Divide Only
inline __hi32s *_hi64_div(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] / b[i];
    }
    return c;
}

// 22) Divide Only Unsigned
inline __hi32u *_hi64_divu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] / b[i];
    }
    return c;
}

// 23) Module Only
inline __hi32s *_hi64_mod(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] % b[i];
    }
    return c;
}

// 24) Module Only Unsigned
inline __hi32u *_hi64_modu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] % b[i];
    }
    return c;
}

// 25) Multiply 32-bits
inline __hi32s *_hi64_mod(__hi32s *a, __hi32s *b) {
    __hi32s *c = malloc(sizeof(__hi32s) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}

// 26) Multiply 32-bits Unsigned
inline __hi32u *_hi64_modu(__hi32u *a, __hi32u *b) {
    __hi32u *c = malloc(sizeof(__hi32u) * HI64I);
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}

// 27) Multiply 64-bits
inline __hi64s *_hi32_mod(__hi64s *a, __hi64s *b) {
    __hi64s *c = malloc(sizeof(__hi64s) * HI32L);
    for (int i = 0; i < HI32L; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}

// 28) Multiply 64-bits Unsigned
inline __hi64u *_hi32_modu(__hi64u *a, __hi64u *b) {
    __hi64u *c = malloc(sizeof(__hi64u) * HI32L);
    for (int i = 0; i < HI32L; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}
