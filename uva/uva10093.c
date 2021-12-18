#include <stdio.h>
#include <string.h>
#define MAX 10000
/*An Easy Problem!*/
int ascii(char ch[],int n){
	n = ch[n]-'0';
	if(n >= 10) n-=7;
	if(n >= 36) n-=6;
	return n; 
}
int main(){
	int i,j,a=0,len,max_digit=0,remainder;
	char ch[MAX];
	while(scanf(" %s", ch) == 1){
		len = strlen(ch); ch[len]='0';
		for(i=0; i < len; i++){
			if(ascii(ch,i) > max_digit)
				max_digit = ascii(ch,i);
		}
		if(ch[0] == '+' || ch[0] == '-'){
			if(len == 2 && ch[1] == '0'){ 
				printf("%d\n", 2);
				continue;
			}
			++a;
		}
		if(len == 1 && ch[0] == '0'){
			printf("%d\n", 2);
			continue;
		}
		for(i=max_digit+1; i <= 62; i++){
			remainder = (ascii(ch,0+a)*i+ascii(ch,1+a))%(i-1);
			for(j=2+a; j < len; j++){
				remainder = (remainder*i+ascii(ch,j))%(i-1);
			}
			if(remainder == 0){
				printf("%d\n", i);
				break;
			}
		}
		if(i == 63)
			printf("such number is impossible!\n");
		a=0; max_digit=0;
	}
	return 0;
}
