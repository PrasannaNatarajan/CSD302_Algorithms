/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   A graph represented in a N*N matrix, a source node and a sink node
Outputs 	:   finds the maximum flow and tells if the two kids can go to the same school
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define N 6

//defining global variables
int graph[N][N]; //graph N*N
int head,tail;  //for maintaining a queue
int q[N+2];     //the queue for using in bfs

//declaring functions
void initGraph();
void printGraph();
void enqueue (int x);
int dequeue();
int doBFS(int s,int t,int parent[]);
int fordFulkerson(int s,int t);

int main(){
    time_t t;
    srand((unsigned)time(&t));

    //initialise the graph
    initGraph();

    //print the graph
    printGraph();

    // ret stores the maximum flow
    int ret = fordFulkerson(0,4); // the inputs are s and t
    printf("max_flow = %d\n",ret);

    if(ret >=2){
        printf("The two kids can go to school\n");
    }else{
        printf("The two kids cannot go to school\n");
    }
    return 0;
}

//function to initialise the graph
void initGraph(){
    time_t t;
    srand((unsigned)time(&t));
    int i,j;
    //initialising to 0
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            graph[i][j] = 0;

    //initialising as per the question
    for(i=0;i<(N*N)/2;i++){
        int r1 = rand()%N;
        int r2 = rand()%N;
        //printf("%d - %d \n",r1,r2);fflush(stdout);
        if(graph[r1][r2]==0) //check if already a weight was given
            graph[r1][r2] = 1+(rand())%1;
        else i--;   //else repeat the iteration
    }

}

//function to print the graph
void printGraph(){
    int i,j;
    //print the graph
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

}


//enqueue into the queue
void enqueue (int x) {
    q[tail] = x;
    tail++;
}

//dequeue from the queue
int dequeue () {
    int x = q[head];
    head++;
    return x;
}

//traverse the graph using Breath First Search
int doBFS(int s,int t,int parent[]){
    int vis[N];
    int i;
    for(i=0;i<N;i++){
        vis[i] = 0;
    }
    enqueue(s); //enqueue the source node
    vis[s] = 1; //mark source node as visited
    parent[s] = -1;

    while(head!=tail){
        int j = dequeue();
        int k;
        for (k=0; k<N; k++) {
            if (vis[k]==0 && graph[j][k]>0) {
                enqueue(k);
                parent[k] = j;
                vis[k] = 1;
            }
        }
    }

    if(vis[t]==1)   // if from source to sink is reached then return 1
        return 1;
    return 0;
}

// implement the fordFulkerson algorithm
// s is the source node and t is the destination node
int fordFulkerson(int s,int t){
    int j,k;
    int parent[N];  //store the BFS paths
    int maxFlow=0; // total flow
    while(doBFS(s,t,parent)==1){
        int PFlow = INT_MAX;   //total path flow
        for(k=t;k!=s;k=parent[k]){  //find the minimim path distance from BFS
            j = parent[k];
            PFlow = (PFlow<graph[j][k])?PFlow:graph[j][k];
        }
        for(k=t;k!=s;k=parent[k]){//reverse the paths and update the weights
            j=parent[k];
            graph[j][k]-=PFlow;
            graph[k][j]+=PFlow;
        }
        maxFlow+=PFlow;   //add path flow to total flow
    }

    return maxFlow;
}
