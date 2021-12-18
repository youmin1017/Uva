#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
// Recycling

using namespace std;

int main(int argc, char const *argv[])
{
	while(cin.peek() != '#')
	{
		int num = 0, changes;
		vector< map<char, char> > citys;
		vector<int> change_record;
		map<char, char> city;
		string str;

		while(cin.peek() != 'e')
		{
			num++;
			getline(cin, str);
			city[ str[0] ] = str[2];
			city[ str[4] ] = str[6];
			city[ str[8] ] = str[10];
			city[ str[12]] = str[14];
			city[ str[16]] = str[18];
			citys.push_back(city);		
		}

		for(int i=0; i < num; ++i)
		{
			changes = 0;

			for(int j=0; j < num; ++j)
			{
				if( i == j ) continue;
				if(citys[i]['r'] != citys[j]['r']) changes++;
				if(citys[i]['o'] != citys[j]['o']) changes++;
				if(citys[i]['y'] != citys[j]['y']) changes++;
				if(citys[i]['g'] != citys[j]['g']) changes++;
				if(citys[i]['b'] != citys[j]['b']) changes++;
			}
			change_record.push_back(changes);
		}
		cout << min_element(change_record.begin(), change_record.end()) - change_record.begin() +1 << endl;
		getline(cin, str);
	}

	return 0;
}
