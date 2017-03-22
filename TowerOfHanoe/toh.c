/*
This code was written after the python code in the same folder...
*/
#include <stdio.h>
int count = 0; // to maintain counter for counting number of iterations
void toh(int n, char A,char B, char C){
	if (n == 1)
	{
		printf("move block number 1 from %c to %c\n",A,B);
		count++;
		return;
	}
	toh(n-1,A,C,B);
	printf("move block number %d from %c to %c\n",n,A,B);
	count++;
	toh(n-1,C,B,A);
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the height of the tower\n");
	scanf("%d",&n);
	toh(n,'A','B','C');
	printf("The number of iterations: %d\n",count);
	return 0;
}
