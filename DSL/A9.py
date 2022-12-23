# To display a matrix
r = int(input("Enter the number of rows : "))
c = int(input("Enter the number of columns : "))
n = int(input("Enter the number of Matrices: "))
M_1 = []
M_2 = []
M_A = []
M_S = []
M_T_1 = []
M_T_2 = []
M_M = []
def Calculation():
    for k in range(0, n):
        print("Enter Entries for Matrix %d : " %(k + 1))
        if k == 0:
            for i in range (0, r):
                A = []
                B = []
                for l in range(0 , c):
                    A.append(int(input("Enter Element from Row %d and column %d :" %((i + 1), (l + 1)))))
                M_1.append(A)
        if k == 1:
            for i in range (0, r):
                A = []
                B = []
                for l in range(0 , c):
                    B.append(int(input("Enter Element from Row %d and column %d :" %((i + 1), (l + 1)))))
                M_2.append(B)
Calculation() 

def display():
    print("\n")  
    print("Matrix A is : ")         
    for i in range(0, r):
        for j in range(0, c):
            print(M_1[i][j], end= "    ")
        print ("\n")
    print ("\n")
    print("Matrix B is : ")
    for i in range(0, r):
        for j in range(0, c):
            print(M_2[i][j], end= "    ")    
        print("\n")  
    print ("\n") 

display()
# To add two matrices

def Matrix_Addition():
    for i in range(0, r):
        C = []
        for j in range(0, c):
            b = M_1[i][j] + M_2[i][j]
            C.append(b)
        M_A.append(C)
            # print(b, end= "    ")
        # print("\n")
    print("Addition of Matrices : ")
    for i in range(0, r):
        for j in range(0, c):
            print(M_A[i][j], end= "    ")    
        print("\n")  
    print ("\n")

Matrix_Addition()

def Matrix_Subtraction():
    for i in range(0, r):
        C = []
        for j in range(0, c):
            b = M_1[i][j] - M_2[i][j]
            C.append(b)
        M_S.append(C)
            # print(b, end= "    ")
        # print("\n")
    print("Subtraction of matrices is : ")
    for i in range(0, r):
        for j in range(0, c):
            print(M_S[i][j], end= "    ")    
        print("\n")  
    print ("\n")

Matrix_Subtraction()

def Matrix_Multiplication():
    if r == c:
        for i in range(0, r):
            C = []
            add1 = 0
            add = 0
            for j in range(0, c):
                b = M_1[i][j] * M_2[j][i]
                e = M_1[i][j] * M_2[j][1]
                add1 += e
                add += b 
            C.append(add)
            C.append(add1)
            M_M.append(C)
                # print(b, end= "    ")
            # print("\n")
        print("Multiplication of both Matrices is : ")
        for i in range(0, r):
            for j in range(0, c):
                print(M_M[i][j], end= "    ")    
            print("\n")  
        print ("\n")
    else:
        print("Multiplication not Possible ")

Matrix_Multiplication()

def Matrix_Inverse():
    for i in range(0, r):
        C = []
        for j in range(0, c):
            d = M_1[j][i] 
            C.append(d)
        M_T_1.append(C)
    
    for i in range(0, r):
        D = []
        for j in range(0, c):
            d = M_2[j][i] 
            D.append(d)
        M_T_2.append(D)
    print("Transpose of Matrix A is : ")
    for i in range(0, r):
        for j in range(0, c):
            print(M_T_1[i][j], end= "    ")    
        print("\n")  
    print ("\n")
    print("Transpose of Matrix B is : ")
    for i in range(0, r):
        for j in range(0, c):
            print(M_T_2[i][j], end= "    ")    
        print("\n")  
    print ("\n")

Matrix_Inverse()
