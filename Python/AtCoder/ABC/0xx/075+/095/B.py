N, X = map(int, input().split())

data = []

for _ in range(N):
    data.append(int(input()))

total = sum(data)

print(N + (X-total) // min(data))
