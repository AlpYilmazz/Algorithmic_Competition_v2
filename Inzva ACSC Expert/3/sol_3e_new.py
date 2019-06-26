lst = list(map(int, input().split()))
a = lst[0]
b = lst[1]

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
not_zero = 0

ans = a * b
for pi in primes:
    ans -= int(a**(1 / pi)) * (b // pi)
    if(b // pi != 0):
        not_zero += 1

#ans += not_zero

print(ans)
