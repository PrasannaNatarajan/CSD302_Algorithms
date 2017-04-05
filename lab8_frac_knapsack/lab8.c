#include<stdio.h>
#include<stdlib.h>

#define n 5  // Number of items
#define k 15 // Weight capacity of knapsack

int main(){
    double w[n],p[n]; // arrays to store weights and prices
    double value[n],index[n]; //arrays to store price/weight and sorted indeces
    int i=0,j=0;
    printf("enter the weights price of each of the items"); //getting user inputs
    for(i=0;i<n;i++){
        scanf(" %lf",&w[i]);
        scanf(" %lf",&p[i]);
        value[i] = (double)p[i]/w[i];
        index[i] = i;
    }
    double temp_value[n];
    for(i=0;i<n;i++){
        temp_value[i] = value[i];
    }

    int temp;
    // sorting the value array
    for(i=0;i<n-1;i++){

        for(j=0;j<n-i-1;j++){
            if(temp_value[j] <= temp_value[j+1]){
                temp = temp_value[j];
                temp_value[j] = temp_value[j+1];
                temp_value[j+1] = temp;
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }

        }
    }

    printf("value:");
    for(i=0;i<n;i++){
        printf("%lf ",value[i]);
    }
    printf("\n");
    printf("index:");
    for(i=0;i<n;i++){
        printf("%lf ",index[i]);
    }
    printf("\n");
    int curr_ind=0;
    double curr_weigth = 0;
    double curr_value=0;
    int counter=0;
    //Greedy approach to solve the problem
    while(k> curr_weigth){
        curr_ind = (int)index[counter];
        counter++;
        if(curr_weigth<=w[curr_ind]){
            curr_weigth+=w[curr_ind];
            curr_value+=value[curr_ind]*w[curr_ind];
            printf("Item in the knapsack is: %d\n",curr_ind);
            printf("The current weight = %lf and value is = %lf\n",curr_weigth,curr_value);

        }
        else if(curr_weigth<k){
           int t = k-curr_weigth;
           curr_weigth = k;
           curr_value += value[curr_ind]*t;
           printf("Item in the knapsack is: %d\n",curr_ind);
           printf("The current weight = %lf and value is = %lf\n",curr_weigth,curr_value);

        }

    }
    return 0;
}
