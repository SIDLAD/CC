n = input()
lst = map(int,input().split())
lst = list(lst)
ans = 0
for i in range(1,len(lst)):
    if(lst[i] < lst[i-1]):
        ans += lst[i-1] - lst[i]
        lst[i] = lst[i-1]
    
print(ans)