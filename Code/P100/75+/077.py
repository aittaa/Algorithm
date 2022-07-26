
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

# sys.setrecursionlimit(10**7)

###

N, M = map(int, input().split())

sum = [0, 0]

temp = 0
for i in range(N-1):
    temp += int(input())
    sum.append(temp)


answer = 0
prev = 1
for _ in range(M):
    e = int(input())
    answer += abs(sum[prev + e] - sum[prev])
    answer %= 10**5
    prev += e

print(answer%10**5)