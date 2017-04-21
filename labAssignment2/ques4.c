/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   The number of queens that need to be placed
Outputs 	:   All possible placements for the Queens
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining number of queens
#define num_queens 8

//global integer for holding the position of queens in board
int x[num_queens];
int count = 0;
//declaring functions
int place(int k, int i);    //function to return 1 if queen can be placed in kth row ad ith col 0 otherwise
void NQueens(int k, int n); //function to recursively compute the solution

int main(){

    NQueens(1,num_queens);  //function call to NQueens
    printf("\nThe number of solutions = %d\n",count);
    return 0;
}
/*  function NQueens
*   input : k : row index,
*           n : number of queens
*   output :Prints all possible solution for the given number of queens
*/
void NQueens(int k,int n){
    int i= 1;
    for(i=1;i<=n;i++){
        if(place(k,i) == 1){
            //Solution gets printed
            //Printing the board with the queens placed
            x[k] = i;
            if(k==n){
            int j = 0,k=0;
            for(j=1;j<=n;j++){
                printf("\n%d ",j);
                for(k=1;k<=n;k++){
                    if(x[j] == k) printf("\tQ%d",j);
                    else printf("\t-");
                }
            }
            printf("\n");
            count++;    //incrementing count to keep track of the number of solutions
            }else{
                //recursively call NQueens
                NQueens(k+1,n);
            }
        }
    }

}
/*  function place
*   input : k : row index,
*           i : col index
*   output :returns 1 if placement of queen is possible in kth row and ith col
*/
int place(int k, int i){

    int j = 0;
    for(j=1;j<k;j++){
        if((x[j] == i) || ((x[j]-i) == (j-k)) || ((x[j] - i) == (k-j))){
            return 0;
        }
    }
    return 1;
}
