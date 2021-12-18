#include <stdio.h>
#define MAX 102
/*Largest Square*/

char square[MAX][MAX];

int largest_square(int r, int c, int row, int col, int size, char ch);

int main()
{
	int n_case, i;
	scanf("%d", &n_case);

	for(i=0; i < n_case; ++i)
	{
		int row, col, size, q, j, r, c;
		scanf("%d%d%d", &row, &col, &q);
		printf("%d %d %d\n", row, col, q);
		getchar(); /*go to next line*/
		
		for(j=0; j < row; ++j)
			fgets(square[j], MAX, stdin);

		for(j=0; j < q; ++j)
		{
			scanf("%d%d", &r, &c);
			/*calculate largest square number by the function*/
			for(size=3; largest_square(r-size/2, c-size/2, row, col, size, square[r][c]); size += 2)
				;
			
			printf("%d\n", size-2);
		}
	}
	return 0;
}
int largest_square(int r, int c, int row, int col, int size, char ch)
{	
	int i, j;
	/*form (r-1, c-1) use double loop to check whether all character is same*/
	for(i=0; i < size; ++i)
		for(j=0; j < size; ++j)
			if((r+i) == row || (c+j) == col)
				return 0;
			else if(square[r+i][c+j] != ch)
				return 0;
	
	return 1;
}