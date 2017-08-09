#include <stdlib.h>
#include <stdio.h>
#include "../hmc.hpp"

int main() {
    __h64l1 *outer, *inner, *join_res;
    outer = (__h64l1 *) malloc (100000 * sizeof(__h64l1));
    inner = (__h64l1 *) malloc (100000 * sizeof(__h64l1));
    join_res = (__h64l1 *) malloc (100000 * sizeof(__h64l1));
    
    for(size_t i=0; i < 100000; ++i) {
        for(size_t j=0; j < 100000; ++j) {
        	if( _hmc64_equalto_s(outer[i], inner[j]) == 1 ) {
                join_res[i] = j;
                break;
            }
        }
    }
    return 0;
}
