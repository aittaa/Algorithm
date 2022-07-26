
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

sys.setrecursionlimit(1 << 25)
###

N, Q = map(int, input().split())
G = [ [] for _ in range(N+1)]
W = [0] * (N+1)

for _ in range(1, N):
    a, b = map(int, input().split())
    G[a].append(b)


def dfs(start_node : int, value : int):
    global G, W

    W[start_node] += value

    for node in G[start_node]:
        dfs(node, value)



for _ in range(Q):
    p, x = map(int, input().split())
    dfs(p, x)

for i in range(1, N+1):
    print(W[i], end=' ')