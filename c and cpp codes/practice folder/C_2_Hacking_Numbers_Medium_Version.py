def print(*args, **kwargs):
    import builtins
    kwargs['flush'] = True
    builtins.print(*args, **kwargs)
    return int(input())
t = int(input())

for _ in range(t):
    n = int(input())
    print("mul 9")
    print("digit")
    print("digit")
    print(f"add {n-9}")
    print("!")
