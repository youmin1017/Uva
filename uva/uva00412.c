#include<stdio.h>
#include<math.h>
/*Pi*/
int gcd(int m,int n){
    int t = 1;
    while(t != 0){
        t=m%n;
        m=n;
        n=t;
    }
    return m;
}

int main(){
    int a[500];
    int ans=0,n,count=0;
    double x;
    int i,j;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        for(i=0; i < n; i++)
            scanf("%d", &a[i]);
        for(i=0; i < n-1; i++)
            for(j=i+1; j < n; j++)
                if(gcd(a[i],a[j]) == 1) count++;
        if(count == 0){
            printf("No estimate for this data set.\n");
            continue;
        }
        x = sqrt(3.0*(n-1)*n/count);
        printf("%1.6f\n", x);
        count = 0;
    }
    return 0;
}
