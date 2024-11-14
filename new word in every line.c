#include<stdio.h>
#include<string.h>
int main(){
    char arr[1000];
    fgets(arr,999,stdin);
    for(int i=0;/*i<1000*/arr[i] != 0;i++){
        if(arr[i] == 32){
        printf("\n");
        continue;
        }
        printf("%c", arr[i]);
    }
}
