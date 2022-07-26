
import sys

def input() :
    return sys.stdin.readline().rstrip()

dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

sys.setrecursionlimit(10**7)

###

w, h = map(int, input().split())
visited = [[False] * w for _ in range(h)]
G = []

def dfs(y : int, x : int):
    global w, h, visited, G
    visited[y][x] = True

    for i in range(8):
        new_x = x + dx[i]; new_y = y + dy[i]
        if 0 <= new_y < h and 0 <= new_x < w and G[new_y][new_x] == 1 and not visited[new_y][new_x]:
            dfs(new_y, new_x)

while w != 0 or h != 0 :
    cnt = 0
    G = []

    for i in range(h):
        G.append(list(map(int, input().split())))
    
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and G[i][j] == 1:
                cnt += 1
                dfs(i, j)

    print(cnt)
    w, h = map(int, input().split())
    visited = [[False] * w for _ in range(h)]

