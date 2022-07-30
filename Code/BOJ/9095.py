
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

INF = float('inf')

# sys.setrecursionlimit(10**7)

###


DP = [0] * (10+1)
DP[1] = 1; DP[2] = 2; DP[3] = 4

for i in range(4, 11):
    DP[i] = DP[i-1] + DP[i-2] + DP[i-3]

T = int(input())

for _ in range(T):
    print(DP[int(input())])

    
