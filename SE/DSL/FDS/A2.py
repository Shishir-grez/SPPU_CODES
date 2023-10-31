n = int(input("Enter number of students :" ))
l = []
for i in range(0,n,1):
    a = int(input("Enter Marks of student no %d : "%(i+1)))
    l.append(a)
# To display counter of students as the entries progress we use "above" syntax
# syntax "inside comment %d/%f/%s" % (changing value (here it is "i") )
# when adding a changing integer value we use (%d) , when dealing with float we use (%f) and so on
#Not compulsary to add

# for average :
def avg():
    sum1 = 0
    count_2 = 0
    count_1 = 0
    avg = 0
    for j in l:
        if j == -1:
            count_1 += 1
        else:
            sum1 += j
            count_2 += 1
        
    avg = sum1/count_2
    print("Average of the class is : " ,avg)
    print("No of Absent students is : ",count_1)


#for maximum and minimum
def max_min():
    max_1 = l[0]
    min_1 = l[0]
    for k in l:
        if k > max_1:
            max_1 = k
        if k < min_1:
            if k == -1:
                pass
            else:
                min_1 = k        
    print("Maximum Entry from the list is : ", max_1)
    print("Minimum Entry from the list is : ", min_1)


# for getting number with maximum frequency
def higheset_freq():
    max_freq = 0
    freq = 0
    test = 0

    for m in range(0, n, 1):
        test = l[m]
        for i in l:
            if test == i:
                freq += 1
            if freq > max_freq:
                max_freq = freq
                max_freq_no = i
        freq = 0
    print("The number with highest frequency from the list is : ", max_freq_no)
    print("The highest frequency is : ", max_freq)

avg()
max_min()
higheset_freq()