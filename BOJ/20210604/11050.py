n, k = map(int, input().split())
deno = 1 # 분모
frac = 1 # 분자
for _ in range(k):
    deno *= n
    n -= 1

while k > 0:
    frac *= k
    k -= 1

ans = deno // frac
print(ans)
