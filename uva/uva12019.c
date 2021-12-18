#include <stdio.h>
/*Doom's Day Algorithm*/

 void day(int days[][32]){
	int i,j,a=6;
	int x[13] = {0,0,3,0,1,0,1,0,0,1,0,1,0};
	for(i=1; i <= 12; ++i){
		for(j=1; j <= 31-x[i]; ++j){
			days[i][j] = a%7;
			++a;
		}
	}
}

int main(){
	int days[13][32];
	day(days);
	int N,i,M,D;
	scanf("%d", &N);
	for(i=1; i <= N; ++i){
		scanf("%d%d", &M,&D);
		switch(days[M][D]){
			case 0 : printf("Sunday\n"   ); break;
			case 1 : printf("Monday\n"   ); break;
			case 2 : printf("Tuesday\n"  ); break;
			case 3 : printf("Wednesday\n"); break;
			case 4 : printf("Thursday\n" ); break;
			case 5 : printf("Friday\n"   ); break;
			case 6 : printf("Saturday\n" ); break;
		}
	}
	return 0;
}