#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// Walking on the Safe Side 

using namespace std;

int main()
{
	int n, row, col, x;
	string unsafe_po;

	cin >> n;

	while(n--)
	{
		cin >> row >> col;

		vector<int> a(col+1, 1);
		a[0] = 0;
		vector< vector<int> > ans(row+1, a);
		ans[0].assign(col+1, 0);
		ans[0][1] = 1;
		cin.ignore();

		for(int i=1; i <= row; ++i)
		{
			getline(cin, unsafe_po);
			stringstream ss(unsafe_po);
			ss >> x;    // ignore the first number
			while (ss >> x)
				ans[i][x] = 0;
		}

		for(int i=1; i <= row; ++i)
		{
			for(int j=1; j <= col; ++j)
			{
				if(ans[i][j] == 0) 
					continue;
				else
					ans[i][j] = ans[i-1][j] + ans[i][j-1];
			}

		}
		cout << ans[row][col] << endl;

		if(n) cout << endl;
	}

	return 0;
}