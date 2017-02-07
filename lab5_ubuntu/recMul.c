/*
Name        :   Prasanna Natarajan
Roll Number :   1410110298
Inputs      :   Two 128x128 matrices (a,b): random integers from 0 to 9
Outputs     :   Time taken to multiply two 128x128 matrix via strassen's multiplication is printed.
Method      :   Normal Recursion
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 128   // Change the value of N to check for a different size of matrix

// Function defenitions
int ** operate(int** a, int a_rs,int a_cs,int** b, int b_rs, int b_cs, int size, int operator);
void display(int **a, int size);
int ** iniMatrix(int size);
int ** multiply(int **a, int a_rs, int a_cs, int **b, int b_rs, int b_cs,int size);

int main(){

	time_t t;
	srand((unsigned)time(&t));
	int **a,**b;
	a=iniMatrix(N);
	b=iniMatrix(N);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j] = rand()%10;
			b[i][j] = rand()%10;
		}
	}
	//display(a,N);
	//display(b,N);
	//display(operate(a,0,0,b,0,0,N,1),N);
	//display(multiply(a,0,0,b,0,0,N),N);
	clock_t begin1 = clock();
	multiply(a,0,0,b,0,0,N);
	clock_t end1 = clock();
	double time_spent = (double)(end1-begin1)/CLOCKS_PER_SEC;
	printf("Time for execution of Recursive Matrix Multiplication = %lf\n",time_spent);
	
	printf("Done\n");fflush(stdout);
	return 0;

}
// initialize matrix with of size sizeXsize and returns the matrix
int ** iniMatrix(int size){
	int **a;
	a=(int**)malloc(sizeof(int*)*size);
	int i;
	for(i=0;i<size;i++){
		a[i] = (int*)calloc(size,sizeof(int));
	}
	return a;
}
// prints the matrix a of size sizeXsize
void display(int **a, int size){

	int i,j;
	for(i=0;i<(size);i++){
		for(j=0;j<size;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
// returns addition or subtraction of matrix a and b 
// if operate == 1 then addition is performed
// else subtraction is performed 
int ** operate(int** a, int a_rs,int a_cs,int** b, int b_rs, int b_cs, int size, int operator){

	//operator == 1 for addition and 0 for substraction
	int **res = iniMatrix(size);
	int a_i, a_j;
	int b_i, b_j;
	int i,j;

	for(a_i = a_rs,b_i = b_rs,i=0;a_i<(a_rs+size);i++,a_i++,b_i++){
		for(a_j = a_cs,b_j = b_cs,j=0; a_j<(a_cs+size);j++,a_j++,b_j++){
			if(operator == 1){
				//printf("i=%d,a_i = %d, b_i = %d\n",i,a_i,b_i);fflush(stdout);
				res[i][j] = a[a_i][a_j] + b[b_i][b_j];
				//printf("res[%d][%d] = %d",i,j,res[i][j]);fflush(stdout);
			}else{
				res[i][j] = a[a_i][a_j] - b[b_i][b_j];
			}
		}
	}
	return res;
}
// multiplies matrix a and b using recursive multiplication of matrices and then return the result
int ** multiply(int **a, int a_rs, int a_cs, int **b, int b_rs, int b_cs,int size){

	if(size==2){
		// Multiply twoXtwo matrices
		int p,q,r,s,t,u,v;
		int **c = iniMatrix(2);
		p= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
  		q= (a[1][0]+a[1][1])*b[0][0];
  		r= a[0][0]*(b[0][1]-b[1][1]);
  		s= a[1][1]*(b[1][0]-b[0][0]);
  		t= (a[0][0]+a[0][1])*b[1][1];
  		u= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  		v= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

  		c[0][0]=p+s-t+v;
  		c[0][1]=r+t;
  		c[1][0]=q+s;
  		c[1][1]=p-q+r+u;

  		return c;
	}
	// Four quadrants
	int **Q1 = iniMatrix(size/2);
	int **Q2 = iniMatrix(size/2);
	int **Q3 = iniMatrix(size/2);
	int **Q4 = iniMatrix(size/2);
	
	Q2 = operate(multiply(a,a_rs,a_cs,b,b_rs,((b_cs+size+b_cs)/2),size/2),0,0,multiply(a,a_rs,((a_cs+size+a_cs)/2),b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2),0,0,size/2,1);
	Q1 = operate(multiply(a,a_rs,a_cs,b,b_rs,b_cs,size/2),0,0,multiply(a,a_rs,((a_cs+size+a_cs)/2),b,((b_rs+size+b_rs)/2),b_cs,size/2),0,0,size/2,1);
	Q3 = operate(multiply(a,((a_rs+size+a_rs)/2),a_cs,b,b_rs,b_cs,size/2),0,0,multiply(a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),b,((b_rs+size+b_rs)/2),b_cs,size/2),0,0,size/2,1);	
	Q4 = operate(multiply(a,((a_rs+size+a_rs)/2),a_cs,b,b_rs,((b_cs+size+b_cs)/2),size/2),0,0,multiply(a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2),0,0,size/2,1);
	int **result = iniMatrix(size);
	// Combining the result
	int m1_i,m1_j,i,j;
	for (m1_i=0, i=0 ; m1_i<(size/2) ; m1_i++, i++)
        for (m1_j=0, j=0 ; m1_j<(size/2) ; m1_j++, j++){
            result[i][j] = Q1[m1_i][m1_j];
            //printf(" %d ", result[i][j]);fflush(stdout);
        }
    //printf("\n");

    for (m1_i=0, i=0 ; m1_i<(size/2) ; m1_i++, i++)
        for (m1_j=0, j=(size/2) ; m1_j<(size/2) ; m1_j++, j++){
            result[i][j] = Q2[m1_i][m1_j];
        }
        

    for (m1_i=0, i=(size/2) ; m1_i<(size/2) ; m1_i++, i++)
        for (m1_j=0, j=0 ; m1_j<(size/2) ; m1_j++, j++){
            result[i][j] = Q3[m1_i][m1_j];      
        }


    for (m1_i=0, i=(size/2) ; m1_i<(size/2) ; m1_i++, i++)
        for (m1_j=0, j=(size/2) ; m1_j<(size/2) ; m1_j++, j++){
            result[i][j] = Q4[m1_i][m1_j];
        }

    free(Q1);free(Q2);free(Q3);free(Q4);	

    return result;
}


