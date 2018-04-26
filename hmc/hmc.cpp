/**
 * Aline Santana Cordeiro - ascordeiro@inf.ufpr.br
 * LSE - Embedded Sistems Laboratory - 2018
 * PPGInf - Federal University of Paraná
 */

#include "hmc.hpp"

/* HMC types */
__h16u1  ret16u1;
__h64u1  ret64u1,  op1_64u1 = 11, op2_64u1 = 4, op3_64u1 = 5;
__h64u2  ret64u2,  op1_64u2 = {10, 15}, op2_64u2 = {4, 9};
__h128u1 ret128u1, op1_128u1 = 4294967296, op2_128u1 = 3989146375, op3_128u1 = 5, op4_128u1 = 4;

int main(){

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 01 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu e %lu | op2 = %lu e %lu\n", op1_64u2[0], op1_64u2[1], op2_64u2[0], op2_64u2[1]);
    ret64u2 = _hmc64_saddimm_d(op1_64u2, op2_64u2);
    printf("   _hmc64_saddimm_d: res[1] = %lu   res[2] = %lu\n\n", ret64u2[0], ret64u2[1]);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 02 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op1_128u1 << " | op2 = " << op2_128u1 << "\n";
    ret128u1 = _hmc128_saddimm_s(op1_128u1, op2_128u1);
    std::cout << "   _hmc128_saddimm_s: res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 03 *");
    printf("%s\n", "***************");

    printf("   Operando: op1 = %lu\n", op1_64u1);
    ret64u1 = _hmc64_incr_s(op1_64u1);
    printf("   _hmc64_incr_s: res = %lu\n\n", ret64u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 04 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu | op3 = %lu\n", op1_64u1, op2_64u1, op3_64u1);
    ret64u1 = _hmc64_bwrite_s(op1_64u1, op2_64u1, op3_64u1);
    printf("   _hmc64_bwrite_s: res = %lu\n\n", ret64u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 05 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op1_128u1 << " | op2 = " << op2_128u1 << "\n";
    ret128u1 = _hmc128_bswap_s(&op1_128u1, op2_128u1);
    std::cout << "   _hmc128_bswap_s: op1 = " << op1_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 06 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_and_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_and_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 07 *");
    printf("%s\n", "***************");
    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_nand_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_nand_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 08 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_nor_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_nor_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 09 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_or_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_or_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 10 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_xor_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_xor_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 11 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret64u1 = _hmc64_cmpswapgt_s(&op2_64u1, op3_64u1);
    printf("   _hmc64_cmpswapgt_s: op1 = %lu    res = %lu\n\n", op2_64u1, ret64u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 12 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret64u1 = _hmc64_cmpswaplt_s(&op2_64u1, op3_64u1);
    printf("   _hmc64_cmpswaplt_s: op1 = %lu    res = %lu\n\n", op2_64u1, ret64u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 13 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_cmpswapgt_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_cmpswapgt_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 14 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_cmpswaplt_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_cmpswaplt_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 15 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu | op3 = %lu\n", op2_64u1, op3_64u1, op1_64u1);
    ret64u1 = _hmc64_cmpswapeq_s(&op2_64u1, op3_64u1, op1_64u1);
    printf("   _hmc64_cmpswapeq_s: op1 = %lu    res = %lu\n\n", op2_64u1, ret64u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 16 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret128u1 = _hmc128_cmpswapz_s(&op3_128u1, op4_128u1);
    std::cout << "   _hmc128_cmpswapz_s: op1 = " << op3_128u1 << "   res = " << ret128u1 << "\n\n";

    /*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 17 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret16u1 = _hmc64_equalto_s(op2_64u1, op3_64u1);
    printf("   _hmc64_equalto_s: op1 = %lu    res = %u\n\n", op2_64u1, ret16u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 18 *");
    printf("%s\n", "***************");

    std::cout << "   Operandos: op1 = " << op3_128u1 << " | op2 = " << op4_128u1 << "\n";
    ret16u1 = _hmc128_equalto_s(op3_128u1, op4_128u1);
    std::cout << "   _hmc128_equalto_s: op1 = " << op3_128u1 << "   res = " << ret16u1 << "\n\n";

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 19 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret16u1 = _hmc64_cmpgteq_s(&op2_64u1, op3_64u1);
    printf("   _hmc64_cmpgteq_s: op1 = %lu    res = %u\n\n", op2_64u1, ret16u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 20 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret16u1 = _hmc64_cmplteq_s(&op2_64u1, op3_64u1);
    printf("   _hmc64_cmplteq_s: op1 = %lu    res = %u\n\n", op2_64u1, ret16u1);

/*****************************************************************************/

    printf("%s\n", "***************");
    printf("%s\n", "* Operação 21 *");
    printf("%s\n", "***************");

    printf("   Operandos: op1 = %lu | op2 = %lu\n", op2_64u1, op3_64u1);
    ret16u1 = _hmc64_cmplt_s(&op2_64u1, op3_64u1);
    printf("   _hmc64_cmplt_s: op1 = %lu    res = %u\n\n", op2_64u1, ret16u1);

    return 0;
}
