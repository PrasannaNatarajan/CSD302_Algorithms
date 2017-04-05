#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 64

typedef struct matrix{
    int row_start;
    int row_end;
    int col_start;
    int col_end;
    int a[N][N];
}mat;


// Struct to store a 2x2 matrix
typedef struct matrix2x2{
	 int c[2][2];
}mat_2x2;

// function declarations
mat_2x2 multiply2cross2(int a[2][2],int b[2][2]); // function to multiply two 2x2 matrices


mat m1,m2;
void display(mat m)
{
    int i, j;

    for (i=m.row_start ; i<=m.row_end ; i++) {
        for (j=m.col_start ; j<=m.col_end ; j++)
            printf("%d ", m.a[i][j]);
        printf("\n");
    }
    printf("\n");

    return;
}

mat plus(mat m1, mat m2)
{
    mat result;
    int m1_i, m1_j;
    int m2_i, m2_j;
    int i, j;
    int n = m1.row_end - m1.row_start;

    //printf("In plus: %d:%d\n",m1.row_end,m1.row_start);
    result.row_start = result.col_start = 0;
    result.row_end = result.col_end = n;

    for (m1_i=m1.row_start, m2_i=m2.row_start, i=0 ; m1_i<=m1.row_end ; m1_i++, m2_i++, i++)
        for (m1_j=m1.col_start, m2_j=m2.col_start, j=0 ; m1_j<=m1.col_end ; m1_j++, m2_j++, j++)
            result.a[i][j] = m1.a[m1_i][m1_j] + m2.a[m2_i][m2_j];

    return result;
}

mat minus(mat m1, mat m2){
    mat result;
    int m1_i,m1_j;
    int m2_i,m2_j;
    int i,j;
    int n = m1.row_end - m1.row_start;
    //printf("In minus: %d:%d\n",m1.row_end,m1.row_start);

    result.row_start = result.col_start = 0;
    result.row_end = result.col_end = n;

    for (m1_i=m1.row_start, m2_i=m2.row_start, i=0 ; m1_i<=m1.row_end ; m1_i++, m2_i++, i++)
        for (m1_j=m1.col_start, m2_j=m2.col_start, j=0 ; m1_j<=m1.col_end ; m1_j++, m2_j++, j++)
            result.a[i][j] = m1.a[m1_i][m1_j] - m2.a[m2_i][m2_j];

    return result;
}

mat multiply (mat m1, mat m2){

    //puts("first line");
    int n = m1.row_end - m1.row_start +1;
    //printf("m1_row, %d:%d ",m1.row_end,m1.row_start);
    //printf("m1_col, %d:%d ",m1.col_end,m1.col_start);
    //printf("m2_row, %d:%d ",m2.row_end,m2.row_start);
    //printf("m2_col, %d:%d\n",m2.col_end,m2.col_start);
    //fflush(stdout);
    //display(m2);
    if(n <= 2){
        /*mat m3 = m1;
        int a[2][2];
        int b[2][2];
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                a[i][j] = m1.a[m1.row_start+i][m1.col_start+j];
                b[i][j] = m2.a[m2.row_start+i][m2.col_start+j];
            }
        }
        mat_2x2 val = multiply2cross2(a,b);

        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                m3.a[m3.row_start+i][m3.col_start+j] = val.c[i][j];
            }
        }*/
        int a, b, c, d, e, f, g, h;
        mat m3 = m1;
        //printf("")
        a = m1.a[m1.row_start][m1.col_start];
        b = m1.a[m1.row_start][m1.col_start+1];
        c = m1.a[m1.row_start+1][m1.col_start];
        d = m1.a[m1.row_start+1][m1.col_start+1];
        e = m2.a[m2.row_start][m2.col_start];
        f = m2.a[m2.row_start][m2.col_start+1];
        g = m2.a[m2.row_start+1][m2.col_start];
        h = m2.a[m2.row_start+1][m2.col_start+1];

        m3.a[m3.row_start][m3.col_start]      = a*e + b*g;
        m3.a[m3.row_start][m3.col_start+1]    = a*f + b*h;
        m3.a[m3.row_start+1][m3.col_start]    = c*e + d*g;
        m3.a[m3.row_start+1][m3.col_start+1]  = c*f + d*h;


        m3.row_end = m3.row_start+1;
        m3.col_end = m3.col_start+1;

        return m3;
    }

    mat A, B;//, C, D, E, F, G, H;
    mat P1, P2, P3, P4, P5, P6, P7;
    mat Q1, Q2, Q3, Q4;
    mat result;
    int m1_i, m1_j;
    int i, j;

    result.row_start = result.col_start = 0;
    result.col_end = result.row_end = n-1;

    //F
    B=m2;
    B.row_start = m2.row_start;
    B.row_end = (m2.row_end + m2.row_start)/2;
    B.col_start = (m2.col_end + m2.col_start)/2 + 1;
    B.col_end = m2.col_end;
    // H
    A=m2;
    A.row_start = (m2.row_end + m2.row_start)/2 + 1;
    A.row_end = m2.row_end;
    A.col_start = (m2.col_end + m2.col_start)/2 + 1;
    A.col_end = m2.col_end;

    mat temp = minus(B,A);
    //A
    A=m1;
    A.row_start = m1.row_start;
    A.row_end = (m1.row_end+m1.row_start)/2;
    A.col_start = m1.col_start;
    A.col_end = (m1.col_end+m1.col_start)/2;

    P1 = multiply(A, temp);

    //Q2 = plus(P1, P2);
    //B
    B=m1;
    B.row_start = m1.row_start;
    B.row_end = (m1.row_end+m1.row_start)/2;
    B.col_start = (m1.col_end+m1.col_start)/2 + 1;
    B.col_end = m1.col_end;

    // H
    temp=m2;
    temp.row_start = (m2.row_end + m2.row_start)/2 + 1;
    temp.row_end = m2.row_end;
    temp.col_start = (m2.col_end + m2.col_start)/2 + 1;
    temp.col_end = m2.col_end;

    P2 = multiply(plus(A, B), temp);
    //C
    A=m1;
    A.row_start = (m1.row_end+m1.row_start)/2 + 1;
    A.row_end = m1.row_end;
    A.col_start = m1.col_start;
    A.col_end = (m1.col_end + m1.col_start)/2;

    //D
    B=m1;
    B.row_start = (m1.row_end + m1.row_start)/2 + 1;
    B.row_end = m1.row_end;
    B.col_start = (m1.col_end + m1.col_start)/2 + 1;
    B.col_end = m1.col_end;

    temp = plus(A,B);
    //E
    B=m2;
    B.row_start = m2.row_start;
    B.row_end = (m2.row_end + m2.row_start)/2;
    B.col_start = m2.col_start;
    B.col_end = (m2.col_end + m2.col_start)/2;

    P3 = multiply(temp, B);
    //D
    B=m1;
    B.row_start = (m1.row_end + m1.row_start)/2 + 1;
    B.row_end = m1.row_end;
    B.col_start = (m1.col_end + m1.col_start)/2 + 1;
    B.col_end = m1.col_end;

    //G
    A = m2;
    A.row_start = (m2.row_end + m2.row_start)/2 + 1;
    A.row_end = m2.row_end;
    A.col_start = m2.col_start;
    A.col_end = (m2.col_end + m2.col_start)/2;

    //E
    temp = m2;
    temp.row_start = m2.row_start;
    temp.row_end = (m2.row_end + m2.row_start)/2;
    temp.col_start = m2.col_start;
    temp.col_end = (m2.col_end + m2.col_start)/2;

    P4 = multiply(B, minus(A, temp));
    //A
    A=m1;
    A.row_start = m1.row_start;
    A.row_end = (m1.row_end+m1.row_start)/2;
    A.col_start = m1.col_start;
    A.col_end = (m1.col_end+m1.col_start)/2;
    //D
    B=m1;
    B.row_start = (m1.row_end + m1.row_start)/2 + 1;
    B.row_end = m1.row_end;
    B.col_start = (m1.col_end + m1.col_start)/2 + 1;
    B.col_end = m1.col_end;
    //E
    temp = m2;
    temp.row_start = m2.row_start;
    temp.row_end = (m2.row_end + m2.row_start)/2;
    temp.col_start = m2.col_start;
    temp.col_end = (m2.col_end + m2.col_start)/2;
    //H
    mat H = m2;
    H.row_start = (m2.row_end + m2.row_start)/2 + 1;
    H.row_end = m2.row_end;
    H.col_start = (m2.col_end + m2.col_start)/2 + 1;
    H.col_end = m2.col_end;

    P5 = multiply(plus(A, B), plus(temp, H));

    //G
    temp = m2;
    temp.row_start = (m2.row_end + m2.row_start)/2 + 1;
    temp.row_end = m2.row_end;
    temp.col_start = m2.col_start;
    temp.col_end = (m2.col_end + m2.col_start)/2;
    //B
    A=m1;
    A.row_start = m1.row_start;
    A.row_end = (m1.row_end+m1.row_start)/2;
    A.col_start = (m1.col_end+m1.col_start)/2 + 1;
    A.col_end = m1.col_end;
    //D->B
    P6 = multiply(minus(A, B), plus(temp, H));
    //A
    A=m1;
    A.row_start = m1.row_start;
    A.row_end = (m1.row_end+m1.row_start)/2;
    A.col_start = m1.col_start;
    A.col_end = (m1.col_end+m1.col_start)/2;

    //C
    H = m1;
    H.row_start = (m1.row_end+m1.row_start)/2 + 1;
    H.row_end = m1.row_end;
    H.col_start = m1.col_start;
    H.col_end = (m1.col_end + m1.col_start)/2;
    //E
    temp = m2;
    temp.row_start = m2.row_start;
    temp.row_end = (m2.row_end + m2.row_start)/2;
    temp.col_start = m2.col_start;
    temp.col_end = (m2.col_end + m2.col_start)/2;

    //F
    B=m2;
    B.row_start = m2.row_start;
    B.row_end = (m2.row_end + m2.row_start)/2;
    B.col_start = (m2.col_end + m2.col_start)/2 + 1;
    B.col_end = m2.col_end;

    P7 = multiply(minus(A, H), plus(temp, B));

    Q1 = plus(minus(plus(P5, P4), P2), P6);
    Q2 = plus(P1, P2);
    Q3 = plus(P3, P4);
    Q4 = minus(minus(plus(P1, P5), P3), P7);

    /*display(Q1);
    display(Q2);
    display(Q3);
    display(Q4);*/

    for (m1_i=Q1.row_start, i=0 ; m1_i<=Q1.row_end ; m1_i++, i++)
        for (m1_j=Q1.col_start, j=0 ; m1_j<=Q1.col_end ; m1_j++, j++){
            result.a[i][j] = Q1.a[m1_i][m1_j];
            /*printf(" Q1 = %d ",Q1.a[m1_i][m1_j]);
            printf("\n res.a[%d][%d] = %d ",i,j,result.a[i][j]);*/
        }


    for (m1_i=Q2.row_start, i=0 ; m1_i<=Q2.row_end ; m1_i++, i++)
        for (m1_j=Q2.col_start, j=(n/2) ; m1_j<=Q2.col_end ; m1_j++, j++){
            result.a[i][j] = Q2.a[m1_i][m1_j];
            /*printf(" Q2 = %d ",Q2.a[m1_i][m1_j]);
            printf("\n res.a[%d][%d] = %d ",i,j,result.a[i][j]);*/
        }
        //printf("\n");

    for (m1_i=Q3.row_start, i=(n/2) ; m1_i<=Q3.row_end ; m1_i++, i++)
        for (m1_j=Q3.col_start, j=0 ; m1_j<=Q3.col_end ; m1_j++, j++){

            result.a[i][j] = Q3.a[m1_i][m1_j];
            /*printf(" Q3 = %d ",Q3.a[m1_i][m1_j]);
            printf("\n res[%d][%d] = %d ",i,j,result.a[i][j]);*/

        }


    for (m1_i=Q4.row_start, i=(n/2) ; m1_i<=Q4.row_end ; m1_i++, i++)
        for (m1_j=Q4.col_start, j=(n/2) ; m1_j<=Q4.col_end ; m1_j++, j++){

            result.a[i][j] = Q4.a[m1_i][m1_j];
            /*printf(" Q4 = %d ",Q4.a[m1_i][m1_j]);
            printf("\n res[%d][%d] = %d ",i,j,result.a[i][j]);*/

        }


    /*for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("\n result.a[%d][%d] = %d ",i,j,result.a[i][j]);
        }
        printf("\n");
    }*/

    return result;
}

void generate_matrix(){

    srand(time(NULL));
    int i,j;
    //int a[N][N],b[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            m1.a[i][j] = (int)(rand()%9)+1;
            m2.a[i][j] = (int)(rand()%9)+1;
        }
    }
    //m1 = {0, N-1, 0, N-1, a};
    //m1.a = a;
    m1.row_start = 0;
    m1.row_end = N-1;
    m1.col_start = 0;
    m1.col_end = N-1;
    //m2 = {0, N-1, 0, N-1, b};
    //m2.a = b;
    m2.row_start = 0;
    m2.row_end = N-1;
    m2.col_start = 0;
    m2.col_end = N-1;
}

 int main(){

    generate_matrix();
    //display(m1);
    //display(m2);
    printf("Result: \n");
    mat m3 = multiply(m1,m2);
    int i,j,k;

    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            int sum = 0;
            for(k=0;k<N;k++)
                sum += m1.a[i][k] * m2.a[k][j];

            if(sum != m3.a[i][j]) {
                printf("WRONG");
                exit(1);
            }
        }
    }

    //display();

 }



// Function to multiply two 2x2 matrices
// returns a mat_2x2 struct
mat_2x2 multiply2cross2(int a[2][2],int b[2][2]){
  //declaring essention variables
  int i,j;
  int p,q,r,s,t,u,v;

  mat_2x2 m;
  /*printf("\nMatrix a is :\n");
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
	  }*/

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

  /*printf("inside 2x2 res: \n");
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d ",m.c[i][j]);
    }
    printf("\n");
  }*/
  return m; //returning mat_2x2 struct
}
