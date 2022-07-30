
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

if N < 2:
    print(N)
    exit(0)
DP = [0] * (N+1)

DP[1] = 1
DP[2] = 2

mod = 10007

for i in range(3, N+1):
    DP[i] = (DP[i-1] + DP[i-2])%mod

print(DP[N])
