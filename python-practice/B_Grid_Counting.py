from typing import List
M = 998244353
N = 200001
fact: List[int] = [1]
for i in range(1, N):
    fact.append(fact[-1] * i % M)

assert(fact[3] == 6)
rfact = [0] * N

def binexp(base: int, pow: int) -> int:
    ans = 1
    while pow:
        if pow&1:
            ans = ans * base % M
        base = base * base % M
        pow >>= 1
    return ans

assert(binexp(4,3) == 64)
assert(binexp(1,10) == 1)

rfact[-1] = binexp(fact[-1], M-2)
assert(rfact[-1] * fact[-1] % M == 1)
for i in range(N-2, -1, -1):
    rfact[i] = rfact[i + 1] * (i + 1) % M

assert(rfact[1] == 1)

def nck(n: int,k: int):
    if min(n,k) < 0 or k > n:
        return 0
    return fact[n] * rfact[k] % M * rfact[n-k] % M

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    tot = sum(arr)
    if tot != n:
        print(0)
        continue
    ch = True
    for i in range(tot + 1 >> 1, tot):
        if arr[i] != 0:
            ch = False
            break
    if not ch:
        print(0)
        continue
    
    i = (tot - 1 >> 1)
    rem = 1 if n&1 else 2
    ans = 1
    while i >= 0:
        # print("Hello" , rem, arr[i])
        if rem < arr[i]:
            ch = False
            break
        ans = (ans * nck(rem, arr[i])) % M
        rem -= arr[i]
        i -= 1
        rem += 2
    
    if not ch:
        print(0)
        continue
    
    print(ans)