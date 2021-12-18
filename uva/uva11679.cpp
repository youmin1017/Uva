#include <iostream>
#include <algorithm>
#include <vector>
//Sub-prime

using namespace std;

int main()
{
	int B, N, debt, credit, value;

	while(cin >> B >> N && B && N)
	{
		vector<int> own(B+1, 0);

		for(int i=1; i <= B; ++i)
			cin >> own[i];

		while(N--)
		{
			cin >> debt >> credit >> value;
			own[debt  ] -= value;
			own[credit] += value;
		}

		sort(own.begin(), own.end());
		
		cout << (own[0]<0 ? 'N' : 'S') << endl;
	}
	
	return 0;
}