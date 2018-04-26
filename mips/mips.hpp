/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stdint.h>

/* MIPS types */
typedef int32_t  __m32s1; // 1 signed integer operand
typedef uint32_t __m32u1; // 1 unsigned integer operand
// typedef int32_t  __m32s2 __attribute__((vector_size(8))); // 2 signed integer operands
// typedef uint32_t __m32u2 __attribute__((vector_size(8))); //2 unsigned integer operands
typedef uint64_t __m64u1; // 1 long unsigned integer operand
typedef int64_t  __m64s1; // 1 long integer operand

/********************************/
/* MIPS Arithmetic instructions */
/********************************/

// 01) Add
inline __m32s1 _mips_add(__m32s1 rs, __m32s1 rt){
    return rs + rt;
}

// 02) Add Unsigned
inline __m32u1 _mips_addu(__m32u1 rs, __m32u1 rt){
    return rs + rt;
}

// 03) Subtract
inline __m32s1 _mips_sub(__m32s1 rs, __m32s1 rt){
    return rs - rt;
}

// 04) Subtract Unsigned
inline __m32u1 _mips_subu(__m32u1 rs, __m32u1 rt){
    return rs - rt;
}

/******************************************/
/* MIPS Immediate Arithmetic instructions */
/******************************************/

// 05) Add Immediate
inline __m32s1 _mips_addi(__m32s1 rs, __m32s1 imm_op){
    return rs + imm_op;
}

// 06) Add Immediate Unsigned
inline __m32u1 _mips_addiu(__m32u1 rs, __m32u1 imm_op){
    return rs + imm_op;
}

/***************************/
/* MIPS Logic instructions */
/***************************/

// 07) And
inline __m32u1 _mips_and(__m32u1 rs, __m32u1 rt){
    return rs & rt;
}

// 08) Nor
inline __m32u1 _mips_nor(__m32u1 rs, __m32u1 rt){
    return ~(rs | rt);
}

// 09) Or
inline __m32u1 _mips_or(__m32u1 rs, __m32u1 rt){
    return rs | rt;
}

// 10) Xor
inline __m32u1 _mips_xor(__m32u1 rs, __m32u1 rt){
    return ~(rs & rt) & ~(~rs & ~rt);
}

/*************************************/
/* MIPS Immediate Logic instructions */
/*************************************/

// 11) And Immediate
inline __m32u1 _mips_andi(__m32u1 rs, __m32u1 imm_op){
    return rs & imm_op;
}

// 12) Or Immediate
inline __m32u1 _mips_ori(__m32u1 rs, __m32u1 imm_op){
    return rs | imm_op;
}

// 13) Xor Immediate
inline __m32u1 _mips_xori(__m32u1 rs, __m32u1 imm_op){
    return ~(rs & imm_op) & ~(~rs & ~imm_op);
}

/********************************/
/* MIPS Comparison instructions */
/********************************/

// 14) Set Less Than
inline __m32s1 _mips_slt(__m32s1 rs, __m32s1 rt){
    return (rs < rt) ? 1 : 0;
}

// 15) Set Less Than Unsigned
inline __m32u1 _mips_sltu(__m32u1 rs, __m32u1 rt){
    return (rs < rt) ? 1 : 0;
}

/******************************************/
/* MIPS Immediate Comparison instructions */
/******************************************/

// 16) Set Less Than Immediate
inline __m32s1 _mips_slti(__m32s1 rs, __m32s1 imm_op){
    return (rs < imm_op) ? 1 : 0;
}

// 17) Set Less Than Immediate Unsigned
inline __m32u1 _mips_sltiu(__m32u1 rs, __m32u1 imm_op){
    return (rs < imm_op) ? 1 : 0;
}

/***************************/
/* MIPS Shift instructions */
/***************************/

// 18) Shift Left Logical
inline __m32u1 _mips_sll(__m32u1 rt, __m32u1 shamt){
    return rt << shamt;
}

// 19) Shift Right Logical
inline __m32u1 _mips_srl(__m32u1 rt, __m32u1 shamt){
    return rt >> shamt;
}

// 20) Shift Right Arithmetic
inline __m32s1 _mips_sra(__m32s1 rt, __m32s1 shamt){
    return rt >> shamt;
}

/*********************************************/
/* MIPS Multiplication/Division instructions */
/*********************************************/

// 21) Divide Only
inline __m32s1 _mips_div(__m32s1 rs, __m32s1 rt){
    return rs / rt;
}

// 22) Divide Only Unsigned
inline __m32u1 _mips_divu(__m32u1 rs, __m32u1 rt){
    return rs / rt;
}

// 23) Module Only
inline __m32s1 _mips_mod(__m32s1 rs, __m32s1 rt){
    return rs % rt;
}

// 24) Module Only Unsigned
inline __m32u1 _mips_modu(__m32u1 rs, __m32u1 rt){
    return rs % rt;
}

// 25) Multiply 32-bits
inline __m32s1 _mips_mult32(__m32s1 rs, __m32s1 rt){
    return rs * rt;
}

// 26) Multiply 32-bits Unsigned
inline __m32u1 _mips_multu32(__m32u1 rs, __m32u1 rt){
    return rs * rt;
}

// 27) Multiply 64-bits
inline __m64s1 _mips_mult64(__m32s1 rs, __m32s1 rt){
    return (__m64s1)rs * (__m64s1)rt;
}

// 28) Multiply 64-bits Unsigned
inline __m64u1 _mips_multu64(__m32u1 rs, __m32u1 rt){
    return (__m64u1)rs * (__m64u1)rt;
}
