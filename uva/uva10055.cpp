#include <cstdio>
#include <iostream>
//Hashmat the brave warrior

using namespace std;

int main()
{
	long int us, op;

	while(scanf("%lu%lu", &us, &op) == 2)
		printf("%lu\n", ( (us-op>0)? us-op:op-us) );
	
	return 0;
}