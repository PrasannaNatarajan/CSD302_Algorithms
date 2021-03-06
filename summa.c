/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   The number of items,capacity of the knapsack and price and weights of each items
Outputs 	:   The maximum value that can be taken
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// #defines

//global variables

//function declarations

int main(){


    //random
    time_t t;
    srand((unsigned)time(&t));
    //rand() to get random numbers
    clock_t begin = clock();
    // code that should be timed...
    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time for execution of %dth input = %lf\n",i,time_spent);

	return 0;
}

// bubbleSort :: ascending order
// inputs : array to be sorted
//          size of the array
void bubbleSort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j] >= a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// radixSort
// inputs : array to be sorted
//          size of the array
void radixSort(int a[], int n){
    int i,temp,j,k;
    int c[10],div=10,counter=0;

    for(i=0;i<10;i++)
        c[i] = 0;

    int space[10][100000]; // to store the hash table

    for(i=0;i<10;i++){
        for(j=0;j<100000;j++){
            space[i][j] = -1;
        }
    }

    for(j=1;j<4;j++){ // restircting j to 4 since the range of inputs in from 0 to 999
        for(i=0;i<n;i++){
            temp = a[i]%((int)pow(div,j));
            if(j>=2) temp = temp/(int)pow(div,j-1);

            //printf("temp = %d\n",temp);
            space[temp][c[temp]++] = a[i];
        }

        for(i=0;i<10;i++){
            for(k=0;k<999999;k++){
                if(space[i][k] != -1){
                    //printf("counter = %d\t",counter);
                    a[counter] = space[i][k];
                    //printf("a = %d\n",a[counter]);
                    counter++;
                }

            }
        }
        counter = 0;
        for(i=0;i<10;i++){
            for(k=0;k<999999;k++){
                space[i][k] = -1;
            }
        }
    }
}

// merge function: to sort the elements in the right order
void merge(int a[], int l, int m, int r){
    int i,j,k;
    int Left[m-l+1], Right[r-m];

    for (i = 0; i < m-l+1; i++)
        Left[i] = a[l + i];
    for (j = 0; j < r-m; j++)
        Right[j] = a[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < m-l+1 && j < r-m){
        if (Left[i] <= Right[j]){
            a[k] = Left[i];
            i++;
        }
        else{
            a[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < m-l+1){
        a[k] = Left[i];
        i++;
        k++;
    }

    while (j < r-m){
        a[k] = Right[j];
        j++;
        k++;
    }


}

// join function: Recursive function to split the elements into two halves
void join(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        join(a, l, m);
        join(a, m+1, r);
        merge(a, l, m, r);
    }

}
// mergeSort
// inputs : array to be sorted
//          index of left most and right most element
void mergeSort(int a[], int l, int r){

    join(a,l,r);
    int i=0;
    /*for(i=0;i<r;i++)
        printf("%d ",a[i]); // printing for debuggins

    printf("\n");*/
}




