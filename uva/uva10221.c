#include <stdio.h>
#include <string.h>
#include <math.h>
#define EARTH_RADIUS 6440
#define PI 3.14159265358979323846
/*Satellites*/

int main()
{
	int temp;
	double a, s, arc_distance, chord_distance;
	char *string = "min";
	char str[4];

	while(scanf("%lf%lf%s", &s, &a, str) == 3)
	{
		if(strcmp(str, string) == 0)
			a /= 60; /*convert minutes to degree*/
		/*a %= 360 since angle a is double, can't use mod straightly*/
		temp = a;
		a -= temp;
		temp %= 360;
		a += temp;
		a = (a > 180) ? 360-a : a; /*if a > 180 a = 360-a*/

		/*use cosine formula to calculate chord distance, arc distance omit description*/
		chord_distance = (EARTH_RADIUS+s)*cos((90.0-a/2.0)/180.0*PI)*2.0;
		arc_distance   = (EARTH_RADIUS+s)*2*PI*(a/360);

		printf("%.6lf %.6lf\n", arc_distance, chord_distance);
	}
	return 0;
}