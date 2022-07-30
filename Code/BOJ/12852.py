
from re import A
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

DP = [INF] * (N+1)
pre = [0] * (N+1)

DP[1] = 0
list = []

for i in range(2, N+1):

    a = DP[i-1] + 1
    b = DP[i//2]+1 if (i%2 == 0) else INF
    c = DP[i//3]+1 if (i%3 == 0) else INF

    DP[i] = min(a, b, c)

    if DP[i] == a:
        pre[i] = i-1
    elif DP[i] == b:
        pre[i] = i//2
    else:
        pre[i] = i//3
    
val = N
while val != 1:
    list.append(val)
    val = pre[val]

list.append(1)

print(DP[N])

for e in list:
    print(e, end=' ')
