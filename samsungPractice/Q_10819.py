"""
n = int(input())
a = list(map(int, input().split()))

visited = [0]*n # 데이터의 사용 여부 - 데이터의 index  visited[1] = 1
arr = [0] * n  # 어떤 데이터를 선택했는가 (순열 정보 저장)  arr[1] = 2
arr_list = []

def permutation(level):
    if level >=n:
        arr_list.append(arr.copy())
        return

    for i in range(n):
        if visited[i]:continue
        visited[i] = 1
        arr[level] = a[i]
        permutation(level+1)
        visited[i] = 0

permutation(0)

ans = 0

for i in arr_list:
    s = 0
    for j in range(1, n):
        s += abs(i[j] - i[j - 1])
    if ans < s:
        ans = s
print(ans)
"""

n = int(input())
a = list(map(int, input().split()))
visited = [0]*len(a)
arr = [0]*len(a)
per_list = []
max_result = float('-inf')

def permutation(level):
    global max_result
    if level == len(a):
        per_list.append(arr.copy())

        #최대값 갱신하는 부분
        sum = 0
        for i in range(len(a)-1):
            sum += abs(arr[i] - arr[i+1])
        max_result = max(max_result, sum)

        return

    for i in range(len(a)):
        if visited[i]:
            continue
        visited[i] =1
        arr[level] = a[i]
        permutation(level+1)
        visited[i] = 0

permutation(0)

print(max_result)







