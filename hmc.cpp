#include "hmc.hpp"

int main(){
    uint64_t imm_op[2], mem_op[2];

    printf("%s", "Entrar com operando imediato1:");
    scanf("%lu", &imm_op[0]);
    printf("%s", "Entrar com operando imediato2:");
    scanf("%lu", &imm_op[1]);

    srand (imm_op[0]);
    mem_op[0] = rand() % 20;
    mem_op[1] = rand() % 8;

    printf("_hmc64_saddimm_d: mem_op[1] = %lu   mem_op[2] = %lu\n-\n", mem_op[0], mem_op[1]);
    _hmc64_saddimm_d(&mem_op, &imm_op);
    printf("_hmc64_saddimm_d: mem_op[1] = %lu   mem_op[2] = %lu\n-\n", mem_op[0], mem_op[1]);

/*****************************************************************************/

    uint64_t mem_op1;

    printf("%s", "Entrar com operador de memória:");
    scanf("%lu", &mem_op1);

    _hmc64_incr_s(&mem_op1);
    printf("_hmc64_incr_s: mem_op = %lu\n-\n", mem_op1);

/*****************************************************************************/

    mp::uint128_t imm_op1 = 3989146375;
    mp::uint128_t mem_op2 = 4294967296;
    _hmc128_saddimm_s(&mem_op2, imm_op1);
    std::cout << "_hmc128_saddimm_s: mem_op = " << mem_op2 << "\n-\n";

/*****************************************************************************/

    uint64_t bit_mask, write_data;

    printf("%s", "Entrar com dado para escrita:");
    scanf("%lu", &write_data);
    bit_mask = 5;

    _hmc64_bwrite_s(&mem_op1, bit_mask, write_data);
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
    aux64 = _hmc64_cmpswapeq_s(&mem_op1, imm_op2);
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

    mem_op2 = 4;
    imm_op1 = 4;
    aux128 = _hmc128_equalto_s(mem_op2, imm_op1);
    std::cout << "_hmc128_equalto_s: mem_op = " << mem_op2 << "   aux128 = " << aux128 << "\n-\n";

/*****************************************************************************/

    mem_op1 = 10;
    imm_op2 = 5;
    aux64 = _hmc64_equalto_s(mem_op1, imm_op2);
    printf("_hmc64_equalto_s: mem_op = %lu    aux64 = %lu\n-\n", mem_op1, aux64);

/*****************************************************************************/

    return 0;
}


// mp::uint128_t a = 4294967296;
// mp::uint128_t d = 3989146375;
// mp::uint128_t e;
// mp::uint256_t b(0);
// mp::uint512_t c(0);
//
// e = a + d;
//
// b = a * a;
// c = b * b;
//
// std::cout << "e: " << e << "\n";
// std::cout << "c: " << c << "\n";
