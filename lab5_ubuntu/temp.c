#include<stdio.h>
#define MAX 64

void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
int m,n,o,p;
int c[MAX][MAX];

int main(){
   
    int a[MAX][MAX],b[MAX][MAX],i,j,k;

    printf("Enter the row and column of first matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter the row and column of second matrix: ");
    scanf("%d %d",&o,&p);

    if(n!=o){

         printf("Matrix multiplication is not possible");
         printf("\nColumn of first matrix must be same as row of second matrix");
    }
  else{

      printf("Enter the First matrix: ");
      for(i=0;i<m;i++)
      for(j=0;j<n;j++)
           a[i][j] = 2;

      printf("Enter the Second matrix: ");
      for(i=0;i<o;i++)
      for(j=0;j<p;j++)
           b[i][j] = 6;

      printf("\nThe First matrix is: \n");
      for(i=0;i<m;i++){
      printf("\n");
      for(j=0;j<n;j++){
           printf("%d\t",a[i][j]);
      }
      }

      printf("\nThe Second matrix is: \n");
      for(i=0;i<o;i++){
      printf("\n");
      for(j=0;j<p;j++){
           printf("%d\t",b[i][j]);
      }
      }

      multiplyMatrix(a,b);

  }

  printf("\nThe multiplication of two matrix is: \n");
  for(i=0;i<m;i++){
      printf("\n");
      for(j=0;j<p;j++){
           printf("%d\t",c[i][j]);
      }
  }
  return 0;
}

void multiplyMatrix(int a[MAX][MAX],int b[MAX][MAX]){

    static int sum,i=0,j=0,k=0;

    if(i<m){ //row of first matrix
    if(j<p){  //column of second matrix
         if(k<n){
             sum=sum+a[i][k]*b[k][j];
             k++;
             multiplyMatrix(a,b);
         }
         c[i][j]=sum;
             sum=0;
             k=0;
             j++;
             multiplyMatrix(a,b);
    }
    j=0;
    i++;
    multiplyMatrix(a,b);
    }
}