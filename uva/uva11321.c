#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
/*Sort! Sort!! and Sort!!!*/

int mod_num;
int num_cmp(const void *a, const void *b);
int main(){
	int n_case, i;
	int num[MAX];
	while(1){
		scanf("%d%d", &n_case, &mod_num);
		printf("%d %d\n", n_case, mod_num);
		if(n_case==0 && mod_num==0) break;
		for(i=0; i < n_case; ++i){
			scanf("%d", &num[i]);
		}
		qsort(num, n_case, sizeof(int), num_cmp);
		for(i=0; i < n_case; ++i){
			printf("%d\n", num[i]);
		}
	}
	return 0;
}
int num_cmp(const void *a, const void *b){
	if(*(int *)a%mod_num == *(int *)b%mod_num){
		if(!(*(int *)a&1^*(int *)b&1)){
			if(*(int *)a&1) return *(int *)a < *(int *)b;
			else            return *(int *)a > *(int *)b;
		}
		else return *(int *)b&1 - *(int *)a&1;
		
	}
	else return *(int *)a%mod_num > *(int *)b%mod_num;
}