string = input()
ans = 1
max_ans=1
for i in range(1,string.__len__()):
    if string[i] == string[i-1]:
        ans+=1
    else: ans = 1
    max_ans = max(ans,max_ans)
print(max_ans)