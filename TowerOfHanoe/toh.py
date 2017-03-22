#a counter c to store number of iterations
c = 0 
#define a function for recursively solving toh problem
def toh(n,f,t,o):
	#using the global variable c for counting the number of iterations
	global c
	#stopping condition for recursion
	if n == 1:
		print "move disk 1 from %c to %c" %(f,t)		 
		c = c+1
		return
	#recursive call
	toh(n-1,f,o,t)
	#printing the current disk status
	print "move disk %d from %c to %c"%(n,f,t)
	#incrementing the counter
	c = c+1
	#recursive call
	toh(n-1,o,t,f)
	#end of function

#the program driver
#maybe make it a separate function

#taking n as input from the user
n = int(raw_input("Enter the height of the tower at source: "))
#calling the toh function
toh(n,'A','B','C')
#printing the number of recursions
print "Number of steps = ",c
