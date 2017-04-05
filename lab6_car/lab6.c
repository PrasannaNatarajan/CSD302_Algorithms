/*
Name        :   Prasanna Natarajan
Roll Number :   1410110298
Inputs      :   dist - Distance between A and B, 
                m - the distance that can be crossed in full tank, 
                c - capacity of gas that the car can hold, 
                n - number of gas stations in between A and B, 
                rate - rate at which the gas can be filled.
Outputs     :   A set of gas stations generated and all the relevant stations that the car should stop displayed.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// defining all the inputs
#define dist 100
#define m 20
#define c 10.0
#define n 9
#define rate 1

// function declarations
int * generate();

int main(){

    int *b = generate();
    double a[n] = {0,18,30,48,60,72,85,90,100};
    int i=0;
    for(i=0;i<n;i++){
        printf("%lf ",a[i]);
    }
    
    // Algorithm to find out the optimum gas stations
    
    double curDist = 0;
    double DistTravel = m;
    double prev = 0;
    double time = 10;
    double freq = 0;
    double curFuel = 10;
    for(i=1;i<n;i++){                  // outer for loop to travel through all gas stations
        while(i<n && DistTravel>a[i]){ // loop to find out if ith gas station can be skipped
        i++;
        } 
        i--;
        curDist = a[i];                 // Travelling to the ith gas station        
        freq = (curDist - prev) *(double)(c/m); // fuel required to go till the farthest gas station within m
        //printf("freq = %lf cur fuel = %lf \n",freq , curFuel);
        if(freq > curFuel){
            time += freq - curFuel;
            curFuel = freq ;
        }
        curFuel -= freq;
        DistTravel = curDist+m;
        prev = a[i];
        printf("\n node visited = %lf, time spent = %lf",a[i],time);
    }
    printf("\n");


}
double* populate()
{
    time_t t;
    srand((unsigned)time(&t));
    double*output = (double)malloc(sizeof(double)*n);
	double* arr = (double)malloc(sizeof(double)*n);
	double equalDiv = dist/(n);
	int i, node1, node2;
	int numRand = 10;
	int temp;

	for(i=0;i<num;i++){
		arr[i] = equalDiv;
	}
	
	for(i=0;i<((int)D-num*((int)D/num));i++){
		arr[i]++;
	}
	while(numRand!=0){
		node1 = rand()%n;
		node2 = rand()%n;
		while(node1 == node2)
			node2 = rand()%n;
		temp = rand()%arr[node1];
		if(arr[node2]+temp <= m){
			arr[node1]-=temp;
			arr[node2]+=temp;
			numRand--;
		}
	}
	double sum = 0;
	output[0] = 0;
	for(i=0;i<num;i++)
	{
		sum+=arr[i];
		output[i+1]+=sum;
	}
	return output;
}







double * generate(){
    time_t t;
    srand((unsigned)time(&t));

    double *a = (double*)malloc(sizeof(double)*(2*n));
    a[0] = 0;
    int curDist = 0;
    int i=1;
    int ran;
    int prev = 0;
    while(i<=2*n /*&& curDist <= dist*/){
        //ran = (rand()+(prev))%(i*m);
        //ran = prev + rand()%m;
        ran = rand()%dist;
        //printf("prev = %d, ran = %d\n ",prev,ran);
        if(ran<curDist+m){
            a[i] = ran;
            i++;
            curDist = ran;
            prev = ran;
        }
    }
    return a;

}

void recurse(int *a,int DistTravel){

    static int curDist = 0,index = 1,time = 0;
    if(index>=n){
    exit(0);
    return;
    }
    if(DistTravel < a[index+1]){
        time += c - (-a[index] + DistTravel)*c/m;
        printf("\nRefilling in %d time = %d",a[index],time);        
        index++;
        curDist = a[index-1];
        recurse(a,curDist+m/c*10);
        return;
    }
    else{
        time+=(c-((c/m)*(a[index+1] - a[index])))/rate;
        
        printf("\nGoing to %d time = %d",a[index],time);
        index++;
        recurse(a,(c/m*(a[index]-curDist))*c/m);
        return;

    }
    
    return;

}
