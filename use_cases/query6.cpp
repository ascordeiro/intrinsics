#include <stdlib.h>
#include <stdio.h>
#include "../hmc.hpp"

int main() {
	__h64l1 *l_shipdate, *l_discount, *l_quantity, *l_extendedprice, res = 0;

	l_shipdate 		= (__h64l1 *) malloc (100000 * sizeof(__h64l1));
	l_discount 		= (__h64l1 *) malloc (100000 * sizeof(__h64l1));
	l_quantity 		= (__h64l1 *) malloc (100000 * sizeof(__h64l1));
	l_extendedprice = (__h64l1 *) malloc (100000 * sizeof(__h64l1));

    for(size_t i=0; i < 100000; ++i) {
        _hmc64_cmpswapgt_s(&l_shipdate[i], 19940101);
        _hmc64_cmpswaplt_s(&l_shipdate[i], 19950101);
        _hmc64_cmpswapgt_s(&l_discount[i], 5);
        _hmc64_cmpswaplt_s(&l_discount[i], 7);
        _hmc64_cmpswaplt_s(&l_quantity[i], 24);
		if( l_shipdate[i] != 19940101 &&
			l_shipdate[i] != 19950101 &&
			l_discount[i] != 5 &&
     		l_discount[i] != 7 &&
     		l_quantity[i] != 24)
		{
			res += l_extendedprice[i] * l_discount[i];
		}
    }
    return 0;
}

//SELECT
//    sum(l_extendedprice * l_discount) as revenue
//FROM
//    lineitem
//WHERE
//    l_shipdate >= date '1994-01-01'
//    AND l_shipdate < date '1994-01-01' + interval '1' year
//    AND l_discount between 0.06 - 0.01 AND 0.06 + 0.01
//    AND l_quantity < 24;
