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
ref = [-INF, data[1]]

for i in range(1, N+1):
    maxVal = -INF

    idx = bisect_left(ref, data[i])
    
    if len(ref) > idx:
        ref[idx] = data[i]
    else :
        ref.append(data[i])

    DP[i] = idx

print(max(DP))

    
