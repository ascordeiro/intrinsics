#include <stdio.h>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>

namespace mp = boost::multiprecision;

// HMC integer types
typedef uint16_t __h16l1; // 1 short unsigned int
typedef uint64_t __h64l1; // __attribute__((vector_size(8))); // 1 long unsigned integer
typedef uint64_t __h64l2 __attribute__((vector_size(16))); // 2 long unsigned integer
typedef mp::uint128_t __h128ll1; // __attribute__((vector_size(16))); // 1 long long unsigned integer

/**************************/
/* HMC Arithmetic Atomics */
/**************************/

// Dual 8-byte Signed Add Immediate
__h64l2 _hmc64_saddimm_d(__h64l2 mem_op, __h64l2 imm_op){
    __h64l2 ret;
    ret = mem_op + imm_op;
    return ret;
}

// Single 16-byte Signed Add Immediate
__h128ll1 _hmc128_saddimm_s(__h128ll1 mem_op, __h128ll1 imm_op){
    return mem_op + imm_op;
}

// 8-byte Increment
__h64l1 _hmc64_incr_s(__h64l1 mem_op){
    return mem_op + 1;
}

/***********************/
/* HMC Bitwise Atomics */
/***********************/

// 8-byte Bit Write
__h64l1 _hmc64_bwrite_s(__h64l1 mem_op, __h64l1 bit_mask, __h64l1 write_data){
    return mem_op & (bit_mask & write_data);
}

// 16-byte Swap
__h128ll1 _hmc128_bswap_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = imm_op;
    return ret;
}

/***********************/
/* HMC Boolean Atomics */
/***********************/

// 16-byte AND
__h128ll1 _hmc128_and_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = *mem_op & imm_op;
    return ret;
}

// 16-byte NAND
__h128ll1 _hmc128_nand_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = ~(*mem_op & imm_op);
    return ret;
}

// 16-byte NOR
__h128ll1 _hmc128_nor_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = ~(*mem_op | imm_op);
    return ret;
}

// 16-byte OR
__h128ll1 _hmc128_or_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = *mem_op | imm_op;
    return ret;
}

// 16-byte XOR
__h128ll1 _hmc128_xor_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    *mem_op = ~(*mem_op & imm_op) & ~(~*mem_op & ~imm_op);
    return ret;
}

/**************************/
/* HMC Comparison Atomics */
/**************************/

//8-Byte Compare and Swap if Greater Than
__h64l1 _hmc64_cmpswapgt_s(__h64l1 *mem_op, __h64l1 imm_op){
    __h64l1 ret = *mem_op;
    if (*mem_op < imm_op)
        *mem_op = imm_op;
    return ret;
}

//8-Byte Compare and Swap if Less Than
__h64l1 _hmc64_cmpswaplt_s(__h64l1 *mem_op, __h64l1 imm_op){
    __h64l1 ret = *mem_op;
    if (*mem_op > imm_op)
        *mem_op = imm_op;
    return ret;
}

//8-Byte Compare and Swap if Greater Than
__h128ll1 _hmc128_cmpswapgt_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    if (*mem_op < imm_op)
        *mem_op = imm_op;
    return ret;
}

//8-Byte Compare and Swap if Less Than
__h128ll1 _hmc128_cmpswaplt_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    if (*mem_op > imm_op)
        *mem_op = imm_op;
    return ret;
}

//8-Byte Compare and Swap if Equal
__h64l1 _hmc64_cmpswapeq_s(__h64l1 *mem_op, __h64l1 imm_op, __h64l1 cmp_field){
    __h64l1 ret = *mem_op;
    if (*mem_op == cmp_field)
        *mem_op = imm_op;
    return ret;
}

//16-Byte Compare and Swap if Zero
__h128ll1 _hmc128_cmpswapz_s(__h128ll1 *mem_op, __h128ll1 imm_op){
    __h128ll1 ret = *mem_op;
    if (*mem_op == 0)
        *mem_op = imm_op;
    return ret;
}

//8-byte Equal tos
__h16l1 _hmc64_equalto_s(__h64l1 mem_op, __h64l1 imm_op){
    if (mem_op == imm_op)
        return 1;
    return 0;
}

//16-byte Equal to
__h16l1 _hmc128_equalto_s(__h128ll1 mem_op, __h128ll1 imm_op){
    if (mem_op == imm_op)
        return 1;
    return 0;
}
