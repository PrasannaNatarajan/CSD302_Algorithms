c = 0 
def toh(n,f,t,o):
	global c
	if n == 1:
		print "move disk 1 from %c to %c" %(f,t)		 
		c = c+1
		return
	toh(n-1,f,o,t)
	print "move disk %d from %c to %c"%(n,f,t)
	c = c+1
	toh(n-1,o,t,f)


n = int(raw_input("Enter the height of the tower at source: "))
toh(n,'A','B','C')
print "Number of steps = ",c