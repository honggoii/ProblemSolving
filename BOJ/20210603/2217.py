n = int(input())
data = []
for i in range(n):
    data.append(int(input()))

data.sort(reverse = True)

ans = []
for i in range(n):
    ans.append(data[i]*(i+1))

ans.sort(reverse = True)

print(ans[0])
