
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

sys.setrecursionlimit(300000)

###

N, Q = map(int, input().split())
G = [ [] for _ in range(N+1)]
W = [0] * (N+1)
data = [0] * (N+1)
visited = [False] * (N+1)

for _ in range(1, N):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

for _ in range(Q):
    p, x = map(int, input().split())
    data[p] += x

def dfs(start_node : int, value : int):
    global G, W, data
    visited[start_node] = True
    W[start_node] += data[start_node] + value

    for node in G[start_node]:
        if not visited[node]:
            dfs(node, W[start_node])


dfs(1, 0)

for i in range(1, N+1):
    print(W[i], end=' ')