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
#define n 4  // Number of items
#define W 5 // Weight capacity of knapsack

//global variables
int B[n+1][W+1];
//function declarations

int main(){

    int w[n],p[n]; // arrays to store weights and prices
    int i=0,j=0;
    printf("enter the weights price of each of the items"); //getting user inputs
    for(i=0;i<n;i++){
        scanf(" %d",&w[i]);
        scanf(" %d",&p[i]);
    }
    knapsack(w,p);


    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }

    i=n;
    j=W;
    while(i>0 && j>0){
        if(B[i][j]!=B[i-1][j]){
            printf("The item %d is in the knapsack\n",i);
            i--;j-=w[i];
        }
        else{
            i--;
        }

    }

	return 0;
}

void knapsack(int w[],int p[]){
    int i;
    for(i=0;i<=W;i++){
        B[0][i] = 0;
    }

    for(i=0;i<=n;i++){
        B[i][0] = 0;
    }

    int j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(w[i-1]<=j){
                if(p[i]+B[i-1][j-w[i]] > B[i-1][j]){
                    B[i][j] = p[i-1] + B[i-1][j-w[i-1]];
                    //printf("1\tB[%d][%d] = %d\n",i,j,B[i][j]);
                }
                else{
                    B[i][j] = B[i-1][j];
                    //printf("2\tB[%d][%d] = %d\n",i,j,B[i][j]);
                }
            }
            else if(i!=0){
                B[i][j] = B[i-1][j];
                //printf("3\tB[%d][%d] = %d\n",i,j,B[i][j]);
            }
        }
    }


}
