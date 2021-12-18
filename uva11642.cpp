#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
//Age Sort

using namespace std;

int main()
{
	// ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	vector<int> input(2000000);

	while(~scanf("%d", &n) && n)
	{
		input.resize(n);
		
		for(int i=0; i < n; ++i)
			scanf("%d", &input[i]);

		sort(input.begin(), input.end());

		for(int i = 0; i < n-1 ; ++i)
			printf("%d ", input[i]);

		printf("%d\n", input[n-1]);
	}
	
	return 0;
}