#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	while(cin >> n && n >= 3)
	{
		long long ans = 0;
		long long layer = n-3, cent = layer&1 ? layer/2 + 1 : layer/2;
		long long x = layer&1 ? 1 : 3;

		ans = -4 * cent * (cent+1) * (2*cent+1) / 6 + (4*cent+x) * cent * (cent+1) / 2;
		
		cout << ans << endl;
	}

	return 0;
}

// the law
//     1
//    1+1
//   1+2+1
//  1+2+2+1
//     .
//     .     and using sigma to get the function.
