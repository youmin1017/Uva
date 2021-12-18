#include <iostream>

using namespace std;

int main()
{
	int n;

	while(cin >> n && n)
	{
		ios::sync_with_stdio(false), cin.tie(0);
		int sum = 0, max = 0, x;
		bool status = true;

		while(n--)
		{
			cin >> x;

			if(x < 0 && status)
				status = false;

			else if(!status && x > 0)
			{
				if(sum < 0)
					sum = 0;
				status = true;
			}			
			sum += x;			
			if(sum > max && status)
				max = sum;
		}
		
		if(sum <= 0) cout << "Losing streak.\n";
		else         cout << "The maximum winning streak is " << max << ".\n";
	}

	return 0;
}
