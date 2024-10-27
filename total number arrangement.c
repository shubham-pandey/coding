#include <stdio.h>
int i = 0;
int calc(int n){
    n = n/10;
    i += 1;
    if(n==0){
        return i;
    }
    calc(n);
    return 0;
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    calc(n);
    printf("%d\n",i);
    int j=1;
    int fact=1;
    for(j=i;j>=1;j--){
        fact = fact *j;
        
    }
    printf("Total number of ways : %d", fact);
}
