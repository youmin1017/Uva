#include <iostream>
#include <vector>

bool bound_check(int x, int y, int& dx, int& dy)
{
	return (x < 0 || y < 0 || x >= dx || y >= dy) ? false : true;
}

int shop_num(std::vector< std::vector<int> >& city, int& px, int& py, int& dx, int& dy, int& willing_dis);

int main()
{
	int dx, dy, n, q, x, y, willing_dis;

	for(int i=1; std::cin >> dx >> dy >> n >> q && q; ++i)
	{
		std::vector<int> row(dy, 0);
		std::vector< std::vector<int> > city(dx, row);

		for(int j=0; j < n; ++j)
		{
			std::cin >> x >> y;
			city[x-1][y-1] = 1;
		}
		
		std::cout << "Case " << i << ':' << std::endl;
		for(int j=0; j < q; ++j)
		{
			int valuable = 0, ans_x = dx, ans_y = dy, nums;
			std::cin >> willing_dis;
			
			for(int px=0; px < dx; ++px)
			{
				for(int py=0; py < dy; ++py)
				{
					nums = shop_num(city, px, py, dx, dy, willing_dis);

					if(nums > valuable || (nums == valuable && py < ans_y))
					{
						valuable = nums;
						ans_x = px;
						ans_y = py;
					}
				}
			}
			std::cout << valuable << " (" << ans_x+1 << ',' << ans_y+1 << ')' << std::endl;
		}
	}
}

int shop_num(std::vector< std::vector<int> >& city, int& px, int& py, int& dx, int& dy, int& willing_dis)
{
	int nums = 0;

	for(int i=0; i < 2*willing_dis+1; ++i)
	{
		if( bound_check(px, py - willing_dis + i, dx, dy) ) if(city[px][ py - willing_dis + i]) nums++;
	}

	for(int i=1; i <= willing_dis; ++i)
	{
		for(int j=0; j < 2*willing_dis - 2*i+1; ++j)
		{
			if( bound_check(px-i, py - willing_dis + i + j, dx, dy) ) if(city[px-i][ py - willing_dis + i + j]) nums++;
			if( bound_check(px+i, py - willing_dis + i + j, dx, dy) ) if(city[px+i][ py - willing_dis + i + j]) nums++;
		}
	}

	return nums;
}
