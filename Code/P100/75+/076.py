
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

# sys.setrecursionlimit(10**7)

###

N = int(input())
A = list(map(int, input().split()))


sum = [0]

temp = 0
for i in range(N):
    sum.append(temp + A[i])
    temp = sum[-1]


for k in range(1, N+1):
    maxVal = 0
    for i in range(N-k +1):
        maxVal = max(maxVal, sum[i+k]-sum[i])

    print(maxVal)
