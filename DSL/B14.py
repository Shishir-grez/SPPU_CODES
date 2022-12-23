def Selection_Sort(arr):
    for j in range(0,len(arr)):

        min_indx = j

        for i in range(j + 1, len(arr)):
            if arr[min_indx] > arr[i]:
                min_indx = i

        temp = arr[j]
        arr[j] = arr[min_indx]
        arr[min_indx] = temp

def Bubble_Sort(arr):
    for i in range(0,len(arr)-1):
        k = 0
        for j in range(1,len(arr)-i):
            if arr[k] > arr[j]:
                temp = arr[k]
                arr[k] = arr[j]
                arr[j] = temp
            k = k + 1

#Driver code

n = int(input("Enter total no students : "))
l = []
q = 5
for i in range (n) :
    l.append(float(input("Enter Marks of Student no %d : "%(i+1))))
print("Enter 1 for Bubble Sort")
print("Enter 2 for Selection Sort")
choice = int(input("Enter your choice : "))
if choice == 1:
    Bubble_Sort(l)
    print("Top 5 scores are : ")
    for j in range (-1,-(q+1),-1): # To print last 5 elements {Since list is sorted is ascending order}
        print (l[j])

elif choice == 2:
    Selection_Sort(l)
    print("Top 5 scores are : ")
    for j in range (-1,-(q+1),-1):
        print(l[j])

else :
    print("Enter correct choice!")
    exit()

#Refrences
'''
    https://www.geeksforgeeks.org/selection-sort/
    https://www.geeksforgeeks.org/bubble-sort/
'''