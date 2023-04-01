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