t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    s = input()
    st = set(map(int,input().split()))
    curPos = 1
    for ch in s:
        curPos += 1
        if ch == 'A':
            st.add(curPos)
        else:
            while curPos in st:
                curPos += 1
            st.add(curPos)
            while curPos in st:
                curPos += 1
    print(len(st))
    for e in sorted(st):
        print(e, end=' ')
    print()
            