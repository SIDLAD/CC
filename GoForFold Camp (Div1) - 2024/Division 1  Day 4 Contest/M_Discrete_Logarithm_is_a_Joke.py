M = int(1e18) + 31

def modpow(a,b,M = M):
    a%=M
    res = 1
    while(b > 0):
        if(b&1):res = res*a%M
        a = a*a%M
        b>>=1
    return res

n = int(input())
n = 1e6 - n
a = 300
while n > 0:
    n-=1
    a = modpow(42,a)
    
print(a)