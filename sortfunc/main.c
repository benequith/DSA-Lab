#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(long int *arr,long int n);
void mbubble(long int *arr,long int n);
void cocktail(long int *arr,long int n);
void selection(long int *arr,long int n);
void quick(long int *arr,long int low,long int high);
long int *create(long int *arr,long int n);
void display(long int *arr, long int n);
void createdata(long int n);

int main()
{
    long int n;
    int ch;
    long int *arr;
    clock_t start, end;
    double time_taken;


    printf("\nEnter a number:");
    scanf("%ld",&n);
    createdata(n);
    printf("\nDataset created");
    arr = (long int*)malloc(n* sizeof(long int));
    printf("\nCreating array and reading from file");


    do{
            arr=create(arr,n);
            printf("\n1. Bubble Sort\n2. Modified Bubble Sort\n3. Cocktail Shaker Sort\n4. Selection Sort\n5. Quick Sort\n6. To change input size\n7. Exit\nEnter your choice:");
            scanf("%d",&ch);
            start = clock();
            switch(ch){

                case 1: bubble(arr,n);
                        break;

                case 2: mbubble(arr,n);
                        break;

                case 3: cocktail(arr,n);
                        break;

                case 4: selection(arr,n);
                        break;

                case 5: quick(arr,0,n-1);
                        break;

                case 6: free(arr);
                        printf("\nEnter a number:");
                        scanf("%ld",&n);
                        arr = (long int*)malloc(n* sizeof(long int));
                        break;
                default: printf("\nWrong choice");
            }
            end= clock();
             time_taken= ((double)(end-start))/ (double)CLOCKS_PER_SEC;
            printf("\nTime taken by program block: %lf", time_taken);
        } while(ch!=7);





        return 0;
    }


void createdata(long int n){
     FILE *fp;
     long int r,t=0,i;
     long int *arr;
     arr= (long int*)malloc(100000*sizeof(long int));
     for(i=0;i<100000;i++){
        arr[i]=i;
     }

     srand( time(NULL) );

     for(i=100000;i>0;i--){
        r=rand()%100000;
        t=arr[i-1];
        arr[i-1]=arr[r];
        arr[r]=t;
     }
     fp=fopen("input.txt","w");
     for(i = 0; i <100000; ++i)
   {
      fprintf(fp,"%ld ",arr[i]);
   }

     fclose(fp);

}

long int *create(long int *arr, long int n){

    FILE *f;
    long int i;
    f= fopen("input.txt","r");
    if(f==NULL){
       printf("\nFile is empty");
    }
    else{
            for(i=0;i<n;i++){
            fscanf(f,"%ld",&arr[i]);
        }
    }
    fclose(f);
    //display(arr,n);
    return arr;

}


void bubble(long int *arr,long int n){

    long int i,j,temp=0;
      for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]> arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]= temp;
            }
        }
      }

      //display(arr,n);

}


void mbubble(long int *arr,long int n){
    long int i,j,temp=0,c=0;
    for(i=0; i<n; i++){
		c=0;
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				c++;
			}
		}
		if(c==0)
			break;
	}
	 //display(arr,n);
}


void cocktail(long int *arr,long int n){
    long int c= 1,begin = 0,i,end,temp=0;
    end= n-1;

    while(c){
         c= 0;
         //Sorting from left end
         for (i=begin;i<end;i++) {
                if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                c= 1;
                }
            }
         if (!c)
            break;
         c= 0;
         --end;
         //Sorting from right end
         for (i=end-1; i>=begin;i--) {
             if (arr[i]> arr[i + 1])
            {
              temp = arr[i];
              arr[i]=arr[i+1];
              arr[i+1]=temp;
              c=1;
            }
         }
         ++begin;

    }
    //display(arr,n);
}


void selection(long int *arr, long int n){
    long int i, j, min,temp=0;
    for (i=0; i<n-1; i++)
    {
        min= i;
        for (j = i+1; j<n; j++)
          if (arr[j]<arr[min])
            min= j;

        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    //display(arr,n);
}

long int partition(long int *arr,long int low, long int high){

    long int pivot,i,j,temp=0;
    pivot = arr[high];
    i=low-1;

    for (j=low;j<high;j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i + 1);

}


void quick(long int *arr, long int low, long int high){
    if (low < high)
    {
        long int p= partition(arr,low,high);
        quick(arr,low,p-1);
        quick(arr,p+1,high);
    }
}

void display(long int *arr, long int n){
    long int i;
    printf("\nThe array is:\n");
    for(i=0;i<n;i++)
        printf("%ld ",arr[i]);

    printf("\n");
}
