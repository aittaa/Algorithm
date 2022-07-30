

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
data = [[0, 0]]
for _ in range(N):
    data.append(list(map(int, input().split())))

DP  = [[0, 0] for _ in range(N+1)]


for i in range(1, N+1):
    