#include "hmc.hpp"

int main(){
    __h64l2 imm_op, mem_op;

    printf("%s", "Entrar com operando imediato1:");
    scanf("%lu", &imm_op[0]);
    printf("%s", "Entrar com operando imediato2:");
    scanf("%lu", &imm_op[1]);

    srand (imm_op[0]);
    mem_op[0] = rand() % 20;
    mem_op[1] = rand() % 8;

    mem_op = _hmc64_saddimm_d(mem_op, imm_op);
    printf("_hmc64_saddimm_d: mem_op[1] = %lu   mem_op[2] = %lu\n-\n", mem_op[0], mem_op[1]);

/*****************************************************************************/

    uint64_t mem_op1;

    printf("%s", "Entrar com operador de memória:");
    scanf("%lu", &mem_op1);

    mem_op1 = _hmc64_incr_s(mem_op1);
    printf("_hmc64_incr_s: mem_op = %lu\n-\n", mem_op1);

/*****************************************************************************/

    mp::uint128_t mem_op2 = 4294967296;
    mp::uint128_t imm_op1 = 3989146375;
    mp::uint128_t m;

    mem_op2 = _hmc128_saddimm_s(mem_op2, imm_op1);
    std::cout << "_hmc128_saddimm_s: mem_op = " << mem_op2 << "\n-\n";

/*****************************************************************************/

    uint64_t bit_mask, write_data;

    printf("%s", "Entrar com dado para escrita:");
    scanf("%lu", &write_data);
    printf("%s", "Entrar com máscara:");
    scanf("%lu", &bit_mask);

    mem_op1 = _hmc64_bwrite_s(mem_op1, bit_mask, write_data);
    printf("_hmc64_bwrite_s: mem_op = %lu\n-\n", mem_op1);

/*****************************************************************************/

    mp::uint128_t aux128;
    aux128 = _hmc128_bswap_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_bswap_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    aux128 = _hmc128_and_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_and_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_nand_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_nand_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_nor_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_nor_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_or_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_or_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_xor_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_xor_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    uint64_t aux64, imm_op2;
    mem_op1 = 10;
    imm_op2 = 5;
    aux64 = _hmc64_cmpswapgt_s(&mem_op1, imm_op2);
    printf("_hmc64_cmpswapgt_s: mem_op = %lu    aux64 = %lu\n-\n", mem_op1, aux64);

/*****************************************************************************/

    mem_op1 = 10;
    imm_op2 = 5;
    aux64 = _hmc64_cmpswaplt_s(&mem_op1, imm_op2);
    printf("_hmc64_cmpswaplt_s: mem_op = %lu    aux64 = %lu\n-\n", mem_op1, aux64);

/*****************************************************************************/

    mem_op1 = 10;
    imm_op2 = 5;
    uint64_t cmp_field = 10;
    aux64 = _hmc64_cmpswapeq_s(&mem_op1, imm_op2, cmp_field);
    printf("_hmc64_cmpswapeq_s: mem_op = %lu    aux64 = %lu\n-\n", mem_op1, aux64);

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_cmpswapgt_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_cmpswapgt_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_cmpswaplt_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_cmpswaplt_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op2 = 5;
    imm_op1 = 4;
    aux128 = _hmc128_cmpswapz_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_cmpswapz_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    uint16_t sinal;
    mem_op2 = 4;
    imm_op1 = 4;
    sinal = _hmc128_equalto_s(mem_op2, imm_op1);
    std::cout << "_hmc128_equalto_s: mem_op = " << mem_op2 << "   sinal = " << sinal << "\n-\n";

/*****************************************************************************/

    mem_op1 = 10;
    imm_op2 = 5;
    sinal = _hmc64_equalto_s(mem_op1, imm_op2);
    printf("_hmc64_equalto_s: mem_op = %lu    sinal = %u\n-\n", mem_op1, sinal);

/*****************************************************************************/

    return 0;
}
