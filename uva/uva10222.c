#include <stdio.h>
#include <ctype.h>
#define MAX 1000
/*Decode the Mad man*/
int main(){
	char code[MAX], decode[26] = {'d','m','b','g','t','h','j','k','p','l',';','\'','.',
	                              ',','[',']','e','y','f','u','o','n','r','v','i' ,'c'};
	char new_str[MAX];
	int i, j;
	fgets(code, MAX, stdin);
	for(i=0; code[i] != '\n'; ++i){
		if(code[i] == ' ') new_str[i] = ' ';
		if(isupper(code[i])) code[i] += 32;
		for(j=0; j < 26; ++j){
			if(code[i] == decode[j]){
				new_str[i] = 'a'+j;
			}
		}
	}
	printf("%s\n", new_str);
	return 0;
}