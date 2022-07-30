

from collections import deque
import math
import heapq
from bisect import bisect_left, bisect_right
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
data = [-INF] + list(map(int, input().split()))

DP = [0] * (N+1)


DP[1] = 1
ref = [[-INF, data[1]], [0, 1] ]
path = [0] + [0]*(N+1)


for i in range(1, N+1):
    maxVal = -INF

    idx = bisect_left(ref[0], data[i])
    
    if len(ref[0]) > idx:
        ref[0][idx] = data[i]
        ref[1][idx] = i
        
    else :
        ref[0].append(data[i])
        ref[1].append(i)


    path[i] = ref[1][idx-1]

    DP[i] = idx


maxIdx = 0; maxVal = 0
for i in range(1, N+1):
    
    if DP[i] > maxVal:
        maxVal = DP[i]
        maxIdx = i


print(DP[maxIdx])



idx = maxIdx

answer = []
answer.append(data[idx])

while path[idx] != 0:
    idx = path[idx]
    answer.append(data[idx])

answer.reverse()

for e in answer:
    print(e, end=' ')
