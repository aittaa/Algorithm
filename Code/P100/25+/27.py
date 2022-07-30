
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

sys.setrecursionlimit(10**9)

###

m = int(input())
n = int(input())


maxVal = 0

data = []

for _ in range(n):
    data.append(list(map(int, input().split())))

def dfs(y : int, x : int, value : int):
    global maxVal, visited
    maxVal = max(maxVal, value)

    visited[y][x] = True

    for i in range(4):
        newX = x + dx[i]
        newY = y + dy[i]

        if 0 <= newX < m and 0 <= newY < n and data[newY][newX] == 1 and not visited[newY][newX]:
            dfs(newY, newX, value+1)

    visited[y][x] = False


for i in range(n):
    for j in range(m):
        visited = [[False] * m for _ in range(n)]
        if data[i][j] == 1:
            dfs(i, j, 1)


print(maxVal)
