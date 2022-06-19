
N = int(input())
A = list(map(int, input().split()))

cnt = 0
data = [0, 0, 0, 0]

for i in range(N):
    data[0] = 1
    for j in reversed(range(4)):
        if data[j] == 1:
            newPos = j + A[i]

            if newPos < 4:
                data[j] = 0
                data[newPos] = 1


            else:
                cnt+=1
                data[j] = 0
        
print(cnt)
