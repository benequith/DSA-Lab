#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float sub(float a, float b);
float multiply(float a, float b);
float division(float a, float b);
int fact(int n1);

int main()
{
    printf("Hello world!\n");
    int ch,n1,factor;
    float a,b,sum,subtr,mul,div;



    do{
            printf("\n1. Addition\n2. Subtraction \n3. Multiplication \n4. Division\n5. Factorial 6. Exit\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch){
                case 1: printf("Enter two numbers:");
                        scanf("%f %f",&a,&b);
                        sum=add(a,b) ;
                        printf("\nThe addition result of two numbers are:%.2f",sum);
                        break;

                case 2: printf("Enter two numbers:");
                        scanf("%f %f",&a,&b);
                        subtr= sub(a,b);
                        printf("\nThe subtraction result of two numbers are:%.2f",subtr);
                        break;

                case 3: printf("Enter two numbers:");
                        scanf("%f %f",&a,&b);
                        mul= multiply(a,b);
                        printf("\nThe multiplication result of two numbers are:%.2f",mul);
                        break;

                case 4: printf("Enter two numbers:");
                        scanf("%f %f",&a,&b);
                        div= division(a,b);
                        printf("\nThe division result of two numbers are:%.2f",div);
                        break;

                case 5: printf("Enter a number to find its factorial:");
                        scanf("%d",&n1);
                        factor= fact(n1);
                        printf("\nThe factorial result of two numbers are:%d",factor);
                        break;

                case 6: exit(0);
                        break;
            }
    }while(1);
     return 0;
}

