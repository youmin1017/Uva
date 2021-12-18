#include <stdio.h>
/*Can You Solve It?*/

int solve(long long point[]);

int main()
{
	int i, n_case;
	scanf("%d", &n_case);

	for(i=1; i <= n_case; ++i)
	{
		long long count, point_a[2], point_b[2];
		scanf("%lld%lld%lld%lld", &point_a[0], &point_a[1], &point_b[0], &point_b[1]);

		for(count=0; solve(point_a); --count)
			;

		for(  ; solve(point_b); ++count)
			;

		count += (point_b[0]-point_a[0])*(point_b[0]+point_a[0]+1)/2;

		if(point_a[0] == 0 && point_a[1] == 0)
			++count;

		printf("Case %d: %lld\n", i, count);	
	}
	return 0;
}

int solve(long long point[])
{
	if(point[1] != 0)
	{
		if(point[1] == 1)
		{
			point[0] += 1;
			point[1]  = 0;
			return 1;
		}
		else
		{
			point[0] += 1;
			point[1] -= 1;
			return 1;
		}
	}
	
	return 0;
}