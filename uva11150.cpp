#include <iostream>
//Cola

using namespace std;

int main()
{
	int num;
	// the most numbers of returned cola is n/2
	while(cin >> num)
		cout << num+num/2 << endl;

	return 0;
}