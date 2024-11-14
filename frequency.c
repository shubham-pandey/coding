#include<stdio.h>
#include<string.h>
int main(){
    char arr[50]={}; char number[10]={'0','1','2','3','4','5','6','7','8','9'}; 
    int freq[10];
    for(int i=0;i<10;i++){
        freq[i]=0;
    }
    for(int i=0;i<50;i++){
        arr[i]=0;
    }
    fgets(arr, 49, stdin);
    for(int i=0;i<10;i++){
        for(int j=0; j<strlen(arr); /*arr[j]!='\0' && arr[j]!='\n'*/j++){
          if(arr[j]-number[i]==0){
            freq[i]++;
          }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",freq[i]);
    }
}
/*code by chat got
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int digit_count[10] = {0};

    // Read a line of input (up to 999 characters)
    fgets(str, sizeof(str), stdin);

    // Count each digit in the input
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            digit_count[str[i] - '0']++;
        }
    }

    // Print the count of each digit from 0 to 9
    for (int i = 0; i < 10; i++) {
        printf("%d ", digit_count[i]);
    }
    
    return 0;
}
*/



