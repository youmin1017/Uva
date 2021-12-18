#include<stdio.h>
/*Continued Fractions*/
int gcd(int m,int n){
	int t = 1;
	while(t != 0){
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}

int main(){
	int n,t,i,b,temp,count=0;
	int a[500];
	while(scanf("%d%d", &n,&t) == 2){
		if(t == 0){
			printf("[0]");
			continue;
		}
		b = gcd(n,t);
		n /= b;
		t /= b;
		if(n > t){
			a[0] = n/t;
			n %= t;
		}
		else{
			a[0] = 0;
		}
		while(1){
			if(n == 1) break;
			count++;
			if(count%2 == 0){
				a[count] = n/t;
				n %= t;
				if(n == 1) break;
			}
			else{
				a[count] = t/n;
				t %= n;
				if(t == 1) break;
			}
		}
		if(count%2 == 0){
			temp = n;
			n = t;
			t = temp;
		}
		printf("[%d;", a[0]);
		for(i=1; i <= count; i++)
			printf("%d,",a[i]);
		printf("%d]\n",n);
		count=0;
	}
	return 0;
}
