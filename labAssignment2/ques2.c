/*
Name    	:   Prasanna Natarajan
Roll Number :   1410110298
Inputs  	:   A graph represented in a N*N matrix, a start node from where the shortest path has to be found
Outputs 	:   prints the shortest path distance from the given node to all other nodes
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define N 11

//defining global variables
int graph[N][N];

//declaring functions
void initGraph();
void printGraph();
int findMinDist(int distance[], int incSet[]);
void dijkstra_shortest_path(int startNode);

int main(){
    time_t t;
    srand((unsigned)time(&t));

    //initialise the graph
    initGraph();

    //print the graph
    printGraph();

    //function call for dijkstra_shortest_path with a random source node
    dijkstra_shortest_path(rand()%N);

    return 0;
}

//function to initialise the graph
void initGraph(){
    time_t t;
    srand((unsigned)time(&t));
    int i,j;
    //initialising to -1
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            graph[i][j] = -1;

    //initialising as per the question
    for(i=0;i<(N*N)/2;i++){
        int r1 = rand()%N;
        int r2 = rand()%N;
        //printf("%d - %d \n",r1,r2);fflush(stdout);
        if(graph[r1][r2]==-1) //check if already a weight was given
            graph[r1][r2] = 1+(rand())%10;
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

//function to perform dijkstra's shortest path algorithm. the start node is given as input
void dijkstra_shortest_path(int startNode){
    int distance[N],incSet[N]; //distance to maintain the shortest path, incSet to maintain the visited nodes
    int i,j;
    //loop to initialise distances to infinity and not to include any node yet
    for(i=0;i<N;i++){
        distance[i]= INT_MAX;
        incSet[i] = 0;
    }

    distance[startNode] = 0; //make the source node to be of distance zero

    for(i=0;i<N-1;i++){
        int minDistIndex = findMinDist(distance,incSet); // select the minDist from the nodes that are not yet selected
        printf("\nMin dist index = %d\n",minDistIndex);
        incSet[minDistIndex] = 1; //since this node is picked, include it in the selected nodes

        for(j=0;j<N;j++){
            //change the distance only if it is not already visited, an edge is present,the dist is smaller than infinity or less than through the current node is smaller than the previous distance
            if((incSet[j]==0) && (graph[minDistIndex][j]!=-1) && (distance[minDistIndex]!=INT_MAX) &&(distance[minDistIndex]+graph[minDistIndex][j]<distance[j])){
                distance[j] = distance[minDistIndex] + graph[minDistIndex][j];
                //printf("distance[%d] = %d\n",j,distance[j]);
            }

        }

    }

    //print the distance array
    printf("Node \t Dist from Source\n");
    for(i=0;i<N;i++){
        printf("%d\t\t%d\n",i,distance[i]);
    }

}

//function to find the minimum distance index from the set of vertices not yet visited
int findMinDist(int distance[], int incSet[]){
    int minVal = INT_MAX, temp; // min to hold the minimum value and temp minimum index
    int i;
    for(i=0;i<N;i++){
        // not visited and distance is minimum
        if(incSet[i]==0 &&distance[i]<=minVal){
            minVal = distance[i];
            temp = i;
        }
    }
    return temp;
}

