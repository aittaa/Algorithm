# Templates
 
import sys, re
from math import ceil, floor, sqrt, pi, factorial, gcd, sqrt, cos, sin, tan
from copy import deepcopy
from collections import Counter, deque
from heapq import heapify, heappop, heappush
from itertools import accumulate, product, combinations, combinations_with_replacement
from bisect import bisect, bisect_left, bisect_right
from functools import reduce
from decimal import Decimal, getcontext
 
 
input = sys.stdin.readline
 
def i_input() -> int : return int(input())
def i_map() -> map : return map(int, input().split())
def i_list() -> list: return list(i_map())
def i_row(N) : return [i_input() for _ in range(N)]
def i_row_list(N) : return [i_list() for _ in range(N)]
 
def s_input() -> str : return input().rstrip()
def s_map() -> map: return input().split()
def s_list() -> list: return list(s_map())
def s_row(N): return [s_input() for _ in range(N)]
def s_row_str(N): return [s_list() for _ in range(N)]
def s_row_list(N): return [list(s_input()) for _ in range(N)]
 
def lcm(a, b): return a * b // gcd(a, b)
 
#O(sqrt(N))
def prime_factorization(N:int) -> list:
    result = []
 
    for i in range(2, int(sqrt(N))+1):
 
        while N % i == 0:
            N //= i
            result.append(i)
 
    if N != 1:
        result.append(N)
 
    return result
 
#O(N^1/2)
def divisors(N:int) -> list:
    N = int(N)
    divisors = []
    divisors_back = []
 
    for i in range(1, int(N ** (1 / 2))+1):
        if (N % i == 0):
            divisors.append(i)
            if (i != (N // i)):
                divisors_back.append(N // i)
 
    return divisors + divisors_back[::-1]
 
# O(sqrt(N))
def is_prime(N: int) -> bool:
    for i in range(2, int(sqrt(N) + 1)):
        if N % i == 0:
            break
    else:
        return True
 
    return False
 
sys.setrecursionlimit(10 ** 6)
INF = float('inf')
MOD = 10 ** 9 + 7
num_list = []
str_list = []
 
 
##