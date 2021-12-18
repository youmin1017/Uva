#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//Bangla Numbers

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	string num;

	for(int i=1; cin >> num; ++i)
	{
		vector<int> ans(8, 0);
		vector<string> bangla = {" lakh", " hajar", " shata", " kuti"};

		cout << setw(4) << i << '.';
		if(num == "0")
		{	
			cout << " 0\n";
			continue;
		}

		int len = num.size(), x;

		if(len == 15)
		{
			cout << ' ' << num[0] << bangla[3];
			num.erase(num.begin());
		}
		if(len > 7)
		{
			num.insert(num.end()-7, ' ');
			x = stoi(num);
			ans[3] = x%100, x /= 100;
			ans[2] = x%10, x /= 10;
			ans[1] = x%100, x /= 100;
			ans[0] = x;
			num.erase(num.begin(), num.end()-7);
			for(int j=0; j < 3; ++j)
				if(ans[j]) cout << ' ' << ans[j] << bangla[j];
			if(ans[3]) cout << ' ' << ans[3];
			cout << bangla[3]; 
		}
		x = stoi(num);
		ans[7] = x%100, x /= 100;
		ans[6] = x%10, x /= 10;
		ans[5] = x%100, x /= 100;
		ans[4] = x;
		for(int j=4; j < 7; ++j)
			if(ans[j]) cout << ' ' << ans[j] << bangla[j-4];
		if(ans[7]) cout << ' ' << ans[7];
		cout << endl;
	}
	return 0;
}