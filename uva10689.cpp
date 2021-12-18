#include <iostream>
#include <vector>
//Yet another Number Sequence

using namespace std;

vector<int> matrix_product(const vector<int> &a, const vector<int> &b, int mod_num)
{
	vector<int> x(4, 0);
	
	x[0] = (a[0]*b[0] + a[1]*b[2])%mod_num;
	x[1] = (a[0]*b[1] + a[1]*b[3])%mod_num;
	x[2] = (a[2]*b[0] + a[3]*b[2])%mod_num;
	x[3] = (a[2]*b[1] + a[3]*b[3])%mod_num;

	return x;
}

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	int n_tests;
	int mod[5] = {0, 10, 100, 1000, 10000};

	cin >> n_tests;

	while (n_tests--)
	{
		int a, b, n, m;
		vector<int>  v1 = {1, 1, 1, 0};
		vector<int> ans = {1, 0, 1, 0};
		
		cin >> a >> b >> n >> m;
		if(n == 0 || n == 1)
		{
			cout << (n? b:a) << '\n';
			continue;
		}
		n--;

		while(n)
		{
			if(n&1)
				ans = matrix_product(ans, v1, mod[m]);
			v1 = matrix_product(v1, v1, mod[m]);
			n >>= 1;
		}

		cout << ((ans[2]*b)+(ans[3]*a))%mod[m] << endl;

	}

	return 0;
}