#include <stdio.h>
/*GCD*/
int gcd(int m,int n){
	int a=1;
	while(a != 0){
		a=m%n;
		m=n;
		n=a;
	}
	return m;
}

int main(){
	int G=0,N,i,j;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		for(i=1; i < N; i++)
			for(j=i+1; j <= N; j++)
				G += gcd(i,j);
		printf("%d\n", G);
		G=0;
	}

	return 0;
}