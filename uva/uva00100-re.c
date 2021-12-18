#include <stdio.h>
/*3n+1*/
void math(int n,int *MAX){
    int count = 1;
    while(n-1){
        if(n&1) n = 3*n+1;
        else    n /= 2;
        ++count;
    }
    if(count > *MAX) *MAX = count;
}
int main(){
    int a,b,i,MAX=1;
    while(scanf("%d%d", &a,&b) == 2){
        printf("%d %d ", a,b);
        if(a > b) a^=b^=a^=b;
        for(i=a; i <= b; ++i)
            math(i,&MAX);
        printf("%d\n", MAX);
        MAX=1;
    }
    return 0;
}