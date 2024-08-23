n = int(input())

ans = 1
for _ in range(n):
    ans = ans*2%(int)(1e9 + 7)

print(ans)