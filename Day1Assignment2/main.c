#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    float sum=0.0, n1, n2;
    printf("\n Enter the value of number:");
    scanf("%d",&n);
    for(n2=0;n2<=n;n2++){
        n1=1/n2;
        sum = sum+n1;
    }
    printf("\n The sum of series 1/1 + 1/2 +.... +l/%d = %f",n,sum);
    return 0;
}
