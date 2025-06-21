t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a = [a[i] for i in range(n) if i == 0 or a[i] != a[i-1]]
    ans = 0
    for i in range(len(a)):
        if (i == 0 or a[i-1] < a[i]) and (i == len(a)-1 or a[i + 1] < a[i]):
            ans += 1
    print(ans)