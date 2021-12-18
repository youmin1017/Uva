#include <iostream>
#include <string>
// All You Need Is Love

using namespace std;

int gcd(int a, int b)
{
	int t;
	while(b)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
	int n;
	string str1, str2;

	cin >> n;

	for(int i=1; i <= n; ++i)
	{
		int a=0, b=0;
		cin >> str1 >> str2;

		for(char x: str1)
		{
			if(x == '1') ++a;
			a <<= 1; 
		}
		for(char x: str2)
		{
			if(x == '1') ++b;
			b <<= 1; 
		}
		a >>= 1, b >>= 1; 
		
		cout << "Pair #" << i << ": ";
		if(gcd(a, b) == 1) cout << "Love is not all you need!" << endl;
		else               cout << "All you need is love!" << endl;

	}

	return 0;
}