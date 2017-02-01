/*
Name        :   Prasanna Natarajan
Roll Number :   1410110298
Inputs      :   number of sides of coin
Outputs     :   Distribution of occurences in the number of sample points

*/

#include<stdio.h>
#include<math.h>
#include<time.h>
// declaring functions
int toDecimal(int a[], int n); // a is a binary array, n is the size of the array

int main(){
    int *a;
    int n; // number of sides
    int i = 0;
    time_t t;
    srand((unsigned)time(&t));
    printf("Enter the number of sides: ");
    scanf("%d",&n);
    int num_sample_points = 1000;
    int j=0;
    int m;
    int counter[] = {0,0,0,0,0,0};
    int dec=0;
    for(j=0;j<num_sample_points;j++){
        m = ceil(log2(n));
        //printf("m = %d\n",m);
        a = (int *)malloc( sizeof(int)*m );
        for(i=0;i<m;i++){
            a[i] = rand()%2;
            //printf("a[%d] = %d\n",i,a[i]);
        }
        dec = toDecimal(a,m);
        //printf("dec = %d\n",dec);
        if(dec<7 && dec>0){
            //printf("in the range");
            counter[dec-1]++;
        }

        else j--;
    }

    for(i=0;i<6;i++){
        printf("\nNumber of %d's out of %d number of trails = %d\n",i+1,num_sample_points,counter[i]);
    }
    return 0;
}

int toDecimal(int a[], int n){
    int ret = 0;
    int i=0;
    for(i=1;i<=n;i++){
        //printf("This is a[n-i] = %d n= %d\n",a[n-i],n);
        ret += (a[n-i]*pow(2,i-1));
    }
    return ret;

}
