#include<stdio.h>
/*3n+1*/
int main(){
   int i, j, k = 0, a = 1, b, c;
   while(scanf("%d%d", &i, &j) != EOF){
      printf("%d ", i);
      printf("%d ", j);
      if(i > j){
         c = i;
         i = j;
         j = c;
      }
      for(i; i <= j; i++){
         b = i;
         while(i != 1){
            if(i%2 == 0)
               i = i/2;
            else
               i = 3*i+1;
            a += 1;
         }
         i = b;
         if(a >= k)
            k = a;
         a = 1;
      }
      printf("%d\n", k);
      k = 0;
   }
   return 0;
}
