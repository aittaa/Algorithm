import sys
input = sys.stdin.readline


N, M = map(int, input().strip().split())
data = []

for _ in range(N):
    data.append(list(map(int, input().strip().split())))

print(N, M)
print(data)