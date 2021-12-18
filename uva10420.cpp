#include <iostream>
#include <map>
#include <string>
//List of Conquests

using namespace std;

int main()
{
	int n;
	map<string, int> countries;
	string country;

	cin >> n;

	while(n--)
	{
		cin >> country;
		countries[country]++;
		getline(cin, country);
	}

	for(auto x: countries)
		cout << x.first << ' ' << x.second << endl;
	
	return 0;
}