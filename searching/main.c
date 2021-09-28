#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick(long int *arr,long int low,long int high);
void createdata(long int n);
int interpolation(long int *arr, int lo, int hi, int x);
int linear(long int *arr, int n, int x);
int binary(long int *arr, int l, int r, int x);
void quick(long int *arr,long int low,long int high);
long int partition(long int *arr,long int low, long int high);
long int *create(long int *arr, long int n);
void display(long int *arr, long int n);

int it=0;


int main(){
	int ch,res,x,ch2;
    clock_t start, end;
    time_t s,e;
     double time_taken;
	long int n;
	long int *arr;
	printf("Enter array size:");
	scanf("%ld",&n);
	createdata(n);
    arr = (long int*)malloc(n*sizeof(long int));

    do{
    arr=create(arr,n);
	printf("\n1. Linear Search\n2. Interpolation Search \n3. Binary Search\nEnter your choice:");
	scanf("%d",&ch);
	printf("\nEnter the number you want to search:");
	scanf("%d",&x);

        switch(ch){
                case 1: it=0;
                        res= linear(arr,n,x);
                        if(res==-1)
                        printf("\nThe number is found");
                        else
                        printf("\nThe number is not found");
                        printf("\nNumber of iteration: %d",it);
                        it=0;
                        break;

                case 2: it=0;
                        quick(arr,0,n-1);
                        printf("\n1. Work with uniform data set\n2. Ununiform data set\nEnter your choice:");
                        scanf("%d",&ch2);
                        if(ch2==2){
                            arr[n-1]=arr[n-1]+n;
                        }
                        res=interpolation(arr,0,n-1,x);
                        if(res!=-1)
                        printf("\nThe number found at position :%d",res);
                        else
                        printf("\nThe number is not found");
                        printf("\nNumber of iteration: %d",it);
                        it=0;
                        break;

                case 3: it=0;
                        quick(arr,0,n-1);
                        res= binary(arr,0,n-1,x);
                        if(res==-1)
                        printf("\nThe number is not found");
                        else
                        printf("\nThe number is found at position %d",res);
                        printf("\nNumber of iteration: %d",it);
                        it=0;
                        break;

                case 4: exit(0);
                        break;

                default: printf("Wrong Choice:");
                         break;
                }

             //time_taken= (((double)(end-start))*1000)/ (double)CLOCKS_PER_SEC ;
            //printf("\nTime taken by program block: %lf", time_taken);
             //printf("\nTime taken by program block: %f", e-s);


    }while(ch!=4);

    return 0;
}

void createdata(long int n){
     FILE *fp;
     long int r,t=0,i;
     long int *arr;
     arr= (long int*)malloc(n*sizeof(long int));
     for(i=0;i<n;i++){
        arr[i]=i;
     }

     srand( time(NULL) );

     for(i=n;i>0;i--){
        r=rand()%n;
        t=arr[i-1];
        arr[i-1]=arr[r];
        arr[r]=t;
     }
     fp=fopen("input.txt","w");
     for(i = 0; i <n; ++i)
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


int interpolation(long int *arr, int bottom, int top, int x)
{
    int mid;
    while (bottom <= top) {

        mid = bottom + (top - bottom)*((x-arr[bottom])/(arr[top]-arr[bottom]));
        if (x == arr[mid]){
                it++;
             return mid + 1;

        }

        else if (x< arr[mid]){
            top = mid - 1;
            it++;
        }

        else{
            bottom = mid + 1;
            it++;
        }

    }
    return -1;
}


int linear(long int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++){
            it++;
         if (arr[i] == x){
            return -1;
        }
    }

    return 0;
}

int binary(long int *arr, int l, int r, int x)
{
    it++;
    if (r>=l) {
        int mid =l+(r-l)/2;


        if (arr[mid]==x)
            return mid;

        if (arr[mid]>x)
            return binary(arr,l,mid-1,x);

        return binary(arr,mid+1,r,x);
    }

    return -1;
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
