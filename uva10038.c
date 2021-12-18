#include <stdio.h>
#include <stdlib.h>
#define MAX 3000
/*Jolly Jumpers*/
int main(){
    int i, n, t, num_arr[MAX], temp[MAX]={0};
    while(scanf("%d", &n) == 1){
        for(i=0; i < n; ++i){
            scanf("%d", &num_arr[i]);
        }
        if(n == 1){
            printf("Jolly\n");
            continue;
        }
        for(i=0; i < n-1; ++i){
            t = abs(num_arr[i]-num_arr[i+1]);
            temp[t] = t;
            if(t >= n){
                printf("Not jolly\n");
                break;
            }
        }
        if(t >= n) continue;
        for(i=1; i < n; ++i){
            if(temp[i] != i){
                printf("Not jolly\n");
                break;
            }
        }
        if(i == n) printf("Jolly\n");
        for(i=0; i < n; ++i) temp[i] = 0;
    }
    return 0;
}
