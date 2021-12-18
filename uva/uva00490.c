#include <stdio.h>
#include <string.h>
#define MAX_LEN 102
/*Rotating Sentences*/

int main(){
	char str[100][MAX_LEN];
	int i, j, k, max=0;
	for(i=0; fgets(str[i], MAX_LEN, stdin) != NULL; ++i){
		if(strlen(str[i]) > max){
			max = strlen(str[i]);
		}
	}
	for(j=0; j < max; ++j){
		for(k=i-1; k >= 0; --k){
			if(j+1 >= strlen(str[k])) putchar(' ');
			else putchar(str[k][j]);
		}
		if(j < max-1) printf("\n");
	}
	return 0;
}