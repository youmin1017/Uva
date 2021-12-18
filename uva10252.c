#include <stdio.h>
#include <ctype.h>
#define MAX 1000
/*Common Permutation*/
void unionf(char *ptr, int alpha[]){
	while(*ptr != '\0'){
		++alpha[*ptr-'a'];
		++ptr;
	}
}
int main(){
	char str_1[MAX], str_2[MAX];
	int i, j, alpha_1[26]={0}, alpha_2[26]={0};
	while(gets(str_1) && gets(str_2)){
		unionf(str_1, alpha_1);
		unionf(str_2, alpha_2);
		for(i=0; i < 26; ++i){
			if(alpha_1[i] && alpha_2[i]){
				if(alpha_1[i] > alpha_2[i]) alpha_1[i] = alpha_2[i];
				for(j=1; j <= alpha_1[i]; ++j) printf("%c", i+'a'); 
			}
			alpha_1[i]=0; alpha_2[i]=0;
		}
		printf("\n");
	}
	return 0;
}