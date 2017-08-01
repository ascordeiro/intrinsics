#include "hmc.hpp"

int main(){
    __h64l2 imm_op;
    __h64l2 mem_op;

    scanf("%lu", &imm_op[0]);
    scanf("%lu", &imm_op[1]);

    srand (imm_op[0]);
    mem_op[0] = rand() % 20;
    mem_op[1] = rand() % 8;

    _hmc64_saddimm_d(&mem_op, &imm_op);
    printf("_hmc64_saddimm_d: mem_op[1] = %lu   mem_op[2] = %lu\n-\n", mem_op[0], mem_op[1]);

/*****************************************************************************/

    __h64l1 mem_op1;

    scanf("%lu", &mem_op1);

    _hmc64_incr_s(&mem_op1);
    printf("_hmc64_incr_s: mem_op = %lu\n-\n", mem_op1);

/*****************************************************************************/

    __h128ll1 imm_op1 = 3989146375;
    __h128ll1 mem_op2 = 4294967296;
    _hmc128_saddimm_s(&mem_op2, &imm_op1);
    std::cout << "_hmc128_saddimm_s: mem_op = " << mem_op2 << "\n-\n";

/*****************************************************************************/

    _hmc64_bwrite_s(&mem_op1, &imm_op);
    printf("_hmc64_bwrite_s: mem_op = %lu\n-\n", mem_op1);

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
    return 0;
}
