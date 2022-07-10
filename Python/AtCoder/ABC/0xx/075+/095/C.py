
A, B, C, X, Y = map(int, input().split())

sum = 0

if A+B > C*2:
    a = min(X, Y)
    
    X -= a
    Y -= a
    sum += C*2*a 

if X > 0:
    if A > C*2:
        sum += C*2*X
    else:
        sum += A*X

if Y > 0:
    if B > C*2:
        sum += C*2*Y
    else:
        sum += Y*B

print(sum)

