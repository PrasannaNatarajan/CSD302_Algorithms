#include<stdio.h>
#include<stdlib.h>

int main(){
    int counter=0;
    int n;
    printf("Enter the number n: ");
    scanf(" %d",&n);
    int i;
    printf("divisors are: ");
    for(i=1;i<=n/2;i++){
        if(n%i==0){
            counter+=i;
            printf("%d ",i);fflush(stdout);
        }
    }
    printf("\n");
    if(counter == n){
        printf("The number is the sum of all its divisors\n");
        fflush(stdout);
    }
    else{
        printf("The number is not the sum of all its divisors\n");
        fflush(stdout);
    }

    return 1;
}
