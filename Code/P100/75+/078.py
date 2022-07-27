
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

data.append(['X'] * (N+1))

prefix_sum_I = [[0] * (N+1) for _ in range(M+1)]
prefix_sum_O = [[0] * (N+1) for _ in range(M+1)]
prefix_sum_J = [[0] * (N+1) for _ in range(M+1)]

for _ in range(M):
    data.append(list("X"+input()))


#prefix sum table 생성
for i in range(1, M+1):
    for j in range(1, N+1):
        prefix_sum_I[i][j] = prefix_sum_I[i-1][j] + prefix_sum_I[i][j-1] - prefix_sum_I[i-1][j-1]
        if data[i][j] == 'I':
            prefix_sum_I[i][j] += 1

for i in range(1, M+1):
    for j in range(1, N+1):
        prefix_sum_O[i][j] = prefix_sum_O[i-1][j] + prefix_sum_O[i][j-1] - prefix_sum_O[i-1][j-1]
        if data[i][j] == 'O':
            prefix_sum_O[i][j] += 1

for i in range(1, M+1):
    for j in range(1, N+1):
        prefix_sum_J[i][j] = prefix_sum_J[i-1][j] + prefix_sum_J[i][j-1] - prefix_sum_J[i-1][j-1]
        if data[i][j] == 'J':
            prefix_sum_J[i][j] += 1

# 질의 도출 및 출력
for _ in range(K):
    a, b, c, d = map(int, input().split())

    oVal = prefix_sum_O[c][d] + prefix_sum_O[a-1][b-1] - prefix_sum_O[a-1][d] - prefix_sum_O[c][b-1]
    jVal = prefix_sum_J[c][d] + prefix_sum_J[a-1][b-1] - prefix_sum_J[a-1][d] - prefix_sum_J[c][b-1]
    iVal = prefix_sum_I[c][d] + prefix_sum_I[a-1][b-1] - prefix_sum_I[a-1][d] - prefix_sum_I[c][b-1]

    print(jVal, oVal, iVal)

