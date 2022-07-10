from collections import Counter

N = int(input())
A = list(map(int, input().split()))

#DP

count = Counter(A)

end = int(2*10e5)+1
dp = [[0] * end for _ in range(3)]

for i in range(1, end):

    dp[0][i] = dp[0][i-1] + count[i]
    dp[1][i] = dp[1][i-1] + dp[0][i-1] * count[i]
    dp[2][i] = dp[2][i-1] + dp[1][i-1] * count[i]

print(dp[2][end-1])

#

# # 무식하게 풀기 

# def pickC(N:int, picked:list, M:int):
#     if(M == 0):
#         global cnt
#         data = set()
#         data.add(A[picked[0]])
#         data.add(A[picked[1]])
#         data.add(A[picked[2]])
#         if(len(data) == 3):
#             cnt += 1
#         return
    
#     smallest = picked[-1] + 1 if picked else 0

#     for next in range(smallest, N):
#         picked.append(next)
#         pickC(N, picked, M-1)
#         picked.pop()

# cnt = 0

# pickC(N, [], 3)

# print(cnt)
# # 