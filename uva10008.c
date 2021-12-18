#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENTH 2000
/*What's Cryptanalysis?*/
typedef struct{
	char alpha;
	int sum;
} Char_int;
int cmp(const void *a, const void *b){
    return ( (*(Char_int *)b).sum-(*(Char_int *)a).sum );
}
int main(){
	Char_int cases[26]={{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0},{'G',0},{'H',0},{'I',0},
{'J',0},{'K',0},{'L',0},{'M',0},{'N',0},{'O',0},{'P',0},{'Q',0},{'R',0},{'S',0},{'T',0},{'U',0},
{'V',0},{'W',0},{'X',0},{'Y',0},{'Z',0}};
	int n, i;
	scanf("%d", &n);
	char str[n][MAX_LENTH], *strPtr;
	getchar();
	for(i=0; i < n; ++i){
		fgets(str[i], MAX_LENTH, stdin);
		strPtr = str[i];
		while(*strPtr != '\n'){
			if(isupper(*strPtr))      ++cases[*strPtr-'A'].sum;
			else if(islower(*strPtr)) ++cases[*strPtr-'a'].sum;
			++strPtr;
		}
	}
	qsort(cases, 26, sizeof(Char_int), cmp);
	for(i=0; i < 26; ++i){
		if(cases[i].sum){
			printf("%c %d\n", cases[i].alpha, cases[i].sum);
		}
	}
	return 0;
}
