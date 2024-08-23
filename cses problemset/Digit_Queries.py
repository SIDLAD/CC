t = int(input())

for _ in range(t):
    n = int(input())
    if(n < 10):
        print(n)
        continue
    
    digcountuptilnow = 9
    n-=9
    base10pow = 1
    while(n > 9*(10**base10pow) * (base10pow + 1)):
        n -= 9*(10**base10pow) * (base10pow + 1)
        digcountuptilnow += 9*(10**base10pow) * (base10pow + 1)
        base10pow += 1
    
    numnum = (n+base10pow)//(base10pow+1) - 1 + 10**(base10pow)
    digit_index = (n-1) % (base10pow + 1)
    print(str(numnum)[digit_index])
    
    
    