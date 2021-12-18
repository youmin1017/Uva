#include <iostream>
//Funny Encryption Method

using namespace std;

int main()
{
	int n_case, num, num_r;
	cin >> n_case;

	for(int i=0; i < n_case; ++i)
	{
		int count_1=0, count_2=0;
		cin >> num;
		num_r = num;

		while(num)
		{
			count_1 += num&1;
			num >>= 1;
		}

		while(num_r)
		{	// hex consists of every 5 binary  e.g. 265(16) = (00010, 00110, 00101)2
			num = num_r%10;
			
			while(num)
			{
				count_2 += num&1;
				num >>= 1;
			}

			num_r /= 10;
		}

		cout << count_1 << ' ' << count_2 << endl;
	}

	return 0;
}