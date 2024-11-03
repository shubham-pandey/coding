#include<stdio.h>
int calc(int x, int y){
    int pow = 1;
    for(int i=1;i<=y;i++){
    pow = pow*x;
   }
   return pow;
}
int main(){
   int x,y;
   printf("Enter a number : ");
   scanf("%d", &x);
   printf("Enter the power to calculate : ");
   scanf("%d", &y);
   printf("powered value = %d\n", calc(x,y));
}
