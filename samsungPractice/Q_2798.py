"""
n, m = map(int, input().split())
a = list(map(int, input().split()))

arr = [0]*3
arr_list=[]
pick_num = 3

def comb(level, s):
    if level == pick_num:
        arr_list.append(arr.copy())
        return

    for i in range(s, n-pick_num+level+1):
        arr[level] = a[i]
        comb(level+1, i+1)

comb(0, 0)

appro_sum = 0
for i in arr_list:
    s = sum(i)
    if appro_sum < s and s <= m:
        appro_sum = s

print(appro_sum)
"""

n, m = map(int, input().split())
card = list(map(int, input().split()))
visited = [0]*n
arr = [0]*3
result = 0

def comb(level, idx):
    global result, m

    if level == 3:
        num = 0
        for i in range(3):
            num += arr[i]
        result = max(num, result) if num <= m else result
        return

    if idx >= len(card):
        return

    visited[idx] = 1
    arr[level] = card[idx]
    comb(level+1,idx+1)
    visited[idx] = 0
    comb(level, idx+1)

comb(0,0)
print(result)