#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
//Above average

using namespace std;

int main()
{
	int n, num, x;
	double average;

	cin >> n;

	while(n--)
	{
		int sum = 0;
		cin >> num;
		vector<int> numbers;

		while(num--)
		{
			cin >> x;
			sum += x;
			numbers.push_back(x);
		}

		average =  static_cast<double>(sum) / numbers.size();

		sum = count_if(numbers.begin(), numbers.end(), 
			[average](int a) { return a > average; });

		cout << fixed << setprecision(3)
			<< static_cast<double>(sum) / numbers.size() * 100.0 << '%' << endl;
	}


	return 0;
}