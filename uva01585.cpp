#include <iostream>
#include <string>

using namespace std;


int main()
{
	int n;
	string cases;

	cin >> n;

	while(n--)
	{
		int sum=0, i=1;
		cin >> cases;

		for(char x: cases)
		{
			if(x == 'X')
				i=1;
			else
				sum += (i++);
		}
		
		cout << sum << endl;

	}

    return 0;
}

