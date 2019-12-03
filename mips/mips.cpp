/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include "mips.hpp"

/* MIPS types */

__m32s1 ret32s1, op1_32s1 = 13, op2_32s1 = 3;
__m32u1 ret32u1, op1_32u1 = 13, op2_32u1 = 3;
// __m32s2 ret32s2;
// __m32u2 ret32u2;
__m64s1 ret64s1;
__m64u1 ret64u1;

int main() {

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 01 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_add(op1_32s1, op2_32s1);
    printf("   _mps32_add: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 02 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_addu(op1_32u1, op2_32u1);
    printf("   _mps32_addu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 03 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_sub(op1_32s1, op2_32s1);
    printf("   _mps32_sub: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 04 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_subu(op1_32u1, op2_32u1);
    printf("   _mps32_subu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 05 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_addi(op1_32s1, op2_32s1);
    printf("   _mps32_addi: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 06 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_addiu(op1_32u1, op2_32u1);
    printf("   _mps32_addiu: res = %d\n\n", ret32u1);


/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 07 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_and(op1_32u1, op2_32u1);
    printf("   _mps32_and: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 08 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_nor(op1_32u1, op2_32u1);
    printf("   _mps32_nor: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 09 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_or(op1_32u1, op2_32u1);
    printf("   _mps32_or: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 10 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_xor(op1_32u1, op2_32u1);
    printf("   _mps32_xor: res = %d\n\n", ret32u1);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 11 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_andi(op1_32u1, op2_32u1);
    printf("   _mps32_andi: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 12 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_ori(op1_32u1, op2_32u1);
    printf("   _mps32_ori: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 13 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_xori(op1_32u1, op2_32u1);
    printf("   _mps32_xori: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 14 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_slt(op1_32s1, op2_32s1);
    printf("   _mps32_slt: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 15 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_sltu(op1_32u1, op2_32u1);
    printf("   _mps32_sltu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 16 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_slti(op1_32s1, op2_32s1);
    printf("   _mps32_slti: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 17 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_sltiu(op1_32u1, op2_32u1);
    printf("   _mps32_sltiu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 18 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_sll(op1_32u1, op2_32u1);
    printf("   _mps32_sll: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 19 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_srl(op1_32u1, op2_32u1);
    printf("   _mps32_srl: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 20 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_sra(op1_32s1, op2_32s1);
    printf("   _mps32_sra: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 21 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_div(op1_32s1, op2_32s1);
    printf("   _mps32_div: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 22 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_divu(op1_32u1, op2_32u1);
    printf("   _mps32_divu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 23 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_mod(op1_32s1, op2_32s1);
    printf("   _mps32_mod: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 24 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_modu(op1_32u1, op2_32u1);
    printf("   _mps32_modu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 25 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mps32_mult(op1_32s1, op2_32s1);
    printf("   _mps32_mult: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 26 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mps32_multu(op1_32u1, op2_32u1);
    printf("   _mps32_multu: res = %d\n\n", ret32u1);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 27 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret64s1 = _mps64_mult(op1_32s1, op2_32s1);
    printf("   _mps64_mult: res = %ld\n\n", ret64s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 28 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret64u1 = _mps64_multu(op1_32u1, op2_32u1);
    printf("   _mps64_multu: res = %lu\n\n", ret64u1);

    return 0;
}
