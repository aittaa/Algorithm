N, K = map(int, input().split())

A = list(map(int, input().split()))
A = [e-1 for e in A]

data = []

for _ in range(N):
    data.append(tuple(map(int, input().split())))


def distance(a:tuple, b:tuple) -> int:
    return abs(a[0] - b[0])**2 + abs(a[1] - b[1])**2

result = 0


for i in range(N):
    if (i) in A: continue

    dist = int(1e20)

    for j in A:
        dist = min(dist, distance(data[i], data[j]))

    result = max(result, dist)

print(result**(1/2))