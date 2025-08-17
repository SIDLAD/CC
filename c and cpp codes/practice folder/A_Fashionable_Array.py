t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    
    b = a.copy()
    b.reverse()
    
    ans = 1000
    
    for i in range(n):
        if (a[i] + a[-1]) % 2 == 0:
            ans = i
            break
    
    for i in range(n):
        if(b[i] + b[-1]) % 2 == 0:
            ans = min(ans, i)
            break
    
    print(ans)
    