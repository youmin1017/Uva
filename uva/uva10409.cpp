#include <iostream>
#include <vector>
//Die Game

using namespace std;

int main()
{
	int n, temp;
	string command;

	while(cin >> n)
	{
		if(n == 0) break;

		vector<int> a = {1, 5, 6, 2, 1}; // south and north
		vector<int> b = {1, 3, 6, 4, 1}; // weast and east
		
		for(int i=0; i < n; ++i)
		{
			cin >> command;
			if(command == "north")
			{
				a.erase(a.begin());
				a.push_back(a[0]);
				b[0]=a[0], b[2]=a[2], b[4]=a[4];
			}
			else if(command == "south")
			{
				temp = a[3];
				a.insert(a.begin(), temp);
				a.pop_back();
				b[0]=a[0], b[2]=a[2], b[4]=a[4];
			}
			else if(command == "east")
			{
				b.erase(b.begin());
				b.push_back(b[0]);
				a[0]=b[0], a[2]=b[2], a[4]=b[4];
			}
			else
			{
				temp = b[3];
				b.insert(b.begin(), temp);
				b.pop_back();
				a[0]=b[0], a[2]=b[2], a[4]=b[4];
			}
		}
		cout << a[0] << endl;
	}
	return 0;
}
//[1]  5  [6]  2  do north
//[1] (3) [6] (4)   
//[5]  6  [2]  1  <---   
//[5] (3) [2] (4)