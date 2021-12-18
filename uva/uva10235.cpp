#include <iostream>
#include <string>
#include <algorithm>
//Simply Emirp

using namespace std;

int is_prime(int n)
{
	if(n < 2) return 0;
	for(int i=2; i*i <= n; ++i)
	{
		if(n%i == 0) return 0;
	}
	return 1;
}

int main()
{
	int a, b;
	string str_num;

	while(cin >> str_num)
	{
		a = stoi(str_num);
		cout << a << " is ";

		if(is_prime(a))
		{
			reverse(str_num.begin(), str_num.end());
			b = stoi(str_num);

			if(is_prime(b) && a != b) cout << "emirp." << endl;
			else                      cout << "prime." << endl;
		}
		else cout << "not prime." << endl;
	}

	return 0;
}