#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float x,n;
    printf("Enter x: ");
    scanf("%f", &x);
    printf("Enter n: ");
    scanf("%f", &n);
    float y=pow((x-1)/x,2);
    float z=(x-1)/x;
    for(float i=3;i<n;i++){
        y = y + pow(z,i);
    } 
    float sum = (x-1)/x + 0.5*y;
    printf("sum = %f", sum);
}
