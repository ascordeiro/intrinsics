/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// 01) 32-bit Add (64 integers)
inline void *_hi64_add(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] + b[i];
        printf("%d = %d + %d\n", c[i], a[i], b[i]);
    }
}

// 02) 32-bit Add (2048 integers)
inline void *_hi2k_add(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] + b[i];
        printf("%d = %d + %d\n", c[i], a[i], b[i]);
    }
}

// 03) 32-bit Add Unsigned (64 integers)
inline void *_hi64_addu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] + b[i];
        printf("%d = %d + %d\n", c[i], a[i], b[i]);
    }
}

// 04) 32-bit Add Unsigned (2048 integers)
inline void *_hi2k_addu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] + b[i];
        printf("%d = %d + %d\n", c[i], a[i], b[i]);
    }
}

// 05) 32-bit Subtract (64 integers)
inline void *_hi64_sub(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] - b[i];
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 06) 32-bit Subtract (2048 integers)
inline void *_hi2k_sub(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] - b[i];
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 07) 32-bit Subtract Unsigned (64 integers)
inline void *_hi64_subu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] - b[i];
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 08) 32-bit Subtract Unsigned (2048 integers)
inline void *_hi2k_subu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] - b[i];
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 09) 32-bit Abs (64 integers)
inline void *_hi64_abs(__hi32s *a, __hi32s *b) {
    int mask;
    int shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < HI64I; i++) {
        mask = a[i] >> shift;
        b[i] = ((a[i] + mask) ^ mask);
        printf("%d = %d\n", a[i], b[i]);
    }
}

// 10) 32-bit Abs (2048 integers)
inline void *_hi2k_abs(__hi32s *a, __hi32s *b) {
    int mask;
    int shift = (sizeof(int) * 8 - 1);
    for (int i = 0; i < HI2kI; i++) {
        mask = a[i] >> shift;
        b[i] = ((a[i] + mask) ^ mask);
        printf("%d = %d\n", a[i], b[i]);
    }
}

// 11) 32-bit Max (64 integers)
inline void *_hi64_max(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] > b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 12) 32-bit Max (2048 integers)
inline void *_hi2k_max(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] > b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
        printf("%d = %d - %d\n", c[i], a[i], b[i]);
    }
}

// 13) 32-bit Min (64 integers)
inline void *_hi64_min(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
    }
}

// 14) 32-bit Min (2048 integers)
inline void *_hi2k_min(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] < b[i]) {
            c[i] = a[i];
        } else {
            c[i] = b[i];
        }
    }
}

/***************************/
/* HIVE Logic instructions */
/***************************/

// 15) 32-bit And (64 integers)
inline void *_hi64_and(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] & b[i];
    }
}


// 16) 32-bit And (2048 integers)
inline void *_hi2k_and(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] & b[i];
    }
}

// 17) 32-bit Or (64 integers)
inline void *_hi64_or(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] | b[i];
    }
}

// 18) 32-bit Or (2048 integers)
inline void *_hi2k_or(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] | b[i];
    }
}

// 19) 32-bit Xor (64 integers)
inline void *_hi64_xor(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);
    }
}

// 20) 32-bit Xor (2048 integers)
inline void *_hi2k_xor(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = ~(a[i] & b[i]) & ~(~a[i] & ~b[i]);
    }
}

// 21) 32-bit Not (64 integers)
inline void *_hi64_not(__hi32s *a, __hi32s *b) {
    for (int i = 0; i < HI64I; i++) {
        b[i] = ~a[i];
    }
}

// 22) 32-bit Not (2048 integers)
inline void *_hi2k_not(__hi32s *a, __hi32s *b) {
    for (int i = 0; i < HI2kI; i++) {
        b[i] = ~a[i];
    }
}

// 23) 32-bit Mask (64 integers)
inline void *_hi64_mask(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
}

// 24) 32-bit Mask (2048 integers)
inline void *_hi2k_mask(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
}

// 25) 32-bit Masku (64 integers)
inline void *_hi64_masku(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
}

// 26) 32-bit Masku (2048 integers)
inline void *_hi2k_masku(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (b[i] == 0) {
            c[i] = a[i];
        }
    }
}

/********************************/
/* HIVE Comparison instructions */
/********************************/

// 27) 32-bit Set Less Than (64 integers)
inline void *_hi64_slt(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 28) 32-bit Set Less Than (2048 integers)
inline void *_hi2k_slt(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 29) 32-bit Set Less Than Unsigned (64 integers)
inline void *_hi64_sltu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 30) 32-bit Set Less Than Unsigned (2048 integers)
inline void *_hi2k_sltu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] < b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 31) 32-bit Compare if equal (64 integers)
inline void *_hi64_ceq(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 32) 32-bit Compare if equal (2048 integers)
inline void *_hi2k_ceq(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 33) 32-bit Compare if equal Unsigned (64 integers)
inline void *_hi64_cequ(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

// 34) 32-bit Compare if equal Unsigned (2048 integers)
inline void *_hi2k_cequ(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        if (a[i] == b[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }
}

/***************************/
/* HIVE Shift instructions */
/***************************/

// 35) 32-bit Shift Left Logical (64 integers)
inline void *_hi64_sll(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] << b[i];
    }
}

// 36) 32-bit Shift Left Logical (2048 integers)
inline void *_hi2k_sll(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] << b[i];
    }
}

// 37) 32-bit Shift Right Logical (64 integers)
inline void *_hi64_srl(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] >> b[i];
    }
}

// 38) 32-bit Shift Right Logical (2048 integers)
inline void *_hi2k_srl(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] >> b[i];
    }
}

// 39) 32-bit Shift Right Arithmetic (64 integers)
inline void *_hi64_sra(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] >> b[i];
    }
}

// 40) 32-bit Shift Right Arithmetic (2048 integers)
inline void *_hi2k_sra(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] >> b[i];
    }
}

/*********************************************/
/* HIVE Multiplication/Division instructions */
/*********************************************/

// 41) Divide Only
inline void *_hi64_div(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] / b[i];
    }
}

// 42) Divide Only
inline void *_hi2k_div(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] / b[i];
    }
}

// 43) Divide Only Unsigned
inline void *_hi64_divu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] / b[i];
    }
}

// 44) Divide Only Unsigned
inline void *_hi2k_divu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] / b[i];
    }
}

// 45) Module Only
inline void *_hi64_mod(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] % b[i];
    }
}

// 46) Module Only
inline void *_hi2k_mod(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] % b[i];
    }
}

// 47) Module Only Unsigned
inline void *_hi64_modu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] % b[i];
    }
}

// 48) Module Only Unsigned
inline void *_hi2k_modu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] % b[i];
    }
}

// 49) Multiply 32-bits
inline void *_hi64_mult(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] * b[i];
    }
}

// 50) Multiply 32-bits
inline void *_hi2k_mult(__hi32s *a, __hi32s *b, __hi32s *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] * b[i];
    }
}

// 51) Multiply 32-bits Unsigned
inline void *_hi64_multu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI64I; i++) {
        c[i] = a[i] * b[i];
    }
}

// 52) Multiply 32-bits Unsigned
inline void *_hi2k_multu(__hi32u *a, __hi32u *b, __hi32u *c) {
    for (int i = 0; i < HI2kI; i++) {
        c[i] = a[i] * b[i];
    }
}

// 53) Multiply 64-bits
inline void *_hi32_mult(__hi64s *a, __hi64s *b, __hi64s *c) {
    for (int i = 0; i < HI32L; i++) {
        c[i] = a[i] * b[i];
    }
}

// 54) Multiply 64-bits
inline void *_hi1k_mult(__hi64s *a, __hi64s *b, __hi64s *c) {
    for (int i = 0; i < HI1kL; i++) {
        c[i] = a[i] * b[i];
    }
}

// 55) Multiply 64-bits Unsigned
inline void *_hi32_multu(__hi64u *a, __hi64u *b, __hi64u *c) {
    for (int i = 0; i < HI32L; i++) {
        c[i] = a[i] * b[i];
    }
}

// 56) Multiply 64-bits Unsigned
inline void *_hi1k_multu(__hi64u *a, __hi64u *b, __hi64u *c) {
    for (int i = 0; i < HI1kL; i++) {
        c[i] = a[i] * b[i];
    }
}
