A = [1, 2, 3, 4, 5]  # 데이터 집합
N = 3     # 순열 요소 개수
visited = [0]*len(A)  # 데이터의 사용 여부 - 데이터의 index  visited[1] = 1
arr = [0] * N  # 어떤 데이터를 선택했는가 (순열 정보 저장)  arr[1] = 2
arr_list = []
def permutation(level):
    if level >=N:
        #print(arr)
        arr_list.append(arr.copy())
        return

    for i in range(len(A)):
        if visited[i]:continue
        visited[i] = 1
        arr[level] = A[i]
        permutation(level+1)
        arr[level] = 0 # 필수 작업은 아님
        visited[i] = 0


permutation(0)
print(arr_list)