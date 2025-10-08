N = int(input()) # take in N

cows = list(map(int, input().strip().split())) 
#split the line up by spaces
#call int() on each element (which turns the strings to ints)
#convert the map type to list type
cows.sort() #sort the list of tuitions

mPaid = 0 #initial value for mPaid
bTuition = 0 #technically not needed but to be consistent

for i in range(N): #loop through all indexes 0 to N-1
    if cows[i]*(N-i) > mPaid: # if total paid > most paid
        mPaid = cows[i]*(N-i) # update most paid
        bTuition = cows[i] # update best tuition

print(f"{mPaid} {bTuition}") #print out answers
# this is called an f-string, which converts all escaped
# variable values into strings, while keeping them on one line
