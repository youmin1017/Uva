#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> set;
// the function of answers uses recursive method.
void foo(int a, int b, int c, int d, int e, int f);

int main(int argc, char const *argv[])
{
	int n;
	bool endl_test = false;

	while(cin >> n && n)
	{
		set.resize(n);

		for(int i = 0; i < n; ++i)
			cin >> set[i];

		if(endl_test) cout << endl;
		else endl_test = true;

		foo(n-6, n-5, n-4, n-3, n-2, n-1);
	}

	return 0;
}

void foo(int a, int b, int c, int d, int e, int f)
{
	int size = set.size();

	if(a != 0 && f-a == 5) foo(a-1, size-5, size-4, size-3, size-2, size-1);
	else if(f-e >= 2)      foo(a, b, c, d, e, f-1);
	else if(e-d >= 2)      foo(a, b, c, d, e-1, size-1);
	else if(d-c >= 2)      foo(a, b, c, d-1, size-2 ,size-1);
	else if(c-b >= 2)      foo(a, b, c-1, size-3, size-2, size-1);
	else if(b-a >= 2)      foo(a, b-1, size-4, size-3, size-2, size-1);

	cout << set[a] << ' ';
	cout << set[b] << ' ';
	cout << set[c] << ' ';
	cout << set[d] << ' ';
	cout << set[e] << ' ';
	cout << set[f] << endl;
}