
N = int(input())
S = input()


maxVal = 0
for i in range(N):
    a = set(S[:i])
    b = set(S[i:])

    cnt = 0
    for e in set(S):
        if(e in a and e in b):
            cnt+=1
    
    maxVal = max(maxVal, cnt)

print(maxVal)