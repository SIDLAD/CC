def print(*args, **kwargs):
    import builtins
    kwargs['flush'] = True
    builtins.print(*args, **kwargs)
    return int(input())
t = int(input())

for _ in range(t):
    n = int(input())
    print(f"mul {'9' * 9}")
    print("digit")
    if(n != 81):
        print(f"add {n - 81}")
    print("!")