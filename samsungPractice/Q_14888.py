n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))


max = -int(1e9)
min = int(1e9)

def dfs(cur_res, idx):
    global max, min

    if(idx == n-1):
        if(min>cur_res): min = cur_res
        if(max<cur_res): max = cur_res
        return

    for i in range(4):
        if(op[i] != 0):
            op[i] -= 1
            if (i == 0):
                dfs(cur_res + arr[idx+1], idx + 1)
            elif(i==1):
                dfs(cur_res - arr[idx+1], idx + 1)
            elif(i==2):
                dfs(cur_res * arr[idx+1], idx + 1)
            elif(i==3): #나눗셈 연산 조건 확인하기
                if cur_res>=0:
                    dfs(cur_res // arr[idx+1], idx + 1)
                else:
                    dfs((-cur_res // arr[idx+1])*-1, idx + 1)
            op[i] += 1


dfs(arr[0], 0)
print(max)
print(min)