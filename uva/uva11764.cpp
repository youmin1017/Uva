#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for(int i=1; i <= n; ++i)
	{
		int high_jumps = 0, low_jumps = 0, wall, wall_num, temp;
		cin >> wall_num >> wall;

		while(--wall_num)
		{
			cin >> temp;
			if(wall > temp)      low_jumps++;
			else if(wall < temp) high_jumps++;
			wall = temp;
		}

		cout << "Case " << i << ": " << high_jumps << ' ' << low_jumps << endl;

	}


	return 0;
}