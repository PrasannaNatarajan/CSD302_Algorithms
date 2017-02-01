/*
Name        :   Prasanna Natarajan
Roll Number :   1410110298
Inputs      :   Two 2x2 matrices (a,b): User inputs
Outputs     :   Output matrix (c), which contains the product of a and b.
Method      :   Strassen's Multiplication
*/

#include<stdio.h>

// Struct to store a 2x2 matrix
typedef struct matrix2x2{
	 int c[2][2];	
}mat_2x2;

// function declarations
mat_2x2 multiply2cross2(int a[2][2],int b[2][2]); // function to multiply two 2x2 matrices


int main(){
	int a[2][2],b[2][2],i,j;
	
	printf("Enter the elements of first matrix (a) : ");
	  for(i=0;i<2;i++)
	      for(j=0;j<2;j++)
	           scanf("%d",&a[i][j]); // getting user input for matrix a

	  printf("Enter the elements of second matrix (b) : ");
	  for(i=0;i<2;i++)
	      for(j=0;j<2;j++)
	           scanf("%d",&b[i][j]); //getting user input for matrix b

	  printf("\nMatrix a is :\n");
	  for(i=0;i<2;i++){
	      printf("\n");
	      for(j=0;j<2;j++)
	           printf("%d\t",a[i][j]); // printing out a
	  }

	  printf("\nMatrix b is :\n");
	  for(i=0;i<2;i++){
	      printf("\n");
	      for(j=0;j<2;j++)
	           printf("%d\t",b[i][j]); //printing out b
	  }

	  mat_2x2 res = multiply2cross2(a,b); // function call to multiply a and b

	  printf("\nResult of multiplication (c) : \n"); fflush(stdout);
    for(i=0;i<2;i++){
       printf("\n");
       for(j=0;j<2;j++){
         printf("%d\t",res.c[i][j]); // printing out the result of the multiplication     
       }       
    }
    printf("\n");

}

// Function to multiply two 2x2 matrices
// returns a mat_2x2 struct
mat_2x2 multiply2cross2(int a[2][2],int b[2][2]){
  //declaring essention variables
  int i,j;
  int p,q,r,s,t,u,v;
  
  mat_2x2 m;

  //Calculating the 7 values
  p= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
  q= (a[1][0]+a[1][1])*b[0][0];
  r= a[0][0]*(b[0][1]-b[1][1]);
  s= a[1][1]*(b[1][0]-b[0][0]);
  t= (a[0][0]+a[0][1])*b[1][1];
  u= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  v= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

  // Using strassen's method to assign the correct value to the matrix
  m.c[0][0]=p+s-t+v;
  m.c[0][1]=r+t;
  m.c[1][0]=q+s;
  m.c[1][1]=p-q+r+u;

  return m; //returning mat_2x2 struct
}