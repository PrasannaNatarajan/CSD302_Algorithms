#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 128

void display(int **a , int size);
int **iniMatrix(int size);
void multiply(int **a, int **b, int size);
static int c[N][N];
int main(){

	time_t t;
	srand((unsigned)time(&t));
	int **a,**b;
	a=iniMatrix(N);
	b=iniMatrix(N);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j] = 6;
			b[i][j] = 2;
		}
	}
	//display(a,N);
	//display(b,N);
	//int **c = iniMatrix(N);
	clock_t begin1 = clock();
	multiply(a,b,N);
	clock_t end1 = clock();
	double time_spent = (double)(end1-begin1)/CLOCKS_PER_SEC;
	printf("Time for execution recursive matrix multiplication = %lf\n",time_spent);
	
	/*for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}*/
		
	//display(c,N);

	return 0;

}

int ** iniMatrix(int size){
	int **a;
	a=(int**)malloc(sizeof(int*)*size);
	int i;
	for(i=0;i<size;i++){
		a[i] = (int*)calloc(size,sizeof(int));
	}
	return a;
}

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

void multiply(int **a, int **b, int size){

	static int i=0,j=0,k=0;
	if (i>=size)
	{
		return;
	}else{

		if (j<size)
		{
			if (k<size)
			{
				c[i][j]+=a[i][k]*b[k][j];
				k++;
				multiply(a,b,size);
			}
			k=0;
			j++;
			multiply(a,b,size);
		}
		j=0;
		i++;
		multiply(a,b,size);
	}

}