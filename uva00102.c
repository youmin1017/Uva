#include<stdio.h>
/*Ecological Bin Packing*/
int main(){

   int b1,g1,c1,b2,g2,c2,b3,g3,c3;
   int steps[6],total,min;
   while(scanf("%d%d%d%d%d%d%d%d%d", &b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) == 9){
      total = b1+b2+b3+g1+g2+g3+c1+c2+c3;
      steps[0] = total-b1-c2-g3; //BCG
      steps[1] = total-b1-g2-c3; //BGC
      steps[2] = total-c1-b2-g3; //CBG
      steps[3] = total-c1-g2-b3; //CGB
      steps[4] = total-g1-b2-c3; //GBC
      steps[5] = total-g1-c2-b3; //GCB

      min = steps[0];
      for(int i = 1; i <= 6; i++){
         if(steps[i] < min)
            min = steps[i];
      }
      if(min == steps[0])
         printf("BCG %d\n", min);
      else if(min == steps[1])
         printf("BGC %d\n", min);
      else if(min == steps[2])
         printf("CBG %d\n", min);
      else if(min == steps[3])
         printf("CGB %d\n", min);
      else if(min == steps[4])
         printf("GBC %d\n", min);
      else
         printf("GCB %d\n", min);
   }
   return 0;
}
