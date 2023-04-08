n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))


max = -int(1e9)
min = int(1e9)

def dfs(cur_res, level): #level은 깊이로, 숫자에서 1을 빼야 연산자의 개수가 나옴
    global max, min

    if(level == n-1):
        if(min>cur_res): min = cur_res
        if(max<cur_res): max = cur_res
        return

    for i in range(4):
        if(op[i] != 0):
            op[i] -= 1
            if (i == 0):
                dfs(cur_res + arr[level+1], level + 1)
            elif(i==1):
                dfs(cur_res - arr[level+1], level + 1)
            elif(i==2):
                dfs(cur_res * arr[level+1], level + 1)
            elif(i==3): #나눗셈 연산 조건 확인하기
                if cur_res>=0:
                    dfs(cur_res // arr[level+1], level + 1)
                else:
                    dfs((-cur_res // arr[level+1])*-1, level + 1)
            op[i] += 1


dfs(arr[0], 0)
print(max)
print(min)