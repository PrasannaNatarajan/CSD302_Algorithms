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
	#printing the 
	print "move disk %d from %c to %c"%(n,f,t)
	c = c+1
	toh(n-1,o,t,f)

#the program driver
#maybe make it a separate function
n = int(raw_input("Enter the height of the tower at source: "))
toh(n,'A','B','C')
print "Number of steps = ",c
