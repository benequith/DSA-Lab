#include <stdio.h>
#include <stdlib.h>

int fact(int i);
float add(float a, float b);
int main()
{
   float fac,sum=0;
   int n;
   printf("\nEnter the number of integers:");
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
    fac=fact(i);
    sum=add(sum,fac);
    fac=1;
   }
    printf("The sum of series is:%.2f",sum);
    return 0;
}
