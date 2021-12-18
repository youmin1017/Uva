#include <stdio.h>
/*Odd Sum*/
int main(){
	int n,i,a,b,sum;
	scanf("%d", &n);
	for(i=1; i <= n; i++){
		scanf("%d%d", &a,&b);
		if(a%2 == 0) ++a;
		if(b%2 == 0) --b;
		sum = (a+b)*((b-a)/2+1)/2;
		printf("Case %d: %d\n", i,sum);
		sum=0;
	}
	return 0;
}