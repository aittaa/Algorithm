 
A, B, C = map(int, input().split())


cnt = 0

while not (A%2 or B%2 or C%2):
    nA = B//2 + C//2
    nB = A//2 + C//2
    nC = A//2 + B//2

    A = nA
    B = nB
    C = nC

    if A == B == C:
        cnt = -1
        break
        
    cnt += 1

print(cnt)