#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    if(n<4 && n>1){
        printf("Prime number\n");
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            printf("not a prime number\n");
            return 0;
        }    
    }
    printf("Its a prime number\n");
}
