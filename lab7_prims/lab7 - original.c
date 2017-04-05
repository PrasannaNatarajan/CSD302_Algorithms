#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define M 38
int graph[N][N];

void makeGraph();
void displayGraph();
void prims();
void printMST(int mst[]);
int minKey(int val[], int included[]);
int totalWeight(int mst[]);

int main(){
	time_t t;
	srand((unsigned)time(&t));
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			graph[i][j] = 0;
	
	
	makeGraph();
	displayGraph();
	prims();

	return 0;
}

void makeGraph(){

	int i,r1,r2;
	
	for(i=0;i<M;i++){
		r1 = rand()%N;
		r2 = rand()%N;
		while(graph[r1][r2] != 0 || r1==r2){
			r1 = rand()%N;
			r2 = rand()%N;		
		}		
		graph[r1][r2] = rand()%10;
		graph[r2][r1] = graph[r1][r2];
		
	}

}

void displayGraph(){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<N;j++){
			printf("\t%d ",graph[i][j]);		
		}	
		
	}
	printf("\n");
}

void printMST(int mst[]){

   printf("\tSelected Edge\tWeight\n");
   int i;
   for (i = 1; i < N; i++)
      printf("\t%d - %d\t\t%d \n", mst[i], i, graph[i][mst[i]]);
}

int totalWeight(int mst[]){
	int i=0;
	int sum=0;
	for(i=0;i<N;i++)
		sum+=graph[i][mst[i]];
		
	return sum;

}

// function to choose the minimum index from the not included
int minKey(int val[], int included[])
{
   // Initialize min value
   int min = 100, min_index;
   int j = 0;
   for (j = 0; j < N; j++)
     if (included[j] == 0 && val[j] < min){
     	min = val[j];
     	min_index = j;     
     }         
 
   return min_index;
}


void prims(){
	
	int mst[N];   		// MST
    int val[N];      	// values used to pick minimum weight edge in cut
    int included[N];   	// To represent set of vertices not yet included in MST
	
	int i;
	for(i=0;i<N;i++){
		mst[i] = -1;
		val[i] = 100; 	// Some relatively large integer
		included[i] = 0;// initialise so that no node in included in the MST 
	}
		
     val[0] = 0;     // picking 0 node as the first node
     mst[0] = -1;    // including 0 node into the MST
     int c = 0;
     for (c = 0; c < N-1; c++){
        int min = minKey(val, included);
        included[min] = 1;
        int j=0;
        for (j = 0; j < N; j++){
          if (graph[min][j] !=0 && included[j] == 0 && graph[min][j] <  val[j]){
             mst[j]  = min;
             val[j] = graph[min][j];
          }
       }
     }
 	 
 	 for(i=1;i<N;i++)
 	 	if(mst[i] ==-1){
 	 		printf("graph is not connected %d for i = %d\n",mst[i],i);
 	 		exit(0);
 	 	}
 	 	
 	     
     printMST(mst);
 	 printf("The total weight by prim's algorithm = %d\n",totalWeight(mst));
}