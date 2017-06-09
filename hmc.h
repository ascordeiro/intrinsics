#include <stdio.h>
#include <stdlib.h>

// HMC integer types
typedef int __h16i __attribute__((vector_size(16))); // 4 integer
typedef int __h32i __attribute__((vector_size(32))); // 8 integer
// typedef int __h48i __attribute__((vector_size(48))); // 12 integer
typedef int __h64i __attribute__((vector_size(64))); // 16 integer
// typedef int __h80i __attribute__((vector_size(80))); // 20 integer
// typedef int __h96i __attribute__((vector_size(96))); // 24 integer
// typedef int __h112i __attribute__((vector_size(112))); // 28 integer
typedef int __h128i __attribute__((vector_size(128))); // 32 integer
typedef int __h256i __attribute__((vector_size(256))); // 36 integer

// HMC long int types
typedef long int __h16l __attribute__((vector_size(16))); // 2 long int
typedef long int __h32l __attribute__((vector_size(32))); // 4 long int
// typedef long int __h48l __attribute__((vector_size(48))); // 6 long int
typedef long int __h64l __attribute__((vector_size(64))); // 8 long int
// typedef long int __h80l __attribute__((vector_size(80))); // 10 long int
// typedef long int __h96l __attribute__((vector_size(96))); // 12 long int
// typedef long int __h112l __attribute__((vector_size(112))); // 14 long int
typedef long int __h128l __attribute__((vector_size(128))); // 16 long int
typedef long int __h256l __attribute__((vector_size(256))); // 18 long int

// HMC write functions
void _hmc16_write_pi(int *mem_addr, __h16i data){
    mem_addr[0] = data[0];
    mem_addr[1] = data[1];
    mem_addr[2] = data[2];
    mem_addr[3] = data[3];
}

void _hmc16_write_pl(long int *mem_addr, __h16l data){
    mem_addr[0] = data[0];
    mem_addr[1] = data[1];
}

void _hmc32_write_pi(int *mem_addr, __h32i data);
void _hmc32_write_pl(long int *mem_addr, __h32l data);

// void _hmc48_write_pi(int *mem_addr, __h48i data);
// void _hmc48_write_pl(long int *mem_addr, __h48l data);

void _hmc64_write_pi(int *mem_addr, __h64i data);
void _hmc64_write_pl(long int *mem_addr, __h64l data);

// void _hmc80_write_pi(int *mem_addr, __h80i data);
// void _hmc80_write_pl(long int *mem_addr, __h80l data);

// void _hmc96_write_pi(int *mem_addr, __h96i data);
// void _hmc96_write_pl(long int *mem_addr, __h96l data);

// void _hmc112_write_pi(int *mem_addr, __h112i data);
// void _hmc112_write_pl(long int *mem_addr, __h112l data);

void _hmc128_write_pi(int *mem_addr, __h128i data);
void _hmc128_write_pl(long int *mem_addr, __h128l data);

void _hmc256_write_pi(int *mem_addr, __h256i data);
void _hmc256_write_pl(long int *mem_addr, __h256l data);

// HMC read functions
__h16i _hmc16_read_pi(int *mem_addr){
    __h16i read;
    read[0] = mem_addr[0];
    read[1] = mem_addr[1];
    read[2] = mem_addr[2];
    read[3] = mem_addr[3];
    return read;
}

__h16l _hmc16_read_pl(long int *mem_addr){
    __h16l read;
    read[0] = mem_addr[0];
    read[1] = mem_addr[1];
    return read;
}

__h32i _hmc32_read_pi(int *mem_addr);
__h32l _hmc32_read_pl(long int *mem_addr);

// __h48i _hmc48_read_pi(int *mem_addr);
// __h48l _hmc48_read_pl(long int *mem_addr);

__h64i _hmc64_read_pi(int *mem_addr);
__h64l _hmc64_read_pl(long int *mem_addr);

// __h80i _hmc80_read_pi(int *mem_addr);
// __h80l _hmc80_read_pl(long int *mem_addr);

// __h96i _hmc96_read_pi(int *mem_addr);
// __h96l _hmc96_read_pl(long int *mem_addr);

// __h112i _hmc112_read_pi(int *mem_addr);
// __h112l _hmc112_read_pl(long int *mem_addr);

__h128i _hmc128_read_pi(int *mem_addr);
__h128l _hmc128_read_pl(long int *mem_addr);

__h256i _hmc256_read_pi(int *mem_addr);
__h256l _hmc256_read_pl(long int *mem_addr);

// HMC Arithmetic Atomics

// HMC Boolean Atomics
__h16i _hmc16_and_pi(__h16i mem_oper, __h16i imm_oper){
    __h16i a = mem_oper;
    mem_oper[0] = mem_oper[0] & imm_oper[0];
    mem_oper[1] = mem_oper[1] & imm_oper[1];
    mem_oper[2] = mem_oper[2] & imm_oper[2];
    mem_oper[3] = mem_oper[3] & imm_oper[3];
    return a;
}

// HMC Comparison Atomics

// HMC Bitwise Atomics
