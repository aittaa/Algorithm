
S = input()

ACGT = ['A', 'C', 'G', 'T']

maxCnt = 0; cnt = 0

for c in S:
    if c in ACGT:
        cnt += 1
    else:
        maxCnt = max(maxCnt, cnt)
        cnt = 0

maxCnt = max(maxCnt, cnt)

print(maxCnt)

