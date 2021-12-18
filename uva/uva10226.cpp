#include <iostream>
#include <string>
#include <map>
#include <iomanip>
//Hardwood Species

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	int n_cases, total;
	string name;
	map<string, double> species;

	cin >> n_cases >> ws;

	while(n_cases--)
	{	
		for(total=0; true; ++total)
		{
			getline(cin, name);
			if(name == "")
				break;
			
			species[name]++;
		}

		for(auto &x: species)
			cout << fixed << setprecision(4) << x.first << ' ' << 100.0*x.second/total << endl;

		species.clear();
		if(n_cases) cout << endl;
	}
	return 0;
}