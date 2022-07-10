import sys
input = sys.stdin.readline


N, M = map(int, input().strip().split())
data = []

for _ in range(N):
    data.append(list(map(int, input().strip().split())))


maxSum = 0; sum = 0
for i in range(M):

    for j in range(i+1, M):

        for k in range(N):
            sum += max(data[k][i], data[k][j])

        maxSum = max(maxSum, sum)
        sum = 0


print(maxSum)