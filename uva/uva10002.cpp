#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>
#include <algorithm>
//Center of Masses

using namespace std;

typedef struct { double x, y; } Point;
vector<Point> p(100);

double distance(const Point& p0, const Point& p)
{
	return (p.x-p0.x) * (p.x-p0.x) + (p.y-p0.y) * (p.y-p0.y);
}
double cross(const Point& p0, const Point& p1, const Point& p2)
{
	return (p1.x-p0.x) * (p2.y-p0.y) - (p2.x-p0.x) * (p1.y-p0.y);
}
bool angle_cmp(const Point& p1, const Point& p2)
{
	double x = cross(p[0], p1, p2);
	if(x == 0 && p1.x == p2.x) return distance(p[0], p1) < distance(p[0], p2);
	if(x == 0 && p1.y == p2.y) return distance(p[0], p1) > distance(p[0], p2);	
	return x < 0;
}

int main()
{
	cin.sync_with_stdio(false), cin.tie(0);
	int n;

	while(cin >> n && n > 2)
	{
		p.resize(n);
		double g_x=0, g_y=0, area, area_sum=0;

		for(int i=0; i < n; ++i)
		{	
			cin >> p[i].x >> p[i].y;
			if(p[i].x < p[0].x)                          swap(p[0], p[i]);
			else if(p[i].x == p[0].x && p[i].y < p[0].y) swap(p[0], p[i]);
		}

		sort(p.begin()+1, p.end(), angle_cmp);

		p.push_back(p[0]);

		for(int i=0; i < n; ++i)
		{
			area = p[i].x * p[i+1].y - p[i+1].x * p[i].y;
			if(area == 0) continue;
			g_x += ( p[i].x + p[i+1].x ) * area ;
			g_y += ( p[i].y + p[i+1].y ) * area ;
			area_sum += area;
		}

		cout << setiosflags(ios::fixed) << setprecision(3) << g_x / (area_sum * 3.0) + 0.0 << ' ';
		cout << setiosflags(ios::fixed) << setprecision(3) << g_y / (area_sum * 3.0) + 0.0 << endl;

	}
	
	return 0;
}