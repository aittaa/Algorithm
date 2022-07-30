

from collections import deque
import math
import heapq
from bisect import bisect_left, bisect_right
from re import L, T
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
data = []

weight = {}

for _ in range(N):
    data.append(input())

for c in "ABCDEFGHIJ":
    weight[c] = [0, 0]

for string in data:
    for i in range(len(string)):
        weight[string[i]][0] += (len(string) - i)**(10)


temp = []

for i in range(9):
    temp.append((weight[chr( ord('A') + i)][0], chr( ord('A') + i)))
temp.sort(reverse=True)

val = 9

for i in range(9):
    weight[temp[i][1]][1] = val
    val -= 1


answer = 0

for string in data:
    temp = []
    for c in string:
        temp.append(weight[c][1])

    answer += int("".join(map(str, temp)))

print(answer)
