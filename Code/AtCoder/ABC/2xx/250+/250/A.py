 
H, W = map(int, input().split())
R, C = map(int, input().split())


dxdy = [(-1, 0), (0, -1), (1, 0), (0, 1)]

cnt = 4
for i in range(4):
    x = R + dxdy[i][0]
    y = C + dxdy[i][1]

    if not ((1 <= x <= H) and (1<= y <= W)):
        cnt -= 1
    
print(cnt)