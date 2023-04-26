n = int(input())
graph = [list(map(int, input())) for _ in range(n)]

list_home_cnt = [] #집의 수 담는 리스트

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def dfs(x, y):
    home_cnt = 1 #각 단지의 집의 수
    graph[x][y] = 0
    stack=[(x, y)]

    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n or graph[nx][ny] ==0: #다음 탐색할 위치가 범위를 벗어나면 continue
                continue
            else:
                graph[nx][ny] = 0 #스택에 넣기 전에 방문 처리(0)
                home_cnt += 1
                stack.append((nx, ny))

    return home_cnt

for i in range(n):
    for j in range(n):
        if graph[i][j] ==1:
            list_home_cnt.append(dfs(i, j))

print(len(list_home_cnt))

list_home_cnt = sorted(list_home_cnt)

for i in range(len(list_home_cnt)):
    print(list_home_cnt[i])