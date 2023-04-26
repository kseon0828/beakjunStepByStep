n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
checked = [False]*n

result = float('inf')

def dfs(level, idx):
    global result

    if level == n//2:
        #팀 계산 시작
        s_score = 0
        l_score = 0

        for i in range(n):
            for j in range(n):
                if checked[i] and checked[j]:
                    s_score += graph[i][j]
                elif not checked[i] and not checked[j]:
                    l_score += graph[i][j]
        result = min(result, abs(s_score-l_score))
        return

    if idx >= n:
        return

    checked[idx] = True
    dfs(level+1, idx+1)
    checked[idx] = False
    dfs(level, idx+1)

dfs(0,0)
print(result)
