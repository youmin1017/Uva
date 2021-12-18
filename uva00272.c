#include <stdio.h>
/*TEX Quotes*/

int main(){
	char ch;
	int i=1;
	while(scanf("%c", &ch) == 1){
		if(ch == '"' && i&1){
			printf("%c%c", '`', '`');
			++i;
		}
		else if(ch == '"'){
			printf("%c%c", '\'', '\'');
			++i;
		}
		else
			putchar(ch);
	}
	return 0;
}