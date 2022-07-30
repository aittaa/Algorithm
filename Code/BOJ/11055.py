import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

INF = float('inf')

# sys.setrecursionlimit(10**7)

###

N = int(input())
data = [0] + list(map(int, input().split()))

DP = [0] * (N+1)

DP[1] = data[1]

for i in range(2, N+1):
    maxVal = 0

    for j in range(1, i):
        if data[j] < data[i] and maxVal < DP[j]:
            maxVal = DP[j]
    
    DP[i] = maxVal + data[i]

print(max(DP))

    
