N, K = map(int, input().split())

foods = list(map(int, input().split()))
dislikes = list(map(int, input().split()))

for i in range(len(foods)):
    foods[i] = [foods[i], False]

for d in dislikes:
    foods[d-1][1] = True


maxValue = max(foods, key= lambda x: x[0])
resultSet = [f for f in foods if f[0] == maxValue[0]]

for e in resultSet:
    if e[1]:
        print('Yes')
        exit()

print('No')
