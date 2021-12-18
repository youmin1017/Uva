#include <iostream>
#include <vector>
//Cheapest Base

using namespace std;

typedef struct 
{
	int b, p;
} b_p; // record the base and it's price

vector<int> costs; //save every price
vector<b_p> cheapest; //using vector to record the minimum base price

void cheapest_base(int num, int base);

int main()
{
	int n_case;
	cin >> n_case; //input times of round

	for(int i=1; i <= n_case; ++i)
	{
		int num, n_test;

		for(int j=0; j < 36; ++j)
		{
			cin >> num; // input the price
			costs.push_back(num);
		}

		cout << "Case " << i << ":" << endl; 
		cin >> n_test; // input the numbers of number 

		for(int j=0; j < n_test; ++j)
		{
			cin >> num; // input the number
			// from base 2 to base 36 using function to save the cheapest base price
			for(int base=2; base <= 36; ++base)
				cheapest_base(num, base);

			cout << "Cheapest base(s) for number " << num << ":";
			// output all of the cheapest base
			for(b_p x: cheapest)
				cout << " " <<x.b;

			cout << endl;
			// clear all
			cheapest.clear();
			costs.clear();
		}
		// last line do not need end line
		if(i != n_case) cout << endl;
	}

	return 0;
}
void cheapest_base(int num, int base)
{
	b_p base_sum={base, 0};
	// to convert decimal to any outher base
	while(num)
	{	
		base_sum.p += costs[num%base]; // add all cost to the sum
		num /= base;
	}
	// if vector is empty, put the base and price to the first
	if(cheapest.empty())
		cheapest.push_back(base_sum);
	// if the price is same, put the base and price to the second, an so on 
	else if(base_sum.p == cheapest[0].p)
		cheapest.push_back(base_sum);
	// if the price is cheaper than before, clear all and put it to the first
	else if(base_sum.p  < cheapest[0].p) 
	{
		cheapest.clear();
		cheapest.push_back(base_sum);
	}
}
