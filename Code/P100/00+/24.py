
import sys
from collections import deque

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()

###


# 인접 리스트 입력
N = int(input())
G = [ [] for _ in range(N+1)]

start = [0] * (N+1)
end = [0] * (N+1)

for _ in range(N):
    id, _, *adj = list(map(int, input().split()))
    G[id] = adj

visited = [False] * (N+1)

time = 0

def dfs(start_node : int):
    global time
    time += 1
    start[start_node] = time
    for node in G[start_node]:
        if not visited[node]:
            visited[node] = True
            dfs(node)
    
    time += 1
    end[start_node] = time

visited[1] = True
dfs(1)

for node in range(1, N+1):
    if not visited[node]:
        dfs(node)


for i in range(1, N+1):
    print(i, start[i], end[i])
