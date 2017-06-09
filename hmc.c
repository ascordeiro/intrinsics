#include "hmc.h"

int main(){
    __h16i datai = {1, 2, 3, 4};
    int *memi_addr = malloc(6*sizeof(int));
    _hmc16_write_pi(memi_addr, datai);
    printf("memi[1] = %d\nmemi[2] = %d\nmemi[3] = %d\nmemi[4] = %d\nmemi[5] = %d\nmemi[6] = %d\n-\n", memi_addr[0], memi_addr[1], memi_addr[2], memi_addr[3], memi_addr[4], memi_addr[5]);
    __h16i readi = _hmc16_read_pi(memi_addr);
    printf("ireg[1] = %d\nireg[2] = %d\nireg[3] = %d\nireg[4] = %d\n\n", readi[0], readi[1], readi[2], readi[3]);

    __h16l datad = {5, 6};
    long int *meml_addr = malloc(6*sizeof(double));
    _hmc16_write_pl(meml_addr, datad);
    printf("meml[1] = %ld\nmeml[2] = %ld\nmeml[3] = %ld\nmeml[4] = %ld\nmeml[5] = %ld\nmeml[6] = %ld\n-\n", meml_addr[0], meml_addr[1], meml_addr[2], meml_addr[3], meml_addr[4], meml_addr[5]);
    __h16l readd = _hmc16_read_pl(meml_addr);
    printf("dreg[1] = %ld\ndreg[2] = %ld\n\n", readd[0], readd[1]);

    __h16i mem_oper = {1, 2, 3, 4};
    __h16i immediate = {5, 6, 7, 8};
    __h16i res_mem_oper = _hmc16_and_pi(mem_oper, immediate);
    printf("memo[1] = %d\nmemo[2] = %d\nmemo[3] = %d\nmemo[4] = %d\nmemo[5] = %d\nmemo[6] = %d\n\n", res_mem_oper[0], res_mem_oper[1], res_mem_oper[2], res_mem_oper[3], res_mem_oper[4], res_mem_oper[5]);

}
