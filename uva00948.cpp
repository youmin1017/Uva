#include <iostream>
#include <string>
//Fibonaccimal Base

using namespace  std;
//Fibonaccimal function
int math(int *init_1, int *init_2, int num)
{
	int count;
	*init_1 = 1; *init_2 = 2;

	for(count=0; *init_2 <= num; ++count)
	{
		*init_2 += *init_1;
		*init_1  = *init_2-*init_1;
	}
	// the return number is represent at (fib) is 1. 
	return count;
}

int main()
{
	int init_1, init_2, n_case, num, count, record;
	cin >> n_case;

	for(int i=1; i <= n_case; ++i)
	{
		cin >> num; // input test data
		cout << num << " = ";
		
		count = math(&init_1, &init_2, num);
		string ans(count+1, '0');
		ans[0] = '1';
		num -= init_1;
		record = count;

		while(num)
		{
			count = math(&init_1, &init_2, num);
			num -= init_1;
			ans[record-count] = '1';
		}

		cout << ans << " (fib)" <<endl;
	}

	return 0;
}