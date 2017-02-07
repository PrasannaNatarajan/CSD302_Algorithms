/*
Name        :   Prasanna Natarajan
Roll Number :   1410110298
Inputs      :   Two 128x128 matrices (a,b): random integers from 0 to 9
Outputs     :   Time taken to multiply two 128x128 matrix via strassen's multiplication is printed.
Method      :   Strassen's Multiplication
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
	printf("Time for execution of Strassen's Multiplication = %lf\n",time_spent);
	
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
				res[i][j] = a[a_i][a_j] + b[b_i][b_j];
			}else{
				res[i][j] = a[a_i][a_j] - b[b_i][b_j];
			}
		}
	}
	return res;
}

// multiplies matrix a and b using strassen's multiplication and return the result
int ** multiply(int **a, int a_rs, int a_cs, int **b, int b_rs, int b_cs,int size){

	// if size is 2 just return the resultant 2x2 matrix 
	if(size==2){
		//puts("inside here");
		// Multiply twocrosstwo matrices
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
	// Calculating the seven products
	int **M1 = iniMatrix(size/2); // M1 = (A11+A22)(B11+B22)
	M1 = multiply(operate(a,a_rs,a_cs,a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),size/2,1),0,0,operate(b,b_rs,b_cs,b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2,1),0,0,size/2);
	int **M2 = iniMatrix(size/2); //M2 = (A21+A22)B11
	M2 = multiply(operate(a,((a_rs+size+a_rs)/2),a_cs,a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),size/2,1),0,0,b,b_rs,b_cs,size/2);
	int **M3 = iniMatrix(size/2); //M3 = (A11)(B12-B22)
	M3 = multiply(a,a_rs,a_cs,operate(b,b_rs,((b_cs+size+b_cs)/2),b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2,0),0,0,size/2);
	int ** M4 = iniMatrix(size/2); //M4 = (A22)(B21-B11)
	M4 = multiply(a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),operate(b,((b_rs+size+b_rs)/2),b_cs,b,b_rs,b_cs,size/2,0),0,0,size/2);
	int ** M5 = iniMatrix(size/2); //M5 = (A11+A12)B22
	M5 = multiply(operate(a,a_rs,a_cs,a,a_rs,((a_cs+size+a_cs)/2),size/2,1),0,0,b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2);
	int **M6 = iniMatrix(size/2); //M6 = (A21 - A11)(B11+B12)
	M6 = multiply(operate(a,((a_rs+size+a_rs)/2),a_cs,a,a_rs,a_cs,size/2,0),0,0,operate(b,b_rs,b_cs,b,b_rs,((b_cs+size+b_cs)/2),size/2,1),0,0,size/2);
	int **M7 = iniMatrix(size/2); //M7 = (A12 - A22)(B21+B22)
	M7 = multiply(operate(a,a_rs,((a_cs+size+a_cs)/2),a,((a_rs+size+a_rs)/2),((a_cs+size+a_cs)/2),size/2,0),0,0,operate(b,((b_rs+size+b_rs)/2),b_cs,b,((b_rs+size+b_rs)/2),((b_cs+size+b_cs)/2),size/2,1),0,0,size/2);
	
	//Calculating the four quadrants
	int **Q1 = iniMatrix(size/2); // Q1 = M1+M4-M5+M7
	int **Q2 = iniMatrix(size/2); // Q2 = M3 + M5
	int **Q3 = iniMatrix(size/2); // Q3 = M2+M4
	int **Q4 = iniMatrix(size/2); // Q4 = M1-M2+M3+M6

	Q1 = operate(operate(operate(M1,0,0,M4,0,0,size/2,1),0,0,M5,0,0,size/2,0),0,0,M7,0,0,size/2,1);
	Q2 = operate(M3,0,0,M5,0,0,size/2,1);
	Q3 = operate(M2,0,0,M4,0,0,size/2,1);
	Q4 = operate(operate(operate(M1,0,0,M2,0,0,size/2,0),0,0,M3,0,0,size/2,1),0,0,M6,0,0,size/2,1);
	
	free(M1); free(M2); free(M3); free(M4); free(M5); free(M6); free(M7);
	
	// Combining the matrices into one final result
	int **result = iniMatrix(size);
	int m1_i,m1_j,i,j;
	
	for (m1_i=0, i=0 ; m1_i<(size/2) ; m1_i++, i++)
        for (m1_j=0, j=0 ; m1_j<(size/2) ; m1_j++, j++){
            result[i][j] = Q1[m1_i][m1_j];            
        }
    

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


