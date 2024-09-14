#include<stdio.h>
int main()
{
  int a[6]={};
  printf("Enter array of 5 elements : ");
 for(int i=0;i<5;i++) //taking input
 {
  scanf("%d", &a[i]);
 }
  printf("\nEnter the element which you want to insert : ");
  int ele;
  scanf("%d", &ele);
  printf("\nEnter position : ");
  int pos;
  scanf("%d",&pos);
  
int b[6]={};  //copying element to new array
for (int i = 0; i < 5; i++) {
    b[i] = a[i];
}

  b[pos-1] = ele; //inserting 
  for(int i=pos;i<6;i++)
  {
    b[i] = a[i-1];
  }
  printf("\nArray after insertion: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", b[i]);
    }
}