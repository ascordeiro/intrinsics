#include <stdio.h>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

namespace mp = boost::multiprecision;

// HMC integer types
typedef uint64_t __h64l1; // __attribute__((vector_size(8))); // 1 long integer
typedef uint64_t __h64l2 __attribute__((vector_size(16))); // 2 long integer
typedef mp::uint128_t __h128ll1; // __attribute__((vector_size(16))); // 1 long long integer

/**************************/
/* HMC Arithmetic Atomics */
/*************************/

// Dual 8-byte Signed Add Immediate
void _hmc64_saddimm_d(__h64l2 *mem_op, __h64l2 *imm_op){
    *mem_op = *mem_op + *imm_op;
}

// Single 16-byte Signed Add Immediate
void _hmc128_saddimm_s(__h128ll1 *mem_op, __h128ll1 *imm_op){
    *mem_op = *mem_op + *imm_op;
}

// 8-byte Increment
void _hmc64_incr_s(__h64l1 *mem_op){
    *mem_op = *mem_op + 1;
}

// // Dual 8-byte Signed Add Immediate and Return
// int _hmc64_saddimmret_d(__h64l2 mem_op, long int *imm_op){
//     char sign1 =  mem_op[0] > 0 && imm_op[0] > 0 ? 1 : mem_op[0] < 0 && imm_op[0] < 0 ? -1 : 0;
//     char sign2 =  mem_op[1] > 0 && imm_op[1] > 0 ? 1 : mem_op[1] < 0 && imm_op[1] < 0 ? -1 : 0;
//     mem_op[0] = mem_op[0] + imm_op[0];
//     mem_op[1] = mem_op[1] + imm_op[1];
//     if ((sign1 && sign1 == 1 && mem_op[0] < 0 || sign1 == -1 && mem_op[0] > 0) ||
//         (sign2 && sign2 == 1 && mem_op[1] < 0 || sign2 == -1 && mem_op[1] > 0)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// // Single 16-byte Signed Add Immediate and Return
// int _hmc128_saddimmret_s(__h128ll1 mem_op, long long int imm_op){
//     char sign =  mem_op > 0 && imm_op > 0 ? 1 : mem_op < 0 && imm_op < 0 ? -1 : 0;
//     mem_op = mem_op ^ imm_op;
//     if ((sign && sign == 1 && mem_op < 0 || sign == -1 && mem_op > 0)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// 8-byte Increment
// void _hmc64_incr_s(uint64_t *mem_op){
    // char sign =  mem_op > 0 ? 1 : 0;
    // *mem_op = *mem_op + 1;
    // if (sign && sign == 1 && mem_op < 0){
    //     return 1;
    // }
    // else{
    //     return 0;
    // }
// }

/***********************/
/* HMC Bitwise Atomics */
/***********************/

// 8-byte Bit Write
void _hmc64_bwrite_s(__h64l1 *mem_op, __h64l2 *imm_op){
    // __h64l1 bit_mask, write_data;
    // bit_mask = (uint64_t)imm_op[0];
    // write_data = imm_op[1];
    *mem_op = *mem_op & const_cast<uint64_t>(imm_op[0] & imm_op[1]);
}

// // 8-byte Bit Write with Return
// int _hmc64_bwriteret_s(__h64l1 mem_op, __h64l2 imm_op){
//     __h64l1 mem_op_cmp = mem_op;
//     imm_op[0] = imm_op[0] & imm_op[1];
//     mem_op = mem_op & imm_op[0];
//     if (mem_op_cmp != mem_op){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
//
// // 16-byte Swap
// __h128ll1 _hmc128_bswap_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     __h128ll1 a = mem_op;
//     mem_op = imm_op;
//     return a;
// }
//
// /* HMC Boolean Atomics */
// // 16-byte AND
// ret_value _hmc16_and_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     ret.mem = mem_op;
//     mem_op = mem_op & imm_op;
//     if (mem_op != ret.mem){
//         ret.at = 1;
//     }
//     else{
//         ret.at = 0;
//     }
//     return ret;
// }
//
// // 16-byte NAND
// ret_value _hmc16_nand_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     ret.mem = mem_op;
//     mem_op = ~(mem_op & imm_op);
//     if (mem_op != ret.mem){
//         ret.at = 1;
//     }
//     else{
//         ret.at = 0;
//     }
//     return ret;
// }
//
// // 16-byte NOR
// ret_value _hmc16_nor_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     ret.mem = mem_op;
//     mem_op = ~(mem_op | imm_op);
//     if (mem_op != ret.mem){
//         ret.at = 1;
//     }
//     else{
//         ret.at = 0;
//     }
//     return ret;
// }
//
// // 16-byte OR
// ret_value _hmc16_or_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     ret.mem = mem_op;
//     mem_op = mem_op | imm_op;
//     if (mem_op != ret.mem){
//         ret.at = 1;
//     }
//     else{
//         ret.at = 0;
//     }
//     return ret;
// }
//
// // 16-byte XOR
// ret_value _hmc16_xor_s(__h128ll1 mem_op, __h128ll1 imm_op){
//     ret.mem = mem_op;
//     mem_op = mem_op | imm_op;
//     if (mem_op != ret.mem){
//         ret.at = 1;
//     }
//     else{
//         ret.at = 0;
//     }
//     return ret;
// }




// HMC Comparison Atomics




// typedef int __h16i __attribute__((vector_size(16))); // 4 integer
// typedef int __h32i __attribute__((vector_size(32))); // 8 integer
// // typedef int __h48i __attribute__((vector_size(48))); // 12 integer
// typedef int __h64i __attribute__((vector_size(64))); // 16 integer
// // typedef int __h80i __attribute__((vector_size(80))); // 20 integer
// // typedef int __h96i __attribute__((vector_size(96))); // 24 integer
// // typedef int __h112i __attribute__((vector_size(112))); // 28 integer
// typedef int __h128i __attribute__((vector_size(128))); // 32 integer
// typedef int __h256i __attribute__((vector_size(256))); // 36 integer
//
// // HMC long int types
// typedef long int __h16l __attribute__((vector_size(16))); // 2 long int
// typedef long int __h32l __attribute__((vector_size(32))); // 4 long int
// // typedef long int __h48l __attribute__((vector_size(48))); // 6 long int
// typedef long int __h64l __attribute__((vector_size(64))); // 8 long int
// // typedef long int __h80l __attribute__((vector_size(80))); // 10 long int
// // typedef long int __h96l __attribute__((vector_size(96))); // 12 long int
// // typedef long int __h112l __attribute__((vector_size(112))); // 14 long int
// typedef long int __h128l __attribute__((vector_size(128))); // 16 long int
// typedef long int __h256l __attribute__((vector_size(256))); // 18 long int
//
// // HMC write functions
// void _hmc16_write_pi(int *mem_addr, __h16i data){
//     mem_addr[0] = data[0];
//     mem_addr[1] = data[1];
//     mem_addr[2] = data[2];
//     mem_addr[3] = data[3];
// }
//
// void _hmc16_write_pl(long int *mem_addr, __h16l data){
//     mem_addr[0] = data[0];
//     mem_addr[1] = data[1];
// }
//
// void _hmc32_write_pi(int *mem_addr, __h32i data);
// void _hmc32_write_pl(long int *mem_addr, __h32l data);
//
// // void _hmc48_write_pi(int *mem_addr, __h48i data);
// // void _hmc48_write_pl(long int *mem_addr, __h48l data);
//
// void _hmc64_write_pi(int *mem_addr, __h64i data);
// void _hmc64_write_pl(long int *mem_addr, __h64l data);
//
// // void _hmc80_write_pi(int *mem_addr, __h80i data);
// // void _hmc80_write_pl(long int *mem_addr, __h80l data);
//
// // void _hmc96_write_pi(int *mem_addr, __h96i data);
// // void _hmc96_write_pl(long int *mem_addr, __h96l data);
//
// // void _hmc112_write_pi(int *mem_addr, __h112i data);
// // void _hmc112_write_pl(long int *mem_addr, __h112l data);
//
// void _hmc128_write_pi(int *mem_addr, __h128i data);
// void _hmc128_write_pl(long int *mem_addr, __h128l data);
//
// void _hmc256_write_pi(int *mem_addr, __h256i data);
// void _hmc256_write_pl(long int *mem_addr, __h256l data);
//
// // HMC read functions
// __h16i _hmc16_read_pi(int *mem_addr){
//     __h16i read;
//     read[0] = mem_addr[0];
//     read[1] = mem_addr[1];
//     read[2] = mem_addr[2];
//     read[3] = mem_addr[3];
//     return read;
// }
//
// __h16l _hmc16_read_pl(long int *mem_addr){
//     __h16l read;
//     read[0] = mem_addr[0];
//     read[1] = mem_addr[1];
//     return read;
// }
//
// __h32i _hmc32_read_pi(int *mem_addr);
// __h32l _hmc32_read_pl(long int *mem_addr);
//
// // imm_oper__h48i _hmc48_read_pi(int *mem_addr);
// // __h48l _hmc48_read_pl(long int *mem_addr);
//
// __h64i _hmc64_read_pi(int *mem_addr);
// __h64l _hmc64_read_pl(long int *mem_addr);
//
// // __h80i _hmc80_read_pi(int *mem_addr);
// // __h80l _hmc80_read_pl(long int *mem_addr);
//
// // __h96i _hmc96_read_pi(int *mem_addr);
// // __h96l _hmc96_read_pl(long int *mem_addr);
//
// // __h112i _hmc112_read_pi(int *mem_addr);
// // __h112l _hmc112_read_pl(long int *mem_addr);
//
// __h128i _hmc128_read_pi(int *mem_addr);
// __h128l _hmc128_read_pl(long int *mem_addr);
//
// __h256i _hmc256_read_pi(int *mem_addr);
// __h256l _hmc256_read_pl(long int *mem_addr);
//
