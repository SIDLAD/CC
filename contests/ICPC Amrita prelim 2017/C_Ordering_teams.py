for _ in range(int(input())):
    arr = [[] for i in range(3)]
    for i in range(3):
        a,b,c = map(int,input().split())
        arr[i].append(a)
        arr[i].append(b)
        arr[i].append(c)
        
    
    ways = [
        [0,1,2],
        [0,2,1],
        [1,0,2],
        [1,2,0],
        [2,0,1],
        [2,1,0],
    ]
    
    # print(arr)
    
    for way in ways:
        prev = arr[way[0]]
        correct = True
        for i in range(1,3):
            more = False
            for j in range(3):
                if(arr[way[i]][j] >= prev[j]):
                    if(arr[way[i]][j] > prev[j]):
                        more = True
                else:
                    correct = False
                    break
            if not more:
                correct = False
            
            prev = arr[way[i]]
        if(correct):
            print("yes")
            break
    else:
        print("no")