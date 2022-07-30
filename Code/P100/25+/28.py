
import sys
from collections import deque

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

# sys.setrecursionlimit(10**7)

###

n = int(input())

G = [[] for _ in range(n+1)]

for i in range(1, n+1):
    G[i] = list(map(int, input().split()))

dist = [-1] * (n+1)

def bfs(node : int):
    global dist

    discovered = [False] * (n+1)
    discovered[node] = True

    dist[node] = 0

    queue = deque()
    queue.append(node)

    while queue:
        
        newNode = queue.popleft()
        
        for e in G[newNode]:
            if not discovered[e]:
                queue.append(e)
                discovered[e] = True
                dist[e] = dist[newNode] + 1

bfs(1)

for i in range(1, n+1):
    print(i, dist[i])

 