#include <iostream>
#include <string>
#include <vector>
//Primary Arithmetic

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	string a, b;

	while(cin >> a >> b)
	{
		if(a=="0" && b =="0")
			break;
		
		int count = 0;
		vector<int> sum;

		if(a.size() < b.size()) a.swap(b);

		for(auto x: a)
			sum.push_back(x-'0');
		for(int i=b.size()-1; i >= 0; --i)
			sum[a.size()-b.size()+i] += b[i]-'0';
		
		for(int i=sum.size()-1; i >= 1; --i)
			if(sum[i] >= 10) ++count, ++sum[i-1];
		if(sum[0] >= 10) ++count;

		if(count) cout << count << " carry operation" << (count>1? "s.\n" : ".\n");
		else      cout << "No carry operation.\n";
	}
	
	return 0;
}