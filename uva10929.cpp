#include <iostream>
#include <string>
//You can say 11

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	string num;

	while(cin >> num)
	{
		if(num == "0")
			break;

		int sum=0;

		for(unsigned int i=0; i < num.length(); ++i)
		{
			if(i&1) sum += num[i]-'0';
			else    sum -= num[i]-'0';
		}

		if(sum%11) cout << num << " is not a multiple of 11.\n";
		else       cout << num << " is a multiple of 11.\n";
	}
	
	return 0;
}