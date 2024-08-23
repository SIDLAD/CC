n = int(input())
for i in range(1,n+1):
    total_squares = i*i
    total_comb = total_squares*(total_squares-1)//2
    subtract_comb = 4 * (i-1)*(i-2)
    print(total_comb - subtract_comb)