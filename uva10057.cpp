#include <iostream>
#include <vector>
#include <algorithm>
//A mid-summer night’s dream

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	int n, num;
	vector<int> numbers;

	while(cin >> n)
	{
		int count = 0;

		for(int i=0; i < n; ++i)
			cin >> num, numbers.push_back(num);

		sort(numbers.begin(), numbers.end());

		for(int x: numbers)
			if(n%2 == 0 && x >= numbers[n/2-1] && x <= numbers[n/2])
				++count;
			else if(n&1 && x == numbers [n/2])
				++count;

		cout << numbers[num = (n&1)? n/2:n/2-1] << ' ' << count << ' '; 
		if(n&1) cout << 1 << endl;
		else    cout << numbers[n/2]-numbers[n/2-1]+1 << endl;

		numbers.clear();
	}
	
	return 0;
}