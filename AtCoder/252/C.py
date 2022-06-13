import sys
N = int(input())

data = []
for _ in range(N):
    data.append(list(map(int, str(input()))))

###

minStep = int(1e9)

def findFirstIndex(num):
    for j in range(10):
        for i in range(N):
            if data[i][j] == num:
                return i, j
                

for num in range(10):
    
    searchSet = {i for i in range(N)}
    foundElement, step = findFirstIndex(num)
    searchSet.remove(foundElement)

    while len(searchSet) > 0:
        step += 1
        for i in searchSet:
            if data[i][step % 10] == num:
                searchSet.remove(i)
                break

    minStep = min(minStep, step)

print(minStep)
