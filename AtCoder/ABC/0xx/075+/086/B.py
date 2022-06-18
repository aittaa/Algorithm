import math

a, b = input().split()
c = int(a+b)

if int(math.sqrt(c)) == c**(1/2):
    print('Yes')
else:
    print('No')
