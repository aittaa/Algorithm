
X, A, D, N = map(int, input().split())

B = A + D * (N-1)

if D < 0 :
    start = B
    end = A
    D *= -1
else:
    start = A
    end = B

if (start <= X <= end):
    # if A == X or B == X:
    #     print(0)
    #     exit()

    if D != 0:
        a = (X - start) % D
        b = D - (X - start) % D
        print(min(a, b))
    else:
        print(0)

else:
    if X < start:
        print(start - X)
    else:
        print(X-end)
