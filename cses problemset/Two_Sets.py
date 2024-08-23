n = int(input())
if (n+1>>1)&1:
    print("NO")
    exit()

print("YES")
first_lst = []
second_lst = []

for i in range(1,n//2+1):
    if i&1:
        first_lst.append(i)
        first_lst.append((n&(n^1))-i + 1)
    else:
        second_lst.append(i)
        second_lst.append((n&(n^1))-i + 1)

if n&1:
    second_lst.append(n)
    
print(len(first_lst))
for ele in first_lst: print(ele,end=" ")
print()

print(len(second_lst))
for ele in second_lst: print(ele,end=" ")