#include <stdio.h>
/*he Hotel with Infinite Rooms*/

int main(){
	unsigned long long s, d;
	while(scanf("%llu%llu", &s, &d) == 2){
		unsigned long long i, tc = 2*d+s*(s-1);
		for(i=1; i*(i+1) < tc; ++i);
		printf("%llu\n", i);
	}
	return 0;
}