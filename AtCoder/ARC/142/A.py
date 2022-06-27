import sys
input = sys.stdin.readline


N, K = map(int, input().rstrip().split())


cnt = 0
if K % 10 == 0 or int(str(K)[::-1]) < K:
    cnt = 0
elif N == K:
    cnt = 1

else:

    if K < N:
        cnt+=1
    
    value = K*10
    while value <= N:
        cnt += 1
        value = value*10

    value = int(str(K)[::-1])
    if K != value:
        value = int(str(K)[::-1])
        while value <= N:
            cnt += 1
            value = value*10

print(cnt)