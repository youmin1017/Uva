#include <stdio.h>
/*Train Swapping*/
int main(){
	int i,j,k,n,l,count=0;
	int a[50];
	scanf("%d", &n);
	for(i=1; i <= n;i++){
		scanf("%d", &l);
		for(j=0; j < l; j++)
			scanf("%d", &a[j]);
		for(j=1; j <= l; j++){
			for(k=0; k < l-j; k++){
				if(a[k] > a[k+1]){
					a[k]^=a[k+1]^=a[k]^=a[k+1];
					++count;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", count);
		count=0;
	}
	return 0;
}