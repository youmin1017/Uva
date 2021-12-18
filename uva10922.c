#include <stdio.h>
#include <string.h>
#define MAX 1002
/*2 the 9s*/

int math(char num[])
{
	int i, sum=0;
	/*add all digit to the sum*/
	for(i=0; i < strlen(num) ; ++i)
		sum += num[i]-'0';
	/*put sum into num_string*/
	sprintf(num, "%d", sum);

	if(sum%9 == 0 && sum != 9)
		return 1;
	else
		return 0;
}

int main()
{
	char num_1[MAX], num_2[MAX];

	while(1)
	{
		int n_degree;
		gets(num_1); /*get the line*/
		strcpy(num_2, num_1); /*preserve the original num_string*/

        if(num_1[0] == '0')
			break;
		/*while math function math return 0 the for loop whill stop*/
		for(n_degree=1; math(num_2); ++n_degree)
			;

		if(n_degree-1)
			printf("%s is a multiple of 9 and has 9-degree %d.\n", num_1, n_degree);
		else
			printf("%s is not a multiple of 9.\n", num_1);
	}
	return 0;
}