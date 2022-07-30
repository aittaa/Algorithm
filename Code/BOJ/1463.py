
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

DP = [INF] * (N+1)

DP[1] = 0

for i in range(2, N+1):
    value = DP[i-1] + 1
    value = min(value, DP[i//2]+1 if (i%2 == 0) else INF)
    value = min(value, DP[i//3]+1 if (i%3 == 0) else INF)

    DP[i] = value

print(DP[N])
