
A = input()
B = input()

for i in range(len(A)):
    
    str = A[i:] + A[:i]
    if str == B:
        print("Yes")
        break
else:
    print("No")