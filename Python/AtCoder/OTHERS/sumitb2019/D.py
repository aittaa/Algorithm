

N = int(input())
S = list(map(int, input()))


cnt = 0

for i in range(0, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            
            checkNum = 1
            
            for c in S:
                if checkNum == 1 and c == i:
                    checkNum += 1
                elif checkNum == 2 and c == j:
                    checkNum += 1
                elif checkNum == 3 and c == k:
                    checkNum += 1
                elif checkNum == 4:
                    break
            if checkNum == 4:
                cnt += 1

print(cnt)
                    

