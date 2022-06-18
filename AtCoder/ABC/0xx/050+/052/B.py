
N = int(input())
S = input()

maxVal = 0
val = 0

for c in S:
    if c == 'I':
        val+=1
    else:
        val-=1

    maxVal = max(maxVal, val)

print(maxVal)