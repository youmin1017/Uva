#include <stdio.h>
#define MAX 12
/*Summing Digits*/

int summing(char *numPtr){
	int sum=0;
	while(*numPtr != '\n'){
		sum += *numPtr-'0';
		++numPtr;
	}
	return sum;
}
int main(){
	char num[MAX];
	int sum;
	while(fgets(num, MAX, stdin) != NULL){
		if(num[0] == '0') break;
		sum = summing(num);
		while(sum >= 10){
			sum = sum%10+sum/10;
		}
		printf("%d\n", sum);
	}
	return 0;
}