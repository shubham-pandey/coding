#include<stdio.h>
#include<string.h>
double hash(char s[100]){
    s[strcspn(s, "\n")] = '\0';
    int x=strlen(s);
    double prod=1;
    double sum=0;
    for(int i=0;i<x;i++){
        prod = prod*(int)s[i];
        sum=sum+(int)s[i];
    }
    return prod/sum;
}
int main(){
  char pass[100];
  fgets(pass,99,stdin);
  if(hash(pass)==202675733318.709686){
    printf("Success\n");
  }
  else{
    printf("Try again\n");
  }
}
