#include <iostream>
#include <queue>
#include <string>
//Knight Moves

using namespace std;

struct Point { int x, y; };

int bfs(queue<Point>& q, Point target);

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	Point start, target;
	string input_1, input_2;

	while(cin >> input_1 >> input_2)
	{
		if(input_1 == input_2)
		{
			cout << "To get from " << input_1 << " to " << input_2 << " takes 0 knight moves.\n";
			continue;
		}

		start.x = input_1[0] - 'a', start.y = input_1[1] - '1';
		target.x = input_2[0] - 'a', target.y = input_2[1] - '1';

		queue<Point> q;
		q.push(start);

		cout << "To get from " << input_1 << " to " << input_2 << " takes " << bfs(q, target) << " knight moves.\n";

	}

	return 0;
}

int bfs(queue<Point>& q, Point target)
{
	const int move_x[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	const int move_y[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int length = 1;
	Point a;
	q.push({-1, -1}); // every (-1, -1) is representd of one layer.

	while(!q.empty())
	{	
		if(q.front().x == -1)
		{
			++length;
			q.push({-1, -1});
			q.pop();
		}

		for(int i = 0; i < 8; ++i)
		{
			a = q.front();
			a.x += move_x[i];
			a.y += move_y[i];

			if(a.x >= 0 && a.x < 8 && a.y >= 0 && a.y < 8)
			{	
				if(a.x == target.x && a.y == target.y)
					return length;

				q.push(a);
			}
		}
		q.pop();
	}
	return 0;
}