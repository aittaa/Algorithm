
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 0, -1, 0, 1, -1, -1, 1)
dy = (0, -1, 0, 1, -1, -1, 1, 1)

INF = float('inf')

# sys.setrecursionlimit(10**7)

###

N = int(input())

if(N == 1):
    print(int(input()))
    exit(0)
    
data = [0]

for _ in range(N):
    data.append(int(input()))

DP = [[0]*(2) for _ in range(N+1+10)]

DP[1][0] = 0
DP[1][1] = data[1]
DP[2][0] = data[1]
DP[2][1] = data[1] + data[2]

for i in range(3, N+1):
    # DP[i][0] = max(DP[i-1][1], DP[i-1][0]) : 세 계단 오를 수 없기에 잘못된 코드
    DP[i][1] = max(DP[i-3][1] + data[i-1], DP[i-2][1]) + data[i]

print(DP[N][1])

