#include <iostream>
#include <string>
//Very Big Perfect Squares

using namespace std;

int pow_fun(int x)
{
	int i;
	
	for(i=1; i*i <= x; ++i)
		;
		
	return i-1;
}

int main()
{
	
	int str_len;
	string test_case;

	// terminate by input 0
	while(cin >> test_case && test_case != "0")
	{
		str_len = test_case.length();

		if(str_len&1) // one digit
			cout << pow_fun(test_case[0]-'0');
		else // two digit
			cout << pow_fun(10*(test_case[0]-'0')+test_case[1]-'0');
		// if str_len is even need to minus one
		str_len = str_len/2 - (str_len&1? 0:1); 

		while(str_len--) cout << '0';

		cout << endl;
	}
	
	return 0;
}