from collections import defaultdict
from typing import Dict
import sys
d=sys.stdin.buffer.read().split()
it=iter(d)
nx=it.__next__
ni=lambda:int(nx())
t=ni()
o=[]
ap=o.append

dct: Dict[int,int] = defaultdict(int)

for _  in range(t):
    n=ni();k=ni();l=ni();r=ni();
    ar=[nx() for _ in range(n)]
    kending = [n] * len(ar)
    dct.clear()
    distinct_cnt = 0
    rptr = -1
    for lptr in range(n):
        ele = ar[lptr]
        while rptr + 1 < n and distinct_cnt < k:
            rptr += 1
            rele = ar[rptr]
            dct[rele] += 1
            if dct[rele] == 1:
                distinct_cnt += 1
        if distinct_cnt == k:
            kending[lptr] = rptr
        else:
            break
        dct[ele] -= 1
        if dct[ele] == 0:
            distinct_cnt -= 1
    
    dct.clear()
    rptr = -1
    distinct_cnt = 0
    ans = 0
    for lptr in range(n):
        ele = ar[lptr]
        while rptr + 1 < n and distinct_cnt < k + 1:
            rptr += 1
            rele = ar[rptr]
            dct[rele] += 1
            if dct[rele] == 1:
                distinct_cnt += 1
        if distinct_cnt == k + 1:
            kp1ending = rptr
        else:
            kp1ending = n
        kending[lptr] = max(kending[lptr], lptr + l - 1)
        kp1ending = min(kp1ending, lptr + r)
        ans += max(0, kp1ending - kending[lptr])
        dct[ele] -= 1
        if dct[ele] == 0:
            distinct_cnt -= 1

    ap(str(ans))
sys.stdout.write("\n".join(o))
