#include <iostream>
#include <istream>
#include <vector>
#include <set>
//Coffee Central

bool bound_check(int x, int y, int& dx, int& dy)
{
	return (x < 0 || y < 0 || x >= dx || y >= dy) ? false : true;
}

class Point{
public:
	int x;
	int y;
};

inline bool operator<(const Point& p1, const Point& p2)
{
	if(p1.x == p2.x) return p1.y < p2.y;
	else             return p1.x < p2.x;
}

void number_of_shop(std::vector< std::vector<int> >& city, int px, int py, int steps, int& dx, int& dy, int& willing_dis);

// Global varible
int nums;
std::set<Point> repeat;

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
			int valuable = 0, ans_x = dx, ans_y = dy;
			std::cin >> willing_dis;
			
			for(int px=0; px < dx; ++px)
			{
				for(int py=0; py < dy; ++py)
				{
					nums = 0;
					repeat.clear();

					number_of_shop(city, px, py, 0, dx, dy, willing_dis);

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

	return 0;
}

void number_of_shop(std::vector< std::vector<int> >& city, int px, int py, int steps, int& dx, int& dy, int& willing_dis)
{
	Point p = {px, py};	
	if(city[px][py] && !repeat.count(p)) nums++;
	repeat.insert(p);
	
	if( bound_check(px-1, py, dx, dy) && steps < willing_dis) number_of_shop(city, px-1, py, steps+1, dx, dy, willing_dis);
	if( bound_check(px, py-1, dx, dy) && steps < willing_dis) number_of_shop(city, px, py-1, steps+1, dx, dy, willing_dis);
	if( bound_check(px+1, py, dx, dy) && steps < willing_dis) number_of_shop(city, px+1, py, steps+1, dx, dy, willing_dis);
	if( bound_check(px, py+1, dx, dy) && steps < willing_dis) number_of_shop(city, px, py+1, steps+1, dx, dy, willing_dis);

}
