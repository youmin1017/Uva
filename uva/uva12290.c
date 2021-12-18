#include <stdio.h>
/*Counting Game*/
int math(int n){
	if(n%7 == 0) return 1;	
	else{
		while(n){
			if(n%10 == 7) return 1;
			n /= 10;
		}
	}
	return 0;
}
int mod(int n,int m,int count){
	if(m == 1 && count%n == 1) return 1;
	if(m == 2 && (count%n == 0 || count%n == 2)) return 1;
	if(count%n == m || count%n == n+2-m) return 1;
	return 0;
}

int main(){
	int n,m,k,i=7,j=0;
	while(scanf("%d%d%d", &n,&m,&k) == 3){
		if(n == 0 && m == 0 && k == 0) break;
		while(j != k){
			if(math(i) == 1 && mod(2*n-2,m,i) == 1){
				++j;
			}
			++i;
		}
		printf("%d\n", i-1);
		i=7; j=0;
	}
	return 0;
}
