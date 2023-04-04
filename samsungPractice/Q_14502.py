from collections import deque
import copy

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

queue = deque()

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

result = 0 #벽을 3개 세운 각 상태들 중에서 빈방이 제일 많은 수

def bfs():
    global result
    test_map = copy.deepcopy(graph)

    for i in range(n):
        for j in range(m):
            #바이러스(2)를 가지고 bfs 해가기
            if test_map[i][j] == 2:
                queue.append((i, j))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny<0 or ny >= m:
                continue

            #빈방이면 바이러스 퍼트리기 그리고 queue에 담에서 계속해서 더 퍼트리기기
            if test_map[nx][ny] ==0:
                test_map[nx][ny] = 2
                queue.append((nx, ny))

    count = 0 #현재 벽을 3개 세운 상태에서의 빈 방이 몇개인지 count
    for i in range(n):
        for j in range(m):
            if test_map[i][j] == 0:
                count += 1

    result = max(result, count)

def dfs(count):
    if count == 3:
        bfs()
        return
    for i in range(n):
            for j in range(m):
                if graph[i][j] == 0:
                    graph[i][j] = 1
                    dfs(count+1)
                    graph[i][j] = 0

dfs(0)
print(result)