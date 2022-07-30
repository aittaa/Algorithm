
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

data = [[0, 0, 0]]

for _ in range(1, N+1):
    data.append(list(map(int, input().split())))

DP = [[0] * 3 for _ in range(N+1)]

DP[1][0] = data[1][0]
DP[1][1] = data[1][1]
DP[1][2] = data[1][2]

for i in range(2, N+1):
    DP[i][0] = data[i][0] + min(DP[i-1][1], DP[i-1][2])
    DP[i][1] = data[i][1] + min(DP[i-1][0], DP[i-1][2])
    DP[i][2] = data[i][2] + min(DP[i-1][0], DP[i-1][1])

print(min(DP[N][0], DP[N][1], DP[N][2]))