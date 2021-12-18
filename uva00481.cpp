#include <iostream>
#include <algorithm>
#include <vector>
//What Goes Up

using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int x;

	vector< vector<int> > LIS(1);
	vector<int> LIS_END(1);
	vector<int>::iterator it;

	cin >> x;
	LIS[0].push_back(x);
	LIS_END[0] = x;

	while(cin >> x)
	{
		if(x < LIS[0][0])
		{
			LIS[0][0] = x;
			LIS_END.pop_back();
			LIS_END.push_back(x);
			continue;
		}

		it = lower_bound(LIS_END.begin(), LIS_END.end(), x, greater<int>());
		if(x == *it) continue; // need not to process repeat number

		if(it == LIS_END.begin())
		{
			LIS.push_back(LIS.back());
			LIS[ LIS.size()-1 ].push_back(x);
			LIS_END.insert(LIS_END.begin(), x);
		}
		else
		{
			int end_po = it - LIS_END.begin();
			int lis_po = LIS_END.size() - end_po;

			LIS[ lis_po ] = LIS[ lis_po-1 ];
			LIS[ lis_po ].push_back(x);
			LIS_END[ end_po-1 ] = x;
		}
	}

	cout << LIS_END.size() << endl << '-' << endl;

	for(auto num: LIS[LIS.size()-1])
		cout << num << endl;
	
	return 0;
}