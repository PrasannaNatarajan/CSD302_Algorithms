/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   A vector p of length N
Outputs 	:   Matrices with correct order of multiplication specified by brackets
Description :   This algorithm is taken from Introduction to Algorithm By Cormen Pg.375 - 377
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define N 8

//Global variables

int m[N+1][N+1];
int s[N][N];

//function declarations

void matrixChainOrder(int p[]);
void printOptimalParens(int i, int j);

int main(){

    int p[N] = {20, 10, 5, 35, 45, 5, 10, 15}; // input p vector
    // filling the global variables m and s
    matrixChainOrder(p);
    int i,j;
    // printing m
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // printing s
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    // printing the optimal order of multiplication for getting minimum cost
    printOptimalParens(1,N-1);
}

void matrixChainOrder(int p[]){
    int i;
    int n = N-1;
    for(i=0;i<=n;i++){
        m[i][i] = 0;
    }

    int l;
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            int k;
            for(k=i;k<j;k++){
                int q = m[i][k] +m[k+1][j]+(p[i-1]*p[j]*p[k]);
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int i, int j){
    if(i==(j)){
        printf("A%d",i);
    }

    else{
        printf("(");
        printOptimalParens(i,s[i][j]);
        printOptimalParens(s[i][j]+1,j);
        printf(")");
    }

}
