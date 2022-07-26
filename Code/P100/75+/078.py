
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

# sys.setrecursionlimit(10**7)

###

M, N = map(int, input().split()) # 남북, 동서
K = int(input()) # 조사 대상 영역의 개수

data = []
area = []

for _ in range(M):
    data.append(list(input()))

for _ in range(K):
    a, b, c, d = map(int, input().split())
    area.append((a, b, c, d))

