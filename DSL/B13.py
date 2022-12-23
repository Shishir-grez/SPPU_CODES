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

arr = [80,60,20,40,90]
Selection_Sort(arr)
print(arr)   

arr1 = [90,80,27,40,50]
Bubble_Sort(arr1)
print(arr1)
