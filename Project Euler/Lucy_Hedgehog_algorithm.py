def Psum(n):
    r = int(n**0.5)
    
    V = [n//k for k in range(1,r+1)]
    # V += list(range(V[-1] - 1,0,-1))
    V += list(range(r if V[-1] != r else r-1,0,-1))
    S = {i:i * (i + 1)//2  - 1 for i in V}
    for p in range(2,r+1):
        if S[p] > S[p-1]: #p is prime
            p2 = p * p
            for v in V:
                if v < p*p: break
                S[v] -= p * (S[v//p] - S[p-1])
    
    return S[n]

def Pcount(n):
    r = int(n**0.5)
    V = [n//k for k in range(1,r+1)]
    V += list(range(r if V[-1] != r else r-1,0,-1))
    S = {i:i-1 for i in V}
    for p in range(2,r+1):
        if S[p] > S[p-1]:
            p2 = p * p
            sp = S[p-1]
            for v in V:
                if v < p * p: break
                S[v] -= S[v//p] - S[p-1]
    return S[n]
# print(Psum(int(2e6)))
print(Psum(int(25)))
print(Psum(170))
print(Psum(195))
print(Pcount(int(2e6)))