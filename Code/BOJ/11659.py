
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

INF = float('inf')

# sys.setrecursionlimit(10**7)

###

N, M = map(int, input().split())

data = [0] + list(map(int, input().split()))
ps = [0] * (N+1)

for i in range(1, N+1):
    ps[i] = ps[i-1] + data[i]


for _ in range(M):
    a, b = map(int, input().split())
    print(ps[b] - ps[a-1])

