#include <iostream>
#include <iomanip>
//Uniform Generator

using namespace std;

int gcd(int, int);

int main()
{
	int step, mod;

	while(cin >> step >> mod)
	{
		cout << setw(10) << step << setw(10) << mod;

		if(gcd(step, mod) == 1) cout << "    Good Choice\n\n";
		else                    cout << "    Bad Choice\n\n";
	}
	
	return 0;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}