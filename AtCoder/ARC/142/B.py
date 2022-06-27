import math

N = int(input())


cnt = 1

data = [[] for _ in range(N)]

for i in range(0, N, 2):
    data[i] = list(range(cnt, cnt+N))
    cnt += N

for i in range(1, N, 2):
    data[i] = list(range(cnt, cnt+N))
    cnt += N


for i in range(N):
    for j in range(N):
        print(data[i][j], end=' ')
    print()



