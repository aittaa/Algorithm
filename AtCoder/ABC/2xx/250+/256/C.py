import sys
input = sys.stdin.readline

h = [0, 0, 0]
w = [0, 0, 0]

h[0], h[1], h[2], w[0], w[1], w[2] = map(int, input().rstrip().split())

MIN = 1
MAX = 30

if h[0] + h[1] + h[2] != w[0] + w[1] + w[2]:
    print(0)
    exit()

cnt = 0

for d11 in range(1, 29):
    for d21 in range(1, 29):
        for d12 in range(1, 29):
            for d22 in range(1, 29):
                
                d13 = h[0] - d11 - d12
                d23 = h[1] - d21 - d22

                d31 = w[0] - d11 - d21
                d32 = w[1] - d12 - d22

                d33 = w[2] - d13 - d23
                
                if (min(d13, d23, d31, d32, d33) < 1):
                    continue

                if (d31 + d32 + d33 != h[2]):
                    continue

                cnt += 1

print(cnt)