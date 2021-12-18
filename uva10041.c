#include <stdio.h>
#include <stdlib.h>
/*Vito's Family*/
int home[500];
int math(int n){
	int median,i,distance=0;
	if((n+1)%2 == 0){ 
		median = (home[n/2]+home[n/2+1])/2;
		for(i=0; i <= n; i++){
			distance += abs(home[i]-median);
		}
	}
	else{
		median = home[n/2];
		for(i=0; i <= n; i++){
			distance += abs(home[i]-median);
		}
	}
	return distance;
}
int main(){
	int t,i,j,k,n;
	scanf("%d", &t);
	for(i=1; i <= t; i++){
		scanf("%d", &n);
		for(j=0; j < n; j++)
			scanf("%d", &home[j]);
		for(j=1; j < n; j++)
			for(k=0; k < n-j; k++)
				if(home[k] > home[k+1])
					home[k]^=home[k+1]^=home[k]^=home[k+1];
		printf("%d\n", math(n-1));
	}
	return 0;
}