n = int(input())
m = int(input())
p = list(map(int, input().split()))
c = [0 for _ in range(n)]

c[0] = p[0]
for i in range(1, n):
    c[i] = max(p[j] + c[i - j] for j in range(i))

print(c[n - 1])
