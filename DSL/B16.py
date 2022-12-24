def partition(array, low, high):

    pivot = array[high] # Last element in the range[low,high] is pivot
    i = low - 1     #Greater element

    for j in range(low,high): 
        if pivot >= array[j]: # If element smaller than pivot is found , swap it with (i+1)th element 
            i = i + 1
            (array[i],array[j]) = (array[j],array[i])

    # Swap the (i+1)th element with pivot , since [ array[i+1] > array[high]]
    (array[i+1],array[high]) = (array[high],array[i+1])

    return i + 1 #Return the position of partition

def quick_sort(array,low,high): #This is a recursive function

    if low<high:
        pi = partition(array,low,high)
        #find partition element

        quick_sort(array,low,pi - 1)
        #Apply quicksort on left side of partition element

        quick_sort(array,pi + 1, high)
        #Apply quicksort on right side of partition element
    
n = int(input("Enter the number of students : "))
l = []

for i in range(n):
    l.append(float(input("Enter marks of student no %d : "%(i+1))))

quick_sort(l,0,n-1)

print("Top 5 scores are : ")
for i in range(-1,-6,-1): #print array in reverse order
    print(l[i])
