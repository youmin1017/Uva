#include <iostream>
#include <vector>
#include <string>
#include <map>
//Eb Alto Saxophone Player

using namespace std;

int main()
{
	int n;
	string music;
	map<char, vector<int>> tone =
	{
		{ 'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1} },
		{ 'd', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0} },
		{ 'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0} },
		{ 'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0} },
		{ 'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0} },
		{ 'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0} },
		{ 'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0} },
		{ 'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0} },
		{ 'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0} },
		{ 'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0} },
		{ 'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0} },
		{ 'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0} },
		{ 'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0} },
		{ 'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0} },
	}; // 1 is pressed, but 0.

	cin >> n, cin.get();

	while(n--)
	{
		vector<int> finger_state(10, 0), sum(10, 0);

		getline(cin, music);

		for(auto x: music)
		{
			for(int i=0; i < 10; ++i)
				if(finger_state[i] == 0 && tone[x][i])
				{
					++sum[i];
					finger_state[i] = 1;
				}
				else if(tone[x][i] == 0)
					finger_state[i] = 0;
		}

		for(int i=0; i < 9; ++i)
			cout << sum[i] << ' ';

		cout << sum[9] << endl;
	}

	return 0;
}