t = int(input())

for _ in range(t):
    a,b = map(int,input().split())
    mx = max(a,b)
    start = (mx - 1) ** 2

    if mx&1:
        #start starts from the bottom
        if a == mx:
            print(start + b) 
        else:
            print(start + mx + (mx - a))
    else:
        #start starts from the top
        if b == mx:
            print(start + a)
        else:
            print(start + mx + (mx - b))