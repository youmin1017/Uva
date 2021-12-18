#include <stdio.h>
/*Square Numbers*/
int main(){
	int a,b,i,count=0;
	while(scanf("%d%d", &a,&b) == 2){
		if(a == 0 && b == 0)
			break;
		if(a > b)
			a^=b^=a^=b;
		for(i=1; i < b; i++){
			if(i*i <= b && i*i >= a)
				++count;
			if(i*i > b)
				break;
		}
		printf("%d\n", count);
		count=0;
	}
	return 0;
}