/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision; //necessary for 128-bit operands

/* HMC types */
typedef uint16_t __h16u1; // 1 short unsigned integer operand
typedef uint64_t __h64u1; // 1 long unsigned integer operand
typedef uint64_t __h64u2 __attribute__((vector_size(16))); // 2 long unsigned integer operands
typedef mp::uint128_t __h128u1; // 1 long long unsigned integer operand

/**************************/
/* HMC Arithmetic Atomics */
/**************************/

// 01) Dual 8-byte Signed Add Immediate
inline __h64u2 _hmc64_saddimm_d(__h64u2 mem_op, __h64u2 imm_op){
    __h64u2 ret;
    ret = mem_op + imm_op;
    return ret;
}

// 02) Single 16-byte Signed Add Immediate
inline __h128u1 _hmc128_saddimm_s(__h128u1 mem_op, __h128u1 imm_op){
    return mem_op + imm_op;
}

// 03) 8-byte Increment
inline __h64u1 _hmc64_incr_s(__h64u1 mem_op){
    return mem_op + 1;
}

/***********************/
/* HMC Bitwise Atomics */
/***********************/

// 04) 8-byte Bit Write
inline __h64u1 _hmc64_bwrite_s(__h64u1 mem_op, __h64u1 bit_mask, __h64u1 write_data){
    return mem_op & (bit_mask & write_data);
}

// 05) 16-byte Swap
inline __h128u1 _hmc128_bswap_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = imm_op;
    return ret;
}

/***********************/
/* HMC Boolean Atomics */
/***********************/

// 06) 16-byte AND
inline __h128u1 _hmc128_and_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = *mem_op & imm_op;
    return ret;
}

// 07) 16-byte NAND
inline __h128u1 _hmc128_nand_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = ~(*mem_op & imm_op);
    return ret;
}

// 08) 16-byte NOR
inline __h128u1 _hmc128_nor_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = ~(*mem_op | imm_op);
    return ret;
}

// 09) 16-byte OR
inline __h128u1 _hmc128_or_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = *mem_op | imm_op;
    return ret;
}

// 10) 16-byte XOR
inline __h128u1 _hmc128_xor_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    *mem_op = ~(*mem_op & imm_op) & ~(~*mem_op & ~imm_op);
    return ret;
}

/**************************/
/* HMC Comparison Atomics */
/**************************/

// 11) 8-Byte Compare and Swap if Greater Than
inline __h64u1 _hmc64_cmpswapgt_s(__h64u1 *mem_op, __h64u1 imm_op){
    __h64u1 ret = *mem_op;
    if (*mem_op < imm_op)
        *mem_op = imm_op;
    return ret;
}

// 12) 8-Byte Compare and Swap if Less Than
inline __h64u1 _hmc64_cmpswaplt_s(__h64u1 *mem_op, __h64u1 imm_op){
    __h64u1 ret = *mem_op;
    if (*mem_op > imm_op)
        *mem_op = imm_op;
    return ret;
}

// 13) 8-Byte Compare and Swap if Greater Than
inline __h128u1 _hmc128_cmpswapgt_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    if (*mem_op < imm_op)
        *mem_op = imm_op;
    return ret;
}

// 14) 8-Byte Compare and Swap if Less Than
inline __h128u1 _hmc128_cmpswaplt_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    if (*mem_op > imm_op)
        *mem_op = imm_op;
    return ret;
}

// 15) 8-Byte Compare and Swap if Equal
inline __h64u1 _hmc64_cmpswapeq_s(__h64u1 *mem_op, __h64u1 imm_op, __h64u1 cmp_field){
    __h64u1 ret = *mem_op;
    if (*mem_op == cmp_field)
        *mem_op = imm_op;
    return ret;
}

// 16) 16-Byte Compare and Swap if Zero
inline __h128u1 _hmc128_cmpswapz_s(__h128u1 *mem_op, __h128u1 imm_op){
    __h128u1 ret = *mem_op;
    if (*mem_op == 0)
        *mem_op = imm_op;
    return ret;
}

// 17) 8-byte Equal to
inline __h16u1 _hmc64_equalto_s(__h64u1 mem_op, __h64u1 imm_op){
    return (mem_op == imm_op) ? 1 : 0;
}

// 18) 16-byte Equal to
inline __h16u1 _hmc128_equalto_s(__h128u1 mem_op, __h128u1 imm_op){
    return (mem_op == imm_op) ? 1 : 0;
}

/*******************************/
/* Customized HMC instructions */
/*******************************/

// 19) 8-Byte Compare if Greater Than or equal
inline __h16u1 _hmc64_cmpgteq_s(__h64u1 *mem_op, __h64u1 imm_op){
    return (*mem_op <= imm_op) ? 0 : 1;
}

// 20) 8-Byte Compare if Less Than or equal
inline __h16u1 _hmc64_cmplteq_s(__h64u1 *mem_op, __h64u1 imm_op){
    return (*mem_op >= imm_op) ? 0 : 1;
}

// 21) 8-Byte Compare if Less Than
inline __h16u1 _hmc64_cmplt_s(__h64u1 *mem_op, __h64u1 imm_op){
    return (*mem_op > imm_op) ? 0 : 1;
}
