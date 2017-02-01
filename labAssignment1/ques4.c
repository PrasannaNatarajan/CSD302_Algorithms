#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define t 1000

int prime(int n);
int main(){
    printf("Enter the number n: ");
    int n;
    scanf(" %d",&n);
    int res = prime(n);
    if(res == 1)
        printf("The number n = %d is a prime number\n",n);
    else
        printf("The number n = %d is not a prime number\n",n);

    return 0;
}

int prime(int n){
    time_t ti;
    srand((unsigned)time(&ti));
    int m,j;
    long int i = 0;
    for(i=0;i<t;i++){
        m = pow(n,0.5);
        j = random()%m+2;
        if(n%j == 0) return 0;
    }
    return 1;

}
