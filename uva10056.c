#include <stdio.h>
#define ROUND 40
#define MAX 1000
/* What is the Probability ?*/

int main(){
	int n_case, target, peo_num, i, j, k;
	double p0, q, p[MAX]={0};
	scanf("%d", &n_case);
	for(i=1; i <= n_case; ++i){
		scanf("%d%lf%d", &peo_num, &p0, &target);
		q = 1-p0;
		for(j=1; j <= ROUND; ++j){
			for(k=0; k < peo_num; ++k){
				p[k] += p0;
				p0 *= q;
			}
		}
		printf("%.4lf\n", p[target-1]);
		for(j=0; j < peo_num; ++j) p[j]=0;
	}
	return 0;
}
