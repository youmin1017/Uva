#include <stdio.h>
/*Hartals*/
int main(){
	int n,i,j,k,Day,party,hartal;
	scanf("%d", &n);
	for(i=1; i <= n; i++){
		scanf("%d%d", &Day,&party);
		int Days[Day];
		for(j=0; j < Day; j++) Days[j]=0;
		for(j=1; j <= party; j++){
			scanf("%d", &hartal);
			for(k=1; k <= Day; k++){
				if(k%hartal == 0)
					Days[k-1]=1;
			}
		}
		hartal=0;
		for(k=0; k < Day; k++){
			if(k%7 == 5 || k%7 == 6) 
				continue;
			if(Days[k] == 1) 
				++hartal;
			Days[k]=0;
		}
		printf("%d\n", hartal);
	}
	return 0;
}