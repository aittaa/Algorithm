
import bisect

N, Q = map(int, input().split())
A = sorted(list(map(int, input().split())))


prefixSum = [0, ]
for e in A:
    prefixSum.append(prefixSum[-1] + e)


for _ in range(Q):
    target = int(input())

    if target == 0:
        print(prefixSum[-1])
        continue

    leftIdx = bisect.bisect_left(A, target)
    rightIdx = bisect.bisect_right(A, target)

    leftSum = (leftIdx * target) - prefixSum[leftIdx] 
    rightSum = (prefixSum[-1] - prefixSum[rightIdx]) - ((N - rightIdx)*target)

    print(leftSum + rightSum)

