#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//Tell me the frequencies!

using namespace std;

typedef  struct {int ascii, count;} Record;

bool cmp(Record x, Record y)
{
	if(x.count == y.count) return x.ascii > y.ascii;
	else                   return x.count < y.count;
}

int main()
{	
	int i=0;
	vector<Record> num(97);
	string test;

	while(getline(cin, test))
	{
		if(i) cout << endl;
		++i;

		for(char ch: test)
			num[ch-32].ascii = ch, num[ch-32].count++;

		sort(num.begin(), num.end(), cmp);

		for(auto x: num)
			if(x.ascii) cout << x.ascii << " " << x.count << endl;		
	
		num.clear();
		num.resize(97);
	}
	return 0;
}