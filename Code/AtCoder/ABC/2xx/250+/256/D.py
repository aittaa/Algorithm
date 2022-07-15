import sys
input = sys.stdin.readline

N = int(input().rstrip())

data = []

for _ in range(N):
    data.append(tuple(map(int, input().rstrip().split())))


data.sort(key=lambda x:x[0])


left=data[0][0]
right=data[0][1]

for i in range(1, N):
    
    if data[i][0] <= right and right <= data[i][1]:
        right = data[i][1]
    elif data[i][0] <= right and right >= data[i][1]:
        continue
    else:
        print(left, right)
        left = data[i][0]
        right = data[i][1]

print(left, right)