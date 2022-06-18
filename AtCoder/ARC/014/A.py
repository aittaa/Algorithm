 
A, B, C = map(int, input().split())


cnt = 0

while not (A%2 or B%2 or C%2):
    B = A//2 + C//2
    C = A//2 + B//2
    A = C//2 + B//2
    
print(cnt)