#include <stdio.h>

int main()
{
	int n_round, i;
	scanf("%d", &n_round);
	
	for(i=0; i < n_round; ++i)
	{	
		long long score_1, score_2, sum, dif; 
		scanf("%lld%lld", &sum, &dif);
		
		score_1 = (sum+dif)/2;
		score_2 = (sum-dif)/2;
		
		if(score_1 < score_2)
			score_1^=score_2^=score_1^=score_2;		

		if(score_2 < 0 || score_1+score_2 != sum || score_1-score_2 != dif)
		{
			printf("impossible\n");
			continue;
		}

		printf("%lld %lld\n", score_1, score_2);
	}
	return 0;
}