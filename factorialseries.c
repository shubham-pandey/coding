#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
float calc(float n){
    float fact = 1;
    for(float i=1;i<=n;i++)
    {
       fact =  fact*i; 
    }
    return fact;
}
int main()
{
    float n;
    float sum=0;
    printf("Enter n: ");
    scanf("%f", &n);
    for(float i=1;i<=n;i++){
    
      sum = sum + i/(calc(i));  
    }
    printf("Sum upto %f = %f", n, sum);
}
