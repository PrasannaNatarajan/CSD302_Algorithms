#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 6

typedef struct matrix{
    int row_index;
    int col_index;
    int c[N][N];
}mat;


// function declarations

void display(mat m);
void recurse(mat a, mat b);

mat res;


int main(){

    mat a,b;
    srand(time(NULL));
    int i,j;
    //int a[N][N],b[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a.c[i][j] = (int)(rand()%10);
            b.c[i][j] = (int)(rand()%10);
        }
    }
    a.col_index = N;
    a.row_index = N;
    b.row_index = N;
    b.col_index = N;

    printf("input matrices are:");
    display(a);
    display(b);
    printf("The result of multiplication is:");
    res.col_index = N;
    res.row_index = N;
    recurse(a,b);
    display(res);
    return 0;

}

void recurse(mat a,mat b){
    static int c,i=0,j=0,k=0;
    if(i>=a.row_index){
    return;
    }
    else if(i<a.row_index){
        if(j<b.col_index){
            if(k<a.col_index){
                c += a.c[i][k] * b.c[k][j];
                k++;
                recurse(a,b);
            }
            res.c[i][j] = c;
            c=0;
            k=0;
            j++;
            recurse(a,b);

        }
        j=0;
        i++;
        recurse(a,b);
    }
}

void display(mat m)
{
    int i, j;
    printf("\n");
    for (i=0 ; i<m.row_index ; i++) {
        for (j=0 ; j<m.col_index ; j++)
            printf("%d ", m.c[i][j]);
        printf("\n");
    }
    printf("\n");
}


