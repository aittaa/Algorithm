
while True:
    
    pickedSet = []

    N, X = map(int, input().split())
    
    if N == 0 and X == 0:
        break

    li = list(range(1, N+1))

    cnt = 0

    for i in range(N):
        for j in range(i+1, N):
            for k in range(j+1, N):
                if li[i] + li[j] + li[k] == X:
                    cnt += 1
    
    print(cnt)



