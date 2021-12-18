#include <iostream>
//Gleaming the Cubes

using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n;

	while(cin >> n && n)
	{
		int x, y, z, dis;
		int x_r[2], y_r[2], z_r[2]; // the range of x, y and z. 

		cin >> x_r[0] >> y_r[0] >> z_r[0] >> dis;
		x_r[1] = x_r[0]+dis, y_r[1] = y_r[0]+dis, z_r[1] = z_r[0]+dis;
		n--;

		while(n--)
		{
			cin >> x >> y >> z >> dis;

			if(x > x_r[0]) x_r[0] = x;
			if(y > y_r[0]) y_r[0] = y;
			if(z > z_r[0]) z_r[0] = z;
			if(x + dis < x_r[1]) x_r[1] = x + dis;
			if(y + dis < y_r[1]) y_r[1] = y + dis;
			if(z + dis < z_r[1]) z_r[1] = z + dis;
		}
		x = x_r[1] - x_r[0];
		y = y_r[1] - y_r[0];
		z = z_r[1] - z_r[0];

		if(x < 0 || y < 0 || z < 0) cout << 0 << endl;
		else                        cout << x * y * z << endl;
	}
	
	return 0;
}
