def merge_sort(arr):
    if len(arr) > 1:

        mid = len(arr)//2 # Finding middle element of array

        left = arr[:mid] # Left part of the array [Array of elements from index 0 to mid - 1(exclude mid)]

        right = arr[mid:] # Right part of the array [Array of elements from index mid to last element of the array]

        merge_sort(left) # Sorting left array

        merge_sort(right) # Sorting right array 

        i = j = k = 0 # Indices for left , right and arr respectively

        while i < len(left) and j < len(right) :
            if left[i] <= right[j]: # Comparison in element of left and right array
                arr[k] = left[i] 
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        
        # Copy the rest of element/s {if any}
        while i < len(left) :
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right) :
            arr[k] = right[j]
            j += 1
            k += 1

#Driver code        
n = int(input("Enter the number of elements in the list : "))
l = []
for i in range(n):
    l.append(int(input("Enter element no %d : "%(i+1))))
print("Original list : ", l)
merge_sort(l)
print("After sorting : ", l)

#Refrences
"""
    https://www.geeksforgeeks.org/merge-sort/ ~ for merge sort
"""