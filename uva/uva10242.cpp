#include <iostream>
#include <cstdio>
#include <vector>
// Fourth Point!!

using namespace std;

int main()
{
	int record;
	vector<double> row(2, 0);
	vector< vector<double> > co(4, row); // 2 dimension vector
	// get tests data
	while(cin >> co[0][0] >> co[0][1] >> co[1][0] >> co[1][1]
			  >> co[2][0] >> co[2][1] >> co[3][0] >> co[3][1])
	{
		double x=0, y=0;
		// seek the same point
		for(int i=0; i < 4; ++i)
		{
			for(int j=i+1; j < 4; ++j)
			{
				if(co[i][0] == co[j][0] && co[i][1] == co[j][1])
					record = j;
			}
		}
		// x and y are the sum of points 
		for(int i=0; i < 4; ++i)
		{
			x += co[i][0];
			y += co[i][1];
		}
		// find the forth point
		x -= 3*co[record][0];
		y -= 3*co[record][1];

		printf("%.3f %.3f\n", x, y);
	}

	return 0;
}
