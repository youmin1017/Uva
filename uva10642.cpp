#include <iostream>
//Can You Solve It?

using namespace std;

int main()
{
	int n_case;

	cin >> n_case;

	for (int i = 1; i <= n_case; ++i)
	{
		long long steps, x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		// since the steps of (a, 0) go to (b, 0) is AP, so need to manefacture that condiction.  
		steps = (x2+y2-x1-y1)*(x2+y2+x1+y1+3)/2+y1-y2;

		cout << "Case " << i << ": "<< steps << endl;
	}

	return 0;
}
