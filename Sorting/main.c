#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
     FILE *fp;
     long int n,r,t=0,i;
     long int *arr;
     printf("\nEnter a number:");
     scanf("%ld",&n);
     arr= (long int*)malloc(n*sizeof(long int));
     for(int i=0;i<n;i++){
        arr[i]=t;
        t++;
     }

     srand( time(NULL) );

     for(i=n;i>0;i--){
        r=rand()%n;
        t=arr[i-1];
        arr[i-1]=arr[r];
        arr[r]=t;
     }
     fp=fopen("input.txt","w");
   // printf("\n%d. %ld", i+1,arr[i]);
     for(int i = 0; i <n; ++i)
   {
      fprintf(fp,"%ld ",arr[i]);
   }

     fclose(fp);
     return 0;
}
