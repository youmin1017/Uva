#include <iostream>
#include <vector>
#include <numeric>

int row_check(std::vector< std::vector<int> >& matrix, int n);
int col_check(std::vector< std::vector<int> >& matrix, int n);

int main(int argc, char const *argv[])
{
	int n;

	while(std::cin >> n && n)
	{
		int row_po, col_po;
		std::vector<int> row(n);
		std::vector< std::vector<int> > matrix;	
		matrix.clear();
		matrix.reserve(n);

		for(int i=0; i < n; ++i)
		{
			for(int j=0; j < n; ++j)
				std::cin >> row[j];
		
			matrix.emplace_back(row);
		}

		row_po = row_check(matrix, n);
		col_po = col_check(matrix, n);
		
		if(row_po == 0 && col_po ==0)
			std::cout << "OK\n";
		else if(row_po > 0 && col_po > 0)
			std::cout << "Change bit (" << row_po << ',' << col_po << ")\n";
		else
			std::cout << "Corrupt" << std::endl;
	}

	return 0;
}

int row_check(std::vector< std::vector<int> >& matrix, int n)
{
	int odd_row = 0;
	int sum;
	for(int i=0; i < n; ++i)
	{
		sum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0); 
		if(sum&1)
		{
			if(odd_row)
				return -1;
			
			odd_row = i+1;
		}
	}

	return odd_row;
}

int col_check(std::vector< std::vector<int> >& matrix, int n)
{
	int odd_col = 0;
	for(int i=0; i < n; ++i)
	{
		int sum =0;
		for(int j=0; j < n; ++j)
		{
			sum += matrix[j][i];
		}
		if(sum&1)
		{
			if(odd_col)
				return -1;

			odd_col = i+1;
		}
	}

	return odd_col;
}






