#include <iostream>
#include <string>
#include <vector>
//Minesweeper

using namespace std;

int main()
{
	int m, n;

	for(int count=1; cin >> m >> n; ++count)
	{
		if(n == 0 && m == 0)
			break;
		if(count-1) cout << endl;

		string row;
		vector<string> col(m);

		for(int i=0; i < m; ++i)
			cin >> col[i];

		cout << "Field #" << count << ':' << endl;
		
		for(int i=0; i < m; ++i)
		{
			for(int j=0; j < n; ++j)
			{
				int sum = 0;
				
				if(col[i][j] == '*')
				{
					cout << '*';
					continue;
				}
				for(int r=i-1; r < i+2; ++r)
				{
					for(int c=j-1; c < j+2; ++c)
					{
						if(r < 0 || c < 0 || r >= m || c >= n)
							continue;
						else if(col[r][c] == '*')
							++sum;
					}
				}
				cout << sum;
			}
			cout << endl;
		}
	}
	
	return 0;
}