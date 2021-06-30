n = int(input())
pt = list(map(int, input().split()))
pt.sort() # 오름차순 정렬
if len(pt) % 2 != 0:
    pt.pop() # 최댓값 제거

ans = -1
for i in range(len(pt)//2):
    ans = max(ans, pt[i] + pt[-1-i])
print(ans)
