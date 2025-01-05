for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    min_b = min(b)
    c = []
    for a_e,b_e in zip(a,b):
        c.append([a_e%b_e,b_e])
    c.sort(key=lambda x: [x[0],-x[1]])
    
    suf = [0]*n
    suf[n-1] = c[n-1][1]-c[n-1][0]
    for i in range(n-2,-1,-1):
        suf[i] = suf[i+1] + (c[i][1]-c[i][0])
    suf.append(0)
    # print(c)
    # print(suf)
    res = suf[0]
    sum_yet = 0
    for i in range(n):
        if(c[i][0] >= min_b):
            continue
        ans = (i*c[i][0]-sum_yet)+suf[i+1]+(n-i-1)*c[i][0]
        sum_yet += c[i][0]
        res = min(ans,res)
    print(res)