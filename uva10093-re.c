#include <stdio.h>
#include <ctype.h>
#define MAX 10000
/*An Easy Problem!*/

int main(){
	char num[MAX], *numPtr;
	int sum=0, max=1, temp, i;
	while(scanf("%s", num) == 1){
		numPtr = num;
		while(*numPtr != '\0'){
			if(isdigit(*numPtr))      sum += temp=*numPtr-'0';
			else if(isupper(*numPtr)) sum += temp=*numPtr-55;
			else if(islower(*numPtr)) sum += temp=*numPtr-61;
			if(temp > max) max = temp;
			++numPtr;
		}
		for(i=max; i <= 61; ++i){
			if(sum%i == 0){
				printf("%d\n", i+1);
				break;
			}
		}
		if(i == 62) printf("such number is impossible!\n");
		max=1;
		sum=0;
	}
	return 0;
}