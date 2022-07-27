
import sys

# input = sys.stdin.readline
def input() :
    return sys.stdin.readline().rstrip()
    
dx = (1, 1, 0, -1, -1, -1, 0, 1 )
dy = (0, -1, -1, -1, 0, 1, 1, 1 )

# sys.setrecursionlimit(10**7)

###

N = int(input())

imos = [0] * 1000010 # 이모스 리스트
imos_sum = [0] * 1000010 # 이모스 누적합 리스트

for _ in range(N):
    a, b = map(int, input().split())

    imos[a] += 1
    imos[b+1] -= 1

imos_sum[0] = imos[0]

for i in range(1, 1000001):
    imos_sum[i] = imos_sum[i-1] + imos[i]

print(max(imos_sum))