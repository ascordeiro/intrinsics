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
    ret32s1 = _mips_add(op1_32s1, op2_32s1);
    printf("   _mips_add: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 02 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_addu(op1_32u1, op2_32u1);
    printf("   _mips_addu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 03 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_sub(op1_32s1, op2_32s1);
    printf("   _mips_sub: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 04 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_subu(op1_32u1, op2_32u1);
    printf("   _mips_subu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 05 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_addi(op1_32s1, op2_32s1);
    printf("   _mips_addi: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 06 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_addiu(op1_32u1, op2_32u1);
    printf("   _mips_addiu: res = %d\n\n", ret32u1);


/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 07 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_and(op1_32u1, op2_32u1);
    printf("   _mips_and: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 08 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_nor(op1_32u1, op2_32u1);
    printf("   _mips_nor: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 09 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_or(op1_32u1, op2_32u1);
    printf("   _mips_or: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 10 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_xor(op1_32u1, op2_32u1);
    printf("   _mips_xor: res = %d\n\n", ret32u1);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 11 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_andi(op1_32u1, op2_32u1);
    printf("   _mips_andi: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 12 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_ori(op1_32u1, op2_32u1);
    printf("   _mips_ori: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 13 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_xori(op1_32u1, op2_32u1);
    printf("   _mips_xori: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 14 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_slt(op1_32s1, op2_32s1);
    printf("   _mips_slt: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 15 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_sltu(op1_32u1, op2_32u1);
    printf("   _mips_sltu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 16 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_slti(op1_32s1, op2_32s1);
    printf("   _mips_slti: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 17 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_sltiu(op1_32u1, op2_32u1);
    printf("   _mips_sltiu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 18 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_sll(op1_32u1, op2_32u1);
    printf("   _mips_sll: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 19 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_srl(op1_32u1, op2_32u1);
    printf("   _mips_srl: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 20 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_sra(op1_32s1, op2_32s1);
    printf("   _mips_sra: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 21 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_div(op1_32s1, op2_32s1);
    printf("   _mips_div: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 22 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_divu(op1_32u1, op2_32u1);
    printf("   _mips_divu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 23 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_mod(op1_32s1, op2_32s1);
    printf("   _mips_mod: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 24 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_modu(op1_32u1, op2_32u1);
    printf("   _mips_modu: res = %d\n\n", ret32u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 25 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret32s1 = _mips_mult32(op1_32s1, op2_32s1);
    printf("   _mips_mult32: res = %d\n\n", ret32s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 26 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret32u1 = _mips_multu32(op1_32u1, op2_32u1);
    printf("   _mips_multu32: res = %d\n\n", ret32u1);

/*****************************************************************************/
    printf("%s\n", "***************");
    printf("%s\n", "* Operação 27 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32s1, op2_32s1);
    ret64s1 = _mips_mult64(op1_32s1, op2_32s1);
    printf("   _mips_mult64: res = %ld\n\n", ret64s1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 28 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %d | op2 = %d\n", op1_32u1, op2_32u1);
    ret64u1 = _mips_multu64(op1_32u1, op2_32u1);
    printf("   _mips_multu64: res = %lu\n\n", ret64u1);

    return 0;
}
