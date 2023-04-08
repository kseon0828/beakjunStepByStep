a = [1,2,3,4,5]
n = 3
visited = [0]*len(a)
arr =[0]*n
comb_list =[]

def comb(level, idx):
    if level == n:
        comb_list.append(arr.copy())
        return

    if idx >= len(visited):
        return

    visited[idx] = 1
    arr[level] = a[idx]
    comb(level+1, idx+1)
    visited[idx] = 0
    comb(level, idx+1)

comb(0, 0)
print(comb_list)