import sys
input = sys.stdin.readline


#O(N^1/2)
def divisors(N:int) -> list:
    N = int(N)
    divisors = []
    divisors_back = []

    for i in range(1, int(N ** (1 / 2))+1):
        if (N % i == 0):
            divisors.append(i)
            if (i != (N // i)):
                divisors_back.append(N // i)

    return divisors + divisors_back[::-1]

N = int(input())

cnt = 0
for i in range(103, N+1, 2):
    if len(divisors(i)) == 8:
        cnt += 1

print(cnt)

