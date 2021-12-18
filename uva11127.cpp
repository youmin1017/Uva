#include <iostream>

using namespace std;

int main()
{
	int n;

	while(cin >> n)
	{
		int remainder = 1, ans, temp;

		for(ans = 1; remainder; ans++)
		{
			temp = remainder * 10 + 1;
			remainder = temp%n;
		}

		cout << ans << endl;

	}

	return 0;
}