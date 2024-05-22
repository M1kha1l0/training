#name = input()
#f = open(name)
f = open('test.txt')
n = int(f.readline())
A = [0] * n
ans = [0] * n
sum = 0
rs = 0
ls = 0
for i in range(0, n): A[i] = int(f.readline())

for i in range(1, n // 2):
    sum = sum + A[i] * i + A[n - i] * i
    rs += A[i]
    ls += A[n - i]
    
sum += A[n // 2] * n // 2
ans[0] = sum
for i in range(1, n):
    ans[i] = ans[i - 1] + ls + A[i - 1] - rs - A[(i + (n // 2) - 1) % n]
    rs -= A[i] - A[(i + (n // 2) - 1) % n]
    ls -= A[(i + (n // 2)) % n] - A[i - 1]

print(ans.index(min(ans)), min(ans))