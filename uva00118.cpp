#include <iostream>
#include <string>
#include <set>
#include <map>
//Mutant Flatworld Explorers

using namespace std;

typedef struct{ int x, y;} Point;

bool operator<(const Point &a, const Point &b)
{
	if(a.x == b.x) return a.y < b.y;
	else           return a.x < b.x;
}

int main()
{
	int x_boundary, y_boundary, x_init, y_init;
	char direction;
	string command;
	set<Point> lost;
	map<char, Point> move
	{
		{ 'N', { 1, 0} },
		{ 'W', { 0,-1} },
		{ 'E', { 0, 1} },
		{ 'S', {-1, 0} },
	};

	cin >> y_boundary >> x_boundary;

	while(cin >> y_init >> x_init >> direction >> command)
	{
		bool result = true;

		for(char ch: command)
		{
			if(ch == 'R')
			{
				if     (direction == 'N') direction = 'E';
				else if(direction == 'E') direction = 'S';
				else if(direction == 'S') direction = 'W';
				else                      direction = 'N';
			}
			else if(ch == 'L')
			{
				if     (direction == 'N') direction = 'W';
				else if(direction == 'E') direction = 'N';
				else if(direction == 'S') direction = 'E';
				else                      direction = 'S';
			}
			else if(lost.count({x_init, y_init}))
			{
				x_init += move[direction].x;
				y_init += move[direction].y;
				if(x_init < 0 || y_init < 0 || x_init > x_boundary || y_init > y_boundary)
				{
					x_init -= move[direction].x;
					y_init -= move[direction].y;
				}
			}
			else
			{
				x_init += move[direction].x;
				y_init += move[direction].y;
				if(x_init < 0 || y_init < 0 || x_init > x_boundary || y_init > y_boundary)
				{
					x_init -= move[direction].x;
					y_init -= move[direction].y;
					result = false;
					lost.insert({x_init, y_init});
					break;
				}
			}
		}
		cout << y_init << ' ' << x_init << ' ' << direction;
		cout << (result? "\n":" LOST\n");
	}
	
	return 0;
}
//(E)
// X FXXK
// | IS NOT 
// | LIKE
// | COMMANSENCE
// +--------Y(N)










