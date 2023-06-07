MAX = 50


class SET:
    def __init__(self):
        self.data = [None] * MAX
        self.n = -1  # Index to insert any element

    def insert(self, element):
        if self.n >= MAX - 1:
            print("\n Overflow. SET is full.")
            return False
        self.n += 1
        self.data[self.n] = element
        return True

    def remove(self, element):
        if self.n == -1:
            print("Underflow. Cannot perform delete operation on empty SET.")
            return False
        for i in range(self.n + 1):
            if self.data[i] == element:
                for j in range(i, self.n):
                    self.data[j] = self.data[j + 1]
                self.data[self.n] = None # Logical Deletion of Last element
                self.n -= 1
                return True
        return False

    def contains(self, element):  # Search for element
        for i in range(self.n + 1):
            if self.data[i] == element:
                return True
        return False

    def size(self):
        return self.n + 1

    def Output(self):  # Display Set
        for i in range(self.n + 1):
            print(" ", self.data[i])

    def input(self, num):
        for i in range(num):
            element = int(input("\nEnter Element " + str(i + 1) + " :- "))
            self.insert(element)

    def iterator(self):
        return iter(self.data)

    @staticmethod # When function is called upon object (Usually) the data gets stored on that object where the data get store for static methods?
    def unionS(s1, s2):
        s3 = SET()
        for i in range(s1.n + 1):
            s3.insert(s1.data[i])
        for j in range(s2.n + 1):
            flag = False
            for i in range(s1.n + 1):
                if s1.data[i] == s2.data[j]:
                    flag = True
                    break
            if not flag:
                s3.insert(s2.data[j])
        return s3

    @staticmethod
    def difference(s1, s2):
        s3 = SET()
        for i in range(s1.n + 1):
            flag = True
            for j in range(s2.n + 1):
                if s1.data[i] == s2.data[j]:
                    flag = False
                    break
            if flag:
                s3.insert(s1.data[i])
        return s3

    @staticmethod
    def intersection(s1, s2):
        s3 = SET()
        for i in range(s1.n + 1):
            for j in range(s2.n + 1):
                if s1.data[i] == s2.data[j]:
                    s3.insert(s1.data[i])
                    break
        return s3

    def subset(self, s2):
        count = 0
        size = s2.size()
        for i in range(self.n + 1):
            for j in range(s2.n + 1):
                if self.data[i] == s2.data[j]:
                    count += 1
                    break
        if count == size:
            return True
        return False


# main function
s1 = SET()
s2 = SET()
s3 = SET()
s4 = SET()

element = int(input("\nEnter number of elements in SET1: "))
s1.input(element)

element = int(input("\nEnter number of elements in SET2: "))
s2.input(element)

while True:
    print("\n***** SET OPERATIONS *****")
    print("1. Insert")
    print("2. Remove")
    print("3. Search")  # Contains?
    print("4. Size of Set")
    print("5. Intersection")
    print("6. Union")
    print("7. Difference")
    print("8. Subset")
    print("9. Iterator")
    print("10. Print Set")
    print("11. Exit")
    n = int(input("Enter Choice :- "))
    if n == 1:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            n2 = int(input("Enter Element to be inserted :- "))
            s1.insert(n2)
        elif (n1 == "B" or n1 == "b"):
            n2 = int(input("Enter Element to be inserted :- "))
            s2.insert(n2)
        else:
            print("Enter Valid Choice!")

    elif n == 2:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            n2 = int(input("Enter Element to be deleted :- "))
            s1.remove(n2)
        elif (n1 == "B" or n1 == "b"):
            n2 = int(input("Enter Element to be deleted :- "))
            s2.remove(n2)
        else:
            print("Enter Valid Choice!")

    elif n == 3:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            n2 = int(input("Enter Element to be found :- "))
            if (s1.contains(n2) == True):
                print("Element is Present!!")
            else:
                print("Element is not present")
        elif (n1 == "B" or n1 == "b"):
            n2 = int(input("Enter Element to be found :- "))
            if (s2.contains(n2) == True):
                print("Element is Present!!")
            else:
                print("Element is not present")

    elif n == 4:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            print("Size of Set A is :- ", s1.size())
        elif (n1 == "B" or n1 == "b"):
            print("Size of Set B is :- ", s2.size())
        else:
            print("Enter Valid Choice!")

    elif n == 5:
        s3 = SET.intersection(s1, s2)
        s3.Output()

    elif n == 6:
        s3 = SET.unionS(s1, s2)
        s3.Output()

    elif n == 7:
        s3 = SET.difference(s1, s2)
        s3.Output()

    elif n == 8:
        if (s1.size() > s2.size()):
            if (print(s1.subset(s2)) == True):
                print("S2 is Subset of S1")
        else:
            if (print(s2.subset(s1)) == True):
                print("S1 is Subset of S2")

    elif n == 9:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            print(s1.iterator())
        elif (n1 == "B" or n1 == "b"):
            print(s2.iterator())
        else:
            print("Enter Valid Choice!")

    elif n == 10:
        n1 = input("Enter A/a for Set A and B/b for Set B")
        if (n1 == "A" or n1 == "a"):
            s1.Output()
        elif (n1 == "B" or n1 == "b"):
            s2.Output()
        else:
            print("Enter Valid Choice!")

    elif n == 11:
        exit()
