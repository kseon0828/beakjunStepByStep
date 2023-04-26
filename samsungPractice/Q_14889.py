n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [False]*n #방문한 사람인지를 확인하기 위한 1차원 리스트
result = 999999

def dfs(depth, idx):
    #idx를 받는 이유는 전에 탐색했던 구간 후 부터 탐색을 진행하기 위해
    global result #전역변수 result를 함수 dfs에서 사용하겠다는 소리

    if depth == n//2:
        #깊이가 인원수의 절반일때
        #더 이상 탐색하지 않고, 팀의 점수를 계산하여 result를 갱신 or 유지하고 해당 재귀 탈출
        a_score = 0
        b_score = 0
        for i in range(n):
            for j in range(n):
                #방문한 사람은 동일한 팀에 속하는 사람이므로 a팀 점수에 더함
                if visited[i] and visited[j]:
                    a_score += graph[i][j]
                elif not visited[i] and not visited[j]:
                    b_score += graph[i][j]

        result = min(result, abs(a_score-b_score))
        return


    for i in range(idx, n):
        if not visited[i]:
            visited[i] = True
            dfs(depth+1, i+1)
            visited[i] = False

dfs(0, 0)
print(result)
