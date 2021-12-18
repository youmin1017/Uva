#include <iostream>
#include <vector>
//Parity

using namespace std;

int main()
{
	int num;
	vector<int> binary;
	// get the test data and check whether num is 0
	while(cin >> num && num)
	{
		int count=0;

		while(num)
		{	//insert binary number from begin, using insert on account of start from tail.
			binary.insert(binary.begin(), num&1);
			count += num&1;
			num >>= 1;
		}
		// output ans
		cout << "The parity of ";

		for(int x: binary)
			cout << x;

		cout << " is " << count << " (mod 2)." << endl;

		binary.clear();

	}
	
	return 0;
}