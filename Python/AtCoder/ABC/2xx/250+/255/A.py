
R, C = map(int ,input().split())

data = []
for _ in range(2):
    data.append(list(input().split()))

print(data[R-1][C-1])