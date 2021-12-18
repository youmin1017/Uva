#include <iostream>
#include <vector>
//Divide, But Not Quite Conquer!

using namespace std;

int main()
{
	int n, m;
	vector<int> num;

	while(cin >> n >> m)
	{
		bool result = true;
		num.push_back(n);

		if(n == 0 || m == 0 || n== 1 || m == 1) result = false, n = 1;

		while(n != 1)
		{
			if(n%m)
			{
				result = false;
				break;
			}
			n /= m;
			num.push_back(n);
		}

		if(result)
		{
			for(int i=0; i < num.size()-1; ++i)
				cout << num[i] << ' ';
			cout << 1 << endl;
		}
		else
			cout << "Boring!" << endl;
		num.clear();
	}
	return 0;
}