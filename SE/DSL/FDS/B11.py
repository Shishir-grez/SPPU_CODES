#Refrences at End 
def Linear_Search(arr , size , key):
    check = 0 # To check if key is found or not
    for i in range(0, size):
        if(arr[i] == key):
            check = 1
            return i
    if(check == 0):
        return -1

def Sentinal_Search(arr, size ,key):
    last = arr[size-1] #Variable to store last element
    arr[size-1] = key #Replace last element with key
    i=0

    while(arr[i]!=key): #while key is not found increment "i"
        i=i+1

    arr[size-1] = last #At the end of the add last element back to list

    if(i<size-1 or arr[size - 1] == key): # if key is found before last element or key is the last element 
       print("Key found at index : ",i)
    else:
        print("Key not found in given array!")

#Binary Search in iterative approach
def Binary_Search(arr, left, right, key): #Input is a sorted array
    while right >= left: # while the array from index {left,right} is valid
        mid = left + (right - left)//2 

        if arr[mid] == key: 
            return mid
        
        elif key > arr[mid]: # new searched array arr[mid+1,right]
            left = mid + 1

        else : #new searhced array arr[left, mid -1]
            right = mid - 1
    
    return -1 #if key not found return -1

def Fib_no(no): #Function to calculate nth Fibonacci Number
    fib1 = 0
    fib2 = 1
    if no == 1: # 1st Fib. no is 0
        return fib1
    elif no == 2: # 2nd Fib. no is 1
        return fib2
    else:
        while(no > 2):
            fib3 = fib2 + fib1
            fib1 = fib2
            fib2 = fib3
            no = no - 1
        return fib3

def Fibonacci_Search(arr, key, size):
    i = 1 # i represents ith Fibonacci number

    while (Fib_no(i) < size): #Find the index "i" until Fib(i) < size(array)
        i = i + 1 

    if i == 1 or i == 2: #size cannot be 0[Fib(1)] or 1 [Fib(2)]
        print("invalid")
        return 0

    check = 0       # If value if found check = 1 and if not check = 0
    offset = -1     # a required variable
    while(Fib_no(i) > 1):
        k = min(offset + Fib_no(i-2),size-1)    # min function returns minimun value of given numbers

        if (key == arr[k]):
            check = 1     
            return k    # if key found return index
        
        elif(key > arr[k]): 
            i = i - 1 
            offset = k
        else :
            i = i - 2

    if check == 0:
        return -1
        
#Driver code
n = int(input("Enter the number of students : "))
l=[]
print("Enteries in Random Order are allowed")

for i in range(n):
    l.append(int(input("Enter Roll no of Student no %d : "%(i+1))))

key = int(input("Enter key to be searched : "))
print("Enter 1 for Linear Search")
print("Enter 2 for Sentinal Search")
choice = int(input("Enter choice : "))

if choice == 1:
    b = Linear_Search(l,n,key)
    if b==-1:
        print("Key not found!")
    else:
        print("Key is found at index : ",b)

elif choice == 2:
    b = Sentinal_Search(l,n,key)
else : 
    print("Enter correct choice")
    exit()

n1 = int(input("Enter number of students : "))
print("Entries must be in Sorted Order")
l1 = []
for i in range(n1):
    l1.append(int(input("Enter Roll no of Student no %d : "%(i+1))))

key1 = int(input("Enter key to be searched : "))
print("Enter 1 for Binary Search")
print("Enter 2 for Fibonacci Search")
choice1 = int(input("Enter your choice : "))

if choice1 == 1:
    b = Binary_Search(l1,0,n1-1,key1)
    if b==-1:
        print("Key not found!")
    else:
        print("Key found at index : ",b)

elif choice1 == 2:
    b = Fibonacci_Search(l1,key1,n1)
    if b == -1:
        print("Key not found")
    else:
        print("Key found at index : ",b)

else:
    print("Enter correct choice")
    exit()

#Refrences
'''
    https://www.geeksforgeeks.org/linear-search/  - for linear search

    https://www.geeksforgeeks.org/sentinel-linear-search/ - for sentinal search

    https://www.geeksforgeeks.org/binary-search/ - for binary search 

    https://www.geeksforgeeks.org/start-end-start2-preferrable-method-calculating-middle-array-start-end2/

    geeksforgeeks.org/fibonacci-search/ - for fibonacci search 

    https://www.youtube.com/watch?v=q_AVjuzBxoc&ab_channel=EnggTutes - YouTube video link for fibonacci search
    
'''