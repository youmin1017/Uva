#include <iostream>
#include <algorithm>
#include <vector>
//Symmetric Matrix

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	long n, size, num; //times of test, matrix size
	char ch[2];
	
	cin >> n;

	for(int i=1; i <= n; ++i)
	{
		cin >> ch >> ch;
		cin >> size;
		bool b = true;
		vector<long> vec_1(size*size), vec_2(size*size);

		for(int j=0; j < size*size; ++j)
			cin >> vec_1[j];

		vec_2 = vec_1;
		reverse(vec_2.begin(), vec_2.end());

		if(vec_1 == vec_2)
		{
			for(auto x: vec_1)
				if(x < 0) 
				{	
					b = false ;
					break;
				} 
		}
		else b = false;

		if(b) cout << "Test #" << i << ": Symmetric." << endl;
		else  cout << "Test #" << i << ": Non-symmetric." << endl;
	}
	return 0;
}