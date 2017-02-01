#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int counter=0;
    long int n;
    printf("Enter the number n: ");
    scanf(" %ld",&n);
    long int i;
    printf("divisors are: ");
    clock_t begin = clock();
    for(i=1;i<=n/2;i++){
        if(n%i==0){
            counter+=i;
            printf("%ld ",i);fflush(stdout);
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
    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("The time taken for n = %ld  is: %1f\n",n,time_spent);
    return 1;
}
