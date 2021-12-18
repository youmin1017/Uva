#include <stdio.h>
#define MAX 1000000
/*498-bis*/

int coe[MAX];

int main()
{
    int x, i, count, total;

    while(scanf("%d", &x) == 1)
    {
        for(count = 0;  scanf("%d", coe+(count++) ) && (getchar() != '\n');  )
            ; 

        total = coe[0]*(count-1);
        
        for(i=1; i < count-1; ++i)
        	total = total*x+coe[i]*(count-1-i);
        
        printf("%d\n", total);
    }
    return 0;
}