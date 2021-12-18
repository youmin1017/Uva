#include <algorithm>
#include <iostream>
#include <vector>
//Error Correction

int main()
{
	int n;

	while(std::cin >> n && n)
	{
		int x, odd_row, odd_col;
		auto f = [](int sum){ return sum&1; };
		std::vector<int> row_sum(n,0);
		std::vector<int> col_sum(n,0);

		for(int i=0; i < n; ++i)
		{
			for(int j=0; j < n; ++j)
			{
				std::cin >> x;
				row_sum[i] += x;
				col_sum[j] += x;
			}
		}

		odd_row = std::count_if(row_sum.begin(), row_sum.end(), f);	
		odd_col = std::count_if(col_sum.begin(), col_sum.end(), f);

		if(odd_col == 0 && odd_row == 0) std::cout << "OK" << std::endl;
		else if(odd_col == 1 && odd_row == 1) 
		{
			int po_row = std::find_if(row_sum.begin(), row_sum.end(), f) - row_sum.begin();
			int po_col = std::find_if(col_sum.begin(), col_sum.end(), f) - col_sum.begin();

			std::cout << "Change bit (" << po_row + 1 << ',' << po_col + 1 << ')' << std::endl;
		}
		else std::cout << "Corrupt" << std::endl;
	}	

	return 0;
}