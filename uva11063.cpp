#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//B2-Sequence

using namespace std;

int main()
{
	int n, count=1; //the numbers of number
	while(cin >> n)
	{	
		bool b = true;
		vector<int> num(n);
		map<int, int> sum;

		for(int i=0; i < n; ++i)
		{
			cin >> num[i];
			if(num[i] <= 0 || (i >=1 && num[i] <= num[i-1])) 
				b = false;
		}

		for(int i=0; i < n; ++i)
			for(int j=i; j < n; ++j)
			{
				sum[num[i]+num[j]]++;
				if(sum[num[i]+num[j]] == 2)
				{
					b = false;
					break;
				}

			}

		if(b) cout << "Case #" << count << ": It is a B2-Sequence.\n\n";
		else  cout << "Case #" << count << ": It is not a B2-Sequence.\n\n";
		++count, sum.clear();
	}
	return 0;
}