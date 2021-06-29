k, n = map(int, input().split())
line = []
for _ in range(k):
    line.append(int(input()))
line.sort(reverse=True) # 오름차순

start = 1
end = line[0] # 가장 긴 랜선

while start <= end:
    mid = (start + end) // 2
    total = 0
    for i in range(k):
        total += (line[i] // mid)
    if total >= n:
        start = mid + 1
    elif total < n:
        end = mid -1

print(end)
